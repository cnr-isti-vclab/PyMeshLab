/****************************************************************************
* PyMeshLab                                                         o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005-2021                                           \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
#include <pybind11/pybind11.h> //needs to be included before anything else
#include "meshset_helper.h"

#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <common/parameters/rich_parameter_list.h>
#include <common/mlexception.h>
#include <common/globals.h>
#include <common/GLExtensionsManager.h>
#include <common/utilities/load_save.h>
#include <common/python/function_set.h>
#include <common/python/python_utils.h>
#include <wrap/io_trimesh/alnParser.h>

#include <QApplication>
#include <QDir>

#include "common.h"
#include "verbosity_manager.h"
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
		const FunctionParameter& ffp,
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

		abs.setValue(FloatValue(absvalue));
	}
	else if (meshlabType == MESHLAB_TYPE_COLOR) {
		par.setValue(ColorValue(py::cast<QColor>(k.second)));
	}
	else if (meshlabType == MESHLAB_TYPE_DYNAMIC_FLOAT) {
		RichDynamicFloat& dyn = dynamic_cast<RichDynamicFloat&>(par);
		float val = py::cast<float>(k.second);
		if (val >= dyn.min && val <= dyn.max)
			dyn.setValue(FloatValue(val));
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
		en.setValue(IntValue(value));
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
		rm.setValue(IntValue(py::cast<int>(k.second)));
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

pybind11::dict pydictFromRichParameterList( 
		const RichParameterList& rps)
{
	pybind11::dict kw;
	for (const RichParameter& par : rps){
		std::string pname = computePythonName(par.name()).toStdString();
		const Value& v = par.value();
		if (par.isOfType<RichBool>())
			kw[pname.c_str()] = v.getBool();
		if (par.isOfType<RichInt>())
			kw[pname.c_str()] = v.getInt();
		if (par.isOfType<RichFloat>())
			kw[pname.c_str()] = v.getFloat();
		if (par.isOfType<RichString>())
			kw[pname.c_str()] = v.getString().toStdString();
		if (par.isOfType<RichEnum>())
			kw[pname.c_str()] = v.getInt();
		if (par.isOfType<RichAbsPerc>())
			kw[pname.c_str()] = v.getFloat();
		if (par.isOfType<RichDynamicFloat>())
			kw[pname.c_str()] = v.getFloat();
		if (par.isOfType<RichMatrix44f>())
			kw[pname.c_str()] = v.getMatrix44f().ToEigenMatrix<Eigen::Matrix4d>();
		if (par.isOfType<RichPoint3f>())
			kw[pname.c_str()] = v.getPoint3f().ToEigenVector<Eigen::Vector3d>();
		if (par.isOfType<RichShotf>())
			kw[pname.c_str()] = "still_unsupported";
		if (par.isOfType<RichColor>())
			kw[pname.c_str()] = v.getColor();
		if (par.isOfType<RichMesh>())
			kw[pname.c_str()] = v.getInt();
		if (par.isOfType<RichOpenFile>() || par.isOfType<RichSaveFile>())
			kw[pname.c_str()] = v.getString().toStdString();
	}
	return kw;
}

void updateRichParameterListFromKwargs(
		const Function& f,
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
					const FunctionParameter& ffp = f.getFilterFunctionParameter(QString::fromStdString(key));
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

/** QVariant map management **/

pybind11::dict toPyDict(const std::map<std::string, QVariant>& qVariantMap)
{
	pybind11::dict outDict;
	for (const auto& p : qVariantMap){
		if (std::string(p.second.typeName()) == "int"){
			outDict[p.first.c_str()] = p.second.toInt();
		}
		else if (std::string(p.second.typeName()) == "double"){
			outDict[p.first.c_str()] = p.second.toDouble();
		}
		else if (std::string(p.second.typeName()) == "float"){
			outDict[p.first.c_str()] = p.second.toFloat();
		}
		else if (std::string(p.second.typeName()) == "bool"){
			outDict[p.first.c_str()] = p.second.toBool();
		}
		else if (p.second.canConvert<Point2m>()){
			outDict[p.first.c_str()] = 
					p.second.value<Point2m>().ToEigenVector<Eigen::Vector2d>();
		}
		else if (p.second.canConvert<Point3m>()){
			outDict[p.first.c_str()] = 
					p.second.value<Point3m>().ToEigenVector<Eigen::Vector3d>();
		}
		else if (p.second.canConvert<Box3m>()){
			outDict[p.first.c_str()] = p.second.value<Box3m>();
		}
		else if (p.second.canConvert<Matrix33m>()){
			outDict[p.first.c_str()] = 
					p.second.value<Matrix33m>().ToEigenMatrix<Eigen::Matrix3d>();
		}
		else if (p.second.canConvert<Matrix44m>()){
			outDict[p.first.c_str()] = 
					p.second.value<Matrix44m>().ToEigenMatrix<Eigen::Matrix4d>();
		}
		else if (p.second.canConvert<Eigen::VectorXd>()){
			outDict[p.first.c_str()] = p.second.value<Eigen::VectorXd>();
		}
		else {
			std::cerr << "Warning: type " << p.second.typeName() 
				<< " still not supported for py::dict conversion\n"
				<< "Please open an issue on GitHub about this."; 
		}
	}
	return outDict;
}

