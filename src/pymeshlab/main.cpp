#include "bindings/pyboundingbox.h"
#include "bindings/pycolor.h"
#include "bindings/pymesh.h"
#include "bindings/pymeshset.h"
#include "bindings/pypercentage.h"

#include "bindings/pyexceptions.h"
#include "pymeshlab/helpers/common.h"

namespace py = pybind11;

PYBIND11_MODULE(PYMESHLAB_MODULE_NAME, m) {
	pymeshlab::initBoundingBox(m); //BoundingBox Class
	pymeshlab::initColor(m); //Color Class
	pymeshlab::initMesh(m); //Mesh Class
	pymeshlab::initMeshSet(m); //MeshDocument Class
	pymeshlab::initPercentage(m); //Percentage Class
	
	pymeshlab::initExceptions(m); //Exceptions
	
	m.def("print_pymeshlab_version", &pymeshlab::printVersion);

#ifdef PYMESHLAB_VERSION
	m.attr("__version__") = PYMESHLAB_STRINGIFY(PYMESHLAB_VERSION);
#else
	m.attr("__version__") = "dev";
#endif

}
