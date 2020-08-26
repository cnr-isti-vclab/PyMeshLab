#include "pypercentage.h"

#include "pymeshlab/percentage.h"
#include "docs/pypercentage_doc.h"

namespace py = pybind11;

void pymeshlab::initPercentage(pybind11::module& m)
{
	py::class_<pymeshlab::Percentage> percentageClass(m, "Percentage");

	py::register_exception<pymeshlab::InvalidPercentageException>(m, "InvalidPercentageException");

	//constructor
	percentageClass.def(py::init<float>());

	percentageClass.def("value", &Percentage::value, doc::PYPER_VALUE);
	percentageClass.def("set_value", &Percentage::setValue, doc::PYPER_SET_VALUE);
}
