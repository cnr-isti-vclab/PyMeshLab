#include "pymeshdocument.h"
#include "extendedmeshdocument.h"
#include <vcg/../wrap/io_trimesh/import_obj.h>
#include <pybind11/eval.h>

namespace py = pybind11;

CMeshO& currentMesh(ExtendedMeshDocument& m) {
	return m.mm()->cm;
}

void pymeshlab::initMeshDocument(pybind11::module& m)
{
	py::class_<ExtendedMeshDocument> meshDocumentClass(m, "MeshDocument");

	//empty constructor
	meshDocumentClass.def(py::init());

	meshDocumentClass.def("load_mesh", &ExtendedMeshDocument::loadMesh, py::arg("filename"));

	meshDocumentClass.def("number_meshes", &ExtendedMeshDocument::size);
	meshDocumentClass.def("set_current_mesh", &ExtendedMeshDocument::setCurrentMesh, py::arg("new_curr_id"));
	meshDocumentClass.def("current_mesh", &currentMesh, py::return_value_policy::reference);
}
