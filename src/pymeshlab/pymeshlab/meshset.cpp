#include "meshset.h"
#include "percentage.h"

#include <mlexception.h>
#include <meshlabdocumentxml.h>
#include <meshlabdocumentbundler.h>
#include <wrap/io_trimesh/alnParser.h>
#include "common.h"

namespace py = pybind11;

GLLogStream* pymeshlab::MeshSet::staticLogger = nullptr;

pymeshlab::MeshSet::MeshSet(bool verbose) :
	MeshDocument(), globalRPS(), pm()
{
	QDir dir(QString::fromStdString(pymeshlab::getPluginsPath()));
	pymeshlab::QDebugRedirect* qdbr = nullptr;
	if (!verbose)
		qdbr = new pymeshlab::QDebugRedirect(); //redirect qdebug to null, just for this scope
	pm.loadPlugins(globalRPS, dir);
	filterFunctionSet.popolate(pm);
	setVerbosity(verbose);
	delete qdbr;
}

pymeshlab::MeshSet::~MeshSet()
{
}

void pymeshlab::MeshSet::setVerbosity(bool verbose)
{
	this->verbose = verbose;
	if (verbose){
		for (auto p : pm.ownerPlug)
			p->setLog(&Log);
	}
	else {
		for (auto p : pm.ownerPlug)
			p->setLog(nullptr);
	}
}

CMeshO& pymeshlab::MeshSet::currentMesh()
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no selected Mesh.");
	return mm()->cm;
}

int pymeshlab::MeshSet::currentMeshId() const
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no selected Mesh.");
	return mm()->id();
}

bool pymeshlab::MeshSet::meshIdExists(int id) const
{
	return getMesh(id) != nullptr;
}

CMeshO& pymeshlab::MeshSet::mesh(int id)
{
	MeshModel* tmp = getMesh(id);
	if (tmp == nullptr)
		throw MLException("Mesh ID " + QString::number(id) + " not found in MeshSet.");
	return tmp->cm;
}

void pymeshlab::MeshSet::printPluginList() const
{
	std::cout << "MeshSet class - list of loaded plugins:\n";
	for (const MeshCommonInterface* p : pm.ownerPlug){
		std::cout << "\t" << p->pluginName().toStdString() << "\n";
	}
}

void pymeshlab::MeshSet::printPythonFilterNamesList() const
{
	QStringList list = filterFunctionSet.pythonFunctionNames();
	std::cout << "MeshSet class - list of filter names:\n";
	for (const QString& fname : list){
		std::cout << "\t" << fname.toStdString() << "\n";
	}
}

void pymeshlab::MeshSet::printPythonFilterParameterList(const std::string functionName) const
{
	FilterFunctionSet::iterator it = filterFunctionSet.find(QString::fromStdString(functionName));
	if (it == filterFunctionSet.end()){
		std::cout << "Filter " << functionName << " not found.\n";
	}
	else {
		std::cout <<
					 "Please note: some parameters depend on the mesh(es) used as input of the \n"
					 "filter. Default values listed here are computed on a 1x1x1 cube \n"
					 "(pymeshlab/tests/sample/cube.obj), and they will be computed on the input mesh\n"
					 "if they are left as default.\n";

		std::cout << functionName <<" filter - list of parameter names:\n";
		const FilterFunction& ff = *it;
		if (ff.parametersNumber() == 0) {
			std::cout << "\tNone.\n";
		}
		else {
			for (const FilterFunctionParameter& ffp : ff) {
				std::cout << "\t" << ffp.pythonName().toStdString() << " : "
						  << ffp.pythonTypeString().toStdString() << " = ";
				ffp.printDefaultValue(std::cout);
				std::cout << "\n";
			}
		}
	}
}

void pymeshlab::MeshSet::printFilterScript() const
{
	std::cout << "Filter Script Size : " << filterScript.size() << "\n\n";
	uint i = 0;
	for (const FilterNameParameterValuesPair p :filterScript){
		std::cout << std::to_string(i) + ": " << FilterFunctionSet::toPythonName(p.filterName()).toStdString() <<
					 "\n";
		for (const RichParameter& par : p.second){
			FilterFunctionParameter ffp(FilterFunctionSet::toPythonName(par.name()), par);
			std::cout << "\t" << ffp.pythonName().toStdString() << " : "
					  << ffp.pythonTypeString().toStdString() << " = ";
			ffp.printDefaultValue(std::cout);
			std::cout << "\n";
		}
		std::cout << "\n";
		i++;
	}
}

