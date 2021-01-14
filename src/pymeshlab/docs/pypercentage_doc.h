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
#ifndef PYMESHLAB_PYPERCENTAGE_DOC_H
#define PYMESHLAB_PYPERCENTAGE_DOC_H

namespace pymeshlab {
namespace doc {

//Percentage::__init__
const char* PYPER_INIT =
		"Constructor of the :py:class:`Percentage` class. Takes as input a float "
		"value between 0 and 100 (default: 0) and initializes the percentage. "
		"Raises a :py:exc:`InvalidPercentageException` if the value is not between "
		"0 and 100.";

//Percentage::value
const char* PYPER_VALUE =
		"Returns the value of the percentage [0-100].";

//Percentage::set_value
const char* PYPER_SET_VALUE =
		"Sets the value of the percentage. Raises a "
		":py:exc:`InvalidPercentageException` if the value is not between "
		"0 and 100.";
}
}


#endif // PYMESHLAB_PYPERCENTAGE_DOC_H
