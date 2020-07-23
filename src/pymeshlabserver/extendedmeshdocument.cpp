#include <pybind11/pybind11.h>

#include "extendedmeshdocument.h"


namespace py = pybind11;

ExtendedMeshDocument::ExtendedMeshDocument() :
	MeshDocument(), s(), pm()
{
	py::gil_scoped_acquire acquire;
	py::object pyml = py::module::import("pymeshlab");
	basePath = pyml.attr("__file__").cast<std::string>();
	QDir dir(QString::fromStdString(basePath));
	dir.cdUp();
	dir.cd("lib/meshlab/plugins");
	std::cerr << "Path: " << dir.absolutePath().toStdString() << "\n";

	//for(QString fileName : dir.entryList(QDir::Files)) {
	//	loadPlugin(dir.absolutePath() + "/" + fileName);
	//}

	pm.loadPlugins(s, dir);

	//std::cerr << pm.pluginsDir.absolutePath().toStdString() << "\n";
}

void ExtendedMeshDocument::loadPlugin(const QString& absPath)
{
	QString filename = QFileInfo(absPath).fileName();

	std::cerr << "loading: " << filename.toStdString() << "\n";
	QPluginLoader loader(absPath);
	QObject* plugin = loader.instance();
	if (plugin){
		std::cerr << "\tIt is a plugin\n";
	}
	else {
		std::cerr << "\tSomething is not working\n";
	}
}
