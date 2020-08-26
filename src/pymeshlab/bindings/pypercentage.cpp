#include "pypercentage.h"

#include "pymeshlab/percentage.h"
#include "docs/pypercentage_doc.h"

namespace py = pybind11;

void pymeshlab::initPercentage(pybind11::module& m)
{
	py::class_<pymeshlab::Percentage> percentageClass(m, "Percentage");

	auto exc = py::register_exception<pymeshlab::InvalidPercentageException>(m, "InvalidPercentageException");
	exc.doc() = doc::PYEXC_INV_PER;
	//constructor
	percentageClass.def(py::init<float>(), doc::PYPER_CSTR);

	percentageClass.def("value", &Percentage::value, doc::PYPER_VALUE);
	percentageClass.def("set_value", &Percentage::setValue, doc::PYPER_SET_VALUE);
}
