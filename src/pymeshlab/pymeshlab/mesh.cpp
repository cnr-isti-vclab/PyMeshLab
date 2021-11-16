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
#include "mesh.h"

#include <common/mlexception.h>
#include <common/utilities/eigen_mesh_conversions.h>

CMeshO pymeshlab::Mesh::meshFromMatrices(
	const EigenMatrixX3m&   vertices,
	const Eigen::MatrixX3i& faces,
	const EigenMatrixX3m&   vertexNormals,
	const EigenMatrixX3m&   faceNormals,
	const EigenVectorXm&    vertexQuality,
	const EigenVectorXm&    faceQuality,
	const EigenMatrixX4m&   vertexColor,
	const EigenMatrixX4m&   faceColor)
{
	return meshlab::meshFromMatrices(
		vertices,
		faces,
		vertexNormals,
		faceNormals,
		vertexQuality,
		faceQuality,
		vertexColor,
		faceColor);
}

CMeshO pymeshlab::Mesh::polyMeshFromMatrices(
	const EigenMatrixX3m&            vertices,
	const std::list<EigenVectorXui>& faces,
	const EigenMatrixX3m&            vertexNormals,
	const EigenMatrixX3m&            faceNormals,
	const EigenVectorXm&             vertexQuality,
	const EigenVectorXm&             faceQuality,
	const EigenMatrixX4m&            vertexColor,
	const EigenMatrixX4m&            faceColor)
{
	return meshlab::polyMeshFromMatrices(
		vertices,
		faces,
		vertexNormals,
		faceNormals,
		vertexQuality,
		faceQuality,
		vertexColor,
		faceColor);
}

unsigned int pymeshlab::Mesh::vertexNumber(const CMeshO& m)
{
	return m.VN();
}

unsigned int pymeshlab::Mesh::faceNumber(const CMeshO& m)
{
	return m.FN();
}

unsigned int pymeshlab::Mesh::edgeNumber(const CMeshO& m)
{
	return m.EN();
}

bool pymeshlab::Mesh::isCompact(const CMeshO& mesh)
{
	return mesh.vert.size() == (unsigned int) mesh.VN() &&
		   mesh.face.size() == (unsigned int) mesh.FN() &&
		   mesh.edge.size() == (unsigned int) mesh.EN();
}

Box3m pymeshlab::Mesh::boundingBox(const CMeshO& mesh)
{
	return mesh.bbox;
}

int pymeshlab::Mesh::selectedVertexNumber(const CMeshO& mesh)
{
	int counter = 0;
	for (unsigned int i = 0; i < mesh.vert.size(); i++) {
		if (!mesh.vert[i].IsD() && mesh.vert[i].IsS()) {
			counter++;
		}
	}
	return counter;
}

int pymeshlab::Mesh::selectedFaceNumber(const CMeshO& mesh)
{
	int counter = 0;
	for (unsigned int i = 0; i < mesh.face.size(); i++) {
		if (!mesh.face[i].IsD() && mesh.face[i].IsS()) {
			counter++;
		}
	}
	return counter;
}

void pymeshlab::Mesh::updateBBox(CMeshO& mesh)
{
	vcg::tri::UpdateBounding<CMeshO>::Box(mesh);
}

void pymeshlab::Mesh::updateTopology(CMeshO& mesh)
{
	vcg::tri::UpdateTopology<CMeshO>::FaceFace(mesh);
	vcg::tri::UpdateTopology<CMeshO>::EdgeEdge(mesh);
	vcg::tri::UpdateTopology<CMeshO>::VertexFace(mesh);
	vcg::tri::UpdateTopology<CMeshO>::VertexEdge(mesh);
}

void pymeshlab::Mesh::compact(CMeshO& mesh)
{
	vcg::tri::Allocator<CMeshO>::CompactEveryVector(mesh);
}

void pymeshlab::Mesh::compactVertices(CMeshO& mesh)
{
	vcg::tri::Allocator<CMeshO>::CompactVertexVector(mesh);
}

void pymeshlab::Mesh::compactFaces(CMeshO& mesh)
{
	vcg::tri::Allocator<CMeshO>::CompactFaceVector(mesh);
}

EigenMatrixX3m pymeshlab::Mesh::vertexMatrix(const CMeshO& mesh)
{
	return meshlab::vertexMatrix(mesh);
}

Eigen::MatrixX3i pymeshlab::Mesh::faceMatrix(const CMeshO& mesh)
{
	return meshlab::faceMatrix(mesh);
}

Eigen::MatrixX2i pymeshlab::Mesh::edgeMatrix(const CMeshO& mesh)
{
	return meshlab::edgeMatrix(mesh);
}

std::list<EigenVectorXui> pymeshlab::Mesh::polygonalFaceList(const CMeshO& mesh)
{
	return meshlab::polygonalFaceList(mesh);
}

EigenMatrixX3m pymeshlab::Mesh::vertexNormalMatrix(const CMeshO& mesh)
{
	return meshlab::vertexNormalMatrix(mesh);
}

