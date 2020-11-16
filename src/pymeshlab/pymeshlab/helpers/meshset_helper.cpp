#include <pybind11/pybind11.h> //needs to be included before anything else
#include "meshset_helper.h"

#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <common/filter_parameter/rich_parameter_list.h>
#include <common/mlexception.h>
#include <common/meshlabdocumentxml.h>
#include <common/meshlabdocumentbundler.h>
#include <wrap/io_trimesh/alnParser.h>

#include "common.h"
#include "meshlab_singletons.h"
#include "verbosity_manager.h"
#include "../plugin_management/filterfunctionset.h"
#include "../percentage.h"
#include "../exceptions.h"

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
		Eigen::Matrix4f arr = py::cast<Eigen::Matrix4f>(k.second);
		if (arr.size() != 16){
			throw MLException(
					"Parameter " + ffp.pythonName() + ": invalid array. Expected a "
					"numpy float32 array of 4x4 elements.");
		}
		else {
			vcg::Matrix44f m;
			float* v = m.V();
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
		if (pm.allKnowInputFormats.contains(extension)){
			auto it = filterFunctionSet.find("load_" + extension);
			if (it == filterFunctionSet.end()){
				throw MLException("Unknown format to load in MeshSet. This should never happen.\nPlease open an issue on GitHub!");
			}
			FilterFunction ff = *it;
			IOPluginInterface* plugin = pm.allKnowInputFormats[extension];
			
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

int capabilityMaskFromKwargs(pybind11::kwargs kwargs, int startingMask)
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
			if (value)
				capability &= capabilitiesBits[i];
			else
				capability &= ~capabilitiesBits[i];
		}
	}

	return capability;
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
		IOPluginInterface* plugin = pm.allKnowOutputFormats[extension];
		//int mask = 0; //todo: use this mask
		RichParameterList rps;
		int capability = 0, defbits = 0, capabilityMesh = 0, capabilityUser = 0;
		plugin->GetExportMaskCapability(extension,capability,defbits);
		plugin->initSaveParameter(extension, *mm, rps);

		meshsethelper::updateRichParameterListFromKwargs(ff, kwargs, &md, rps, true);

		capabilityMesh = currentMeshIOCapabilityMask(mm);
		capabilityUser = capabilityMaskFromKwargs(kwargs, capability & capabilityMesh);

		bool ok = plugin->save(
					extension, QString::fromStdString(filename), *mm,
					capabilityUser, rps);
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
		MeshDocument& md,
		const FilterFunctionSet& filterFunctionSet)
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
		loadMeshUsingPlugin(relativeToProj.toStdString(), nullptr, py::kwargs(), md, filterFunctionSet);
		md.mm()->cm.Tr = ir->transformation;
	}

	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void loadMLP(
		const QString& fileName,
		MeshDocument& md, 
		const FilterFunctionSet& filterFunctionSet)
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
		meshsethelper::loadMeshUsingPlugin(fullPath.toStdString(), md.meshList[i], pybind11::kwargs(), md, filterFunctionSet);
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
		MeshDocument& md, 
		const FilterFunctionSet& filterFunctionSet)
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
			meshsethelper::saveMeshUsingPlugin(outfilename.toStdString(), m, py::kwargs(), md, filterFunctionSet);
		}
	}

	bool ok = MeshDocumentToXMLFile(md, fileName, false, false, fi.suffix().toLower() == "mlb");
	if (!ok){
		throw MLException("Error:  Unable to save MeshLab Project file: " + absfilename);
	}
	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
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
		MeshDocument& md)
{
	py::dict outputDict;
	if (!verbose){
		VerbosityManager::disableVersbosity();
		VerbosityManager::staticLogger = nullptr;
	}
	else {
		VerbosityManager::staticLogger = &md.Log;
	}
	try {
		int req=fp->getRequirements(action);
		if (md.mm() != nullptr)
			md.mm()->updateDataMask(req);
		
		unsigned int postConditionMask;
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
			throw MLException(
						"Failed to apply filter: " + QString::fromStdString(filtername) + "\n");
		}
	}
	catch(const std::exception& e) {
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

		doc += "   **Parameters:** \n\n";

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

	/// apply_filter parameters
	doc +=
			"apply_filter parameters\n-----------------------\n\n"
			"Here are listed all the filter names that can be given as paramter "
			"to the function :py:meth:`pmeshlab.MeshSet.apply_filter`.\n\n"
			"Please note: some filter parameters depend on the mesh(es) used as "
			"input of the filter. Default values listed here are computed on a 1x1x1 cube "
			"(pymeshlab/tests/sample/cube.obj), and they will be computed on the input mesh "
			"if they are left as default.\n\n";

	for (auto it = filterFunctionSet.begin(); it != filterFunctionSet.end(); ++it) {
		if (!(it->pythonFunctionName().startsWith("load")) && !(it->pythonFunctionName().startsWith("save")))
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
		if (it->pythonFunctionName().startsWith("load"))
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
		if (it->pythonFunctionName().startsWith("save"))
			doc += filterRSTDocumentation(it, true);
	}

	return doc;
}



}
}


