/*****************************************************************************
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

// MissingCompactnessException
const char* PYEXC_COMPACTNESS =
	"Exception raised when the compactness of some components of a :py:class:`Mesh` is required. "
	"Generally, a mesh is not compact when some elements have been removed.";

// MissingComponentException
const char* PYEXC_COMPONENT =
	"Exception raised when a component required by a filter is missing in a :py:class:`Mesh` "
	"object.";

// Mesh::__init__
const char* PYMESH_INIT =
	"Creates a mesh containing the data passed as input. If no data is passed as argument, an "
	"empty mesh will be created. Color matrices have four columns (RGBA) and values are floats in "
	"the range [0-1]. Values outside this range will result in undefined behaviour.";

// Mesh::__init__ (poly)
const char* PYMESH_INIT_POLY =
	"Creates a polygon mesh containing the data passed as input. At least a numpy array of "
	"vertices and a list of numpy arrays of face indices is required. Since MeshLab and PyMeshLab "
	"can store only triangle meshes, the newly created mesh is actually a triangle mesh with some "
	"edges that are marked as 'faux'. This constructor creates a custom per face scalar attribute "
	"called `poly_birth_faces` that stores, for each face of the newly created mesh, the index of "
	"the polygonal mesh that generated it.Color matrices have four columns (RGBA) and values are "
	"floats in the range [0-1]. Values outside this range will result in undefined behaviour.";

// Mesh::vertex_number
const char* PYMESH_VN = "Returns the number of vertices of the mesh.";

// Mesh::face_number
const char* PYMESH_FN = "Returns the number of faces of the mesh.";

// Mesh::edge_number
const char* PYMESH_EN = "Returns the number of edges of the mesh.";

// Mesh::texture_number
const char* PYMESH_TN = "Returns the number of textures contained in the mesh.";

// Mesh::id
const char* PYMESH_ID =
	"Returns the id of the mesh into a MeshSet. If the Mesh is not part of a MeshSet, the returned "
	"value is -1.";

// Mesh::is_visible
const char* PYMESH_IS_VISIBLE =
	"Returns a boolean indicating wether the mesh is marked as visible or not.";

// Mesh::label
const char* PYMESH_LABEL =
	"Returns a the label associated to the Mesh.";

// Mesh::texture
const char* PYMESH_TEXTURE =
	"Returns the texture of the Mesh at the given index.";

// Mesh::texture
const char* PYMESH_TEXTURE_FROM_NAME =
	"Returns the texture of the Mesh with the given name.";

// Mesh::is_compact
const char* PYMESH_IS_COMPACT = "Returns true if all its arrays are compact.";

// Mesh::is_point_cloud
const char* PYMESH_IS_POINT_CLOUD = "Returns true if the mesh has no faces (it is a point cloud)";

// Mesh::bounding_box
const char* PYMESH_BB = "Returns the bounding box of the mesh.";

// Mesh::transform_matrix
const char* PYMESH_TR_MATRIX = "Returns the 4x4 trasform matrix associated to the mesh.";

// Mesh::selected_vertex_number
const char* PYMESH_SEL_VN = "Returns the number of selected vertices of the mesh.";

// Mesh::selected_face_number
const char* PYMESH_SEL_FN = "Returns the number of selected faces of the mesh.";

// Mesh::textures
const char* PYMESH_TEXTURES =
	"Returns a dictionary with the texture names as keys and the texture images of the mesh as "
	"values.";

// Mesh::has_vertex_color
const char* PYMESH_HAS_VERTEX_COLOR =
	"Returns true if the mesh has the vertex color component, false otherwise.";

// Mesh::has_vertex_scalar
const char* PYMESH_HAS_VERTEX_SCALAR =
	"Returns true if the mesh has the vertex scalar component, false otherwise.";

// Mesh::has_vertex_color
const char* PYMESH_HAS_VERTEX_TEX_COORD =
	"Returns true if the mesh has the vertex texture coordinate component, false otherwise.";

// Mesh::has_vertex_color
const char* PYMESH_HAS_FACE_COLOR =
	"Returns true if the mesh has the face color component, false otherwise.";

// Mesh::has_vertex_scalar
const char* PYMESH_HAS_FACE_SCALAR =
	"Returns true if the mesh has the face scalar component, false otherwise.";

// Mesh::has_vertex_color
const char* PYMESH_HAS_WEDGE_TEX_COORD =
	"Returns true if the mesh has the wedge texture coordinate component, false otherwise.";

// Mesh::set_label
const char* PYMESH_SET_LABEL = "Sets the label associated to the mesh.";

// Mesh::update_bounding_box
const char* PYMESH_UPDATE_BB = "Updates the bounding box of the mesh.";

// Mesh::update_topology
const char* PYMESH_UPDATE_TOPO = "Updates the topology of the mesh.";

// Mesh::compact
const char* PYMESH_COMPACT = "Compacts all the arrays of the mesh.";

// Mesh::vertex_matrix
const char* PYMESH_VERT_MAT =
	"Returns the vertex matrix of the mesh as a numpy array, which is a #V*3 matrix of vertex "
	"coordinates. Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

// Mesh::transformed_vertex_matrix
const char* PYMESH_TR_VERT_MAT =
	"Returns the vertex matrix of the mesh as a numpy array, which is a #V*3 matrix of vertex "
	"coordinates. Coordinates are transformed w.r.t. the transformation matrix of the mesh. Raises "
	"a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

// Mesh::vertex_matrix
const char* PYMESH_EDGE_MAT =
	"Returns the edge matrix of the mesh as a numpy array, which is a #E*2 matrix of vertex "
	"indices. Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

// Mesh::face_matrix
const char* PYMESH_FACE_MAT =
	"Returns the face matrix of the mesh as a numpy array, whic is a #F*3 matrix of vertex "
	"indices. Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

// Mesh::face_matrix
const char* PYMESH_POLYGONAL_FACE_LIST =
	"Returns a list of numpy arrays. Each numpy array contains the vertex indices composing the "
	"ith polygonal face. Raises a :py:exc:`MissingCompactnessException` if the mesh is not "
	"compact.";

// Mesh::vertex_normal_matrix
const char* PYMESH_VERT_NORM_MAT =
	"Returns the vertex normal matrix of the mesh as a numpy array, which is a #V*3 matrix of "
	"vertex normals. Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

// Mesh::face_normal_matrix
const char* PYMESH_FACE_NORM_MAT =
	"Returns the face normal matrix of the mesh as a numpy array, which is a #F*3 matrix of face "
	"normals. Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact.";

// Mesh::vertex_color_matrix
const char* PYMESH_VERT_COLOR_MAT =
	"Returns the vertex color matrix as a numpy array, which is a #V*4 matrix of floats, each "
	"component (RGBA) is in the interval [0, 1]. Raises a :py:exc:`MissingCompactnessException` if "
	"the mesh is not compact.";

// Mesh::face_color_matrix
const char* PYMESH_FACE_COLOR_MAT =
	"Returns the face color matrix as a numpy array, which is a #V*4 matrix of floats, each "
	"component (RGBA) is in the interval [0, 1]. Raises a :py:exc:`MissingCompactnessException` if "
	"the mesh is not compact. Raises a :py:exc:`MissingComponentException` if the mesh has no face "
	"color component.";

// Mesh::vertex_color_array
const char* PYMESH_VERT_COLOR_ARRAY =
	"Returns the vertex color array as a numpy array, which is a #V array of unsigned integers, "
	"each value is the ARGB packed in a 32bit unsigned int (8 bits per component).Raises a "
	":py:exc:`MissingCompactnessException` if the mesh is not compact.";

// Mesh::face_color_array
const char* PYMESH_FACE_COLOR_ARRAY =
	"Returns the face color array as a numpy array, which is a #F array of unsigned integers, "
	"each value is the ARGB packed in a 32bit unsigned int (8 bits per component). Raises a "
	":py:exc:`MissingCompactnessException` if the mesh is not compact. Raises a "
	":py:exc:`MissingComponentException` if the mesh has no face color component.";

// Mesh::vertex_quality_matrix
const char* PYMESH_VERT_QUAL_ARRAY =
	"Returns the vertex scalar array of the mesh as a numpy array, which is a #V array of floats. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. Raises a "
	":py:exc:`MissingComponentException` if the mesh has no vertex quality component. ";

// Mesh::face_quality_matrix
const char* PYMESH_FACE_QUAL_ARRAY =
	"Returns the face scalar array of the mesh as a numpy array, which is a #F array of floats. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. Raises a "
	":py:exc:`MissingComponentException` if the mesh has no face quality component. ";

// Mesh::vertex_tex_matrix
const char* PYMESH_VERT_TEX_MAT =
	"Returns the vertex texcoord matrix of the mesh as a numpy array, which is a #V*2 matrix of "
	"uv texture coordinates. Raises a :py:exc:`MissingCompactnessException` if the mesh is not "
	"compact. Raises a :py:exc:`MissingComponentException` if the mesh has no per-wedge tex "
	"coordinates component. ";

// Mesh::wedge_tex_matrix
const char* PYMESH_WEDGE_TEX_MAT =
	"Returns the per-wedge texcoord matrix of the mesh as a numpy array, which is a #(F*3)*2 "
	"matrix of uv texture coordinates (triplets of wedges texcoords for each face). Raises a "
	":py:exc:`MissingCompactnessException` if the mesh is not compact. Raises a "
	":py:exc:`MissingComponentException` if the mesh has no vertex tex coordinates component. ";

// Mesh::vertex_selection_array
const char* PYMESH_VERT_SEL_ARRAY =
	"Returns the vertex selection array of the mesh as a numpy array, which is a #V array of "
	"booleans (true if the corresponding vertex is selected, false otherwise). Raises a "
	":py:exc:`MissingCompactnessException` if the mesh is not compact. ";

// Mesh::face_selection_array
const char* PYMESH_FACE_SEL_ARRAY =
	"Returns the face selection array of the mesh as a numpy array,which is a #F array of booleans "
	"(true if the corresponding face is selected, false otherwise). Raises a "
	":py:exc:`MissingCompactnessException` if the mesh is not compact. ";

// Mesh::vertex_curvature_principal_dir1_matrix
const char* PYMESH_VERT_CURV_PD1 =
	"Returns the vertex curvature - principal direction 1 matrix of the mesh as a numpy array. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`MissingComponentException` if the mesh has no vertex curvature component.";

// Mesh::vertex_curvature_principal_dir2_matrix
const char* PYMESH_VERT_CURV_PD2 =
	"Returns the vertex curvature - principal direction 2 matrix of the mesh as a numpy array. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`MissingComponentException` if the mesh has no vertex curvature component.";

// Mesh::face_curvature_principal_dir1_matrix
const char* PYMESH_FACE_CURV_PD1 =
	"Returns the face curvature - principal direction 1 matrix of the mesh as a numpy array. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`MissingComponentException` if the mesh has no face curvature component.";

// Mesh::face_curvature_principal_dir2_matrix
const char* PYMESH_FACE_CURV_PD2 =
	"Returns the face curvature - principal direction 2 matrix of the mesh as a numpy array. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`MissingComponentException` if the mesh has no face curvature component.";

// Mesh::face_face_adjacecncy
const char* PYMESH_FFADJ_MAT =
	"Returns face-to-face adjacency matrix of the mesh as a numpy array. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`MissingComponentException` if the mesh has no face-to-face "
	"adjacency component. ";

const char* PYMESH_VERT_CUSTOM_SCALAR_ATTR_ARRAY =
	"Returns a numpy array containing the scalar values of the given user defined "
	"attribute name associated to the vertices of the mesh. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`PyMeshLabException` if the given name does not "
	"represent a vertex scalar attribute in the mesh.";

const char* PYMESH_VERT_CUSTOM_POINT_ATTR_MATRIX =
	"Returns a numpy matrix containing the 3D point values of the given user defined "
	"attribute name associated to the vertices of the mesh. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`PyMeshLabException` if the given name does not "
	"represent a vertex vector attribute in the mesh.";

const char* PYMESH_FACE_CUSTOM_SCALAR_ATTR_ARRAY =
	"Returns a numpy array containing the scalar values of the given user defined "
	"attribute name associated to the faces of the mesh. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`PyMeshLabException` if the given name does not "
	"represent a face scalar attribute in the mesh.";

const char* PYMESH_FACE_CUSTOM_POINT_ATTR_MATRIX =
	"Returns a numpy matrix containing the 3D point values of the given user defined "
	"attribute name associated to the faces of the mesh. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`PyMeshLabException` if the given name does not "
	"represent a face vector attribute in the mesh.";

const char* PYMESH_ADD_VERT_CUSTOM_SCALAR_ATTR =
	"Adds a new user defined scalar attribute associated to the vertices of "
	"the mesh. Takes as input numpy array of scalar having the same size of "
	"the number of vertices of the mesh, and the name of the new attribute. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`PyMeshLabException` if the given array has a different "
	"size from the vertex number of the mesh, or if the mesh already contains "
	"a vertex scalar attribute with the given name.";

const char* PYMESH_ADD_FACE_CUSTOM_SCALAR_ATTR =
	"Adds a new user defined scalar attribute associated to the faces of "
	"the mesh. Takes as input numpy array of scalar having the same size of "
	"the number of faces of the mesh, and the name of the new attribute. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`PyMeshLabException` if the given array has a different "
	"size from the face number of the mesh, or if the mesh already contains "
	"a face scalar attribute with the given name.";

const char* PYMESH_ADD_VERT_CUSTOM_POINT_ATTR =
	"Adds a new user defined 3D point attribute associated to the vertices of "
	"the mesh. Takes as input numpy array of vectors having 3 columns and the "
	"number of rows equal to the number of vertices of the mesh, and the name of "
	"the new attribute. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`PyMeshLabException` if the given array has not the correct "
	"sizes, or if the mesh already contains a vertex vector attribute with the "
	"given name.";

const char* PYMESH_ADD_FACE_CUSTOM_POINT_ATTR =
	"Adds a new user defined 3D point attribute associated to the faces of "
	"the mesh. Takes as input numpy array of vectors having 3 columns and the "
	"number of rows equal to the number of faces of the mesh, and the name of "
	"the new attribute. "
	"Raises a :py:exc:`MissingCompactnessException` if the mesh is not compact. "
	"Raises a :py:exc:`PyMeshLabException` if the given array has not the correct "
	"sizes, or if the mesh already contains a face vector attribute with the "
	"given name.";
} // namespace doc
} // namespace pymeshlab

#endif // PYMESHLAB_PYMESH_DOC_H