void pymeshlab::MeshSet::loadMesh(const std::string& filename, py::kwargs kwargs)
{
	loadMeshUsingPlugin(filename, nullptr, FilterFunction(), kwargs);
}

void pymeshlab::MeshSet::saveMesh(const std::string& filename, pybind11::kwargs kwargs)
{
	if (mm() == nullptr)
		throw MLException("MeshSet has no selected Mesh.");
	saveMeshUsingPlugin(filename, nullptr, FilterFunction(), kwargs);
}

void pymeshlab::MeshSet::loadProject(const std::string& filename)
{
	QString fileName = QString::fromStdString(filename);
	if (filename.empty())
		throw MLException("file_name empty.");

	QFileInfo fi(fileName);
	if((fi.suffix().toLower()!="aln") &&
			(fi.suffix().toLower()!="mlp")  &&
			(fi.suffix().toLower() != "mlb") &&
			(fi.suffix().toLower()!="out") &&
			(fi.suffix().toLower()!="nvm")) {
		throw MLException("Unknown project file extension: " + fi.suffix().toLower());
	}

	setFileName(fileName);
	setDocLabel(fileName);

	if (QString(fi.suffix()).toLower() == "aln") {
		loadALN(fileName);
	}

	if (QString(fi.suffix()).toLower() == "mlp" || QString(fi.suffix()).toLower() == "mlb") {
		loadMLP(fileName);
	}

	if (QString(fi.suffix()).toLower() == "out"){
		loadBundler(fileName);
	}

	if (QString(fi.suffix()).toLower() == "nvm"){
		loadNVM(fileName);
	}
}

void pymeshlab::MeshSet::saveProject(const std::string& filename)
{
	QString fileName = QString::fromStdString(filename);
	if (filename.empty())
		throw MLException("file_name empty.");

	QFileInfo fi(fileName);
	if((fi.suffix().toLower()!="mlp")  &&
			(fi.suffix().toLower() != "mlb")) {
		throw MLException("Unknown project file extension: " + fi.suffix().toLower());
	}

	if (QString(fi.suffix()).toLower() == "mlp" || QString(fi.suffix()).toLower() == "mlb") {
		saveMLP(fileName);
	}
}

void pymeshlab::MeshSet::loadFilterScript(const std::string& filename)
{
	pymeshlab::QDebugRedirect* qdbr = nullptr;
	if (!verbose)
		qdbr = new pymeshlab::QDebugRedirect(); //redirect qdebug to null

	filterScript.open(QString::fromStdString(filename));

	delete qdbr;
}

void pymeshlab::MeshSet::saveFilterScript(const std::string& filename) const
{
	filterScript.save(QString::fromStdString(filename));
}

void pymeshlab::MeshSet::clearFilterScript()
{
	filterScript.clear();
}

void pymeshlab::MeshSet::applyFilterScript()
{
	for (FilterNameParameterValuesPair p : filterScript){
		QString meshlabFilterName = p.first;
		std::string filtername = FilterFunctionSet::toPythonName(meshlabFilterName).toStdString();
		QAction* action = nullptr;
		MeshFilterInterface* fp = getPluginFromFilterName(meshlabFilterName, action);
		RichParameterList rpl;
		fp->initParameterSet(action, *this, rpl);
		updateRichParameterList(filtername, p.second, rpl);
		applyFilterRPL(filtername, meshlabFilterName, action, fp, rpl);
	}
}

void pymeshlab::MeshSet::applyFilter(const std::string& filtername, pybind11::kwargs kwargs)
{
	FilterFunctionSet::iterator it = filterFunctionSet.find(QString::fromStdString(filtername));
	if (it != filterFunctionSet.end()) {
		QString meshlabFilterName = it->meshlabFunctionName();
		//case of load mesh:
		if (QString::fromStdString(filtername).startsWith("load_")){
			std::string filename = py::str(kwargs["file_name"]);
			loadMeshUsingPlugin(filename, nullptr, *it, kwargs);
		}
		//case of save mesh:
		else if (QString::fromStdString(filtername).startsWith("save_")){
			std::string filename = py::str(kwargs["file_name"]);
			saveMeshUsingPlugin(filename, nullptr, *it, kwargs);
		}
		//all the other plugins:
		else {
			QAction* action = nullptr;
			MeshFilterInterface* fp = getPluginFromFilterName(meshlabFilterName, action);
			RichParameterList rpl;
			fp->initParameterSet(action, *this, rpl);
			updateRichParameterList(*it, kwargs, rpl);
			applyFilterRPL(filtername, meshlabFilterName, action, fp, rpl);
		}
	}
	else {
		throw MLException(
					"Failed to apply filter: " + it->pythonFunctionName() + "\n" +
					"Filter does not exists. Take a look at MeshSet.print_filter_list function.");
	}
}

