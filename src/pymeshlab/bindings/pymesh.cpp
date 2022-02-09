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
#include "pymesh.h"
#include "docs/pymesh_doc.h"
#include "pymeshlab/mesh.h"
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <common/utilities/eigen_mesh_conversions.h>

namespace py = pybind11;

void pymeshlab::initMesh(py::module& m)
{
	py::class_<MeshModel> meshClass(m, "Mesh");

	auto compactnessexc =
		py::register_exception<vcg::MissingCompactnessException>(m, "MissingCompactnessException");
	auto componentexc =
		py::register_exception<vcg::MissingComponentException>(m, "MissingComponentException");
	compactnessexc.doc() = doc::PYEXC_COMPACTNESS;
	componentexc.doc()   = doc::PYEXC_COMPONENT;

	// constructor (could be empty)
	meshClass.def(
		py::init(&Mesh::meshFromMatrices),
		doc::PYMESH_INIT,
		py::arg("vertex_matrix")    = Eigen::MatrixX3d(),
		py::arg("face_matrix")      = Eigen::MatrixX3i(),
		py::arg("edge_matrix")      = Eigen::MatrixX2i(),
		py::arg("v_normals_matrix") = Eigen::MatrixX3d(),
		py::arg("f_normals_matrix") = Eigen::MatrixX3d(),
		py::arg("v_scalar_array")   = Eigen::VectorXd(),
		py::arg("f_scalar_array")   = Eigen::VectorXd(),
		py::arg("v_color_matrix")   = Eigen::MatrixX4d(),
		py::arg("f_color_matrix")   = Eigen::MatrixX4d());

	meshClass.def(
		py::init(&Mesh::polyMeshFromMatrices),
		doc::PYMESH_INIT_POLY,
		py::arg("vertex_matrix"),
		py::arg("face_list_of_indices"),
		py::arg("v_normals_matrix") = Eigen::MatrixX3d(),
		py::arg("f_normals_matrix") = Eigen::MatrixX3d(),
		py::arg("v_scalar_array")  = Eigen::VectorXd(),
		py::arg("f_scalar_array")  = Eigen::VectorXd(),
		py::arg("v_color_matrix")   = Eigen::MatrixX4d(),
		py::arg("f_color_matrix")   = Eigen::MatrixX4d());

	meshClass.def("vertex_number", &Mesh::vertexNumber, doc::PYMESH_VN);
	meshClass.def("face_number", &Mesh::faceNumber, doc::PYMESH_FN);
	meshClass.def("edge_number", &Mesh::edgeNumber, doc::PYMESH_EN);
	meshClass.def("texture_number", &Mesh::textureNumber, doc::PYMESH_TN);

	meshClass.def("id", &Mesh::id, doc::PYMESH_ID);
	meshClass.def("is_visible", &Mesh::isVisible, doc::PYMESH_IS_VISIBLE);
	meshClass.def("label", &Mesh::label, doc::PYMESH_LABEL);
	meshClass.def("texture", &Mesh::texture, doc::PYMESH_TEXTURE);
	meshClass.def("texture", &Mesh::textureFromName, doc::PYMESH_TEXTURE_FROM_NAME);
	meshClass.def("textures", &Mesh::textures, doc::PYMESH_TEXTURES);

	meshClass.def("has_vertex_color", &MeshModel::hasPerVertexColor, doc::PYMESH_HAS_VERTEX_COLOR);
	meshClass.def(
		"has_vertex_scalar", &MeshModel::hasPerVertexQuality, doc::PYMESH_HAS_VERTEX_SCALAR);
	meshClass.def(
		"has_vertex_tex_coord", &MeshModel::hasPerVertexTexCoord, doc::PYMESH_HAS_VERTEX_TEX_COORD);
	meshClass.def("has_face_color", &MeshModel::hasPerFaceColor, doc::PYMESH_HAS_FACE_COLOR);
	meshClass.def("has_face_scalar", &MeshModel::hasPerFaceQuality, doc::PYMESH_HAS_FACE_SCALAR);
	meshClass.def(
		"has_wedge_tex_coord",
		&MeshModel::hasPerFaceWedgeTexCoords,
		doc::PYMESH_HAS_WEDGE_TEX_COORD);

	meshClass.def("is_compact", &Mesh::isCompact, doc::PYMESH_IS_COMPACT);
	meshClass.def("is_point_cloud", &Mesh::isPointCloud, doc::PYMESH_IS_POINT_CLOUD);
	meshClass.def("bounding_box", &Mesh::boundingBox, doc::PYMESH_BB);
	meshClass.def("trasform_matrix", &Mesh::transformMatrix, doc::PYMESH_TR_MATRIX);
	meshClass.def("selected_vertex_number", &Mesh::selectedVertexNumber, doc::PYMESH_SEL_VN);
	meshClass.def("selected_face_number", &Mesh::selectedFaceNumber, doc::PYMESH_SEL_FN);

	meshClass.def("set_label", &Mesh::setLabel, doc::PYMESH_SET_LABEL);
	meshClass.def("update_bounding_box", &Mesh::updateBBox, doc::PYMESH_UPDATE_BB);
	meshClass.def("update_topology", &Mesh::updateTopology, doc::PYMESH_UPDATE_TOPO);
	meshClass.def("compact", &Mesh::compact, doc::PYMESH_COMPACT);

	meshClass.def("vertex_matrix", &Mesh::vertexMatrix, doc::PYMESH_VERT_MAT);
	meshClass.def(
		"transformed_vertex_matrix", &Mesh::transformedVertexMatrix, doc::PYMESH_TR_VERT_MAT);
	meshClass.def("edge_matrix", &Mesh::edgeMatrix, doc::PYMESH_EDGE_MAT);
	meshClass.def("face_matrix", &Mesh::faceMatrix, doc::PYMESH_FACE_MAT);
	meshClass.def("polygonal_face_list", &Mesh::polygonalFaceList, doc::PYMESH_POLYGONAL_FACE_LIST);
	meshClass.def("vertex_normal_matrix", &Mesh::vertexNormalMatrix, doc::PYMESH_VERT_NORM_MAT);
	meshClass.def("face_normal_matrix", &Mesh::faceNormalMatrix, doc::PYMESH_FACE_NORM_MAT);
	meshClass.def("vertex_color_matrix", &Mesh::vertexColorMatrix, doc::PYMESH_VERT_COLOR_MAT);
	meshClass.def("vertex_color_array", &Mesh::vertexColorArray, doc::PYMESH_VERT_COLOR_ARRAY);
	meshClass.def("face_color_matrix", &Mesh::faceColorMatrix, doc::PYMESH_FACE_COLOR_MAT);
	meshClass.def("face_color_array", &Mesh::faceColorArray, doc::PYMESH_FACE_COLOR_ARRAY);
	meshClass.def(
		"vertex_scalar_array", &Mesh::vertexQualityArray, doc::PYMESH_VERT_QUAL_ARRAY);
	meshClass.def("face_scalar_array", &Mesh::faceQualityArray, doc::PYMESH_FACE_QUAL_ARRAY);
	meshClass.def(
		"vertex_tex_coord_matrix", &Mesh::vertexTexCoordMatrix, doc::PYMESH_VERT_TEX_MAT);
	meshClass.def(
		"wedge_tex_coord_matrix", &Mesh::wedgeTexCoordMatrix, doc::PYMESH_WEDGE_TEX_MAT);
	meshClass.def(
		"vertex_selection_array", &Mesh::vertexSelectionArray, doc::PYMESH_VERT_SEL_ARRAY);
	meshClass.def("face_selection_array", &Mesh::faceSelectionArray, doc::PYMESH_FACE_SEL_ARRAY);
	meshClass.def(
		"vertex_curvature_principal_dir1_matrix",
		&Mesh::vertexCurvaturePD1Matrix,
		doc::PYMESH_VERT_CURV_PD1);
	meshClass.def(
		"vertex_curvature_principal_dir2_matrix",
		&Mesh::vertexCurvaturePD2Matrix,
		doc::PYMESH_VERT_CURV_PD2);
	meshClass.def(
		"face_curvature_principal_dir1_matrix",
		&Mesh::faceCurvaturePD1Matrix,
		doc::PYMESH_FACE_CURV_PD1);
	meshClass.def(
		"face_curvature_principal_dir2_matrix",
		&Mesh::faceCurvaturePD2Matrix,
		doc::PYMESH_FACE_CURV_PD2);

	meshClass.def(
		"face_face_adjacency_matrix", &Mesh::faceFaceAdjacencyMatrix, doc::PYMESH_FFADJ_MAT);

	meshClass.def(
		"vertex_custom_scalar_attribute_array",
		&Mesh::vertexScalarAttributeArray,
		doc::PYMESH_VERT_CUSTOM_SCALAR_ATTR_ARRAY);
	meshClass.def(
		"vertex_custom_point_attribute_matrix",
		&Mesh::vertexVectorAttributeMatrix,
		doc::PYMESH_VERT_CUSTOM_POINT_ATTR_MATRIX);
	meshClass.def(
		"face_custom_scalar_attribute_array",
		&Mesh::faceScalarAttributeArray,
		doc::PYMESH_FACE_CUSTOM_SCALAR_ATTR_ARRAY);
	meshClass.def(
		"face_custom_point_attribute_matrix",
		&Mesh::faceVectorAttributeMatrix,
		doc::PYMESH_FACE_CUSTOM_POINT_ATTR_MATRIX);

	meshClass.def(
		"add_vertex_custom_scalar_attribute",
		&Mesh::addVertexScalarAttribute,
		doc::PYMESH_ADD_VERT_CUSTOM_SCALAR_ATTR,
		py::arg("attribute_values"),
		py::arg("attribute_name"));
	meshClass.def(
		"add_face_custom_scalar_attribute",
		&Mesh::addFaceScalarAttribute,
		doc::PYMESH_ADD_FACE_CUSTOM_SCALAR_ATTR,
		py::arg("attribute_values"),
		py::arg("attribute_name"));
	meshClass.def(
		"add_vertex_custom_point_attribute",
		&Mesh::addVertexVectorAttribute,
		doc::PYMESH_ADD_VERT_CUSTOM_POINT_ATTR,
		py::arg("attribute_values"),
		py::arg("attribute_name"));
	meshClass.def(
		"add_face_custom_point_attribute",
		&Mesh::addFaceVectorAttribute,
		doc::PYMESH_ADD_FACE_CUSTOM_POINT_ATTR,
		py::arg("attribute_values"),
		py::arg("attribute_name"));
}
