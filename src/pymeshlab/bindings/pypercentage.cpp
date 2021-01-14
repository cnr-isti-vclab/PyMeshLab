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
#include "pypercentage.h"

#include "pymeshlab/percentage.h"
#include "docs/pypercentage_doc.h"

namespace py = pybind11;

void pymeshlab::initPercentage(pybind11::module& m)
{
	py::class_<pymeshlab::Percentage> percentageClass(m, "Percentage");

	//constructor
	percentageClass.def(py::init<float>(), doc::PYPER_INIT);

	percentageClass.def("value", &Percentage::value, doc::PYPER_VALUE);
	percentageClass.def("set_value", &Percentage::setValue, doc::PYPER_SET_VALUE);
}
