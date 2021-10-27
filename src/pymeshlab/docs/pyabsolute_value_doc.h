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
#ifndef PYMESHLAB_PYABSOLUTE_VALUE_DOC_H
#define PYMESHLAB_PYABSOLUTE_VALUE_DOC_H

namespace pymeshlab {
namespace doc {

// Percentage::__init__
const char* PYABS_INIT =
	"Constructor of the :py:class:`AbsoluteValue` class. Takes as input a float "
	"value (default: 0) and initializes the absolute value. ";

// Percentage::value
const char* PYABS_VALUE = "Returns the value of the absolute value.";

// Percentage::set_value
const char* PYABS_SET_VALUE = "Sets the value of the absolute value.";
} // namespace doc
} // namespace pymeshlab

#endif // PYMESHLAB_PYABSOLUTE_VALUE_DOC_H
