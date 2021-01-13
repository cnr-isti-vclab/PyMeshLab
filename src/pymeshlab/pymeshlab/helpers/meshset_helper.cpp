#include <pybind11/pybind11.h> //needs to be included before anything else
#include "meshset_helper.h"

#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <common/parameters/rich_parameter_list.h>
#include <common/mlexception.h>
#include <common/GLExtensionsManager.h>
#include <common/meshlabdocumentxml.h>
#include <common/meshlabdocumentbundler.h>
#include <wrap/io_trimesh/alnParser.h>

#include "common.h"
#include "meshlab_singletons.h"
#include "verbosity_manager.h"
#include "../plugin_management/filterfunctionset.h"
#include "../percentage.h"
#include "../exceptions.h"
#include "../meshset.h"

namespace py = pybind11;

namespace pymeshlab {
namespace meshsethelper {

/** RichParameterList Management **/

void updateRichParameterList(
		const std::string& filtername, 
		const RichParameterList& base, 
		RichParameterList& toUpdate)
{
	for (const RichParameter& p : base){
		if (toUpdate.hasParameter(p.name())){
			toUpdate.setValue(p.name(), p.value());
		}
		else {
			std::cerr << 
					"Warning: parameter " + p.name().toStdString() +
					" not required by filter " + filtername.c_str();
		}
	}
}

void updateRichParameterFromKwarg(
		RichParameter& par,
		MeshDocument* md,
		const FilterFunctionParameter& ffp,
		const std::pair<py::handle, py::handle>& k)
{
	QString meshlabType = ffp.meshlabTypeString();
	if (meshlabType == MESHLAB_TYPE_BOOL){
		par.setValue(BoolValue(py::cast<bool>(k.second)));
	}
	else if (meshlabType == MESHLAB_TYPE_INT) {
		par.setValue(IntValue(py::cast<int>(k.second)));
	}
	else if (meshlabType == MESHLAB_TYPE_FLOAT) {
		par.setValue(FloatValue(py::cast<float>(k.second)));
	}
	else if (meshlabType == MESHLAB_TYPE_STRING) {
		par.setValue(StringValue(
					QString::fromStdString(py::cast<std::string>(k.second))));
	}
	else if (meshlabType == MESHLAB_TYPE_ABSPERC) {
		RichAbsPerc& abs = dynamic_cast<RichAbsPerc&>(par);
		float absvalue;
		try {
			Percentage p = py::cast<Percentage>(k.second);
			absvalue = (abs.max - abs.min);
			absvalue *= p.value()/100;
			absvalue += abs.min;
		}
		catch (const py::cast_error& err) {
			absvalue = py::cast<float>(k.second);
		}

		abs.setValue(AbsPercValue(absvalue));
	}
	else if (meshlabType == MESHLAB_TYPE_COLOR) {
		par.setValue(ColorValue(py::cast<QColor>(k.second)));
	}
	else if (meshlabType == MESHLAB_TYPE_DYNAMIC_FLOAT) {
		RichDynamicFloat& dyn = dynamic_cast<RichDynamicFloat&>(par);
		float val = py::cast<float>(k.second);
		if (val >= dyn.min && val <= dyn.max)
			dyn.setValue(DynamicFloatValue(val));
		else
			throw MLException(
					"Parameter " + ffp.pythonName() + ": float value " + QString::number(val) +
					" out of bounds (min: " + QString::number(dyn.min) +
					"; max: " + QString::number(dyn.max) + ").");
	}
	else if (meshlabType == MESHLAB_TYPE_POINT3F) {
		py::array_t<float> arr = py::cast<py::array_t<float>>(k.second);
		if (arr.size() != 3){
			throw MLException(
					"Parameter " + ffp.pythonName() + ": invalid array. Expected a "
					"numpy float32 array of 3 elements.");
		}
		else {
			vcg::Point3f p(arr.at(0), arr.at(1), arr.at(2));
			par.setValue(Point3fValue(p));
		}
	}
	else if (meshlabType == MESHLAB_TYPE_MATRIX44F){
		Eigen::Matrix4d arr = py::cast<Eigen::Matrix4d>(k.second);
		if (arr.size() != 16){
			throw MLException(
					"Parameter " + ffp.pythonName() + ": invalid array. Expected a "
					"numpy float32 array of 4x4 elements.");
		}
		else {
			Matrix44m m;
			MESHLAB_SCALAR* v = m.V();
			int k = 0;
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 4; j++) {
					v[k++] = arr(i,j);
				}
			}
			par.setValue(Matrix44fValue(m));
		}
	}
	else if (meshlabType == MESHLAB_TYPE_ENUM){
		RichEnum& en = dynamic_cast<RichEnum&>(par);
		int value;
		try{
			std::string e = py::cast<std::string>(k.second);
			value = en.enumvalues.indexOf(QString::fromStdString(e));
			if (value == -1){
				std::string list;
				for (const QString& s : en.enumvalues){
					list += "'" + s.toStdString() + "'; ";
				}
				std::string message =
						"Enum '" + e + "' not found. Possible values are " + list;
				throw InvalidEnumException(message);
			}
		}
		catch(const py::cast_error& err){
			value = py::cast<int>(k.second);
			if (! (value>= 0 && value < en.enumvalues.size()))
				throw InvalidEnumException(
						"Enum " +std::to_string(value)+ " not valid. Must be a "
						"value between 0 and " + std::to_string(en.enumvalues.size()));
		}
		en.setValue(EnumValue(value));
	}
	else if (meshlabType == MESHLAB_TYPE_OPENFILE){
		RichOpenFile& of = dynamic_cast<RichOpenFile&>(par);
		of.setValue(StringValue(
					QString::fromStdString(py::cast<std::string>(k.second))));
	}
	else if (meshlabType == MESHLAB_TYPE_SAVEFILE){
		RichSaveFile& sf = dynamic_cast<RichSaveFile&>(par);
		sf.setValue(StringValue(
					QString::fromStdString(py::cast<std::string>(k.second))));
	}
	else if (meshlabType == MESHLAB_TYPE_MESH) {
		RichMesh& rm = dynamic_cast<RichMesh&>(par);
		rm.meshdoc = md;
		rm.meshindex = py::cast<int>(k.second);
		rm.setValue(MeshValue(rm.meshdoc, rm.meshindex));
	}
	else if (meshlabType.contains("still_unsupported")){
		std::cerr << "Warning: parameter type still not supported";
	}
	else {
		std::cerr << "Parameter type not found. Critical Error. Exiting...";
		assert(0);
		exit(-1);
	}
}

