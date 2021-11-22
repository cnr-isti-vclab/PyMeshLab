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
#ifndef PYMESHLAB_COLOR_H
#define PYMESHLAB_COLOR_H

#include <pybind11/eigen.h>
#include <Eigen/Core>
#include <QColor>

namespace pymeshlab {

class Color
{
public:
	static Eigen::Vector3f toArray3f(const QColor& c);
	static Eigen::Vector4f toArray4f(const QColor& c);
	static Eigen::Vector3i toArray3i(const QColor& c);
	static Eigen::Vector4i toArray4i(const QColor& c);
private:
	Color();
};

}

#endif // PYMESHLAB_COLOR_H
