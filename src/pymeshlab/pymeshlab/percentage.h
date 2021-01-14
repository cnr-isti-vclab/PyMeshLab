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
#ifndef PYMESHLAB_PERCENTAGE_H
#define PYMESHLAB_PERCENTAGE_H

#include <exception>
#include <string>

namespace pymeshlab {

/**
 * @brief The Percentage class
 * Simple class that permits to discriminate between absolute
 * float values (just floats) and percentage values
 */
class Percentage
{
public:
	Percentage(float value = 0);

	void setValue(float v);
	float value() const;
private:
	float val;
};

}

#endif // PYMESHLAB_PERCENTAGE_H
