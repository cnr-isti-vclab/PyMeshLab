#include "pypoint.h"

#include <meshmodel.h>

namespace py = pybind11;

std::string pointDoc()
{
    return R"pbdoc(
              Point
              -----

              .. currentmodule:: pymeshlabserver

              .. autosummary::
                 :toctree: _generate

                 x
                 y
                 z
           )pbdoc";
}

void setX(Point3m& p, MESHLAB_SCALAR x)
{
	p.X() = x;
}

void setY(Point3m& p, MESHLAB_SCALAR y)
{
	p.Y() = y;
}

void setZ(Point3m& p, MESHLAB_SCALAR z)
{
	p.Z() = z;
}

Point3m& iPow(Point3m& p, const Point3m& oth)
{
	p = p ^ oth;
	return p;
}

std::string pointToString(const Point3m& p){
	return "[" + std::to_string(p.X()) + "; " + std::to_string(p.Y()) + "; " + std::to_string(p.Z()) + "]";
}

//static member functions
Point3m fromPolarCoordinates(MESHLAB_SCALAR ro, MESHLAB_SCALAR theta, MESHLAB_SCALAR phi)
{
	Point3m p;
	p.FromPolarRad(ro, theta, phi);
	return p;
}

void pymeshlab::initPoint(pybind11::module& m)
{
	py::class_<Point3m> pointClass(m, "Point");

	pointClass.doc() = pointDoc();

	/*** constructor ***/
	pointClass.def(
				py::init<MESHLAB_SCALAR, MESHLAB_SCALAR, MESHLAB_SCALAR>(),
				py::arg("x") = 0, py::arg("y") = 0, py::arg("z") = 0);

	/*** member functions ***/
	//getters
	pointClass.def(
				"x",
				(const MESHLAB_SCALAR& (Point3m::*)() const) &Point3m::X,
				"Returns the x coordinate of the point");
	pointClass.def(
				"y",
				(const MESHLAB_SCALAR& (Point3m::*)() const) &Point3m::Y,
				"Returns the y coordinate of the point");
	pointClass.def(
				"z",
				(const MESHLAB_SCALAR& (Point3m::*)() const) &Point3m::Z,
				"Returns the z coordinate of the point");

	//setters
	pointClass.def("set_x", &setX, py::arg("x"));
	pointClass.def("set_y", &setY, py::arg("y"));
	pointClass.def("set_z", &setZ, py::arg("z"));

	//norm functions
	pointClass.def("norm", &Point3m::Norm, "Returns the norm of the vector");
	pointClass.def("squared_norm", &Point3m::SquaredNorm, "Returns the squared norm of the vector");
	pointClass.def("normalized", &Point3m::normalized, "Returns the normalized vector, does not modify this vector");
	pointClass.def("normalize", &Point3m::Normalize, "Normalizes and returns the vector");

	//dot and cross
	pointClass.def("dot", &Point3m::dot, py::arg("other_point"));
	pointClass.def("cross", &Point3m::operator^, py::arg("other_point"));

	//unary neg operator
	pointClass.def("__neg__", (Point3m (Point3m::*)() const) &Point3m::operator-);

	//binary operators
	pointClass.def("__add__", &Point3m::operator+, py::arg("other_point"));
	pointClass.def(
				"__sub__",
				(Point3m (Point3m::*)(Point3m const & ) const) &Point3m::operator-,
				py::arg("other_point"));
	pointClass.def(
				"__mul__",
				(MESHLAB_SCALAR (Point3m::*)(Point3m const & ) const) &Point3m::operator*,
				py::arg("other_point"));
	pointClass.def(
				"__mul__",
				(Point3m (Point3m::*)(MESHLAB_SCALAR ) const) &Point3m::operator*,
				py::arg("scalar"));
	pointClass.def("__truediv__", &Point3m::operator/, py::arg("scalar"));
	pointClass.def("__pow__", &Point3m::operator^, py::arg("other_point"));

	//comparison operators
	pointClass.def("__eq__", &Point3m::operator==, py::arg("other_point"));
	pointClass.def("__ne__", &Point3m::operator!=, py::arg("other_point"));
	pointClass.def("__lt__", &Point3m::operator<, py::arg("other_point"));
	pointClass.def("__gt__", &Point3m::operator>, py::arg("other_point"));
	pointClass.def("__le__", &Point3m::operator<=, py::arg("other_point"));
	pointClass.def("__ge__", &Point3m::operator>=, py::arg("other_point"));

	//assignment operators
	pointClass.def("__isub__", &Point3m::operator-=, py::arg("other_point"));
	pointClass.def("__iadd__", &Point3m::operator+=, py::arg("other_point"));
	pointClass.def("__imul__", &Point3m::operator*=, py::arg("scalar"));
	pointClass.def("__idiv__", &Point3m::operator/=, py::arg("scalar"));
	pointClass.def("__ipow__", &iPow, py::arg("other_point"));

	//str function
	pointClass.def("__str__", &pointToString);

	/*** static member functions: ***/
	pointClass.def_static("zero", &Point3m::Zero);
	pointClass.def_static("one", &Point3m::One);
	pointClass.def_static(
				"from_polar_coordinates",
				&fromPolarCoordinates,
				py::arg("ro"), py::arg("theta"), py::arg("phi"));
}
