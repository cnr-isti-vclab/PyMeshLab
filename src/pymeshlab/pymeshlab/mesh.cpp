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
#include "mesh.h"

#include <vcg/complex/algorithms/mesh_to_matrix.h>
#include <vcg/complex/allocate.h>
#include <vcg/../wrap/io_trimesh/import_obj.h>
#include <common/mlexception.h>
#include <common/utilities/eigen_mesh_conversions.h>

bool pymeshlab::Mesh::isCompact(const CMeshO& mesh)
{
	return
			mesh.vert.size() == (unsigned int)mesh.VN() &&
			mesh.face.size() == (unsigned int)mesh.FN() &&
			mesh.edge.size() == (unsigned int)mesh.EN();
}

Box3m pymeshlab::Mesh::boundingBox(const CMeshO& mesh)
{
	return mesh.bbox;
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

int pymeshlab::Mesh::selectedVertexNumber(const CMeshO& mesh)
{
	int counter = 0;
	for (unsigned int i = 0; i < mesh.vert.size(); i++){
		if (!mesh.vert[i].IsD() && mesh.vert[i].IsS()){
			counter++;
		}
	}
	return counter;
}

int pymeshlab::Mesh::selectedFaceNumber(const CMeshO& mesh)
{
	int counter = 0;
	for (unsigned int i = 0; i < mesh.face.size(); i++){
		if (!mesh.face[i].IsD() && mesh.face[i].IsS()){
			counter++;
		}
	}
	return counter;
}

Eigen::MatrixXi pymeshlab::Mesh::faceFaceAdjacency(const CMeshO& mesh)
{
	vcg::tri::RequireFaceCompactness(mesh);
	vcg::tri::RequireFFAdjacency(mesh);

	Eigen::MatrixXi faceFaceMatrix(mesh.FN(),3);

	for (int i = 0; i < mesh.FN(); i++) {
		for (int j = 0; j < 3; j++) {
			auto AdjF= mesh.face[i].cFFp(j);
			if (AdjF==&mesh.face[i]) {
				faceFaceMatrix(i,j)=-1;
			}
			else{
				faceFaceMatrix(i,j)=mesh.face[i].cFFi(j);
			}
		}
	}

	return faceFaceMatrix;
}

Eigen::VectorXd pymeshlab::Mesh::vertexScalarAttributeArray(
		const CMeshO& mesh,
		const std::string& attributeName)
{
	vcg::tri::RequireVertexCompactness(mesh);
	CMeshO::ConstPerVertexAttributeHandle<Scalarm> attributeHandle =
			vcg::tri::Allocator<CMeshO>::GetPerVertexAttribute<Scalarm>(mesh, attributeName);
	if (vcg::tri::Allocator<CMeshO>::IsValidHandle(mesh, attributeHandle)){
		Eigen::VectorXd attrVector(mesh.VN());
		for (unsigned int i = 0; i < (unsigned int) mesh.VN(); ++i){
			attrVector[i] = attributeHandle[i];
		}
		return attrVector;
	}
	else {
		throw MLException("No valid per vertex scalar attribute named " + 
						  QString::fromStdString(attributeName) + " was found.");
	}
}

Eigen::MatrixX3d pymeshlab::Mesh::vertexVectorAttributeMatrix(
		const CMeshO& mesh,
		const std::string& attributeName)
{
	vcg::tri::RequireVertexCompactness(mesh);
	CMeshO::ConstPerVertexAttributeHandle<Point3m> attributeHandle =
			vcg::tri::Allocator<CMeshO>::GetPerVertexAttribute<Point3m>(mesh, attributeName);
	if (vcg::tri::Allocator<CMeshO>::IsValidHandle(mesh, attributeHandle)){
		Eigen::MatrixX3d attrMatrix(mesh.VN(), 3);
		for (unsigned int i = 0; i < (unsigned int) mesh.VN(); ++i){
			attrMatrix(i,0) = attributeHandle[i][0];
			attrMatrix(i,1) = attributeHandle[i][1];
			attrMatrix(i,2) = attributeHandle[i][2];
		}
		return attrMatrix;
	}
	else {
		throw MLException("No valid per vertex vector attribute named " + 
						  QString::fromStdString(attributeName) + " was found.");
	}
}

Eigen::VectorXd pymeshlab::Mesh::faceScalarAttributeArray(
		const CMeshO& mesh, const 
		std::string& attributeName)
{
	vcg::tri::RequireFaceCompactness(mesh);
	CMeshO::ConstPerFaceAttributeHandle<Scalarm> attributeHandle =
			vcg::tri::Allocator<CMeshO>::GetPerFaceAttribute<Scalarm>(mesh, attributeName);
	if (vcg::tri::Allocator<CMeshO>::IsValidHandle(mesh, attributeHandle)){
		Eigen::VectorXd attrMatrix(mesh.FN());
		for (unsigned int i = 0; i < (unsigned int) mesh.FN(); ++i){
			attrMatrix[i] = attributeHandle[i];
		}
		return attrMatrix;
	}
	else {
		throw MLException("No valid per face scalar attribute named " + 
						  QString::fromStdString(attributeName) + " was found.");
	}
}

Eigen::MatrixX3d pymeshlab::Mesh::faceVectorAttributeMatrix(
		const CMeshO& mesh,
		const std::string& attributeName)
{
	vcg::tri::RequireFaceCompactness(mesh);
	CMeshO::ConstPerFaceAttributeHandle<Point3m> attributeHandle =
			vcg::tri::Allocator<CMeshO>::GetPerFaceAttribute<Point3m>(mesh, attributeName);
	if (vcg::tri::Allocator<CMeshO>::IsValidHandle(mesh, attributeHandle)){
		Eigen::MatrixX3d attrMatrix(mesh.FN(), 3);
		for (unsigned int i = 0; i < (unsigned int) mesh.FN(); ++i){
			attrMatrix(i,0) = attributeHandle[i][0];
			attrMatrix(i,1) = attributeHandle[i][1];
			attrMatrix(i,2) = attributeHandle[i][2];
		}
		return attrMatrix;
	}
	else {
		throw MLException("No valid per face vector attribute named " + 
						  QString::fromStdString(attributeName) + " was found.");
	}
}

pymeshlab::Mesh::Mesh()
{
}
