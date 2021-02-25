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
#ifndef PYMESHLAB_MODULE_FUNCTIONS_DOC_H
#define PYMESHLAB_MODULE_FUNCTIONS_DOC_H

namespace pymeshlab {
namespace doc {

//load_default_plugins

const char* MODULE_LOAD_DEFAULT_PLUGINS =
		"Loads the set of default plugins that are shipped with pymeshlab. "
		"This function is automatically run when importing pymeshlab, and it should "
		"be called just one time per session. If called when plugins are already "
		"loaded, a :py:exc:`PyMeshLabException` will be raised.";

//print_pymeshlab_version
const char* MODULE_PRINT_VERSION =
		"Prints the PyMeshLab version that is currently running.";

//number_plugins
const char* MODULE_NUMBER_PLUGINS =
		"Returns the number of plugins loaded in the current session of PyMeshLab.";

//print_plugin_list
const char* MODULE_PRINT_PLUGIN_LIST =
		"Prints all the meshlab plugins loaded in the current session of PyMeshLab.";

//print_filter_list
const char* MODULE_PRINT_FILTER_LIST =
		"Prints the list of all the filters have been loaded in the pymeshlab session.";

//print_filter_parameter_list
const char* MODULE_PRINT_FILTER_PARAMETER_LIST =
		"Prints the list of the parameters of the given filter, with their "
		"default values.";
}
}

#endif // PYMESHLAB_MODULE_FUNCTIONS_DOC_H
