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
#include "pyboundingbox.h"

#include "docs/pyboundingbox_doc.h"
#include "pymeshlab/bounding_box.h"
#include <common/ml_document/base_types.h>
#include <pybind11/eigen.h>

namespace py = pybind11;

void pymeshlab::initBoundingBox(pybind11::module& m)
{
	py::class_<Box3m> boundingBoxClass(m, "BoundingBox");

	// empty constructor
	boundingBoxClass.def(py::init(), doc::PYBB_INIT);

	boundingBoxClass.def("diagonal", &Box3m::Diag, doc::PYBB_DIAGONAL);
	boundingBoxClass.def("dim_x", &Box3m::DimX, doc::PYBB_DIM_X);
	boundingBoxClass.def("dim_y", &Box3m::DimY, doc::PYBB_DIM_Y);
	boundingBoxClass.def("dim_z", &Box3m::DimZ, doc::PYBB_DIM_Z);
	boundingBoxClass.def("min", &BoundingBox::min, doc::PYBB_MIN);
	boundingBoxClass.def("max", &BoundingBox::max, doc::PYBB_MAX);
}
