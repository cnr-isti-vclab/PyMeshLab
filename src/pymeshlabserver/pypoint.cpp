#include "pypoint.h"

#include <meshmodel.h>

namespace py = pybind11;

const MESHLAB_SCALAR& xCoord(const Point3m& p){
	return p.X();
}
const MESHLAB_SCALAR& yCoord(const Point3m& p){
	return p.Y();
}
const MESHLAB_SCALAR& zCoord(const Point3m& p){
	return p.Z();
}
void setX(Point3m& p, MESHLAB_SCALAR x){
	p.X() = x;
}
void setY(Point3m& p, MESHLAB_SCALAR y){
	p.Y() = y;
}
void setZ(Point3m& p, MESHLAB_SCALAR z){
	p.Z() = z;
}
std::string pointToString(const Point3m& p){
	return "[" + std::to_string(p.X()) + "; " + std::to_string(p.Y()) + "; " + std::to_string(p.Z()) + "]";
}

void pymeshlab::initPoint(pybind11::module& m)
{
	py::class_<Point3m> pointClass(m, "Point");

	//constructors
	pointClass.def(py::init());
	pointClass.def(
				py::init<MESHLAB_SCALAR, MESHLAB_SCALAR, MESHLAB_SCALAR>(),
				py::arg("x"), py::arg("y"), py::arg("z"));

	//no way to give &Point3m::X instead of creating a new function xCoord()
	// -> no discrimination between Point3m::X() and Point3m::X() const
	//if you know how to do this, please improve it!!!
	pointClass.def("x", &xCoord);
	pointClass.def("y", &yCoord);
	pointClass.def("z", &zCoord);
	pointClass.def("set_x", &setX, py::arg("x"));
	pointClass.def("set_y", &setY, py::arg("y"));
	pointClass.def("set_z", &setZ, py::arg("z"));
	pointClass.def("norm", &Point3m::Norm);
	pointClass.def("normalized", &Point3m::normalized);
	pointClass.def("normalize", &Point3m::Normalize);
	pointClass.def("__str__", &pointToString);
	pointClass.def("__eq__", &Point3m::operator==);
}
