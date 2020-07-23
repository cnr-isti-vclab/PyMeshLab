#include "pypoint.h"
#include "pyboundingbox.h"
#include "pymesh.h"
#include "pymeshdocument.h"

namespace py = pybind11;

PYBIND11_MODULE(pymeshlabserver, m) {
	m.doc() = "MeshLab python bindings";

	pymeshlab::initPoint(m); //Point Class
	pymeshlab::initBoundingBox(m); //BoundingBox Class
	pymeshlab::initMesh(m); //Mesh Class
	pymeshlab::initMeshDocument(m); //MeshDocument Class

#ifdef PYMESHLAB_VERSION
	m.attr("__version__") = PYMESHLAB_VERSION;
#else
	m.attr("__version__") = "dev";
#endif

}