void pymeshlab::MeshSet::printStatus() const
{
	std::cout << "Number meshes: " << size() << "\n";
	for (const MeshModel* m : meshList){
		std::cout << "\tMesh id: " << m->id() << "\n";
		std::cout << "\tMesh label: " << m->label().toStdString() << "\n";
		std::cout << "\tFull name: " << m->fullName().toStdString() << "\n\n";
	}
}

bool pymeshlab::MeshSet::filterCallBack(const int pos, const char * str)
{
	int static lastPos=-1;
	if(pos==lastPos) return true;
	lastPos=pos;
	std::string s = std::string(str) + "    [ " + std::to_string(pos) +"% ]";
	if (staticLogger)
		staticLogger->Log(GLLogStream::FILTER, s);
	return true;
}

void pymeshlab::MeshSet::updateRichParameterList(
		const std::string& filtername,
		const RichParameterList& base,
		RichParameterList& toUpdate)
{
	for (const RichParameter& p : base){
		if (toUpdate.hasParameter(p.name())){
			toUpdate.setValue(p.name(), p.value());
		}
		else {
			Log.Log(
					GLLogStream::SYSTEM, "Warning: parameter " + p.name().toStdString() +
					" not required by filter " + filtername.c_str());
		}
	}
}

void pymeshlab::MeshSet::updateRichParameterList(
		const FilterFunction& f,
		const pybind11::kwargs& kwargs,
		RichParameterList& rps,
		bool ignoreFileName)
{
	if (kwargs){
		for (std::pair<py::handle, py::handle> p : kwargs){
			std::string key = p.first.cast<std::string>();
			if (!ignoreFileName || key!="file_name"){
				if (f.contains(QString::fromStdString(key))){
					const FilterFunctionParameter& ffp = f.getFilterFunctionParameter(QString::fromStdString(key));
					RichParameterList::iterator it = rps.findParameter(ffp.meshlabName());
					if (it != rps.end()){
						updateRichParameterFromKwarg(*it, ffp, p);
					}
					else {
						//should be impossible
						assert(0);
					}
				}
				else {
					std::cerr << "Warning: parameter " << key << " not found\n";
					//pybind has no bind for python runtime warnings.
				}
			}
		}
	}
}

