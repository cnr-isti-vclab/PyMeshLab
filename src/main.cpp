
#include "pymesh.h"
#include "pymeshdocument.h"

namespace py = pybind11;

PYBIND11_MODULE(pymeshlab, m) {
	m.doc() = "MeshLab python bindings";

	pymeshlab::initMeshDocument(m); //MeshDocument Class
	pymeshlab::initMesh(m); //Mesh Class

#ifdef PYMESHLAB_VERSION
	m.attr("__version__") = PYMESHLAB_VERSION;
#else
	m.attr("__version__") = "dev";
#endif

}
