#include "pypercentage.h"

#include "pymeshlab/percentage.h"

namespace py = pybind11;

void pymeshlab::initPercentage(pybind11::module& m)
{
	py::class_<pymeshlab::Percentage> percentageClass(m, "Percentage");

	py::register_exception<pymeshlab::InvalidPercentageException>(m, "InvalidPercentageException");

	//constructor
	percentageClass.def(py::init<float>());

	percentageClass.def("value", &Percentage::value);
	percentageClass.def("set_value", &Percentage::setValue);
}
