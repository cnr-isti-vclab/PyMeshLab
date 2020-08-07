#include "pymeshlab/mesh.h"
#include "pymesh.h"

namespace py = pybind11;

void pymeshlab::initMesh(py::module& m)
{
	py::class_<CMeshO> meshClass(m, "Mesh");

	py::register_exception<vcg::MissingCompactnessException>(m, "MissingCompactnessException");
	py::register_exception<vcg::MissingComponentException>(m, "MissingComponentException");

	//empty constructor
	meshClass.def(py::init());

	meshClass.def("vertex_number", &CMeshO::VN);
	meshClass.def("face_number", &CMeshO::FN);
	meshClass.def("edge_number", &CMeshO::EN);
	meshClass.def("is_compact", &Mesh::isCompact);

	meshClass.def("update_bounding_box", &Mesh::updateBBox);
	meshClass.def("update_topology", &Mesh::updateTopology);
	meshClass.def("compact", &Mesh::compact);

	meshClass.def("vertex_matrix", &Mesh::vertexMatrix);
	meshClass.def("face_matrix", &Mesh::faceMatrix);
	meshClass.def("vertex_normal_matrix", &Mesh::vertexNormalMatrix);
	meshClass.def("face_normal_matrix", &Mesh::faceNormalMatrix);
	meshClass.def("vertex_quality_matrix", &Mesh::vertexQualityMatrix);
	meshClass.def("face_quality_matrix", &Mesh::faceQualityMatrix);
	meshClass.def("vertex_tex_coord_matrix", &Mesh::vertexTexCoordMatrix);

	meshClass.def("face_face_adjacency_matrix", &Mesh::faceFaceAdjacency);
}
