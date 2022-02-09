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
#ifndef PYMESHLAB_MESH_H
#define PYMESHLAB_MESH_H

#include <pybind11/eigen.h> // needs to be included before anything else
#include <pybind11/stl.h>

#include <Eigen/Core>
#include <common/ml_document/mesh_model.h>
#include <common/utilities/eigen_mesh_conversions.h>

namespace pymeshlab {

class Mesh
{
public:
	static MeshModel meshFromMatrices(
		const EigenMatrixX3m&   vertices,
		const Eigen::MatrixX3i& faces         = Eigen::MatrixX3i(),
		const Eigen::MatrixX2i& edges         = Eigen::MatrixX2i(),
		const EigenMatrixX3m&   vertexNormals = EigenMatrixX3m(),
		const EigenMatrixX3m&   faceNormals   = EigenMatrixX3m(),
		const EigenVectorXm&    vertexQuality = EigenVectorXm(),
		const EigenVectorXm&    faceQuality   = EigenVectorXm(),
		const EigenMatrixX4m&   vertexColor   = EigenMatrixX4m(),
		const EigenMatrixX4m&   faceColor     = EigenMatrixX4m());

	static MeshModel polyMeshFromMatrices(
		const EigenMatrixX3m&            vertices,
		const std::list<EigenVectorXui>& faces,
		const EigenMatrixX3m&            vertexNormals = EigenMatrixX3m(),
		const EigenMatrixX3m&            faceNormals   = EigenMatrixX3m(),
		const EigenVectorXm&             vertexQuality = EigenVectorXm(),
		const EigenVectorXm&             faceQuality   = EigenVectorXm(),
		const EigenMatrixX4m&            vertexColor   = EigenMatrixX4m(),
		const EigenMatrixX4m&            faceColor     = EigenMatrixX4m());

	static unsigned int vertexNumber(const MeshModel& m);
	static unsigned int faceNumber(const MeshModel& m);
	static unsigned int edgeNumber(const MeshModel& m);
	static unsigned int textureNumber(const MeshModel& m);

	static int id(const MeshModel& m);
	static bool isVisible(const MeshModel& m);
	static std::string label(const MeshModel& m);
	static QImage texture(const MeshModel& m, unsigned int i);
	static QImage textureFromName(const MeshModel& m, const std::string& textName);
	static std::map<std::string, QImage> textures(const MeshModel& m);

	static bool isCompact(const MeshModel& mesh);
	static bool isPointCloud(const MeshModel& mesh);
	static Box3m boundingBox(const MeshModel& mesh);
	static Eigen::Matrix4d transformMatrix(const MeshModel& mesh);

	static int selectedVertexNumber(const MeshModel& mesh);
	static int selectedFaceNumber(const MeshModel& mesh);

	static void setLabel(MeshModel& mesh, const std::string& newLabel);
	static void updateBBox(MeshModel& mesh);
	static void updateTopology(MeshModel& mesh);
	static void compact(MeshModel& mesh);
	static void compactVertices(MeshModel& mesh);
	static void compactFaces(MeshModel& mesh);

	static EigenMatrixX3m            vertexMatrix(const MeshModel& mesh);
	static EigenMatrixX3m            transformedVertexMatrix(const MeshModel& mesh);
	static Eigen::MatrixX3i          faceMatrix(const MeshModel& mesh);
	static Eigen::MatrixX2i          edgeMatrix(const MeshModel& mesh);
	static std::list<EigenVectorXui> polygonalFaceList(const MeshModel& mesh);

	static EigenMatrixX3m vertexNormalMatrix(const MeshModel& mesh);
	static EigenMatrixX3m faceNormalMatrix(const MeshModel& mesh);

	static EigenMatrixX4m vertexColorMatrix(const MeshModel& mesh);
	static EigenMatrixX4m faceColorMatrix(const MeshModel& mesh);
	static EigenVectorXui vertexColorArray(const MeshModel& mesh);
	static EigenVectorXui faceColorArray(const MeshModel& mesh);

	static EigenVectorXm vertexQualityArray(const MeshModel& mesh);
	static EigenVectorXm faceQualityArray(const MeshModel& mesh);

	static EigenMatrixX2m vertexTexCoordMatrix(const MeshModel& mesh);
	static EigenMatrixX2m wedgeTexCoordMatrix(const MeshModel& mesh);

	static EigenVectorXb vertexSelectionArray(const MeshModel& mesh);
	static EigenVectorXb faceSelectionArray(const MeshModel& mesh);

	static EigenMatrixX3m vertexCurvaturePD1Matrix(const MeshModel& mesh);
	static EigenMatrixX3m vertexCurvaturePD2Matrix(const MeshModel& mesh);
	static EigenMatrixX3m faceCurvaturePD1Matrix(const MeshModel& mesh);
	static EigenMatrixX3m faceCurvaturePD2Matrix(const MeshModel& mesh);

	static Eigen::MatrixX3i faceFaceAdjacencyMatrix(const MeshModel& mesh);

	static EigenVectorXm
	vertexScalarAttributeArray(const MeshModel& mesh, const std::string& attributeName);
	static EigenMatrixX3m
	vertexVectorAttributeMatrix(const MeshModel& mesh, const std::string& attributeName);
	static EigenVectorXm
	faceScalarAttributeArray(const MeshModel& mesh, const std::string& attributeName);
	static EigenMatrixX3m
	faceVectorAttributeMatrix(const MeshModel& mesh, const std::string& attributeName);

	static void addVertexScalarAttribute(
		MeshModel&           mesh,
		const EigenVectorXm& attributeValues,
		const std::string&   attributeName);

	static void addVertexVectorAttribute(
		MeshModel&            mesh,
		const EigenMatrixX3m& attributeValues,
		const std::string&    attributeName);

	static void addFaceScalarAttribute(
		MeshModel&           mesh,
		const EigenVectorXm& attributeValues,
		const std::string&   attributeName);

	static void addFaceVectorAttribute(
		MeshModel&            mesh,
		const EigenMatrixX3m& attributeValues,
		const std::string&    attributeName);

private:
	Mesh();
};

} // namespace pymeshlab

#endif // PYMESHLAB_MESH_H
