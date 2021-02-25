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
#include <common/plugins/plugin_manager.h>
#include <common/python/function_set.h>
#include <common/globals.h>
#include "helpers/common.h"

void pymeshlab::loadDefaultPlugins()
{
	PluginManager& pm = meshlab::pluginManagerInstance();
	pm.loadPlugins(QString::fromStdString(getPluginsPath()));
}


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
	for (const auto& p : pm.pluginIterator()){
		std::cout << "\t" << p->pluginName().toStdString() << "\n";
	}
}

void pymeshlab::printFilterList()
{
	FunctionSet& fs = pymeshlab::functionSetInstance();
	std::list<std::string> list = fs.pythonFilterFunctionNames();
	std::cout << "MeshSet class - list of filter names:\n";
	for (const std::string& fname : list){
		std::cout << "\t" << fname << "\n";
	}
}

/**
 * @brief @brief given the function names, lists all its parameters that can be
 * passed to the "apply_filter" function
 */
void pymeshlab::printFilterParameterList(const std::string& filterName)
{
	FunctionSet& fs = pymeshlab::functionSetInstance();
	const Function& ff = fs.filterFunction(QString::fromStdString(filterName));
	std::cout <<
				"Please note: some parameters depend on the mesh(es) used as input of the \n"
				"filter. Default values listed here are computed on a 1x1x1 cube \n"
				"(pymeshlab/tests/sample/cube.obj), and they will be computed on the input mesh\n"
				"if they are left as default.\n";

	std::cout << filterName <<" filter - list of parameter names:\n";
	if (ff.parametersNumber() == 0) {
		std::cout << "\tNone.\n";
	}
	else {
		for (const FunctionParameter& ffp : ff) {
			std::cout << "\t" << ffp.pythonName().toStdString() << " : "
					  << ffp.pythonTypeString().toStdString() << " = ";
			ffp.printDefaultValue(std::cout);
			std::cout << "\n";
		}
	}
}