void updateRichParameterListFromKwargs(
		const FilterFunction& f,
		const pybind11::kwargs& kwargs,
		MeshDocument* md,
		RichParameterList& rps,
		bool ignoreFileName)
{
	if (kwargs){
		for (std::pair<pybind11::handle, pybind11::handle> p : kwargs){
			std::string key = p.first.cast<std::string>();
			if (!ignoreFileName || key!="file_name"){
				if (f.contains(QString::fromStdString(key))){
					const FilterFunctionParameter& ffp = f.getFilterFunctionParameter(QString::fromStdString(key));
					RichParameterList::iterator it = rps.findParameter(ffp.meshlabName());
					if (it != rps.end()){
						updateRichParameterFromKwarg(*it, md, ffp, p);
					}
					//else: it happens only for save flags parameters,
					//because these parameters are managed at pymeshlab level
					//but not at meshlab level (e.g. no param in the RichParameterList)
				}
				else {
					std::cerr << "Warning: parameter " << key << " not found\n";
					//pybind has no bind for python runtime warnings.
				}
			}
		}
	}
}

/** Filter name management **/

FilterPluginInterface* pluginFromFilterName(
		const QString& filterName, 
		QAction*& action)
{
	PluginManager& pm = MeshLabSingletons::pluginManagerInstance();
	for (FilterPluginInterface* fp : pm.meshFilterPlug){
		QList<QAction*> acts = fp->actions();
		for (QAction* act : acts) {
			if (filterName == fp->filterName(act)){
				action = act;
				return fp;
			}
		}
	}
	assert(0);
	//todo: manage python exception
	return nullptr;
}

bool pythonFilterNameExists(
		const std::string& filtername,
		const FilterFunctionSet& filterFunctionSet)
{
	FilterFunctionSet::iterator it = filterFunctionSet.find(QString::fromStdString(filtername));
	if (it != filterFunctionSet.end() && 
			!(QString::fromStdString(filtername).startsWith("load_") && 
			!(QString::fromStdString(filtername).startsWith("save_"))))
		return true;
	return false;
}

/** Load/Save Mesh **/

