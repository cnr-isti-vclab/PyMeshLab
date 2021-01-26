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

void loadMesh(CMeshO& m, std::string filename)
{
	vcg::tri::io::ImporterOBJ<CMeshO>::Info oi;
	vcg::tri::io::ImporterOBJ<CMeshO>::Open(m, filename.c_str(), oi);
	vcg::tri::UpdateBounding<CMeshO>::Box(m);
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
	for (int i = 0; i < mesh.VN(); i++){
		if (!mesh.vert[i].IsD() && mesh.vert[i].IsS())
			counter++;
	}
	return counter;
}

int pymeshlab::Mesh::selectedFaceNumber(const CMeshO& mesh)
{
	int counter = 0;
	for (int i = 0; i < mesh.FN(); i++){
		if (!mesh.face[i].IsD() && mesh.face[i].IsS())
			counter++;
	}
	return counter;
}

CMeshO pymeshlab::Mesh::createFromMatrices(
		const Eigen::MatrixX3d& vertices,
		const Eigen::MatrixX3i& faces,
		const Eigen::MatrixX3d& vertexNormals,
		const Eigen::MatrixX3d& faceNormals)
{
	CMeshO m;
	if (vertices.rows() > 0) {
		CMeshO::VertexIterator vi =
				vcg::tri::Allocator<CMeshO>::AddVertices(m, vertices.rows());
		std::vector<CMeshO::VertexPointer> ivp(vertices.rows());

		bool hasVNormals = vertexNormals.rows() == vertices.rows();
		for (unsigned int i = 0; i < vertices.rows(); ++i, ++vi) {
			ivp[i] = &*vi;
			vi->P() = CMeshO::CoordType(vertices(i,0), vertices(i,1), vertices(i,2));
			if (hasVNormals) {
				vi->N() = CMeshO::CoordType(
							vertexNormals(i,0),
							vertexNormals(i,1),
							vertexNormals(i,2));
			}
		}

		CMeshO::FaceIterator fi =
				vcg::tri::Allocator<CMeshO>::AddFaces(m, faces.rows());

		bool hasFNormals = faceNormals.rows() == faces.rows();
		for (unsigned int i = 0; i < faces.rows(); ++i, ++fi) {
			//TODO manage error:
			// ivp[faces(x,y)] could not exists
			// if faces(x,y) >= ivp.size()
			fi->V(0)=ivp[faces(i,0)];
			fi->V(1)=ivp[faces(i,1)];
			fi->V(2)=ivp[faces(i,2)];

			if (hasFNormals){
				fi->N() = CMeshO::CoordType(
							faceNormals(i,0),
							faceNormals(i,1),
							faceNormals(i,2));
			}
		}
	}

	return m;
}

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

Eigen::MatrixXd pymeshlab::Mesh::vertexMatrix(const CMeshO& mesh)
{
	vcg::tri::RequireVertexCompactness(mesh);

	// create eigen matrix of vertices
	Eigen::MatrixXd vert(mesh.VN(), 3);

	// copy vertices
	for (int i = 0; i < mesh.VN(); i++)
		for (int j = 0; j < 3; j++)
			vert(i,j) = mesh.vert[i].cP()[j];

	return vert;
}

Eigen::MatrixXi pymeshlab::Mesh::faceMatrix(const CMeshO& mesh)
{
	vcg::tri::RequireFaceCompactness(mesh);

	// create eigen matrix of faces
	Eigen::MatrixXi faces(mesh.FN(), 3);

	// copy faces
	for (int i = 0; i < mesh.FN(); i++)
		for (int j = 0; j < 3; j++)
			faces(i,j) = (int)vcg::tri::Index(mesh,mesh.face[i].cV(j));

	return faces;
}

Eigen::MatrixXd pymeshlab::Mesh::vertexNormalMatrix(const CMeshO& mesh)
{
	vcg::tri::RequireVertexCompactness(mesh);

	// create eigen matrix of vertex normals
	Eigen::MatrixXd vertexNormals(mesh.VN(), 3);

	// per vertices normals
	for (int i = 0; i < mesh.VN(); i++)
		for (int j = 0; j < 3; j++)
			vertexNormals(i,j) = mesh.vert[i].cN()[j];

	return vertexNormals;
}