/** Filter name management **/

FilterPlugin* pluginFromFilterName(
		const QString& filterName, 
		QAction*& action)
{
	PluginManager& pm = meshlab::pluginManagerInstance();
	for (FilterPlugin* fp : pm.filterPluginIterator()){
		for (QAction* act : fp->actions()) {
			if (filterName == fp->filterName(act)){
				action = act;
				return fp;
			}
		}
	}
	throw MLException("Something really bad happened.\nPlease report this issue on https://github.com/cnr-isti-vclab/PyMeshLab/issues");
	return nullptr;
}

bool pythonFilterNameExists(
		const std::string& filtername,
		const FunctionSet& filterFunctionSet)
{
	return filterFunctionSet.containsFilterFunction(QString::fromStdString(filtername));
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
	
	vcg::tri::UpdateBounding<CMeshO>::Box(m.cm); // updates bounding box
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
		pybind11::kwargs kwargs,
		MeshDocument& md,
		const FunctionSet& filterFunctionSet)
{
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();

	if (!finfo.exists()){
		throw MLException("File does not exists: " + QString::fromStdString(filename));
	}
	else {
		PluginManager& pm = meshlab::pluginManagerInstance();
		if (pm.isInputMeshFormatSupported(extension)){
			const Function& ff = filterFunctionSet.loadMeshFunction(extension);
			IOPlugin* plugin = pm.inputMeshPlugin(extension);
			
			RichParameterList rps = plugin->initPreOpenParameter(extension);
			meshsethelper::updateRichParameterListFromKwargs(ff, kwargs, &md, rps, true);
			try {
				meshlab::loadMeshWithStandardParameters(QString::fromStdString(filename), md, VerbosityManager::filterCallBack, rps);
			}
			catch (const MLException& e) {
				throw MLException("Unable to open file: " + QString::fromStdString(filename) + "\n" + e.what());
			}
		}
		else {
			throw MLException("Unknown format for load: " + extension);
		}
	}
}