void afterLoadOperations(MeshModel& m, int mask)
{
	// In case of polygonal meshes the normal should be updated accordingly
	if( mask & vcg::tri::io::Mask::IOM_BITPOLYGONAL)
	{
		m.updateDataMask(MeshModel::MM_POLYGONAL); // just to be sure. Hopefully it should be done in the plugin...
		int degNum = vcg::tri::Clean<CMeshO>::RemoveDegenerateFace(m.cm);
		if(degNum)
			std::cerr << "Warning: mesh contains " << degNum << " degenerate faces. Removed them.";
		m.updateDataMask(MeshModel::MM_FACEFACETOPO);
		vcg::tri::UpdateNormal<CMeshO>::PerBitQuadFaceNormalized(m.cm);
		vcg::tri::UpdateNormal<CMeshO>::PerVertexFromCurrentFaceNormal(m.cm);
	} // standard case
	else
	{
		vcg::tri::UpdateNormal<CMeshO>::PerFaceNormalized(m.cm);
		if(!( mask & vcg::tri::io::Mask::IOM_VERTNORMAL) )
			vcg::tri::UpdateNormal<CMeshO>::PerVertexAngleWeighted(m.cm);
	}
	
	vcg::tri::UpdateBounding<CMeshO>::Box(m.cm);					// updates bounding box
	if(m.cm.fn==0 && m.cm.en==0) {
		if(mask & vcg::tri::io::Mask::IOM_VERTNORMAL)
			m.updateDataMask(MeshModel::MM_VERTNORMAL);
	}
	
	if(m.cm.fn==0 && m.cm.en>0) {
		if (mask & vcg::tri::io::Mask::IOM_VERTNORMAL)
			m.updateDataMask(MeshModel::MM_VERTNORMAL);
	}
	
	int delVertNum = vcg::tri::Clean<CMeshO>::RemoveDegenerateVertex(m.cm);
	int delFaceNum = vcg::tri::Clean<CMeshO>::RemoveDegenerateFace(m.cm);
	vcg::tri::Allocator<CMeshO>::CompactEveryVector(m.cm);
	if(delVertNum>0 || delFaceNum>0 )
		std::cerr << "Warning: mesh contains " << delVertNum << " vertices with NAN coords and "
				<< delFaceNum << " degenerated faces. Corrected.";
}

void loadMeshUsingPlugin(
		const std::string& filename,
		MeshModel* mm,
		MeshDocument& md)
{
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();

	if (!finfo.exists()){
		throw MLException("File does not exists: " + QString::fromStdString(filename));
	}
	else {
		PluginManager& pm = MeshLabSingletons::pluginManagerInstance();
		if (pm.allKnowInputMeshFormats.contains(extension)){
			IOMeshPluginInterface* plugin = pm.allKnowInputMeshFormats[extension];
			
			bool justCreated = false;
			if (mm == nullptr){
				mm = md.addNewMesh(finfo.filePath(), finfo.fileName());
				justCreated = true;
			}
			else {
				mm->setFileName(finfo.filePath());
				mm->setLabel(finfo.fileName());
			}
			
			RichParameterList rps;
			plugin->initPreOpenParameter(extension, QString::fromStdString(filename), rps);
			plugin->initOpenParameter(extension, *mm, rps);

			int mask = 0;
			bool ok = plugin->open(extension, QString::fromStdString(filename), *mm, mask, rps);
			if (!ok) {
				if (justCreated)
					md.delMesh(md.mm());
				throw MLException("Unable to open file: " + QString::fromStdString(filename));
			}
			else {
				afterLoadOperations(*mm, mask);
			}
		}
		else {
			throw MLException("Unknown format for load: " + extension);
		}
	}
}

void loadMeshUsingPlugin(
		const std::string& filename, 
		MeshModel* mm, 
		pybind11::kwargs kwargs,
		MeshDocument& md,
		const FilterFunctionSet& filterFunctionSet)
{
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();

	if (!finfo.exists()){
		throw MLException("File does not exists: " + QString::fromStdString(filename));
	}
	else {
		PluginManager& pm = MeshLabSingletons::pluginManagerInstance();
		if (pm.allKnowInputMeshFormats.contains(extension)){
			auto it = filterFunctionSet.find("load_" + extension);
			if (it == filterFunctionSet.end()){
				throw MLException("Unknown format to load in MeshSet. This should never happen.\nPlease open an issue on GitHub!");
			}
			FilterFunction ff = *it;
			IOMeshPluginInterface* plugin = pm.allKnowInputMeshFormats[extension];
			
			bool justCreated = false;
			if (mm == nullptr){
				mm = md.addNewMesh(finfo.filePath(), finfo.fileName());
				justCreated = true;
			}
			else {
				mm->setFileName(finfo.filePath());
				mm->setLabel(finfo.fileName());
			}
			
			RichParameterList rps;
			plugin->initPreOpenParameter(extension, QString::fromStdString(filename), rps);
			plugin->initOpenParameter(extension, *mm, rps);

			meshsethelper::updateRichParameterListFromKwargs(ff, kwargs, &md, rps, true);

			int mask = 0;
			bool ok = plugin->open(extension, QString::fromStdString(filename), *mm, mask, rps);
			if (!ok) {
				if (justCreated)
					md.delMesh(md.mm());
				throw MLException("Unable to open file: " + QString::fromStdString(filename));
			}
			else {
				afterLoadOperations(*mm, mask);
			}
		}
		else {
			throw MLException("Unknown format for load: " + extension);
		}
	}
}

