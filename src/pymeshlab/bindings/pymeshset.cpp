#include "pymeshset.h"

#include "pymeshlab/common.h"
#include "pymeshlab/meshset.h"
#include "docs/pymeshset_doc.h"
#include <vcg/../wrap/io_trimesh/import_obj.h>
#include <pybind11/eval.h>

namespace py = pybind11;

void pymeshlab::initMeshSet(pybind11::module& m)
{
	py::class_<MeshSet> meshSetClass(m, "MeshSet");

	//constructor
	meshSetClass.def(py::init<bool>(), doc::PYMS_INIT_VERB, py::arg("verbose") = false);

	meshSetClass.def("set_versbosity", &MeshSet::setVerbosity, doc::PYMS_SET_VERBOSITY_DOC, py::arg("verbosity"));
	meshSetClass.def("number_meshes", &MeshSet::size, doc::PYMS_SIZE_DOC);
	meshSetClass.def("set_current_mesh", &MeshSet::setCurrentMesh, doc::PYMS_SET_CURRENT_MESH, py::arg("new_curr_id"));
	meshSetClass.def("current_mesh", &MeshSet::currentMesh, doc::PYMS_CURRENT_MESH, py::return_value_policy::reference);
	meshSetClass.def("current_mesh_id", &MeshSet::currentMeshId, doc::PYMS_CURRENT_MESH_ID);
	meshSetClass.def("mesh_id_exists", &MeshSet::meshIdExists, doc::PYMS_MESH_ID_EXISTS, py::arg("id"));
	meshSetClass.def("mesh", &MeshSet::mesh, doc::PYMS_MESH, py::arg("id"), py::return_value_policy::reference);
	meshSetClass.def("load_new_mesh", &MeshSet::loadNewMesh, doc::PYMS_LOAD_NEW_MESH, py::arg("file_name"));
	meshSetClass.def("load_current_mesh", &MeshSet::loadCurrentMesh, doc::PYMS_LOAD_CURRENT_MESH, py::arg("file_name"));
	meshSetClass.def("save_current_mesh", &MeshSet::saveCurrentMesh, doc::PYMS_SAVE_CURRENT_MESH, py::arg("file_name"));
	meshSetClass.def("add_mesh", &MeshSet::addMesh, doc::PYMS_ADD_MESH, py::arg("mesh"), py::arg("mesh_name") = "", py::arg("set_as_current") = true);
	meshSetClass.def("clear", &MeshSet::clear, doc::PYMS_CLEAR);
	meshSetClass.def("load_project", &MeshSet::loadProject, doc::PYMS_LOAD_PROJECT, py::arg("file_name"));
	meshSetClass.def("save_project", &MeshSet::saveProject, doc::PYMS_SAVE_PROJECT, py::arg("file_name"));
	meshSetClass.def("apply_filter", &MeshSet::applyFilter, doc::PYMS_APPLY_FILTER, py::arg("filter_name"));
	meshSetClass.def("load_filter_script", &MeshSet::loadFilterScript, doc::PYMS_LOAD_FILTER_SCRIPT, py::arg("filter_script_name"));
	meshSetClass.def("save_filter_script", &MeshSet::saveFilterScript, doc::PYMS_SAVE_FILTER_SCRIPT, py::arg("filter_script_name"));
	meshSetClass.def("clear_filter_script", &MeshSet::clearFilterScript, doc::PYMS_CLEAR_FILTER_SCRIPT);
	meshSetClass.def("apply_filter_script", &MeshSet::applyFilterScript, doc::PYMS_APPLY_FILTER_SCRIPT);
	meshSetClass.def("print_status", &MeshSet::printStatus, doc::PYMS_PRINT_STATUS);
	meshSetClass.def("print_plugin_list", &MeshSet::printPluginList, doc::PYMS_PRINT_PLUGIN_LIST);
	meshSetClass.def("print_filter_list", &MeshSet::printPythonFilterNamesList, doc::PYMS_PRINT_FILTER_LIST);
	meshSetClass.def("print_filter_parameter_list", &MeshSet::printPythonFilterParameterList, doc::PYMS_PRINT_FILTER_PARAMETER_LIST, py::arg("filter_name"));
	meshSetClass.def("print_filter_script", &MeshSet::printFilterScript, doc::PYMS_PRINT_FILTER_SCIRPT);
}
