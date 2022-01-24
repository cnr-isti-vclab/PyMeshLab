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

// load_default_plugins

const char* MODULE_LOAD_DEFAULT_PLUGINS =
	"Loads the set of default plugins that are shipped with pymeshlab. This function is "
	"automatically run when importing pymeshlab, and it should be called just one time per "
	"session. If called when plugins are already loaded, a :py:exc:`PyMeshLabException` will be "
	"raised.";

// print_pymeshlab_version
const char* MODULE_PRINT_VERSION = "Prints the PyMeshLab version that is currently running.";

// filter_list
const char* MODULE_FILTER_LIST =
	"Returns a list of all the (python names of the) filters that have been loaded in the current "
	"session of PyMeshLab.";

// number_plugins
const char* MODULE_NUMBER_PLUGINS =
	"Returns the number of plugins loaded in the current session of PyMeshLab.";

// print_plugin_list
const char* MODULE_PRINT_PLUGIN_LIST =
	"Prints all the meshlab plugins loaded in the current session of PyMeshLab.";

// print_plugin_filter_list
const char* MODULE_PRINT_PLUGIN_FILTER_LIST =
	"Prints the list of filters contained in the given plugin name.";

// print_filter_list
const char* MODULE_PRINT_FILTER_LIST =
	"Prints the list of all the filters have been loaded in the current session of PyMeshLab.";

// print_filter_parameter_list
const char* MODULE_PRINT_FILTER_PARAMETER_LIST =
	"Prints the list of the parameters of the given filter, with their default values.";

// search
const char* MODULE_SEARCH =
	"Performs a search between the filters of pymeshlab with the given a keyword. Prints the "
	"filter names and a link to the documentation of the filters.";

// load_plugin
const char* MODULE_LOAD_PLUGIN =
	"Allows to load an extra plugin into PyMeshLab, given the file name of the MeshLab plugin. "
	"Throws a :py:exc:`PyMeshLabException` if the load of the plugin fails.";

} // namespace doc
} // namespace pymeshlab

#endif // PYMESHLAB_MODULE_FUNCTIONS_DOC_H