void loadRasterUsingPlugin(
		const std::string& filename, 
		RasterModel* rm,
		MeshDocument& md)
{
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();

	if (!finfo.exists()){
		throw MLException("File does not exists: " + QString::fromStdString(filename));
	}
	else {
		PluginManager& pm = MeshLabSingletons::pluginManagerInstance();
		if (pm.allKnownInputRasterFormats.contains(extension)){
			IORasterPluginInterface* plugin = pm.allKnownInputRasterFormats[extension];
			
			bool justCreated = false;
			if (rm == nullptr){
				rm = md.addNewRaster();
				justCreated = true;
			}
			else {
				rm->setLabel(finfo.fileName());
			}
			
			bool ok = plugin->open(extension, QString::fromStdString(filename), *rm);
			if (!ok) {
				if (justCreated)
					md.delRaster(md.rm());
				throw MLException("Unable to open file: " + QString::fromStdString(filename));
			}
		}
		else {
			throw MLException("Unknown format for load: " + extension);
		}
	}
}

int currentMeshIOCapabilityMask(const MeshModel* mm)
{
	int capability = 0;
	for (int bit : capabilitiesBits){
		if (mm->hasDataMask(MeshModel::io2mm(bit)))
			capability |= bit;
	}

	return capability;
}

int computeSaveSettingsMaskFromKwargs(pybind11::kwargs kwargs, int startingMask, int capabilityMask)
{
	std::array<QString, 14> params;
	for (unsigned int i = 0; i < saveCapabilitiesStrings.size(); ++i)
		params[i] = FilterFunctionSet::toPythonName(saveCapabilitiesStrings[i]);

	int capability = startingMask;
	for (std::pair<py::handle, py::handle> p : kwargs){
		std::string par = py::cast<std::string>(p.first);
		auto it = std::find(params.begin(), params.end(), QString::fromStdString(par));
		if (it != params.end()) {
			//get the value p.second and set the right mask to capability
			unsigned int i = it - params.begin();
			bool value = py::cast<bool>(p.second);
			if (value && (capabilitiesBits[i] & capabilityMask))
				capability |= capabilitiesBits[i];
			else
				capability &= ~capabilitiesBits[i];
		}
	}

	return capability;
}

void saveMeshUsingPlugin(
		const std::string& filename,
		MeshModel* mm)
{
	if (mm == nullptr)
		throw MLException("Input model is nullptr. This should never happen.\nPlease open an issue on GitHub!");
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();
	PluginManager& pm = MeshLabSingletons::pluginManagerInstance();
	if (pm.allKnowOutputFormats.contains(extension)){
		IOMeshPluginInterface* plugin = pm.allKnowOutputFormats[extension];
		RichParameterList rps;
		int capability = 0, defbits = 0, capabilityMesh;
		plugin->GetExportMaskCapability(extension, capability, defbits);
		plugin->initSaveParameter(extension, *mm, rps);

		capabilityMesh = currentMeshIOCapabilityMask(mm);
		bool ok = plugin->save(
					extension, QString::fromStdString(filename), *mm,
					capabilityMesh & defbits, rps);
		if (!ok){
			throw MLException("Unable to save file: " + QString::fromStdString(filename));
		}
	}
	else {
		throw MLException("Unknown format for save: " + extension);
	}
}

