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
#ifndef PYMESHLAB_PYBOUNDINGBOX_DOC_H
#define PYMESHLAB_PYBOUNDINGBOX_DOC_H

namespace pymeshlab {
namespace doc {

// BoundingBox::__init__
const char* PYBB_INIT = "Creates an invalid Bounding Box (min: [1,1,1], max:[-1,-1,-1]).";

// BoundingBox::diagonal
const char* PYBB_DIAGONAL = "Returns the diagonal of the Bounding Box.";

// BoundingBox::dim_x
const char* PYBB_DIM_X = "Returns the X size of the Bounding Box.";

// BoundingBox::dim_y
const char* PYBB_DIM_Y = "Returns the Y size of the Bounding Box.";

// BoundingBox::dim_z
const char* PYBB_DIM_Z = "Returns the Z size of the Bounding Box.";

// BoundingBox::min
const char* PYBB_MIN = "Returns the min coordinate of the Bounding Box.";

// BoundingBox::max
const char* PYBB_MAX = "Returns the max coordinate of the Bounding Box.";

} // namespace doc
} // namespace pymeshlab

#endif // PYMESHLAB_PYBOUNDINGBOX_DOC_H
