#include "pymeshset.h"

#include "pymeshlabcommon.h"
#include "meshset.h"
#include <vcg/../wrap/io_trimesh/import_obj.h>
#include <pybind11/eval.h>

namespace py = pybind11;

CMeshO& currentMesh(pymeshlab::MeshSet& m)
{
	return m.mm()->cm;
}

void pymeshlab::initMeshSet(pybind11::module& m)
{
	py::class_<MeshSet> meshSetClass(m, "MeshSet");

	//empty constructor
	meshSetClass.def(py::init());

	meshSetClass.def("number_meshes", &MeshSet::size);
	meshSetClass.def("set_current_mesh", &MeshSet::setCurrentMesh, py::arg("new_curr_id"));
	meshSetClass.def("current_mesh", &currentMesh, py::return_value_policy::reference);
	meshSetClass.def("load_mesh", &MeshSet::loadMesh, py::arg("filename"));
	meshSetClass.def("save_mesh", &MeshSet::saveMesh, py::arg("filename"));
}
