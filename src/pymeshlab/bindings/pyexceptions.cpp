#include "pyexceptions.h"

#include <mlexception.h>
#include "pymeshlab/exceptions.h"
#include "docs/pyexceptions_doc.h"

namespace py = pybind11;

void pymeshlab::initExceptions(pybind11::module& m)
{
	auto mlexc = py::register_exception<MLException>(m, "PyMeshLabException");
	mlexc.doc() = doc::PYEXC_MLEXC;
	
	auto invPercExc = py::register_exception<InvalidPercentageException>(m, "InvalidPercentageException");
	invPercExc.doc() = doc::PYEXC_INV_PER;
	
	auto invEnumExc = py::register_exception<InvalidEnumException>(m, "InvalidEnumException");
	invEnumExc.doc() = doc::PYEXC_INV_ENUM;
}
