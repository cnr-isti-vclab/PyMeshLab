#include "meshset.h"

#include "pymeshlabcommon.h"

namespace py = pybind11;

pymeshlab::MeshSet::MeshSet() :
	MeshDocument(), globalRPS(), pm()
{
	QDir dir(QString::fromStdString(pymeshlab::getPluginsPath()));
	pymeshlab::QDebugRedirect qdbr; //redirect qdebug to null, just for this scope
	pm.loadPlugins(globalRPS, dir);
	filterFunctionSet.popolate(pm);
}

pymeshlab::MeshSet::~MeshSet()
{
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
		std::cout << functionName <<" filter - list of parameter names:\n";
		const FilterFunction& ff = *it;
		if (ff.parametersNumber() == 0){
			std::cout << "\tNone.\n";
		}
		else {
			for (const FilterFunctionParameter& ffp : ff){
				std::cout << "\t" << ffp.pythonName().toStdString() << " : "
						  << ffp.pythonTypeString().toStdString() << " = ";
				ffp.printDefaultValue(std::cout);
				std::cout << "\n";
			}
		}
	}
}

void pymeshlab::MeshSet::loadMesh(const std::string& filename, py::kwargs kwargs)
{
	QFileInfo finfo(QString::fromStdString(filename));

	QString extension = finfo.suffix().toLower();

	if (pm.allKnowInputFormats.contains(extension)){
		kwargs["file_name"] = py::str(filename);
		applyFilter("load_" + extension.toStdString(), kwargs);
	}
	else {
		std::cerr << "Unknown format: " << extension.toStdString() << "\n";
		//todo: manage python exception
	}
}

void pymeshlab::MeshSet::saveMesh(const std::string& filename, pybind11::kwargs kwargs)
{
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();

	if (pm.allKnowOutputFormats.contains(extension)){
		kwargs["file_name"] = py::str(filename);
		applyFilter("save_" + extension.toStdString(), kwargs);
	}
	else {
		std::cerr << "Unknown format: " << extension.toStdString() << "\n";
		//todo: manage python exception
	}
}

void pymeshlab::MeshSet::applyFilter(const std::string& filtername, pybind11::kwargs kwargs)
{
	FilterFunctionSet::iterator it = filterFunctionSet.find(QString::fromStdString(filtername));
	if (it != filterFunctionSet.end()) {
		QString meshlabFilterName = it->meshlabFunctionName();
		if (QString::fromStdString(filtername).startsWith("load_")){
			QString extension = meshlabFilterName;
			std::string filename = py::str(kwargs["file_name"]);
			QFileInfo finfo(QString::fromStdString(filename));
			if (!finfo.exists()){
				std::cerr << "File does not exists!";
				//todo: manage python exception
			}
			else {
				MeshIOInterface* plugin = pm.allKnowInputFormats[extension];
				int mask = 0; //todo: use this mask
				RichParameterSet rps;
				plugin->initGlobalParameterSet(nullptr, rps);
				plugin->initPreOpenParameter(extension, QString::fromStdString(filename), rps);
				plugin->initOpenParameter(extension, *(this->mm()), rps);

				updateRichParameterSet(*it, kwargs, rps, true);

				this->addNewMesh(finfo.filePath(), finfo.fileName());
				bool ok = plugin->open(extension, QString::fromStdString(filename), *(this->mm()), mask, rps);
				if (!ok)
					this->delMesh(this->mm());
			}
		}
		else if (QString::fromStdString(filtername).startsWith("save_")){
			std::string filename = py::str(kwargs["file_name"]);
			QFileInfo finfo(QString::fromStdString(filename));
			QString extension = meshlabFilterName;
			MeshIOInterface* plugin = pm.allKnowOutputFormats[extension];
			int mask = 0; //todo: use this mask
			RichParameterSet rps;
			plugin->initGlobalParameterSet(nullptr, rps);
			plugin->initSaveParameter(extension, *(this->mm()), rps);

			updateRichParameterSet(*it, kwargs, rps, true);

			bool ok = plugin->save(extension, QString::fromStdString(filename), *(this->mm()), mask, rps);
			if (!ok){
				//todo: manage python exception
			}
		}
		else { //normal filter
			QAction* action = nullptr;
			MeshFilterInterface* fp = getPluginFromFilterName(meshlabFilterName, action);
			RichParameterSet rps;
			fp->initParameterSet(action, *this, rps);
			updateRichParameterSet(*it, kwargs, rps);
			fp->applyFilter(action, *this, rps, nullptr);
		}

	}
	else {
		//todo: manage python exception
		std::cerr << "Filter " << filtername << " not found\n";
	}

}

void pymeshlab::MeshSet::updateRichParameterSet(const FilterFunction& f, const pybind11::kwargs& kwargs, RichParameterSet& rps, bool ignoreFileName)
{
	if (kwargs){
		for (auto p : kwargs){
			std::string key = p.first.cast<std::string>();
			std::cerr << "Key: " << key << "\n";
			if (!ignoreFileName || key!="file_name"){
				if (f.contains(QString::fromStdString(key))){
					const FilterFunctionParameter& p = f.getFilterFunctionParameter(QString::fromStdString(key));
					RichParameter* par = rps.findParameter(p.meshlabName());
					if (par){
						std::cerr << "Parameter " << key <<" found.\n";
					}
					else {
						//should be impossible
						assert(0);
					}
				}
				else {
					std::cerr << "Warning: parameter " << key << " not found\n";
					//todo: manage python exception?
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




