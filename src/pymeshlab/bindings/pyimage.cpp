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
#include "pyimage.h"

#include "docs/pyimage_doc.h"
#include "pymeshlab/image.h"

namespace py = pybind11;

void pymeshlab::initImage(pybind11::module& m)
{
	py::class_<QImage> imageClass(m, "Image");

	imageClass.def("width", &QImage::width);
	imageClass.def("height", &QImage::height);

	imageClass.def(
		"save", &Image::save, doc::PYIMAGE_SAVE, py::arg("file_name"), py::arg("quality") = -1);
}
