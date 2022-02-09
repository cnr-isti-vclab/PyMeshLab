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

MeshModel pymeshlab::Mesh::meshFromMatrices(
	const EigenMatrixX3m&   vertices,
	const Eigen::MatrixX3i& faces,
	const Eigen::MatrixX2i& edges,
	const EigenMatrixX3m&   vertexNormals,
	const EigenMatrixX3m&   faceNormals,
	const EigenVectorXm&    vertexQuality,
	const EigenVectorXm&    faceQuality,
	const EigenMatrixX4m&   vertexColor,
	const EigenMatrixX4m&   faceColor)
{
	MeshModel m(-1 ,"", "");
	m.cm = meshlab::meshFromMatrices(
		vertices,
		faces,
		edges,
		vertexNormals,
		faceNormals,
		vertexQuality,
		faceQuality,
		vertexColor,
		faceColor);
	m.updateBoxAndNormals();
	m.updateDataMask();
	return m;
}

MeshModel pymeshlab::Mesh::polyMeshFromMatrices(
	const EigenMatrixX3m&            vertices,
	const std::list<EigenVectorXui>& faces,
	const EigenMatrixX3m&            vertexNormals,
	const EigenMatrixX3m&            faceNormals,
	const EigenVectorXm&             vertexQuality,
	const EigenVectorXm&             faceQuality,
	const EigenMatrixX4m&            vertexColor,
	const EigenMatrixX4m&            faceColor)
{
	MeshModel m(-1 ,"", "");
	m.cm = meshlab::polyMeshFromMatrices(
		vertices,
		faces,
		vertexNormals,
		faceNormals,
		vertexQuality,
		faceQuality,
		vertexColor,
		faceColor);
	m.updateBoxAndNormals();
	m.updateDataMask();
	return m;
}

unsigned int pymeshlab::Mesh::vertexNumber(const MeshModel& m)
{
	return m.cm.VN();
}

unsigned int pymeshlab::Mesh::faceNumber(const MeshModel& m)
{
	return m.cm.FN();
}

unsigned int pymeshlab::Mesh::edgeNumber(const MeshModel& m)
{
	return m.cm.EN();
}

unsigned int pymeshlab::Mesh::textureNumber(const MeshModel& m)
{
	return m.cm.textures.size();
}

int pymeshlab::Mesh::id(const MeshModel& m)
{
	return m.id();
}

bool pymeshlab::Mesh::isVisible(const MeshModel& m)
{
	return m.isVisible();
}

std::string pymeshlab::Mesh::label(const MeshModel& m)
{
	return m.label().toStdString();
}

QImage pymeshlab::Mesh::texture(const MeshModel& m, unsigned int i)
{
	if (i >= textureNumber(m)){
		throw MLException("Mesh does not have texture with index " + QString::number(i));
	}
	return m.getTexture(m.cm.textures[i]);
}

QImage pymeshlab::Mesh::textureFromName(const MeshModel& m, const std::string& textName)
{
	auto it = m.getTextures().find(textName);
	if (it == m.getTextures().end()) {
		throw MLException("Mesh does not have texture with name " + QString::fromStdString(textName));
	}
	return it->second;
}

std::map<std::string, QImage> pymeshlab::Mesh::textures(const MeshModel& m)
{
	return m.getTextures();
}

bool pymeshlab::Mesh::isCompact(const MeshModel& mesh)
{
	return mesh.cm.vert.size() == (unsigned int) mesh.cm.VN() &&
		   mesh.cm.face.size() == (unsigned int) mesh.cm.FN() &&
		   mesh.cm.edge.size() == (unsigned int) mesh.cm.EN();
}

bool pymeshlab::Mesh::isPointCloud(const MeshModel& mesh)
{
	return mesh.cm.FN() == 0;
}

Box3m pymeshlab::Mesh::boundingBox(const MeshModel& mesh)
{
	return mesh.cm.bbox;
}

Eigen::Matrix4d pymeshlab::Mesh::transformMatrix(const MeshModel& mesh)
{
	return mesh.cm.Tr.ToEigenMatrix<Eigen::Matrix4d>();
}

