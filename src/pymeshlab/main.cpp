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
#include "bindings/pyabsolute_value.h"
#include "bindings/pyboundingbox.h"
#include "bindings/pycolor.h"
#include "bindings/pyimage.h"
#include "bindings/pymesh.h"
#include "bindings/pymeshset.h"
#include "bindings/pymodule_functions.h"
#include "bindings/pypercentage.h"

#include "bindings/pyexceptions.h"
#include "pymeshlab/helpers/common.h"

namespace py = pybind11;

// creation of a python module
PYBIND11_MODULE(PYMESHLAB_MODULE_NAME, m)
{
	// binding global module functions
	pymeshlab::initModuleFunctions(m);

	// bindings of all the classes in the module
	pymeshlab::initAbsoluteValue(m); // AbsoluteValue Class
	pymeshlab::initBoundingBox(m);   // BoundingBox Class
	pymeshlab::initColor(m);         // Color Class
	pymeshlab::initImage(m);         // Image Class
	pymeshlab::initMesh(m);          // Mesh Class
	pymeshlab::initMeshSet(m);       // MeshDocument Class
	pymeshlab::initPercentage(m);    // Percentage Class

	// binding the exceptions
	pymeshlab::initExceptions(m); // Exceptions

#ifdef PYMESHLAB_VERSION
	m.attr("__version__") = PYMESHLAB_STRINGIFY(PYMESHLAB_VERSION);
#else
	m.attr("__version__") = "dev";
#endif
}
