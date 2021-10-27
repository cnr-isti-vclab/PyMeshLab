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
#include "pyabsolute_value.h"

#include "docs/pyabsolute_value_doc.h"
#include "pymeshlab/absolute_value.h"

namespace py = pybind11;

void pymeshlab::initAbsoluteValue(pybind11::module& m)
{
	py::class_<pymeshlab::AbsoluteValue> avClass(m, "AbsoluteValue");

	// constructor
	avClass.def(py::init<float>(), doc::PYABS_INIT);

	avClass.def("value", &AbsoluteValue::value, doc::PYABS_VALUE);
	avClass.def("set_value", &AbsoluteValue::setValue, doc::PYABS_SET_VALUE);
}
