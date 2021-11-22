/*****************************************************************************
 * PyMeshLab                                                         o o     *
 * A versatile mesh processing toolbox                             o     o   *
 *                                                                _   O  _   *
 * Copyright(C) 2005-2021                                           \/)\/    *
 * Visual Computing Lab                                            /\/|      *
 * ISTI - Italian National Research Council                           |      *
 *                                                                    \      *
 * All rights reserved.                                                      *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
 * for more details.                                                         *
 *                                                                           *
 ****************************************************************************/
#include "pycolor.h"

#include "docs/pycolor_doc.h"
#include "pymeshlab/color.h"

namespace py = pybind11;

void pymeshlab::initColor(pybind11::module& m)
{
	py::class_<QColor> colorClass(m, "Color");

	colorClass.def(
		py::init<int, int, int>(), doc::PYCOLOR_INIT_RGB, py::arg("r"), py::arg("g"), py::arg("b"));
	colorClass.def(
		py::init<int, int, int, int>(),
		doc::PYCOLOR_INIT_RGBA,
		py::arg("r"),
		py::arg("g"),
		py::arg("b"),
		py::arg("a"));

	colorClass.def("red", &QColor::red, doc::PYCOLOR_RED);
	colorClass.def("green", &QColor::green, doc::PYCOLOR_GREEN);
	colorClass.def("blue", &QColor::blue, doc::PYCOLOR_BLUE);
	colorClass.def("alpha", &QColor::alpha, doc::PYCOLOR_ALPHA);
	colorClass.def("red_f", &QColor::redF, doc::PYCOLOR_REDF);
	colorClass.def("green_f", &QColor::greenF, doc::PYCOLOR_GREENF);
	colorClass.def("blue_f", &QColor::blueF, doc::PYCOLOR_BLUEF);
	colorClass.def("alpha_f", &QColor::alphaF, doc::PYCOLOR_ALPHAF);

	colorClass.def("set_red", &QColor::setRed, doc::PYCOLOR_SET_RED, py::arg("r"));
	colorClass.def("set_green", &QColor::setGreen, doc::PYCOLOR_SET_GREEN, py::arg("g"));
	colorClass.def("set_blue", &QColor::setBlue, doc::PYCOLOR_SET_BLUE, py::arg("b"));
	colorClass.def("set_alpha", &QColor::setAlpha, doc::PYCOLOR_SET_ALPHA, py::arg("a"));
	colorClass.def("set_red_f", &QColor::setRedF, doc::PYCOLOR_SET_REDF, py::arg("r"));
	colorClass.def("set_green_f", &QColor::setGreenF, doc::PYCOLOR_SET_GREENF, py::arg("g"));
	colorClass.def("set_blue_f", &QColor::setBlueF, doc::PYCOLOR_SET_BLUEF, py::arg("b"));
	colorClass.def("set_alpha_f", &QColor::setAlphaF, doc::PYCOLOR_SET_ALPHA, py::arg("a"));

	colorClass.def("to_array3", &Color::toArray3i, doc::PYCOLOR_TO_ARRAY3);
	colorClass.def("to_array4", &Color::toArray4i, doc::PYCOLOR_TO_ARRAY4);
	colorClass.def("to_array3f", &Color::toArray3f, doc::PYCOLOR_TO_ARRAY3F);
	colorClass.def("to_array4f", &Color::toArray4f, doc::PYCOLOR_TO_ARRAY4F);
}
