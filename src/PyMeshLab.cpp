#include <pybind11/pybind11.h>
#include <meshmodel.h>
#include <vcg/../wrap/io_trimesh/import_obj.h>

namespace py = pybind11;

PYBIND11_MODULE(PyMeshLab, m) {
	py::class_<MeshDocument> meshDocumentClass(m, "MeshDocument");

	//empty constructor
	meshDocumentClass.def(py::init());

	//test
	meshDocumentClass.def(
				"load_mesh",
				[](MeshDocument& m) {
					m.addNewMesh("/home/alessandro/Drive/Research/3DMeshes/bunny.obj", "mesh");
					vcg::tri::io::ImporterOBJ<CMeshO>::Info oi;
					vcg::tri::io::ImporterOBJ<CMeshO>::Open(m.mm()->cm, "/home/alessandro/Drive/Research/3DMeshes/bunny.obj", oi);
				});

	//size method
	meshDocumentClass.def("size",
				[](const MeshDocument& m) {
					return m.size();
				});

	//set_current_mesh method
	meshDocumentClass.def("set_current_mesh",
				[](MeshDocument& m, int new_curr_id) {
					m.setCurrentMesh(new_curr_id);
				});

	meshDocumentClass.def(
				"number_vertices_selected_mesh",
				[](MeshDocument& m) {
					return m.mm()->cm.vn;
				});

}
