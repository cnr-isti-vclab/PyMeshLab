#ifndef PYMESHLAB_MESH_H
#define PYMESHLAB_MESH_H

#include <ml_mesh_type.h>
#include <pybind11/eigen.h>
#include <Eigen/Core>

namespace pymeshlab {

class Mesh
{
public:
	static CMeshO createFromMatrices(
			const Eigen::MatrixX3f& vertices,
			const Eigen::MatrixX3i& faces = Eigen::MatrixX3i());

	static bool isCompact(const CMeshO& mesh);

	static Box3m boundingBox(const CMeshO& mesh);
	static void updateBBox(CMeshO& mesh);
	static void updateTopology(CMeshO& mesh);
	static void compact(CMeshO& mesh);

	static int selectedFaceNumber(const CMeshO& mesh);

	static Eigen::MatrixXd vertexMatrix(const CMeshO& mesh);
	static Eigen::MatrixXi faceMatrix(const CMeshO& mesh);
	static Eigen::MatrixXd vertexNormalMatrix(const CMeshO& mesh);
	static Eigen::MatrixXd faceNormalMatrix(const CMeshO& mesh);
	static Eigen::VectorXf vertexQualityMatrix(const CMeshO& mesh);
	static Eigen::VectorXf faceQualityMatrix(const CMeshO& mesh);

	static Eigen::MatrixXf vertexTexCoordMatrix(const CMeshO& mesh);
	static Eigen::MatrixXi faceFaceAdjacency(const CMeshO& mesh);

private:
	Mesh();
};

}

#endif // PYMESHLAB_MESH_H
