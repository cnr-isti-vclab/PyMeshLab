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
#include "pypure_value.h"

#include "docs/pypure_value_doc.h"
#include "pymeshlab/pure_value.h"

namespace py = pybind11;

void pymeshlab::initPureValue(pybind11::module& m)
{
	py::class_<pymeshlab::PureValue> pvClass(m, "PureValue");

	// constructor
	pvClass.def(py::init<float>(), doc::PYPUREVALUE_INIT);

	pvClass.def("value", &PureValue::value, doc::PYPUREVALUE_VALUE);
	pvClass.def("set_value", &PureValue::setValue, doc::PYPUREVALUE_SET_VALUE);
}
