#include "pymeshlab/mesh.h"
#include "pymesh.h"
#include "docs/pymesh_doc.h"

namespace py = pybind11;

void pymeshlab::initMesh(py::module& m)
{
	py::class_<CMeshO> meshClass(m, "Mesh");

	auto compactnessexc = py::register_exception<vcg::MissingCompactnessException>(m, "MissingCompactnessException");
	auto componentexc = py::register_exception<vcg::MissingComponentException>(m, "MissingComponentException");
	compactnessexc.doc() = doc::PYEXC_COMPACTNESS;
	componentexc.doc() = doc::PYEXC_COMPONENT;

	//empty constructor
	meshClass.def(py::init(), doc::PYMESH_INIT);

	meshClass.def("vertex_number", &CMeshO::VN, doc::PYMESH_VN);
	meshClass.def("face_number", &CMeshO::FN, doc::PYMESH_FN);
	meshClass.def("edge_number", &CMeshO::EN, doc::PYMESH_EN);
	meshClass.def("is_compact", &Mesh::isCompact, doc::PYMESH_IS_COMPACT);
	meshClass.def("bounding_box", &Mesh::boundingBox, doc::PYMESH_BB);
	meshClass.def("selected_face_number", &Mesh::selectedFaceNumber, doc::PYMESH_SEL_FN);

	meshClass.def("update_bounding_box", &Mesh::updateBBox, doc::PYMESH_UPDATE_BB);
	meshClass.def("update_topology", &Mesh::updateTopology, doc::PYMESH_UPDATE_TOPO);
	meshClass.def("compact", &Mesh::compact, doc::PYMESH_COMPACT);

	meshClass.def("vertex_matrix", &Mesh::vertexMatrix, doc::PYMESH_VERT_MAT);
	meshClass.def("face_matrix", &Mesh::faceMatrix, doc::PYMESH_FACE_MAT);
	meshClass.def("vertex_normal_matrix", &Mesh::vertexNormalMatrix, doc::PYMESH_VERT_NORM_MAT);
	meshClass.def("face_normal_matrix", &Mesh::faceNormalMatrix, doc::PYMESH_FACE_NORM_MAT);
	meshClass.def("vertex_quality_matrix", &Mesh::vertexQualityMatrix, doc::PYMESH_VERT_QUAL_MAT);
	meshClass.def("face_quality_matrix", &Mesh::faceQualityMatrix, doc::PYMESH_FACE_QUAL_MAT);
	meshClass.def("vertex_tex_coord_matrix", &Mesh::vertexTexCoordMatrix, doc::PYMESH_VERT_QUAL_MAT);

	meshClass.def("face_face_adjacency_matrix", &Mesh::faceFaceAdjacency, doc::PYMESH_FFADJ_MAT);
}
