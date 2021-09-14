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
	py::class_<CMeshO> meshClass(m, "Mesh");

	auto compactnessexc =
		py::register_exception<vcg::MissingCompactnessException>(m, "MissingCompactnessException");
	auto componentexc =
		py::register_exception<vcg::MissingComponentException>(m, "MissingComponentException");
	compactnessexc.doc() = doc::PYEXC_COMPACTNESS;
	componentexc.doc()   = doc::PYEXC_COMPONENT;

	// constructor (could be empty)
	meshClass.def(
		py::init(&meshlab::meshFromMatrices),
		doc::PYMESH_INIT,
		py::arg("vertex_matrix")    = Eigen::MatrixX3d(),
		py::arg("face_matrix")      = Eigen::MatrixX3i(),
		py::arg("v_normals_matrix") = Eigen::MatrixX3d(),
		py::arg("f_normals_matrix") = Eigen::MatrixX3d(),
		py::arg("v_quality_array")  = Eigen::VectorXd(),
		py::arg("f_quality_array")  = Eigen::VectorXd(),
		py::arg("v_color_matrix")   = Eigen::MatrixX4d(),
		py::arg("f_color_matrix")   = Eigen::MatrixX4d());

	meshClass.def(
		py::init(&meshlab::polyMeshFromMatrices),
		doc::PYMESH_INIT_POLY,
		py::arg("vertex_matrix"),
		py::arg("face_list_of_indices"),
		py::arg("v_normals_matrix") = Eigen::MatrixX3d(),
		py::arg("f_normals_matrix") = Eigen::MatrixX3d(),
		py::arg("v_quality_array")  = Eigen::VectorXd(),
		py::arg("f_quality_array")  = Eigen::VectorXd(),
		py::arg("v_color_matrix")   = Eigen::MatrixX4d(),
		py::arg("f_color_matrix")   = Eigen::MatrixX4d());

	meshClass.def("vertex_number", &CMeshO::VN, doc::PYMESH_VN);
	meshClass.def("face_number", &CMeshO::FN, doc::PYMESH_FN);
	meshClass.def("edge_number", &CMeshO::EN, doc::PYMESH_EN);
	meshClass.def("is_compact", &Mesh::isCompact, doc::PYMESH_IS_COMPACT);
	meshClass.def("bounding_box", &Mesh::boundingBox, doc::PYMESH_BB);
	meshClass.def("selected_vertex_number", &Mesh::selectedVertexNumber, doc::PYMESH_SEL_VN);
	meshClass.def("selected_face_number", &Mesh::selectedFaceNumber, doc::PYMESH_SEL_FN);

	meshClass.def("update_bounding_box", &Mesh::updateBBox, doc::PYMESH_UPDATE_BB);
	meshClass.def("update_topology", &Mesh::updateTopology, doc::PYMESH_UPDATE_TOPO);
	meshClass.def("compact", &Mesh::compact, doc::PYMESH_COMPACT);

	meshClass.def("vertex_matrix", &meshlab::vertexMatrix, doc::PYMESH_VERT_MAT);
	meshClass.def("face_matrix", &meshlab::faceMatrix, doc::PYMESH_FACE_MAT);
	meshClass.def("vertex_normal_matrix", &meshlab::vertexNormalMatrix, doc::PYMESH_VERT_NORM_MAT);
	meshClass.def("face_normal_matrix", &meshlab::faceNormalMatrix, doc::PYMESH_FACE_NORM_MAT);
	meshClass.def("vertex_color_matrix", &meshlab::vertexColorMatrix, doc::PYMESH_VERT_COLOR_MAT);
	meshClass.def("vertex_color_array", &meshlab::vertexColorArray, doc::PYMESH_VERT_COLOR_ARRAY);
	meshClass.def("face_color_matrix", &meshlab::faceColorMatrix, doc::PYMESH_FACE_COLOR_MAT);
	meshClass.def("face_color_array", &meshlab::faceColorArray, doc::PYMESH_FACE_COLOR_ARRAY);
	meshClass.def(
		"vertex_quality_array", &meshlab::vertexQualityArray, doc::PYMESH_VERT_QUAL_ARRAY);
	meshClass.def("face_quality_array", &meshlab::faceQualityArray, doc::PYMESH_FACE_QUAL_ARRAY);
	meshClass.def(
		"vertex_tex_coord_matrix", &meshlab::vertexTexCoordMatrix, doc::PYMESH_VERT_TEX_MAT);
	meshClass.def(
		"wedge_tex_coord_matrix", &meshlab::wedgeTexCoordMatrix, doc::PYMESH_WEDGE_TEX_MAT);
	meshClass.def(
		"vertex_selection_array", &meshlab::vertexSelectionArray, doc::PYMESH_VERT_SEL_ARRAY);
	meshClass.def("face_selection_array", &meshlab::faceSelectionArray, doc::PYMESH_FACE_SEL_ARRAY);

	meshClass.def(
		"face_face_adjacency_matrix", &meshlab::faceFaceAdjacencyMatrix, doc::PYMESH_FFADJ_MAT);

	meshClass.def(
		"vertex_scalar_attribute_array",
		&meshlab::vertexScalarAttributeArray,
		doc::PYMESH_VERT_SCALAR_ATTR_ARRAY);
	meshClass.def(
		"vertex_vector_attribute_matrix",
		&meshlab::vertexVectorAttributeMatrix,
		doc::PYMESH_VERT_VECTOR_ATTR_MATRIX);
	meshClass.def(
		"face_scalar_attribute_array",
		&meshlab::faceScalarAttributeArray,
		doc::PYMESH_FACE_SCALAR_ATTR_ARRAY);
	meshClass.def(
		"face_vector_attribute_matrix",
		&meshlab::faceVectorAttributeMatrix,
		doc::PYMESH_FACE_VECTOR_ATTR_MATRIX);

	meshClass.def(
		"add_vertex_scalar_attribute",
		&meshlab::addVertexScalarAttribute,
		doc::PYMESH_ADD_VERT_SCALAR_ATTR,
		py::arg("attribute_values"),
		py::arg("attribute_name"));
	meshClass.def(
		"add_face_scalar_attribute",
		&meshlab::addFaceScalarAttribute,
		doc::PYMESH_ADD_FACE_SCALAR_ATTR,
		py::arg("attribute_values"),
		py::arg("attribute_name"));
	meshClass.def(
		"add_vertex_vector_attribute",
		&meshlab::addVertexVectorAttribute,
		doc::PYMESH_ADD_VERT_VECTOR_ATTR,
		py::arg("attribute_values"),
		py::arg("attribute_name"));
	meshClass.def(
		"add_face_vector_attribute",
		&meshlab::addFaceVectorAttribute,
		doc::PYMESH_ADD_FACE_VECTOR_ATTR,
		py::arg("attribute_values"),
		py::arg("attribute_name"));
}
