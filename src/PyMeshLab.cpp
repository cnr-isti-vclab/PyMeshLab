#include <pybind11/pybind11.h>
#include <meshmodel.h>

namespace py = pybind11;

int add(int i, int j) {
	return i + j;
}

PYBIND11_MODULE(PyMeshLab, m) {
	py::class_<MeshDocument>(m, "MeshDocument")
			.def(py::init())
			.def("size",
				[](const MeshDocument& m) {
					return m.size();
				});
}
