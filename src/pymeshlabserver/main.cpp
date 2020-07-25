#include "pypoint.h"
#include "pyboundingbox.h"
#include "pymesh.h"
#include "pymeshdocument.h"

namespace py = pybind11;

std::string getDoc() {
    return R"pbdoc(
             PyMeshLabServer Module
             ----------------------

              .. currentmodule:: pymeshlabserver

              This module contains a set of classes to
              compute batch MeshLab operations.

              .. autosummary::
                 :toctree: _generate

                 Point
                 BoundingBox
           )pbdoc";
}

PYBIND11_MODULE(pymeshlabserver, m) {
	m.doc() = getDoc();

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
