#include "pymeshset.h"

#include "pymeshlab/common.h"
#include "pymeshlab/meshset.h"
#include "docs/pymeshset_doc.h"
#include <vcg/../wrap/io_trimesh/import_obj.h>
#include <pybind11/eval.h>
#include <mlexception.h>

namespace py = pybind11;

void pymeshlab::initMeshSet(pybind11::module& m)
{
	py::class_<MeshSet> meshSetClass(m, "MeshSet");

	py::register_exception<MLException>(m, "PyMeshLabException");

	//empty constructor
	meshSetClass.def(py::init());
	meshSetClass.def(py::init<bool>(), py::arg("verbose"));

	meshSetClass.def("set_versbosity", &MeshSet::setVerbosity, doc::PYMS_SET_VERBOSITY_DOC, py::arg("verbosity"));
	meshSetClass.def("number_meshes", &MeshSet::size, doc::PYMS_SIZE_DOC);
	meshSetClass.def("set_current_mesh", &MeshSet::setCurrentMesh, doc::PYMS_SET_CURRENT_MESH, py::arg("new_curr_id"));
	meshSetClass.def("current_mesh", &MeshSet::currentMesh, py::return_value_policy::reference);
	meshSetClass.def("current_mesh_id", &MeshSet::currentMeshId);
	meshSetClass.def("mesh_id_exists", &MeshSet::meshIdExists, py::arg("id"));
	meshSetClass.def("mesh", &MeshSet::mesh, py::arg("id"), py::return_value_policy::reference);
	meshSetClass.def("load_mesh", &MeshSet::loadMesh, py::arg("file_name"));
	meshSetClass.def("save_mesh", &MeshSet::saveMesh, py::arg("file_name"));
	meshSetClass.def("load_project", &MeshSet::loadProject, py::arg("file_name"));
	meshSetClass.def("save_project", &MeshSet::saveProject, py::arg("file_name"));
	meshSetClass.def("apply_filter", &MeshSet::applyFilter, py::arg("filter_name"));
	meshSetClass.def("print_status", &MeshSet::printStatus);
	meshSetClass.def("print_plugin_list", &MeshSet::printPluginList);
	meshSetClass.def("print_filter_list", &MeshSet::printPythonFilterNamesList);
	meshSetClass.def("print_filter_parameter_list", &MeshSet::printPythonFilterParameterList, py::arg("filter_name"));
}
