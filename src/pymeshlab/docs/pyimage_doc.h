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
#ifndef PYMESHLAB_PYIMAGE_DOC_H
#define PYMESHLAB_PYIMAGE_DOC_H

namespace pymeshlab {
namespace doc {

// Image::width
const char* PYIMAGE_WIDTH =
	"Get the width of the image.";

// Image::height
const char* PYIMAGE_HEIGHT =
	"Get the height of the image.";

// Image::save
const char* PYIMAGE_SAVE =
	"Save the image to the given filename, deducing automatically the format from the file "
	"name, and with a given quality with default value -1 (default setting of the save process). "
	"Formats are the same supported by the QImage class. See the "
	"`QImage<https://doc.qt.io/qt-5/qimage.html#save>`_ documentation for more details.";

}
}

#endif // PYMESHLAB_PYIMAGE_DOC_H
