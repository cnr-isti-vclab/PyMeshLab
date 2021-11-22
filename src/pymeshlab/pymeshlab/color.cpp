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
#include "color.h"

Eigen::Vector3f pymeshlab::Color::toArray3f(const QColor& c)
{
	Eigen::Vector3f v;
	v << c.redF(), c.greenF(), c.blueF();
	return v;
}

Eigen::Vector4f pymeshlab::Color::toArray4f(const QColor& c)
{
	Eigen::Vector4f v;
	v << c.redF(), c.greenF(), c.blueF(), c.alphaF();
	return v;
}

Eigen::Vector3i pymeshlab::Color::toArray3i(const QColor& c)
{
	Eigen::Vector3i v;
	v << c.red(), c.green(), c.blue();
	return v;
}

Eigen::Vector4i pymeshlab::Color::toArray4i(const QColor& c)
{
	Eigen::Vector4i v;
	v << c.red(), c.green(), c.blue(), c.alpha();
	return v;
}

pymeshlab::Color::Color()
{
}
