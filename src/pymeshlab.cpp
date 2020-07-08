#include <pybind11/pybind11.h>
#include <meshmodel.h>
#include <vcg/../wrap/io_trimesh/import_obj.h>

namespace py = pybind11;

PYBIND11_MODULE(pymeshlab, m) {
	m.doc() = "MeshLab python bindings";

	py::class_<MeshDocument> meshDocumentClass(m, "MeshDocument");

	//empty constructor
	meshDocumentClass.def(py::init());

	//test
	meshDocumentClass.def(
				"load_mesh",
				[](MeshDocument& m, std::string filename) {
					m.addNewMesh(filename.c_str(), "mesh");
					vcg::tri::io::ImporterOBJ<CMeshO>::Info oi;
					vcg::tri::io::ImporterOBJ<CMeshO>::Open(m.mm()->cm, filename.c_str(), oi);
				},
				py::arg("filename"));

	//number_meshes method
	meshDocumentClass.def("number_meshes",
				[](const MeshDocument& m) -> int {
					return m.size();
				});

	//set_current_mesh method
	meshDocumentClass.def("set_current_mesh",
				[](MeshDocument& m, int new_curr_id) {
					m.setCurrentMesh(new_curr_id);
				},
				py::arg("new_curr_id"));

	meshDocumentClass.def(
				"number_vertices_selected_mesh",
				[](MeshDocument& m) -> int {
					return m.mm()->cm.vn;
				});

}
