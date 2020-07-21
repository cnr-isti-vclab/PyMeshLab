#include <ml_mesh_type.h>
#include <vcg/../wrap/io_trimesh/import_obj.h>

#include "pyboundingbox.h"
#include "pymesh.h"

namespace py = pybind11;

void loadMesh(CMeshO& m, std::string filename){
	vcg::tri::io::ImporterOBJ<CMeshO>::Info oi;
	vcg::tri::io::ImporterOBJ<CMeshO>::Open(m, filename.c_str(), oi);
	vcg::tri::UpdateBounding<CMeshO>::Box(m);
}

Box3m& getBBox(CMeshO& m){
	return m.bbox;
}

void pymeshlab::initMesh(py::module& m)
{
	py::class_<CMeshO> meshClass(m, "Mesh");

	//empty constructor
	meshClass.def(py::init());

	meshClass.def("load", &loadMesh, py::arg("filename"));
	meshClass.def("vertex_number", &CMeshO::VN);
	meshClass.def("face_number", &CMeshO::FN);
	meshClass.def("edge_number", &CMeshO::EN);
	meshClass.def("bounding_box", &getBBox, py::return_value_policy::reference);
}
