#include "pymeshlab/mesh.h"
#include "pymesh.h"

namespace py = pybind11;

void pymeshlab::initMesh(py::module& m)
{
	py::class_<CMeshO> meshClass(m, "Mesh");

	//empty constructor
	meshClass.def(py::init());

	meshClass.def("vertex_number", &CMeshO::VN);
	meshClass.def("face_number", &CMeshO::FN);
	meshClass.def("edge_number", &CMeshO::EN);
	meshClass.def("update_bounding_box", &Mesh::updateBBox);
}
