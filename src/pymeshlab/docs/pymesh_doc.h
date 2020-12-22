#ifndef PYMESHLAB_PYMESH_DOC_H
#define PYMESHLAB_PYMESH_DOC_H

namespace pymeshlab {
namespace doc {

//MissingCompactnessException
const char* PYEXC_COMPACTNESS =
		"Exception raised when the compactness of some components of a "
		":py:class:`Mesh` is required. Generally, a mesh is not compact when "
		"some elements have been removed.";

//MissingComponentException
const char* PYEXC_COMPONENT =
		"Exception raiesed when a component required by a filter is missing in a "
		":py:class:`Mesh` object.";

//Mesh::__init__
const char* PYMESH_INIT =
		"Creates a mesh containing the data passed as input. If no "
		"data is passed as argument, an empty mesh will be created.";

//Mesh::vertex_number
const char* PYMESH_VN =
		"Returns the number of vertices of the mesh.";

//Mesh::face_number
const char* PYMESH_FN =
		"Returns the number of faces of the mesh.";

//Mesh::edge_number
const char* PYMESH_EN =
		"Returns the number of edges of the mesh.";

//Mesh::is_compact
const char* PYMESH_IS_COMPACT =
		"Returns true if all its arrays are compact.";

//Mesh::bounding_box
const char* PYMESH_BB =
		"Returns the bounding box of the mesh.";

//Mesh::selected_vertex_number
const char* PYMESH_SEL_VN =
		"Returns the number of selected vertices of the mesh.";

//Mesh::selected_face_number
const char* PYMESH_SEL_FN =
		"Returns the number of selected faces of the mesh.";

//Mesh::update_bounding_box
const char* PYMESH_UPDATE_BB =
		"Updates the bounding box of the mesh.";

//Mesh::update_topology
const char* PYMESH_UPDATE_TOPO =
		"Updates the topology of the mesh.";

//Mesh::compact
const char* PYMESH_COMPACT =
		"Compacts all the arrays of the mesh.";

//Mesh::vertex_matrix
const char* PYMESH_VERT_MAT =
		"Returns the vertex matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the array is not compact.";

//Mesh::face_matrix
const char* PYMESH_FACE_MAT =
		"Returns the face matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the array is not compact.";

//Mesh::vertex_normal_matrix
const char* PYMESH_VERT_NORM_MAT =
		"Returns the vertex normal matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the array is not compact.";

//Mesh::face_normal_matrix
const char* PYMESH_FACE_NORM_MAT =
		"Returns the face normal matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the array is not compact.";

//Mesh::vertex_quality_matrix
const char* PYMESH_VERT_QUAL_MAT =
		"Returns the vertex quality matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the array is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no vertex "
		"quality component. ";

//Mesh::face_quality_matrix
const char* PYMESH_FACE_QUAL_MAT =
		"Returns the face quality matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the array is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no face "
		"quality component. ";

//Mesh::vertex_tex_matrix
const char* PYMESH_VERT_TEX_MAT =
		"Returns the vertex texcoord matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the array is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no vertex "
		"tex coordinates component. ";

//Mesh::face_face_adjacecncy
const char* PYMESH_FFADJ_MAT =
		"Returns face-to-face adjacency matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the array is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no face-to-face "
		"adjacency component. ";
}
}

#endif // PYMESHLAB_PYMESH_DOC_H
