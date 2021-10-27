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
#ifndef PYMESHLAB_ABSOLUTE_VALUE_H
#define PYMESHLAB_ABSOLUTE_VALUE_H

namespace pymeshlab {

/**
 * @brief The AbsoluteValue class
 * Simple class that permits to discriminate between absolute values and
 * percentage values (se Percentage class)
 */
class AbsoluteValue
{
public:
	AbsoluteValue(float value = 0);

	void  setValue(float v);
	float value() const;

private:
	float val;
};

} // namespace pymeshlab

#endif // PYMESHLAB_ABSOLUTE_VALUE_H
