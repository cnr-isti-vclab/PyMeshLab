#include "bindings/pyboundingbox.h"
#include "bindings/pycolor.h"
#include "bindings/pyenum.h"
#include "bindings/pymesh.h"
#include "bindings/pymeshset.h"
#include "bindings/pypercentage.h"

namespace py = pybind11;

PYBIND11_MODULE(meshlab, m) {
	pymeshlab::initBoundingBox(m); //BoundingBox Class
	pymeshlab::initColor(m); //Color Class
	pymeshlab::initEnum(m); //Enum Class
	pymeshlab::initMesh(m); //Mesh Class
	pymeshlab::initMeshSet(m); //MeshDocument Class
	pymeshlab::initPercentage(m); //Percentage Class

#ifdef PYMESHLAB_VERSION
	m.attr("__version__") = PYBIND11_STRINGIFY(PYMESHLAB_VERSION);
#else
	m.attr("__version__") = "dev";
#endif

}