MeshFilterInterface* pymeshlab::MeshSet::getPluginFromFilterName(const QString& filterName, QAction*& action) const
{
	for (MeshFilterInterface* fp : pm.meshFilterPlug){
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

void pymeshlab::MeshSet::loadMeshUsingPlugin(
		const std::string& filename,
		MeshModel* mm,
		FilterFunction ff,
		pybind11::kwargs kwargs)
{
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();

	if (!finfo.exists()){
		throw MLException("File does not exists: " + QString::fromStdString(filename));
	}
	else {
		if (pm.allKnowInputFormats.contains(extension)){
			if (ff.pythonFunctionName().isEmpty()){
				ff = *filterFunctionSet.find("load_" + extension);
			}
			MeshIOInterface* plugin = pm.allKnowInputFormats[extension];
			int mask = 0; //todo: use this mask
			RichParameterList rps;
			plugin->initGlobalParameterSet(nullptr, rps);
			plugin->initPreOpenParameter(extension, QString::fromStdString(filename), rps);
			plugin->initOpenParameter(extension, *(this->mm()), rps);

			updateRichParameterList(ff, kwargs, rps, true);

			if (mm == nullptr)
				mm = this->addNewMesh(finfo.filePath(), finfo.fileName());
			bool ok = plugin->open(extension, QString::fromStdString(filename), *mm, mask, rps);
			if (!ok) {
				this->delMesh(this->mm());
				throw MLException("Unable to open file: " + QString::fromStdString(filename));
			}
		}
		else {
			throw MLException("Unknown format for load: " + extension);
		}
	}
}

void pymeshlab::MeshSet::saveMeshUsingPlugin(
		const std::string& filename,
		MeshModel* mm,
		pymeshlab::FilterFunction ff,
		pybind11::kwargs kwargs)
{
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();
	if (pm.allKnowOutputFormats.contains(extension)){
		if (ff.pythonFunctionName().isEmpty()){
			ff = *filterFunctionSet.find("save_" + extension);
		}
		MeshIOInterface* plugin = pm.allKnowOutputFormats[extension];
		//int mask = 0; //todo: use this mask
		RichParameterList rps;
		int capability = 0;
		int defbits = 0;
		plugin->GetExportMaskCapability(extension,capability,defbits);
		plugin->initGlobalParameterSet(nullptr, rps);
		plugin->initSaveParameter(extension, *(this->mm()), rps);

		updateRichParameterList(ff, kwargs, rps, true);

		if (mm == nullptr)
			mm = this->mm();

		/**
		 * TODO:
		 * do not use as mask formatmask & mm->dataMask()
		 * formatmask contains all the possible things that can be saved with the format
		 * needs to be combined with:
		 * - all the possible things contained in the mesh
		 *   which is NOT mm->dataMask() -> need to convert... see MeshModel::io2mm,
		 *   but I need mm2io I think
		 * - all the things that the user wants to save, deduced in the future by
		 *   kwargs...
		 */
		bool ok = plugin->save(
					extension, QString::fromStdString(filename), *mm,
					capability & currentMeshIOCapabilityMask(mm), rps);
		if (!ok){
			throw MLException("Unable to save file: " + QString::fromStdString(filename));
		}
	}
	else {
		throw MLException("Unknown format for save: " + extension);
	}
}

int pymeshlab::MeshSet::currentMeshIOCapabilityMask(const MeshModel* mm) const
{
	int arrayCapabilities [] = {
		vcg::tri::io::Mask::IOM_VERTQUALITY,
		vcg::tri::io::Mask::IOM_VERTFLAGS,
		vcg::tri::io::Mask::IOM_VERTCOLOR,
		vcg::tri::io::Mask::IOM_VERTTEXCOORD,
		vcg::tri::io::Mask::IOM_VERTNORMAL,
		vcg::tri::io::Mask::IOM_VERTRADIUS,
		vcg::tri::io::Mask::IOM_FACEQUALITY,
		vcg::tri::io::Mask::IOM_FACEFLAGS,
		vcg::tri::io::Mask::IOM_FACECOLOR,
		vcg::tri::io::Mask::IOM_FACENORMAL,
		vcg::tri::io::Mask::IOM_WEDGCOLOR,
		vcg::tri::io::Mask::IOM_WEDGTEXCOORD,
		vcg::tri::io::Mask::IOM_WEDGNORMAL,
		vcg::tri::io::Mask::IOM_BITPOLYGONAL
	};


	int capability = 0;
	for (auto bit : arrayCapabilities){
		if (mm->hasDataMask(MeshModel::io2mm(bit)))
			capability |= bit;
	}

	return capability;
}

void pymeshlab::MeshSet::loadALN(const QString& fileName)
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
		loadMesh(relativeToProj.toStdString(), py::kwargs());
		mm()->cm.Tr = ir->trasformation;
	}

	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void pymeshlab::MeshSet::loadMLP(const QString& fileName)
{
	QFileInfo fi(fileName);
	QString absfilename = fi.absolutePath() + "/" + fi.fileName();
	QDir currentDir = QDir::current();
	// this change of dir is needed for subsequent textures/materials loading
	QDir::setCurrent(fi.absolutePath());

	std::map<int, MLRenderingData> rendOpt;
	int startingIndex = meshList.size();
	if (!MeshDocumentFromXML(*this, absfilename, (QString(fi.suffix()).toLower() == "mlb"), rendOpt)) {
		throw MLException("Error:  Unable to open MeshLab Project file: " + absfilename);
	}
	for (int i=startingIndex; i<meshList.size(); i++) {
		QString fullPath = meshList[i]->fullName();
		Matrix44m trm = meshList[i]->cm.Tr;
		loadMeshUsingPlugin(fullPath.toStdString(), meshList[i]);
		mm()->cm.Tr = trm;
	}

	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void pymeshlab::MeshSet::loadBundler(const QString& fileName)
{
	QFileInfo fi(fileName);
	QString cameras_filename = fi.absolutePath() + "/" + fi.fileName();
	QString image_list_filename = fi.absolutePath() + "/list.txt";
	QString model_filename;

	QDir currentDir = QDir::current();
	// this change of dir is needed for subsequent textures/materials loading
	QDir::setCurrent(fi.absolutePath());

	if(!MeshDocumentFromBundler(*this, cameras_filename, image_list_filename, model_filename)){
		throw MLException("Error:  Unable to open OUTs file: " + cameras_filename);
	}

	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void pymeshlab::MeshSet::loadNVM(const QString& fileName)
{
	QFileInfo fi(fileName);
	QString cameras_filename = fi.absolutePath() + "/" + fi.fileName();
	QString image_list_filename = fi.absolutePath() + "/list.txt";
	QString model_filename;

	QDir currentDir = QDir::current();
	// this change of dir is needed for subsequent textures/materials loading
	QDir::setCurrent(fi.absolutePath());

	if(!MeshDocumentFromNvm(*this, cameras_filename, model_filename)){
		throw MLException("Error:  Unable to open NVMs file: " + cameras_filename);
	}

	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void pymeshlab::MeshSet::saveMLP(const QString& fileName)
{
	QFileInfo fi(fileName);
	QString outdir = fi.absolutePath();
	QString absfilename = outdir + "/" + fi.fileName();
	QDir currentDir = QDir::current();
	// this change of dir is needed for subsequent textures/materials loading
	QDir::setCurrent(fi.absolutePath());

	for(MeshModel* m : meshList) {
		if (m != NULL) {
			QString label = m->label().remove(" ");
			int p = label.lastIndexOf('.');
			if (p > 0)
				label = label.left(p);
			QString outfilename = outdir + "/" + label.remove(" ") + ".ply";
			m->setFileName(outfilename);
			QFileInfo of(outfilename);
			m->setLabel(of.fileName());
			saveMeshUsingPlugin(outfilename.toStdString(), m);
		}
	}

	bool ok = MeshDocumentToXMLFile(*this, fileName, false, false, fi.suffix().toLower() == "mlb");
	if (!ok){
		throw MLException("Error:  Unable to save MeshLab Project file: " + absfilename);
	}
	//restore current dir
	QDir::setCurrent(currentDir.absolutePath());
}

void pymeshlab::MeshSet::updateRichParameterFromKwarg(
		RichParameter& par,
		const FilterFunctionParameter& ffp,
		const std::pair<py::handle, py::handle>& k)
{
	QString pythonType = ffp.pythonTypeString();
	if (pythonType == "bool"){
		par.setValue(BoolValue(py::cast<bool>(k.second)));
	}
	else if (pythonType == "int") {
		par.setValue(IntValue(py::cast<int>(k.second)));
	}
	else if (pythonType == "float") {
		par.setValue(FloatValue(py::cast<float>(k.second)));
	}
	else if (pythonType == "str") {
		par.setValue(StringValue(
					QString::fromStdString(py::cast<std::string>(k.second))));
	}
	else if (pythonType.contains("Percentage")) {
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
	else if (pythonType == "Color") {
		par.setValue(ColorValue(py::cast<QColor>(k.second)));
	}
	else if (pythonType.contains("still_unsupported")){
		std::cerr << "Warning: parameter type still not supported";
	}
	else {
		std::cerr << "Parameter type not found. Critical Error. Exiting...";
		assert(0);
		exit(-1);
	}
}

void pymeshlab::MeshSet::applyFilterRPL(
		const std::string& filtername,
		QString meshlabFilterName,
		QAction* action,
		MeshFilterInterface* fp,
		const RichParameterList& rpl)
{
	try {
		int req=fp->getRequirements(action);
		if (mm() != nullptr)
			mm()->updateDataMask(req);
		staticLogger = verbose ? &Log : nullptr;
		fp->applyFilter(action, *this, rpl, &MeshSet::filterCallBack);
		filterCallBack(100, (filtername + " applied!").c_str());
		if (mm() != nullptr) {
			mm()->cm.svn = int(vcg::tri::UpdateSelection<CMeshO>::VertexCount(mm()->cm));
			mm()->cm.sfn = int(vcg::tri::UpdateSelection<CMeshO>::FaceCount(mm()->cm));
		}
		FilterNameParameterValuesPair pair;
		pair.first = meshlabFilterName; pair.second = rpl;
		filterScript.append(pair);
	}
	catch(const std::exception& e) {
		throw MLException(
					"Failed to apply filter: " + QString::fromStdString(filtername) + "\n" +
					"Details: " + e.what());
	}
}