EigenMatrixX3m pymeshlab::Mesh::faceNormalMatrix(const CMeshO& mesh)
{
	return meshlab::faceNormalMatrix(mesh);
}

EigenMatrixX4m pymeshlab::Mesh::vertexColorMatrix(const CMeshO& mesh)
{
	return meshlab::vertexColorMatrix(mesh);
}

EigenMatrixX4m pymeshlab::Mesh::faceColorMatrix(const CMeshO& mesh)
{
	return meshlab::faceColorMatrix(mesh);
}

EigenVectorXui pymeshlab::Mesh::vertexColorArray(const CMeshO& mesh)
{
	return meshlab::vertexColorArray(mesh);
}

EigenVectorXui pymeshlab::Mesh::faceColorArray(const CMeshO& mesh)
{
	return meshlab::faceColorArray(mesh);
}

EigenVectorXm pymeshlab::Mesh::vertexQualityArray(const CMeshO& mesh)
{
	return meshlab::vertexQualityArray(mesh);
}

EigenVectorXm pymeshlab::Mesh::faceQualityArray(const CMeshO& mesh)
{
	return meshlab::faceQualityArray(mesh);
}

EigenMatrixX2m pymeshlab::Mesh::vertexTexCoordMatrix(const CMeshO& mesh)
{
	return meshlab::vertexTexCoordMatrix(mesh);
}

EigenMatrixX2m pymeshlab::Mesh::wedgeTexCoordMatrix(const CMeshO& mesh)
{
	return meshlab::wedgeTexCoordMatrix(mesh);
}

EigenVectorXb pymeshlab::Mesh::vertexSelectionArray(const CMeshO& mesh)
{
	return meshlab::vertexSelectionArray(mesh);
}

EigenVectorXb pymeshlab::Mesh::faceSelectionArray(const CMeshO& mesh)
{
	return meshlab::faceSelectionArray(mesh);
}

EigenMatrixX3m pymeshlab::Mesh::vertexCurvaturePD1Matrix(const CMeshO& mesh)
{
	return meshlab::vertexCurvaturePD1Matrix(mesh);
}

EigenMatrixX3m pymeshlab::Mesh::vertexCurvaturePD2Matrix(const CMeshO& mesh)
{
	return meshlab::vertexCurvaturePD2Matrix(mesh);
}

EigenMatrixX3m pymeshlab::Mesh::faceCurvaturePD1Matrix(const CMeshO& mesh)
{
	return meshlab::faceCurvaturePD1Matrix(mesh);
}

EigenMatrixX3m pymeshlab::Mesh::faceCurvaturePD2Matrix(const CMeshO& mesh)
{
	return meshlab::faceCurvaturePD2Matrix(mesh);
}

Eigen::MatrixX3i pymeshlab::Mesh::faceFaceAdjacencyMatrix(const CMeshO& mesh)
{
	return meshlab::faceFaceAdjacencyMatrix(mesh);
}

EigenVectorXm
pymeshlab::Mesh::vertexScalarAttributeArray(const CMeshO& mesh, const std::string& attributeName)
{
	return meshlab::vertexScalarAttributeArray(mesh, attributeName);
}

EigenMatrixX3m
pymeshlab::Mesh::vertexVectorAttributeMatrix(const CMeshO& mesh, const std::string& attributeName)
{
	return meshlab::vertexVectorAttributeMatrix(mesh, attributeName);
}

EigenVectorXm
pymeshlab::Mesh::faceScalarAttributeArray(const CMeshO& mesh, const std::string& attributeName)
{
	return meshlab::faceScalarAttributeArray(mesh, attributeName);
}

EigenMatrixX3m
pymeshlab::Mesh::faceVectorAttributeMatrix(const CMeshO& mesh, const std::string& attributeName)
{
	return meshlab::faceVectorAttributeMatrix(mesh, attributeName);
}

void pymeshlab::Mesh::addVertexScalarAttribute(
	CMeshO&              mesh,
	const EigenVectorXm& attributeValues,
	const std::string&   attributeName)
{
	return meshlab::addVertexScalarAttribute(mesh, attributeValues, attributeName);
}

void pymeshlab::Mesh::addVertexVectorAttribute(
	CMeshO&               mesh,
	const EigenMatrixX3m& attributeValues,
	const std::string&    attributeName)
{
	return meshlab::addVertexVectorAttribute(mesh, attributeValues, attributeName);
}

void pymeshlab::Mesh::addFaceScalarAttribute(
	CMeshO&              mesh,
	const EigenVectorXm& attributeValues,
	const std::string&   attributeName)
{
	return meshlab::addFaceScalarAttribute(mesh, attributeValues, attributeName);
}

void pymeshlab::Mesh::addFaceVectorAttribute(
	CMeshO&               mesh,
	const EigenMatrixX3m& attributeValues,
	const std::string&    attributeName)
{
	return meshlab::addFaceVectorAttribute(mesh, attributeValues, attributeName);
}

pymeshlab::Mesh::Mesh()
{
}
