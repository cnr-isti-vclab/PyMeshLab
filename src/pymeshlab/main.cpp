#include "pyboundingbox.h"
#include "pymesh.h"
#include "pymeshset.h"

namespace py = pybind11;

std::string getDoc() {
    return R"pbdoc(
             PyMeshLab Module
             ----------------------

             .. currentmodule:: meshlab

              This module contains a set of classes to
              compute batch MeshLab operations.

              .. autosummary::
                 :toctree: _generate

           )pbdoc";
}

PYBIND11_MODULE(meshlab, m) {
	m.doc() = getDoc();

	pymeshlab::initBoundingBox(m); //BoundingBox Class
	pymeshlab::initMesh(m); //Mesh Class
	pymeshlab::initMeshSet(m); //MeshDocument Class

#ifdef PYMESHLAB_VERSION
	m.attr("__version__") = PYMESHLAB_VERSION;
#else
	m.attr("__version__") = "dev";
#endif

}
