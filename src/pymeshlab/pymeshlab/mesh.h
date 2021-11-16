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

#include <Eigen/Core>
#include <common/ml_document/cmesh.h>
#include <common/utilities/eigen_mesh_conversions.h>
#include <pybind11/eigen.h>

namespace pymeshlab {

class Mesh
{
public:
	static CMeshO meshFromMatrices(
		const EigenMatrixX3m&   vertices,
		const Eigen::MatrixX3i& faces         = Eigen::MatrixX3i(),
		const EigenMatrixX3m&   vertexNormals = EigenMatrixX3m(),
		const EigenMatrixX3m&   faceNormals   = EigenMatrixX3m(),
		const EigenVectorXm&    vertexQuality = EigenVectorXm(),
		const EigenVectorXm&    faceQuality   = EigenVectorXm(),
		const EigenMatrixX4m&   vertexColor   = EigenMatrixX4m(),
		const EigenMatrixX4m&   faceColor     = EigenMatrixX4m());

	static CMeshO polyMeshFromMatrices(
		const EigenMatrixX3m&            vertices,
		const std::list<EigenVectorXui>& faces,
		const EigenMatrixX3m&            vertexNormals = EigenMatrixX3m(),
		const EigenMatrixX3m&            faceNormals   = EigenMatrixX3m(),
		const EigenVectorXm&             vertexQuality = EigenVectorXm(),
		const EigenVectorXm&             faceQuality   = EigenVectorXm(),
		const EigenMatrixX4m&            vertexColor   = EigenMatrixX4m(),
		const EigenMatrixX4m&            faceColor     = EigenMatrixX4m());

	static bool isCompact(const CMeshO& mesh);

	static Box3m boundingBox(const CMeshO& mesh);

	static void updateBBox(CMeshO& mesh);
	static void updateTopology(CMeshO& mesh);
	static void compact(CMeshO& mesh);
	static void compactVertices(CMeshO& mesh);
	static void compactFaces(CMeshO& mesh);

	static int selectedVertexNumber(const CMeshO& mesh);
	static int selectedFaceNumber(const CMeshO& mesh);

private:
	Mesh();
};

} // namespace pymeshlab

#endif // PYMESHLAB_MESH_H