int pymeshlab::Mesh::selectedVertexNumber(const MeshModel& mesh)
{
	int counter = 0;
	for (unsigned int i = 0; i < mesh.cm.vert.size(); i++) {
		if (!mesh.cm.vert[i].IsD() && mesh.cm.vert[i].IsS()) {
			counter++;
		}
	}
	return counter;
}

int pymeshlab::Mesh::selectedFaceNumber(const MeshModel& mesh)
{
	int counter = 0;
	for (unsigned int i = 0; i < mesh.cm.face.size(); i++) {
		if (!mesh.cm.face[i].IsD() && mesh.cm.face[i].IsS()) {
			counter++;
		}
	}
	return counter;
}

void pymeshlab::Mesh::setLabel(MeshModel& mesh, const std::string& newLabel)
{
	mesh.setLabel(QString::fromStdString(newLabel));
}

void pymeshlab::Mesh::updateBBox(MeshModel& mesh)
{
	vcg::tri::UpdateBounding<CMeshO>::Box(mesh.cm);
}

void pymeshlab::Mesh::updateTopology(MeshModel& mesh)
{
	vcg::tri::UpdateTopology<CMeshO>::FaceFace(mesh.cm);
	vcg::tri::UpdateTopology<CMeshO>::EdgeEdge(mesh.cm);
	vcg::tri::UpdateTopology<CMeshO>::VertexFace(mesh.cm);
	vcg::tri::UpdateTopology<CMeshO>::VertexEdge(mesh.cm);
}

void pymeshlab::Mesh::compact(MeshModel& mesh)
{
	vcg::tri::Allocator<CMeshO>::CompactEveryVector(mesh.cm);
}

void pymeshlab::Mesh::compactVertices(MeshModel& mesh)
{
	vcg::tri::Allocator<CMeshO>::CompactVertexVector(mesh.cm);
}

void pymeshlab::Mesh::compactFaces(MeshModel& mesh)
{
	vcg::tri::Allocator<CMeshO>::CompactFaceVector(mesh.cm);
}

EigenMatrixX3m pymeshlab::Mesh::vertexMatrix(const MeshModel& mesh)
{
	return meshlab::vertexMatrix(mesh.cm);
}

EigenMatrixX3m pymeshlab::Mesh::transformedVertexMatrix(const MeshModel &mesh)
{
	return meshlab::transformedVertexMatrix(mesh.cm);
}

Eigen::MatrixX3i pymeshlab::Mesh::faceMatrix(const MeshModel& mesh)
{
	return meshlab::faceMatrix(mesh.cm);
}

Eigen::MatrixX2i pymeshlab::Mesh::edgeMatrix(const MeshModel& mesh)
{
	return meshlab::edgeMatrix(mesh.cm);
}

std::list<EigenVectorXui> pymeshlab::Mesh::polygonalFaceList(const MeshModel& mesh)
{
	return meshlab::polygonalFaceList(mesh.cm);
}

EigenMatrixX3m pymeshlab::Mesh::vertexNormalMatrix(const MeshModel& mesh)
{
	return meshlab::vertexNormalMatrix(mesh.cm);
}

EigenMatrixX3m pymeshlab::Mesh::faceNormalMatrix(const MeshModel& mesh)
{
	return meshlab::faceNormalMatrix(mesh.cm);
}

EigenMatrixX4m pymeshlab::Mesh::vertexColorMatrix(const MeshModel& mesh)
{
	return meshlab::vertexColorMatrix(mesh.cm);
}

EigenMatrixX4m pymeshlab::Mesh::faceColorMatrix(const MeshModel& mesh)
{
	return meshlab::faceColorMatrix(mesh.cm);
}

EigenVectorXui pymeshlab::Mesh::vertexColorArray(const MeshModel& mesh)
{
	return meshlab::vertexColorArray(mesh.cm);
}

EigenVectorXui pymeshlab::Mesh::faceColorArray(const MeshModel& mesh)
{
	return meshlab::faceColorArray(mesh.cm);
}

EigenVectorXm pymeshlab::Mesh::vertexQualityArray(const MeshModel& mesh)
{
	return meshlab::vertexQualityArray(mesh.cm);
}

