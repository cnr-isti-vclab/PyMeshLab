#include "pymeshdocument.h"
#include <meshmodel.h>
#include <vcg/../wrap/io_trimesh/import_obj.h>

namespace py = pybind11;

CMeshO& currentMesh(MeshDocument& m) {
	return m.mm()->cm;
}

void pymeshlab::initMeshDocument(pybind11::module& m)
{
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
					vcg::tri::UpdateBounding<CMeshO>::Box(m.mm()->cm);
				},
				py::arg("filename"));

	meshDocumentClass.def("number_meshes", &MeshDocument::size);
	meshDocumentClass.def("set_current_mesh", &MeshDocument::setCurrentMesh, py::arg("new_curr_id"));
	meshDocumentClass.def("current_mesh", &currentMesh, py::return_value_policy::reference);
}