void loadRasterUsingPlugin(
		const std::string& filename, 
		MeshDocument& md)
{
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();

	if (!finfo.exists()){
		throw MLException("File does not exists: " + QString::fromStdString(filename));
	}
	else {
		PluginManager& pm = meshlab::pluginManagerInstance();
		if (pm.isInputImageFormatSupported(extension)){
			RasterModel* rm = md.addNewRaster();

			try {
				meshlab::loadRaster(QString::fromStdString(filename), *rm, VerbosityManager::staticLogger, VerbosityManager::filterCallBack);
			}
			catch(const MLException& e){
				md.delRaster(md.rm()->id());
				throw MLException("Unable to open file: " + QString::fromStdString(filename) + "\n" + e.what());
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
		params[i] = computePythonName(saveCapabilitiesStrings[i]);

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
		MeshModel* mm,
		bool saveTextures,
		int qualityTextures,
		pybind11::kwargs kwargs,
		MeshDocument& md,
		const FunctionSet& filterFunctionSet)
{
	if (mm == nullptr)
		throw MLException("Input model is nullptr. This should never happen.\nPlease open an issue on GitHub!");
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();
	PluginManager& pm = meshlab::pluginManagerInstance();
	if (pm.isOutputMeshFormatSupported(extension)){
		const Function& ff = filterFunctionSet.saveMeshFunction(extension);
		IOPlugin* plugin = pm.outputMeshPlugin(extension);
		//int mask = 0; //todo: use this mask


		//masks
		int capabilityFormat = 0;    //what can be saved in the given format
		int defaultSaveSettings = 0; //what is suggested to be saved in the given format
		int capabilityMesh = 0;      //what can be saved of the current mesh
		int userSettings = 0;        //what the user wants to be saved
		
		plugin->exportMaskCapability(extension, capabilityFormat, defaultSaveSettings);

		capabilityMesh = currentMeshIOCapabilityMask(mm);

		RichParameterList rps= plugin->initSaveParameter(extension, *mm);
		meshsethelper::updateRichParameterListFromKwargs(ff, kwargs, &md, rps, true);

		capabilityMesh = capabilityMesh & capabilityFormat;
		defaultSaveSettings &= capabilityMesh;

		userSettings = computeSaveSettingsMaskFromKwargs(kwargs, defaultSaveSettings, capabilityMesh);

		if (userSettings & vcg::tri::io::Mask::IOM_BITPOLYGONAL)
			mm->updateDataMask(MeshModel::MM_FACEFACETOPO);
		plugin->save(
					extension, QString::fromStdString(filename), *mm,
					userSettings, rps, &VerbosityManager::filterCallBack);
		if (saveTextures)
			mm->saveTextures(finfo.absolutePath(), qualityTextures);
		mm->setFileName(finfo.absoluteFilePath());
	}
	else {
		throw MLException("Unknown format for save: " + extension);
	}
}

/** OpenGL context **/

class OpenGLContextData
{
public:
	OpenGLContextData(MeshSet& ms, int argc, char **argv) :
		app(argc, argv), 
		gpumeminfo((std::ptrdiff_t) (350 * (float)(1024 * 1024))),
		sceneGLSharedDataContext(ms, gpumeminfo, true, 100000,100000),
		wid(nullptr, &sceneGLSharedDataContext)
	{
		sceneGLSharedDataContext.makeCurrent();
		GLExtensionsManager::initializeGLextensions();
		sceneGLSharedDataContext.doneCurrent();
	}
	QApplication app;
	vcg::QtThreadSafeMemoryInfo gpumeminfo;
	MLSceneGLSharedDataContext sceneGLSharedDataContext;
	QGLWidget wid;
};

void initOpenGLContext(QAction* action, OpenGLContextData& data, FilterPlugin* fp, MeshSet& ms)
{
	if (fp->glContext == nullptr){
		fp->glContext = new MLPluginGLContext(QGLFormat::defaultFormat(), data.wid.context()->device(), data.sceneGLSharedDataContext);
		bool created = fp->glContext->create(data.wid.context());
		if ((!created) || (!fp->glContext->isValid())) {
			throw MLException("A valid GLContext is required by the filter to work.\n");
		}
		MLRenderingData dt;
		MLRenderingData::RendAtts atts;
		atts[MLRenderingData::ATT_NAMES::ATT_VERTPOSITION] = true;
		atts[MLRenderingData::ATT_NAMES::ATT_VERTNORMAL] = true;

		if (fp->filterArity(action) == FilterPlugin::SINGLE_MESH) {
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
			for (MeshModel& mm : ms.meshIterator()) {
				MLRenderingData::PRIMITIVE_MODALITY pm = MLPoliciesStandAloneFunctions::bestPrimitiveModalityAccordingToMesh(&mm);
				if (pm != MLRenderingData::PR_ARITY) {
					dt.set(pm, atts);
					fp->glContext->initPerViewRenderingData(mm.id(), dt);
				}

				mm.cm.svn = int(vcg::tri::UpdateSelection<CMeshO>::VertexCount(mm.cm));
				mm.cm.sfn = int(vcg::tri::UpdateSelection<CMeshO>::FaceCount(mm.cm));
			}
		}
	}
}

void releaseOpenGLContext(FilterPlugin* fp)
{
	delete fp->glContext;
	fp->glContext = nullptr;
}

/** Apply Filter **/

pybind11::dict applyFilterRPL(
		const std::string& filtername, 
		const QString& meshlabFilterName, 
		QAction* action, 
		FilterPlugin* fp, 
		const RichParameterList& rpl, 
		bool verbose, 
		FilterScript& filterScript,
		bool updateFilterScript,
		MeshSet& md)
{
	QStringList missingPreconditions;
	if (!fp->isFilterApplicable(action, *md.mm(), missingPreconditions)) {
		QString enstr = missingPreconditions.join(",");
		throw MLException(
			"Failed to apply filter:  '" + QString::fromStdString(filtername) + ". "
			"Current mesh does not have " + enstr + ".");
	}

	py::dict outputDict;
	OpenGLContextData* data = nullptr;
	if (!verbose){
		VerbosityManager::disableVersbosity();
		VerbosityManager::staticLogger = nullptr;
	}
	else {
		VerbosityManager::staticLogger = &md.Log;
		std::cout << "\nApplying filter " << filtername << " with the following parameters:\n";
		py::dict params = meshsethelper::pydictFromRichParameterList(rpl);
		py::print(params);
		std::cout << "\n";
	}
	try {
		int req=fp->getRequirements(action);
		if (fp->requiresGLContext(action)){
			int argc=1;
			char* argv[] = {(char*)"pymeshlab"};
			data = new OpenGLContextData(md, argc, argv);
			initOpenGLContext(action, *data, fp, md);
		}
		if (md.mm() != nullptr)
			md.mm()->updateDataMask(req);
		
		md.meshDocStateData().clear();
		md.meshDocStateData().create(md);
		md.setBusy(true);
		unsigned int postConditionMask = MeshModel::MM_UNKNOWN;
		std::map<std::string, QVariant> outputValues =
				fp->applyFilter(action, rpl, md, postConditionMask, &VerbosityManager::filterCallBack);
		for (MeshModel& mm : md.meshIterator()){
			vcg::tri::Allocator<CMeshO>::CompactEveryVector(mm.cm);
		}
		md.setBusy(false);
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
		if (fp->requiresGLContext(action)){
			releaseOpenGLContext(fp);
			delete data;
			data = nullptr;
		}
	}
	catch(const std::exception& e) {
		if (data != nullptr){
			releaseOpenGLContext(fp);
			delete data;
			data = nullptr;
		}
		throw MLException(
					"Failed to apply filter: " + QString::fromStdString(filtername) + "\n" +
					"Details: " + e.what());
	}
	VerbosityManager::enableVerbosity();
	return outputDict;
}

}
}


