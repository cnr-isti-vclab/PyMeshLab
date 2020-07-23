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
	//pm.loadPlugins(s, dir);

	//std::cerr << pm.pluginsDir.absolutePath().toStdString() << "\n";
}