EigenVectorXm pymeshlab::Mesh::faceQualityArray(const MeshModel& mesh)
{
	return meshlab::faceQualityArray(mesh.cm);
}

EigenMatrixX2m pymeshlab::Mesh::vertexTexCoordMatrix(const MeshModel& mesh)
{
	return meshlab::vertexTexCoordMatrix(mesh.cm);
}

EigenMatrixX2m pymeshlab::Mesh::wedgeTexCoordMatrix(const MeshModel& mesh)
{
	return meshlab::wedgeTexCoordMatrix(mesh.cm);
}

EigenVectorXb pymeshlab::Mesh::vertexSelectionArray(const MeshModel& mesh)
{
	return meshlab::vertexSelectionArray(mesh.cm);
}

EigenVectorXb pymeshlab::Mesh::faceSelectionArray(const MeshModel& mesh)
{
	return meshlab::faceSelectionArray(mesh.cm);
}

EigenMatrixX3m pymeshlab::Mesh::vertexCurvaturePD1Matrix(const MeshModel& mesh)
{
	return meshlab::vertexCurvaturePD1Matrix(mesh.cm);
}

EigenMatrixX3m pymeshlab::Mesh::vertexCurvaturePD2Matrix(const MeshModel& mesh)
{
	return meshlab::vertexCurvaturePD2Matrix(mesh.cm);
}

EigenMatrixX3m pymeshlab::Mesh::faceCurvaturePD1Matrix(const MeshModel& mesh)
{
	return meshlab::faceCurvaturePD1Matrix(mesh.cm);
}

EigenMatrixX3m pymeshlab::Mesh::faceCurvaturePD2Matrix(const MeshModel& mesh)
{
	return meshlab::faceCurvaturePD2Matrix(mesh.cm);
}

Eigen::MatrixX3i pymeshlab::Mesh::faceFaceAdjacencyMatrix(const MeshModel& mesh)
{
	return meshlab::faceFaceAdjacencyMatrix(mesh.cm);
}

EigenVectorXm
pymeshlab::Mesh::vertexScalarAttributeArray(const MeshModel& mesh, const std::string& attributeName)
{
	return meshlab::vertexScalarAttributeArray(mesh.cm, attributeName);
}

EigenMatrixX3m
pymeshlab::Mesh::vertexVectorAttributeMatrix(const MeshModel& mesh, const std::string& attributeName)
{
	return meshlab::vertexVectorAttributeMatrix(mesh.cm, attributeName);
}

EigenVectorXm
pymeshlab::Mesh::faceScalarAttributeArray(const MeshModel& mesh, const std::string& attributeName)
{
	return meshlab::faceScalarAttributeArray(mesh.cm, attributeName);
}

EigenMatrixX3m
pymeshlab::Mesh::faceVectorAttributeMatrix(const MeshModel& mesh, const std::string& attributeName)
{
	return meshlab::faceVectorAttributeMatrix(mesh.cm, attributeName);
}

void pymeshlab::Mesh::addVertexScalarAttribute(
	MeshModel&              mesh,
	const EigenVectorXm& attributeValues,
	const std::string&   attributeName)
{
	return meshlab::addVertexScalarAttribute(mesh.cm, attributeValues, attributeName);
}

void pymeshlab::Mesh::addVertexVectorAttribute(
	MeshModel&               mesh,
	const EigenMatrixX3m& attributeValues,
	const std::string&    attributeName)
{
	return meshlab::addVertexVectorAttribute(mesh.cm, attributeValues, attributeName);
}

void pymeshlab::Mesh::addFaceScalarAttribute(
	MeshModel&              mesh,
	const EigenVectorXm& attributeValues,
	const std::string&   attributeName)
{
	return meshlab::addFaceScalarAttribute(mesh.cm, attributeValues, attributeName);
}

void pymeshlab::Mesh::addFaceVectorAttribute(
	MeshModel&               mesh,
	const EigenMatrixX3m& attributeValues,
	const std::string&    attributeName)
{
	return meshlab::addFaceVectorAttribute(mesh.cm, attributeValues, attributeName);
}

pymeshlab::Mesh::Mesh()
{
}
