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

std::string pointToString(const Point3m& p){
	return "[" + std::to_string(p.X()) + "; " + std::to_string(p.Y()) + "; " + std::to_string(p.Z()) + "]";
}

MESHLAB_SCALAR dot(const Point3m& p1, const Point3m& p2)
{
	return p1.dot(p2);
}

void pymeshlab::initPoint(pybind11::module& m)
{
	py::class_<Point3m> pointClass(m, "Point");

	pointClass.doc() = pointDoc();

	//constructors
	pointClass.def(py::init());
	pointClass.def(
				py::init<MESHLAB_SCALAR, MESHLAB_SCALAR, MESHLAB_SCALAR>(),
				py::arg("x"), py::arg("y"), py::arg("z"));

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
	pointClass.def("set_x", &setX, py::arg("x"));
	pointClass.def("set_y", &setY, py::arg("y"));
	pointClass.def("set_z", &setZ, py::arg("z"));
	pointClass.def("norm", &Point3m::Norm, "Returns the norm of the vector");
	pointClass.def("normalized", &Point3m::normalized, "Returns the normalized vector, does not modify this vector");
	pointClass.def("normalize", &Point3m::Normalize, "Normalizes and returns the vector");
	pointClass.def("dot", &Point3m::dot, py::arg("other_point"));
	pointClass.def("__add__", &Point3m::operator+, py::arg("other_point"));
	pointClass.def(
				"__sub__",
				(Point3m (Point3m::*)(Point3m const & ) const) &Point3m::operator-,
				py::arg("other_point"));
	pointClass.def(
				"__mul__",
				(MESHLAB_SCALAR (Point3m::*)(Point3m const & ) const) &Point3m::operator*),
				py::arg("other_point");
	pointClass.def(
				"__mul__",
				(Point3m (Point3m::*)(MESHLAB_SCALAR ) const) &Point3m::operator*),
				py::arg("scalar");
	pointClass.def("__str__", &pointToString);
	pointClass.def("__eq__", &Point3m::operator==);


	//functions:
	m.def("doc", &dot, py::arg("point1"), py::arg("point2"));
}