Eigen::MatrixXd pymeshlab::Mesh::faceNormalMatrix(const CMeshO& mesh)
{
	vcg::tri::RequireFaceCompactness(mesh);

	// create eigen matrix of face normals
	Eigen::MatrixXd faceNormals(mesh.FN(), 3);

	// per face normals
	for (int i = 0; i < mesh.FN(); i++)
		for (int j = 0; j < 3; j++)
			faceNormals(i,j) = mesh.face[i].cN()[j];

	return faceNormals;
}

Eigen::VectorXd pymeshlab::Mesh::vertexQualityArray(const CMeshO& mesh)
{
	vcg::tri::RequireVertexCompactness(mesh);
	vcg::tri::RequirePerVertexQuality(mesh);

	Eigen::VectorXd qv(mesh.VN());
	for (int i = 0; i < mesh.VN(); i++){
		qv(i) = mesh.vert[i].cQ();
	}
	return qv;
}

Eigen::VectorXd pymeshlab::Mesh::faceQualityArray(const CMeshO& mesh)
{
	vcg::tri::RequireFaceCompactness(mesh);
	vcg::tri::RequirePerFaceQuality(mesh);

	Eigen::VectorXd qf(mesh.FN());
	for (int i = 0; i < mesh.FN(); i++){
		qf(i) = mesh.face[i].cQ();
	}
	return qf;
}

Eigen::MatrixXd pymeshlab::Mesh::vertexTexCoordMatrix(const CMeshO& mesh)
{
	Eigen::MatrixXd m;
	vcg::tri::MeshToMatrix<CMeshO>::GetUVData(mesh, m);
	return m;
}

Eigen::MatrixXi pymeshlab::Mesh::faceFaceAdjacency(const CMeshO& mesh)
{
	vcg::tri::RequireFaceCompactness(mesh);
	vcg::tri::RequireFFAdjacency(mesh);

	Eigen::MatrixXi faceFaceMatrix(mesh.FN(),3);

	for (int i = 0; i < mesh.FN(); i++) {
		for (int j = 0; j < 3; j++) {
			auto AdjF= mesh.face[i].cFFp(j);
			if (AdjF==&mesh.face[i])
				faceFaceMatrix(i,j)=-1;
			else
				faceFaceMatrix(i,j)=mesh.face[i].cFFi(j);
		}
	}

	return faceFaceMatrix;
}

Eigen::VectorXd pymeshlab::Mesh::vertexScalarAttributeArray(const CMeshO& mesh, const std::string& attributeName)
{
	vcg::tri::RequireVertexCompactness(mesh);
	CMeshO::PerVertexAttributeHandle<Scalarm> attributeHandle = 
			vcg::tri::Allocator<CMeshO>::GetPerVertexAttribute<Scalarm>(mesh, attributeName);
	if (vcg::tri::Allocator<CMeshO>::IsValidHandle(mesh, attributeHandle)){
		Eigen::VectorXd attrVector(mesh.VN());
		for (unsigned int i = 0; i < (unsigned int) mesh.VN(); ++i)
			attrVector[i] = attributeHandle[i];
		return attrVector;
	}
	else {
		throw MLException("No valid per vertex scalar attribute named " + 
						  QString::fromStdString(attributeName) + " was found.");
	}
}

Eigen::MatrixX3d pymeshlab::Mesh::vertexVectorAttributeMatrix(const CMeshO& mesh, const std::string& attributeName)
{
	vcg::tri::RequireVertexCompactness(mesh);
	CMeshO::PerVertexAttributeHandle<Point3m> attributeHandle = 
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
	CMeshO::PerFaceAttributeHandle<Scalarm> attributeHandle = 
			vcg::tri::Allocator<CMeshO>::GetPerFaceAttribute<Scalarm>(mesh, attributeName);
	if (vcg::tri::Allocator<CMeshO>::IsValidHandle(mesh, attributeHandle)){
		Eigen::VectorXd attrMatrix(mesh.FN());
		for (unsigned int i = 0; i < (unsigned int) mesh.FN(); ++i)
			attrMatrix[i] = attributeHandle[i];
		return attrMatrix;
	}
	else {
		throw MLException("No valid per face scalar attribute named " + 
						  QString::fromStdString(attributeName) + " was found.");
	}
}

Eigen::MatrixX3d pymeshlab::Mesh::faceVectorAttributeMatrix(const CMeshO& mesh, const std::string& attributeName)
{
	vcg::tri::RequireFaceCompactness(mesh);
	CMeshO::PerFaceAttributeHandle<Point3m> attributeHandle = 
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
