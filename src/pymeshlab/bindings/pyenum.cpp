#include "pyenum.h"

#include "pymeshlab/enum.h"
#include "docs/pyenum_doc.h"

namespace py = pybind11;

void pymeshlab::initEnum(pybind11::module& m)
{
	py::class_<pymeshlab::Enum> enumClass(m, "Enum");

	auto exc = py::register_exception<pymeshlab::InvalidEnumException>(m, "InvalidEnumException");
	exc.doc() = doc::PYEXC_INV_ENUM;

	enumClass.def(py::init<std::string>(), doc::PYENUM_INIT);
	enumClass.def("value", &Enum::value, doc::PYENUM_VALUE);
}
