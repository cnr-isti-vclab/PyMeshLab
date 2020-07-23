#include "pyboundingbox.h"

#include <meshmodel.h>

namespace py = pybind11;

void pymeshlab::initBoundingBox(pybind11::module& m)
{
	py::class_<Box3m> boundingBoxClass(m, "BoundingBox");

	//empty constructor
	boundingBoxClass.def(py::init());

	boundingBoxClass.def("diagonal", &Box3m::Diag);
	boundingBoxClass.def("dim_x", &Box3m::DimX);
	boundingBoxClass.def("dim_y", &Box3m::DimY);
	boundingBoxClass.def("dim_z", &Box3m::DimZ);
	boundingBoxClass.def_readwrite("min", &Box3m::min);
	boundingBoxClass.def_readwrite("max", &Box3m::max);
}
