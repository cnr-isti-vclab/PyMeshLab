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
#ifndef PYMESHLAB_MODULE_FUNCTIONS_H
#define PYMESHLAB_MODULE_FUNCTIONS_H

#include <list>
#include <string>

namespace pymeshlab {

void loadDefaultPlugins();

std::string getVersion();
void        printVersion();

std::list<std::string> filterList();

int numberPlugins();

void printPluginList();
void printPluginFilterList(const std::string& pluginName);
void printFilterList();
void printFilterParameterList(const std::string& filterName);

void search(const std::string& searchKeyWord);

void loadPlugin(const std::string& filename);
} // namespace pymeshlab

#endif // PYMESHLAB_MODULE_FUNCTIONS_H
