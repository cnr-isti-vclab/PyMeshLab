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

pymeshlab::Mesh::Mesh()
{
}
