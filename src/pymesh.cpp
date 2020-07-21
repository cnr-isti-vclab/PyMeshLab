#include <ml_mesh_type.h>
#include <vcg/../wrap/io_trimesh/import_obj.h>

#include "pymesh.h"

namespace py = pybind11;

void pymeshlab::initMesh(py::module& m)
{
	py::class_<CMeshO> meshClass(m, "Mesh");

	//empty constructor
	meshClass.def(py::init());

	//test
	meshClass.def(
				"load",
				[](CMeshO& m, std::string filename) {
					vcg::tri::io::ImporterOBJ<CMeshO>::Info oi;
					vcg::tri::io::ImporterOBJ<CMeshO>::Open(m, filename.c_str(), oi);
				},
				py::arg("filename"));
}
