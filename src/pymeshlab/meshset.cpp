#include "meshset.h"

#include "pymeshlabcommon.h"

namespace py = pybind11;

pymeshlab::MeshSet::MeshSet() :
	MeshDocument(), globalRPS(), pm()
{
	QDir dir(QString::fromStdString(pymeshlab::getPluginsPath()));
	pymeshlab::QDebugRedirect qdbr; //redirect qdebug to null, just for this scope
	pm.loadPlugins(globalRPS, dir);
	nameBinder.popolate(pm);
}

void pymeshlab::MeshSet::loadMesh(const std::string& filename, py::kwargs kwargs)
{
	QFileInfo finfo(QString::fromStdString(filename));
	if (!finfo.exists()){
		std::cerr << "File does not exists!";
		//todo: manage python exception
	}
	else {
		QString extension = finfo.suffix().toLower();

		if (pm.allKnowInputFormats.contains(extension)){
			MeshIOInterface* plugin = pm.allKnowInputFormats[extension];
			int mask = 0; //todo: use this mask
			RichParameterSet rps;
			plugin->initPreOpenParameter(extension, QString::fromStdString(filename), rps);
			plugin->initOpenParameter(extension, *(this->mm()), rps);

			updateRichParameterSet(kwargs, rps);

			this->addNewMesh(finfo.filePath(), finfo.fileName());
			bool ok = plugin->open(extension, QString::fromStdString(filename), *(this->mm()), mask, rps);
			if (!ok)
				this->delMesh(this->mm());
			//todo: manage python exception
		}
		else {
			std::cerr << "Unknown format: " << extension.toStdString() << "\n";
			//todo: manage python exception
		}

	}
}

void pymeshlab::MeshSet::saveMesh(const std::string& filename, pybind11::kwargs kwargs)
{
	QFileInfo finfo(QString::fromStdString(filename));
	QString extension = finfo.suffix().toLower();

	if (pm.allKnowOutputFormats.contains(extension)){
		MeshIOInterface* plugin = pm.allKnowOutputFormats[extension];
		int mask = 0; //todo: use this mask
		RichParameterSet rps;
		plugin->initSaveParameter(extension, *(this->mm()), rps);

		updateRichParameterSet(kwargs, rps);

		bool ok = plugin->save(extension, QString::fromStdString(filename), *(this->mm()), mask, rps);
		if (!ok){
			//todo: manage python exception
		}
	}
	else {
		std::cerr << "Unknown format: " << extension.toStdString() << "\n";
		//todo: manage python exception
	}
}

void pymeshlab::MeshSet::applyFilter(const std::string& filtername, pybind11::kwargs kwargs)
{

}

void pymeshlab::MeshSet::updateRichParameterSet(const pybind11::kwargs& kwargs, RichParameterSet& rps)
{
	if (kwargs){
		for (auto p : kwargs){
			std::string key = p.first.cast<std::string>();
			RichParameter* par = rps.findParameter(QString::fromStdString(key));
			if (par){

			}
			else {
				std::cerr << "Warning: parameter " << key << " not found\n";
				//todo: manage python exception?
			}
		}
	}
}


