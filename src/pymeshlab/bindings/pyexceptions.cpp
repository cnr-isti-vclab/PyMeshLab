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
#include "pyexceptions.h"

#include <common/mlexception.h>
#include "pymeshlab/exceptions.h"
#include "docs/pyexceptions_doc.h"

namespace py = pybind11;

void pymeshlab::initExceptions(pybind11::module& m)
{
	auto mlexc = py::register_exception<MLException>(m, "PyMeshLabException");
	mlexc.doc() = doc::PYEXC_MLEXC;
	
	auto invPercExc = py::register_exception<InvalidPercentageException>(m, "InvalidPercentageException");
	invPercExc.doc() = doc::PYEXC_INV_PER;
	
	auto invEnumExc = py::register_exception<InvalidEnumException>(m, "InvalidEnumException");
	invEnumExc.doc() = doc::PYEXC_INV_ENUM;
}
