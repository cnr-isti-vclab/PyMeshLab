#include "pyboundingbox.h"

#include <common/ml_document/base_types.h>
#include "docs/pyboundingbox_doc.h"

namespace py = pybind11;

void pymeshlab::initBoundingBox(pybind11::module& m)
{
	py::class_<Box3m> boundingBoxClass(m, "BoundingBox");

	//empty constructor
	boundingBoxClass.def(py::init(), doc::PYBB_INIT);

	boundingBoxClass.def("diagonal", &Box3m::Diag, doc::PYBB_DIAGONAL);
	boundingBoxClass.def("dim_x", &Box3m::DimX, doc::PYBB_DIM_X);
	boundingBoxClass.def("dim_y", &Box3m::DimY, doc::PYBB_DIM_Y);
	boundingBoxClass.def("dim_z", &Box3m::DimZ, doc::PYBB_DIM_Z);
}
