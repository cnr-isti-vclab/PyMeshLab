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
#ifndef PYMESHLAB_MESH_H
#define PYMESHLAB_MESH_H

#include <common/ml_document/cmesh.h>
#include <pybind11/eigen.h>
#include <Eigen/Core>

namespace pymeshlab {

class Mesh
{
public:
	//constructor:
	static CMeshO createFromMatrices(
			const Eigen::MatrixX3d& vertices = Eigen::MatrixX3d(),
			const Eigen::MatrixX3i& faces = Eigen::MatrixX3i(),
			const Eigen::MatrixX3d& vertexNormals = Eigen::MatrixX3d(),
			const Eigen::MatrixX3d& faceNormals = Eigen::MatrixX3d());

	static bool isCompact(const CMeshO& mesh);

	static Box3m boundingBox(const CMeshO& mesh);
	static void updateBBox(CMeshO& mesh);
	static void updateTopology(CMeshO& mesh);
	static void compact(CMeshO& mesh);
	static void compactVertices(CMeshO& mesh);
	static void compactFaces(CMeshO& mesh);

	static int selectedVertexNumber(const CMeshO& mesh);
	static int selectedFaceNumber(const CMeshO& mesh);

	static Eigen::MatrixXd vertexMatrix(const CMeshO& mesh);
	static Eigen::MatrixXi faceMatrix(const CMeshO& mesh);
	static Eigen::MatrixXd vertexNormalMatrix(const CMeshO& mesh);
	static Eigen::MatrixXd faceNormalMatrix(const CMeshO& mesh);
	static Eigen::VectorXd vertexQualityArray(const CMeshO& mesh);
	static Eigen::VectorXd faceQualityArray(const CMeshO& mesh);

	static Eigen::MatrixXd vertexTexCoordMatrix(const CMeshO& mesh);
	static Eigen::MatrixXi faceFaceAdjacency(const CMeshO& mesh);
	
	static Eigen::VectorXd vertexScalarAttributeArray(
			const CMeshO& mesh, 
			const std::string& attributeName);
	static Eigen::MatrixX3d vertexVectorAttributeMatrix(
			const CMeshO& mesh, 
			const std::string& attributeName);
	static Eigen::VectorXd faceScalarAttributeArray(
			const CMeshO& mesh, 
			const std::string& attributeName);
	static Eigen::MatrixX3d faceVectorAttributeMatrix(
			const CMeshO& mesh, 
			const std::string& attributeName);

private:
	Mesh();
};

}

#endif // PYMESHLAB_MESH_H