void saveMeshUsingPlugin(
		const std::string& filename,
		MeshModel* mm,
		pybind11::kwargs kwargs,
		MeshDocument& md,
		const FilterFunctionSet& filterFunctionSet)
{
	if (mm == nullptr)
		throw MLException("Input model is nullptr. This should never happen.\nPlease open an issue on GitHub!");
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();
	PluginManager& pm = MeshLabSingletons::pluginManagerInstance();
	if (pm.allKnowOutputFormats.contains(extension)){
		FilterFunction ff = *filterFunctionSet.find("save_" + extension);
		IOMeshPluginInterface* plugin = pm.allKnowOutputFormats[extension];
		//int mask = 0; //todo: use this mask
		RichParameterList rps;

		//masks
		int capabilityFormat = 0;    //what can be saved in the given format
		int defaultSaveSettings = 0; //what is suggested to be saved in the given format
		int capabilityMesh = 0;      //what can be saved of the current mesh
		int userSettings = 0;        //what the user wants to be saved
		
		plugin->GetExportMaskCapability(extension, capabilityFormat, defaultSaveSettings);

		capabilityMesh = currentMeshIOCapabilityMask(mm);

		plugin->initSaveParameter(extension, *mm, rps);
		meshsethelper::updateRichParameterListFromKwargs(ff, kwargs, &md, rps, true);

		capabilityMesh = capabilityMesh & capabilityFormat;
		defaultSaveSettings &= capabilityMesh;

		userSettings = computeSaveSettingsMaskFromKwargs(kwargs, defaultSaveSettings, capabilityMesh);

		bool ok = plugin->save(
					extension, QString::fromStdString(filename), *mm,
					userSettings, rps);
		if (!ok){
			throw MLException("Unable to save file: " + QString::fromStdString(filename));
		}
	}
	else {
		throw MLException("Unknown format for save: " + extension);
	}
}

/** Load/Save Project **/

