#include <ml_mesh_type.h>
#include <vcg/../wrap/io_trimesh/import_obj.h>

#include "pymesh.h"

namespace py = pybind11;

void loadMesh(CMeshO& m, std::string filename){
	vcg::tri::io::ImporterOBJ<CMeshO>::Info oi;
	vcg::tri::io::ImporterOBJ<CMeshO>::Open(m, filename.c_str(), oi);
	vcg::tri::UpdateBounding<CMeshO>::Box(m);
}

void updateBBox(CMeshO& m) {
	vcg::tri::UpdateBounding<CMeshO>::Box(m);
}

void pymeshlab::initMesh(py::module& m)
{
	py::class_<CMeshO> meshClass(m, "Mesh");

	//empty constructor
	meshClass.def(py::init());

	meshClass.def("vertex_number", &CMeshO::VN);
	meshClass.def("face_number", &CMeshO::FN);
	meshClass.def("edge_number", &CMeshO::EN);
	meshClass.def("update_bounding_box", &updateBBox);
}
