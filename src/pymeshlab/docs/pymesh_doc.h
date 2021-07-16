/****************************************************************************
* PyMeshLab                                                         o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005-2021                                           \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
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
		"Exception raised when a component required by a filter is missing in a "
		":py:class:`Mesh` object.";

//Mesh::__init__
const char* PYMESH_INIT =
		"Creates a mesh containing the data passed as input. If no "
		"data is passed as argument, an empty mesh will be created.";

//Mesh::__init__ (poly)
const char* PYMESH_INIT_POLY =
		"Creates a polygon mesh containing the data passed as input. "
		"At least a numpy array of vertices and a list of numpy arrays of "
		"face indices is required. Since MeshLab and PyMeshLab can store only "
		"triangle meshes, the newly created mesh is actually a triangle mesh "
		"with some edges that are marked as 'faux'. "
		"This constructor creates a custom per face scalar attribute called "
		"`poly_birth_faces` that stores, for each face of the newly created "
		"mesh, the index of the polygonal mesh that generated it.";

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
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

//Mesh::face_matrix
const char* PYMESH_FACE_MAT =
		"Returns the face matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

//Mesh::vertex_normal_matrix
const char* PYMESH_VERT_NORM_MAT =
		"Returns the vertex normal matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

//Mesh::face_normal_matrix
const char* PYMESH_FACE_NORM_MAT =
		"Returns the face normal matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

//Mesh::vertex_color_matrix
const char* PYMESH_VERT_COLOR_MAT =
		"Returns the vertex color matrix as a numpy array of [NV x 4] floats, "
		"where each component (RGBA) is in the interval [0, 1]. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

//Mesh::face_color_matrix
const char* PYMESH_FACE_COLOR_MAT =
		"Returns the face color matrix as a numpy array of [NF x 4] floats, "
		"where each component (RGBA) is in the interval [0, 1]. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no face "
		"color component.";

//Mesh::vertex_color_array
const char* PYMESH_VERT_COLOR_ARRAY =
		"Returns the vertex color matrix as a numpy array of [NV] unsigned integers, "
		"where the (ARGB) is packed in a 32bit unsigned int (8 bits per component)."
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

//Mesh::face_color_array
const char* PYMESH_FACE_COLOR_ARRAY =
		"Returns the face color matrix as a numpy array of [NF] unsigned integers, "
		"where the (ARGB) is packed in a 32bit unsigned int (8 bits per component)."
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no face "
		"color component.";

//Mesh::vertex_quality_matrix
const char* PYMESH_VERT_QUAL_ARRAY =
		"Returns the vertex quality array of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no vertex "
		"quality component. ";

//Mesh::face_quality_matrix
const char* PYMESH_FACE_QUAL_ARRAY =
		"Returns the face quality array of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no face "
		"quality component. ";

//Mesh::vertex_tex_matrix
const char* PYMESH_VERT_TEX_MAT =
		"Returns the vertex texcoord matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no per-wedge "
		"tex coordinates component. ";

//Mesh::wedge_tex_matrix
const char* PYMESH_WEDGE_TEX_MAT =
		"Returns the per-wedge texcoord matrix of the mesh as a numpy array, "
		"composed of NF*3 rows (triplets of wedges for each face) and 2 columns. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no vertex "
		"tex coordinates component. ";

//Mesh::face_face_adjacecncy
const char* PYMESH_FFADJ_MAT =
		"Returns face-to-face adjacency matrix of the mesh as a numpy array. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`MissingComponentException` if the mesh has no face-to-face "
		"adjacency component. ";

const char* PYMESH_VERT_SCALAR_ATTR_ARRAY = 
		"Returns a numpy array containing the scalar values of the given user defined "
		"attribute name associated to the vertices of the mesh. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`PyMeshLabException` if the given name does not "
		"represent a vertex scalar attribute in the mesh.";

const char* PYMESH_VERT_VECTOR_ATTR_MATRIX = 
		"Returns a numpy matrix containing the vector values of the given user defined "
		"attribute name associated to the vertices of the mesh. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`PyMeshLabException` if the given name does not "
		"represent a vertex vector attribute in the mesh.";

const char* PYMESH_FACE_SCALAR_ATTR_ARRAY = 
		"Returns a numpy array containing the scalar values of the given user defined "
		"attribute name associated to the faces of the mesh. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`PyMeshLabException` if the given name does not "
		"represent a face scalar attribute in the mesh.";

const char* PYMESH_FACE_VECTOR_ATTR_MATRIX = 
		"Returns a numpy matrix containing the vector values of the given user defined "
		"attribute name associated to the faces of the mesh. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`PyMeshLabException` if the given name does not "
		"represent a face vector attribute in the mesh.";

const char* PYMESH_ADD_VERT_SCALAR_ATTR =
		"Adds a new user defined scalar attribute associated to the vertices of "
		"the mesh. Takes as input numpy array of scalar having the same size of "
		"the number of vertices of the mesh, and the name of the new attribute. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`PyMeshLabException` if the given array has a different "
		"size from the vertex number of the mesh, or if the mesh already contains "
		"a vertex scalar attribute with the given name.";

const char* PYMESH_ADD_FACE_SCALAR_ATTR =
		"Adds a new user defined scalar attribute associated to the faces of "
		"the mesh. Takes as input numpy array of scalar having the same size of "
		"the number of faces of the mesh, and the name of the new attribute. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`PyMeshLabException` if the given array has a different "
		"size from the face number of the mesh, or if the mesh already contains "
		"a face scalar attribute with the given name.";

const char* PYMESH_ADD_VERT_VECTOR_ATTR =
		"Adds a new user defined vector attribute associated to the vertices of "
		"the mesh. Takes as input numpy array of vectors having 3 columns and the "
		"number of rows equal to the number of vertices of the mesh, and the name of "
		"the new attribute. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`PyMeshLabException` if the given array has not the correct "
		"sizes, or if the mesh already contains a vertex vector attribute with the "
		"given name.";

const char* PYMESH_ADD_FACE_VECTOR_ATTR =
		"Adds a new user defined vector attribute associated to the faces of "
		"the mesh. Takes as input numpy array of vectors having 3 columns and the "
		"number of rows equal to the number of faces of the mesh, and the name of "
		"the new attribute. "
		"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
		"Raises a :py:exc:`PyMeshLabException` if the given array has not the correct "
		"sizes, or if the mesh already contains a face vector attribute with the "
		"given name.";
}
}

#endif // PYMESHLAB_PYMESH_DOC_H