void loadALN(
		const QString& fileName,
		MeshDocument& md)
{
	QFileInfo fi(fileName);
	QString absfilename = fi.absolutePath() + "/" + fi.fileName();
	QDir currentDir = QDir::current();
	// this change of dir is needed for subsequent textures/materials loading
	QDir::setCurrent(fi.absoluteDir().absolutePath());

	std::vector<RangeMap> rmv;
	int retVal = ALNParser::ParseALN(rmv, qUtf8Printable(absfilename));
	if(retVal != ALNParser::NoError) {
		throw MLException("Error: Unable to open ALN file: " + absfilename);
	}

	bool openRes=true;
	std::vector<RangeMap>::iterator ir;
	for(ir=rmv.begin();ir!=rmv.end() && openRes;++ir) {
		QString relativeToProj = fi.absoluteDir().absolutePath() + "/" + (*ir).filename.c_str();
		loadMeshUsingPlugin(relativeToProj.toStdString(), nullptr, md);
		md.mm()->cm.Tr = ir->transformation;
	}

	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void loadMLP(
		const QString& fileName,
		MeshDocument& md)
{
	QFileInfo fi(fileName);
	QString absfilename = fi.absolutePath() + "/" + fi.fileName();
	QDir currentDir = QDir::current();
	// this change of dir is needed for subsequent textures/materials loading
	QDir::setCurrent(fi.absolutePath());

	std::map<int, MLRenderingData> rendOpt;
	int startingIndex = md.meshList.size();
	if (!MeshDocumentFromXML(md, absfilename, (QString(fi.suffix()).toLower() == "mlb"), rendOpt)) {
		throw MLException("Error:  Unable to open MeshLab Project file: " + absfilename);
	}
	for (int i=startingIndex; i<md.meshList.size(); i++) {
		QString fullPath = md.meshList[i]->fullName();
		Matrix44m trm = md.meshList[i]->cm.Tr;
		meshsethelper::loadMeshUsingPlugin(fullPath.toStdString(), md.meshList[i], md);
		md.mm()->cm.Tr = trm;
	}

	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void loadBundler(
		const QString& fileName,
		MeshDocument& md)
{
	QFileInfo fi(fileName);
	QString cameras_filename = fi.absolutePath() + "/" + fi.fileName();
	QString image_list_filename = fi.absolutePath() + "/list.txt";
	QString model_filename;

	QDir currentDir = QDir::current();
	// this change of dir is needed for subsequent textures/materials loading
	QDir::setCurrent(fi.absolutePath());

	if(!MeshDocumentFromBundler(md, cameras_filename, image_list_filename, model_filename)){
		throw MLException("Error:  Unable to open OUTs file: " + cameras_filename);
	}

	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void loadNVM(
		const QString& fileName,
		MeshDocument& md)
{
	QFileInfo fi(fileName);
	QString cameras_filename = fi.absolutePath() + "/" + fi.fileName();
	QString image_list_filename = fi.absolutePath() + "/list.txt";
	QString model_filename;

	QDir currentDir = QDir::current();
	// this change of dir is needed for subsequent textures/materials loading
	QDir::setCurrent(fi.absolutePath());

	if(!MeshDocumentFromNvm(md, cameras_filename, model_filename)){
		throw MLException("Error:  Unable to open NVMs file: " + cameras_filename);
	}

	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void saveMLP(
		const QString& fileName,
		MeshDocument& md)
{
	QFileInfo fi(fileName);
	QString outdir = fi.absolutePath();
	QString absfilename = outdir + "/" + fi.fileName();
	QDir currentDir = QDir::current();
	// this change of dir is needed for subsequent textures/materials loading
	QDir::setCurrent(fi.absolutePath());

	for(MeshModel* m : md.meshList) {
		if (m != NULL) {
			QString label = m->label().remove(" ");
			int p = label.lastIndexOf('.');
			if (p > 0)
				label = label.left(p);
			QString outfilename = outdir + "/" + label.remove(" ") + ".ply";
			m->setFileName(outfilename);
			QFileInfo of(outfilename);
			m->setLabel(of.fileName());
			meshsethelper::saveMeshUsingPlugin(outfilename.toStdString(), m);
		}
	}

	bool ok = MeshDocumentToXMLFile(md, fileName, false, false, fi.suffix().toLower() == "mlb");
	if (!ok){
		throw MLException("Error:  Unable to save MeshLab Project file: " + absfilename);
	}
	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

/** OpenGL context **/

void initOpenGLContext(QAction* action, FilterPluginInterface* fp, QGLWidget*& wid, MeshSet& ms)
{
	if (fp->glContext == nullptr){
		ms.initSceneGLSharedDataContext();
		ms.makeSceneGLCurrent();
		GLExtensionsManager::initializeGLextensions();
		ms.doneSceneGLCurrent();
		wid = new QGLWidget(nullptr, ms.sharedDataContext());
		fp->glContext = new MLPluginGLContext(QGLFormat::defaultFormat(), wid->context()->device(),*ms.sharedDataContext());
		bool created = fp->glContext->create(wid->context());
		if ((!created) || (!fp->glContext->isValid())) {
			throw MLException("A valid GLContext is required by the filter to work.\n");
		}
		MLRenderingData dt;
		MLRenderingData::RendAtts atts;
		atts[MLRenderingData::ATT_NAMES::ATT_VERTPOSITION] = true;
		atts[MLRenderingData::ATT_NAMES::ATT_VERTNORMAL] = true;

		if (fp->filterArity(action) == FilterPluginInterface::SINGLE_MESH) {
			MLRenderingData::PRIMITIVE_MODALITY pm = MLPoliciesStandAloneFunctions::bestPrimitiveModalityAccordingToMesh(ms.mm());
			if ((pm != MLRenderingData::PR_ARITY) && (ms.mm() != nullptr)) {
				dt.set(pm, atts);
				fp->glContext->initPerViewRenderingData(ms.mm()->id(), dt);
			}

			if (ms.mm() != NULL) {
				ms.mm()->cm.svn = int(vcg::tri::UpdateSelection<CMeshO>::VertexCount(ms.mm()->cm));
				ms.mm()->cm.sfn = int(vcg::tri::UpdateSelection<CMeshO>::FaceCount(ms.mm()->cm));
			}
		}
		else {
			for (int ii = 0; ii < ms.meshList.size(); ++ii) {
				MeshModel* mm = ms.meshList[ii];
				MLRenderingData::PRIMITIVE_MODALITY pm = MLPoliciesStandAloneFunctions::bestPrimitiveModalityAccordingToMesh(mm);
				if ((pm != MLRenderingData::PR_ARITY) && (mm != nullptr)) {
					dt.set(pm, atts);
					fp->glContext->initPerViewRenderingData(mm->id(), dt);
				}

				if (mm != nullptr) {
					mm->cm.svn = int(vcg::tri::UpdateSelection<CMeshO>::VertexCount(mm->cm));
					mm->cm.sfn = int(vcg::tri::UpdateSelection<CMeshO>::FaceCount(mm->cm));
				}
			}
		}
	}
}

void releaseOpenGLContext(FilterPluginInterface* fp, QGLWidget*& wid)
{
	delete fp->glContext;
	fp->glContext = nullptr;
	delete wid;
	wid = nullptr;
}

/** Apply Filter **/

pybind11::dict applyFilterRPL(
		const std::string& filtername, 
		const QString& meshlabFilterName, 
		QAction* action, 
		FilterPluginInterface* fp, 
		const RichParameterList& rpl, 
		bool verbose, 
		FilterScript& filterScript,
		bool updateFilterScript,
		MeshSet& md)
{
	py::dict outputDict;
	QGLWidget* wid = nullptr;
	if (!verbose){
		VerbosityManager::disableVersbosity();
		VerbosityManager::staticLogger = nullptr;
	}
	else {
		VerbosityManager::staticLogger = &md.Log;
	}
	try {
		int req=fp->getRequirements(action);
		if (fp->requiresGLContext(action)){
			initOpenGLContext(action, fp, wid, md);
		}
		if (md.mm() != nullptr)
			md.mm()->updateDataMask(req);
		
		md.meshDocStateData().clear();
		md.meshDocStateData().create(md);
		unsigned int postConditionMask = MeshModel::MM_UNKNOWN;
		std::map<std::string, QVariant> outputValues;
		bool res = fp->applyFilter(action, md, outputValues, postConditionMask, rpl, &VerbosityManager::filterCallBack);
		if (res){
			VerbosityManager::filterCallBack(100, (filtername + " applied!").c_str());
			if (md.mm() != nullptr) {
				md.mm()->cm.svn = int(vcg::tri::UpdateSelection<CMeshO>::VertexCount(md.mm()->cm));
				md.mm()->cm.sfn = int(vcg::tri::UpdateSelection<CMeshO>::FaceCount(md.mm()->cm));
			}
			if (updateFilterScript) {
				FilterNameParameterValuesPair pair;
				pair.first = meshlabFilterName; pair.second = rpl;
				filterScript.append(pair);
			}
			outputDict = toPyDict(outputValues);
		}
		else {
			throw MLException(fp->errorMsg());
		}
		if (fp->requiresGLContext(action)){
			releaseOpenGLContext(fp, wid);
		}
	}
	catch(const std::exception& e) {
		if (wid != nullptr){
			releaseOpenGLContext(fp, wid);
		}
		throw MLException(
					"Failed to apply filter: " + QString::fromStdString(filtername) + "\n" +
					"Details: " + e.what());
	}
	VerbosityManager::enableVerbosity();
	return outputDict;
}

/** RST documentation **/

void endLineHTMLSubstitution(QString& htmlString)
{
	htmlString.replace("\n", "<br>");
}

std::string filterRSTDocumentation(
		FilterFunctionSet::iterator it,
		bool loadSave)
{
	std::string doc;

	doc += ".. data:: ";
	if (!loadSave) {
		doc += it->pythonFunctionName().toStdString() + "\n\n";
		doc += "   *MeshLab filter name*: '" + it->meshlabFunctionName().toStdString() + "'\n\n";
	}
	else {
		doc += it->meshlabFunctionName().toStdString() + "\n   :noindex:\n\n";
	}
	doc += "   .. raw:: html\n\n";
	QString desc = it->description();
	meshsethelper::endLineHTMLSubstitution(desc);
	doc += "      " + desc.toStdString() + "</p>\n\n";

	if (it->parametersNumber() > 0) {

		doc += "   **Parameters:**\n\n";

		for (const FilterFunctionParameter& p : *it){

			if (! p.defaultValue().isEnum()){
				doc += "   ``" + p.pythonName().toStdString() + " : " +
						p.pythonTypeString().toStdString() +
						" = " + p.defaultValueString().toStdString() + "``\n\n";
			}
			else {
				doc += "   ``" + p.pythonName().toStdString() + " : " +
						p.pythonTypeString().toStdString() +
						" = " + p.defaultValueString().toStdString() +
						" (or int = " + std::to_string(p.defaultValue().getEnum()) +
						")``\n\n";
				doc += "      Possible enum values:\n\n";

				const RichEnum& ren = dynamic_cast<const RichEnum&>(p.richParameter());
				unsigned int i = 0;
				for (const QString& v : ren.enumvalues){
					doc += "         " + std::to_string(i++) +". ``'" + v.toStdString() +
							"'``\n";
				}
				doc +="\n";
			}

			doc += "      .. raw:: html\n\n";
			QString desc = p.longDescription();
			meshsethelper::endLineHTMLSubstitution(desc);
			doc += "         <i>" + p.description().toStdString() + "</i>: " +
					desc.toStdString() + "\n\n";
		}

	}

	return doc;
}

std::string RSTDocumentationFromFilterFunctionSet(const FilterFunctionSet& filterFunctionSet)
{
	std::string doc;

	doc += ".. _filter_list:\n\nList of Filters\n===============\n\n";

	doc +=
			"Here are listed all the filter names that can be given as paramter "
			"to the function :py:meth:`pmeshlab.MeshSet.apply_filter`.\n\n"
			
			"Each filter accepts a list of parameters, that can be semantically classified as follows:\n\n"
			
			"   * `Boolean`: a classic ``bool`` value;\n"
			"   * `Integer`: a classic ``int`` value;\n"
			"   * `String`: a classic ``str`` value;\n"
			"   * `Float`: a classic ``float`` value;\n"
			"   * `Bounded Float`: a classic ``float`` that is expected to be bounded between a ``min`` and a ``max`` value; an out-of-bounds value will raise an exception;\n"
			"   * `Percentage`: represents a parameter that is relative to some other measure, specified in the documentation of the filter. This parameter can be of two different types:\n\n"
			
			"     * :py:class:`pmeshlab.Percentage` (recommended): the parameter will be treated as relative percentage value; see the documentation of the :py:class:`pmeshlab.Percentage` for further info;\n"
			"     * ``float`` (not recommended): the parameter will be treated as absolute value;\n\n"
			
			"   * `Enum`: represents a parameter that can accept just one of a limited set of possible values. These values type can be ``int`` or ``str``; see the documentation of the specific filter for further info;\n"
			"   * `Color`: represents a color, and the parameter can be of type  :py:class:`pmeshlab.Color`; see the documentation of the  :py:class:`pmeshlab.Color` for further info;\n"
			"   * `3D Point (or 3D Vector)`: represents a 3D point or vector, and the parameter can be of type ``numpy.ndarray[numpy.float64[3]]`` (a numpy array containing three floats);\n"
			"   * `4x4 Matrix`: represents a 4x4 Matrix of floats, and the parameter can be of type ``numpy.ndarray[numpy.float64[4, 4]]`` (a 4x4 numpy array of floats);\n"
			"   * `Mesh`: represents a parameter that links to one of the meshes contained in the MeshSet on which the filter is applied. This parameter is of type ``int``, which indicates the ``id`` of the mesh in the MeshSet;\n"
			"   * `File Name`: a classic ``str`` that represents the path of a file that is going to be saved or loaded by the filter. The string is expected to have at least an extension on its final characters; see the documentation of the specific filter for further info;\n"
			"   * `Camera`: *still not supported*;\n\n"
			
			"**Please note**: some filter parameters depend on the mesh(es) used as "
			"input of the filter. Default values listed here are computed on a 1x1x1 cube "
			"(pymeshlab/tests/sample/cube.obj), but their value will be computed on the input mesh "
			"if they are left as default.\n\n"
			"apply_filter parameters\n-----------------------\n\n";

	/// apply_filter parameters
	for (auto it = filterFunctionSet.begin(); it != filterFunctionSet.end(); ++it) {
		if (!(it->pythonFunctionName().startsWith("load_")) && 
				!(it->pythonFunctionName().startsWith("save_")) &&
				!(it->pythonFunctionName().startsWith("loadr_")))
			doc += filterRSTDocumentation(it, false);
	}

	//load parameters
	doc += 
			"load parameters\n---------------\n\n"
			"Here are listed all the file formats that can be loaded using"
			"the functions :py:meth:`pmeshlab.MeshSet.load_new_mesh` and "
			":py:meth:`pmeshlab.MeshSet.load_current_mesh`, with all the possible "
			"parameters that can be accepted by these functions.\n\n";

	for (auto it = filterFunctionSet.begin(); it != filterFunctionSet.end(); ++it) {
		if (it->pythonFunctionName().startsWith("load_"))
			doc += filterRSTDocumentation(it, true);
	}

	//save parameters
	doc += 
			"save parameters\n---------------\n\n"
			"Here are listed all the file formats that can be saved using"
			"the function :py:meth:`pmeshlab.MeshSet.save_current_mesh`, "
			"with all the possible parameters that can be accepted by these "
			"functions.\n\n";

	for (auto it = filterFunctionSet.begin(); it != filterFunctionSet.end(); ++it) {
		if (it->pythonFunctionName().startsWith("save_"))
			doc += filterRSTDocumentation(it, true);
	}
	
	//load raster parameters
	
	doc +=
			"load raster parameters\n----------------------\n\n"
			"Here are listed all the raster file formats that can be loaded using"
			"the functions :py:meth:`pmeshlab.MeshSet.load_new_raster`.\n\n";
	
	for (auto it = filterFunctionSet.begin(); it != filterFunctionSet.end(); ++it) {
		if (it->pythonFunctionName().startsWith("loadr_"))
			doc += filterRSTDocumentation(it, true);
	}

	return doc;
}

}
}


