#include "pycamera.h"

#include <vcg/math/shot.h>

namespace py = pybind11;

void pymeshlab::initCamera(pybind11::module& m)
{
	py::class_<vcg::Shotf> cameraClass(m, "Camera");
	
	//todo
}
