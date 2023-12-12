/****************************************************************************
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
#include "pypercentage_value.h"

#include "pymeshlab/percentage_value.h"
#include "docs/pypercentage_value_doc.h"

namespace py = pybind11;

void pymeshlab::initPercentageValue(pybind11::module& m)
{
	py::class_<pymeshlab::PercentageValue> percentageClass(m, "PercentageValue");

	//constructor
	percentageClass.def(py::init<float>(), doc::PYPER_INIT);

	percentageClass.def("value", &PercentageValue::value, doc::PYPER_VALUE);
	percentageClass.def("set_value", &PercentageValue::setValue, doc::PYPER_SET_VALUE);
}
