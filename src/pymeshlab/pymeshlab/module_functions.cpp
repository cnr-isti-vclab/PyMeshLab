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
#include "module_functions.h"
#include <common/mlapplication.h>
#include <common/plugin_manager.h>
#include "helpers/common.h"
#include <common/globals.h>

void pymeshlab::printVersion()
{
	std::string pymsversion;
#ifdef PYMESHLAB_VERSION
	pymsversion = PYMESHLAB_STRINGIFY(PYMESHLAB_VERSION);
#else
	pymsversion = "DEV";
#endif
	
	std::cout << "PyMeshLab " << pymsversion << " based on MeshLab " << 
		MeshLabApplication::appVer().toStdString() << "\n";
}

int pymeshlab::numberPlugins()
{
	PluginManager& pm = meshlab::pluginManagerInstance();
	return pm.size();
}

void pymeshlab::printPluginList()
{
	PluginManager& pm = meshlab::pluginManagerInstance();
	std::cout
			<< "PyMeshLab - List of loaded plugins ("
			<< pm.size() << "):\n";
	for (const auto& p : pm.namePluginPairIterator()){
		std::cout << "\t" << p.first.toStdString() << "\n";
	}
}

