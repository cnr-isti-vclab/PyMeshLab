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
#ifndef PYMESHLAB_PYMESHSET_DOC_H
#define PYMESHLAB_PYMESHSET_DOC_H

namespace pymeshlab {
namespace doc {

// MeshSet::__init__
const char* PYMS_INIT_VERB =
	"Initializes a MeshSet, setting the verbosity with the given value (default is ``False``).";

// MeshSet::set_verbosity
const char* PYMS_SET_VERBOSITY_DOC =
	"Sets the verbosity when using the MeshSet class. When set to true, all the logs that usually "
	"are printed in the bottom left of MeshLab, along with other messages, are printed when "
	"filters are applied.";

// MeshSet::set_parameter_verbosity
const char* PYMS_SET_PAR_VERBOSITY_DOC =
	"Sets the verbosity of the MeshSet, regarding only the print of the parameters when running a"
	"filter. When set to true, only the parameters of the filter with their values will be printed "
	"when a filter is executed. Other messages are not printed.";

// MeshSet::number_meshes
const char* PYMS_NUMBER_MESHES_DOC = "Returns the number of meshes contained in the MeshSet.";

// MeshSet::number_rasters
const char* PYMS_NUMBER_RASTERS_DOC = "Returns the number of rasters contained in the MeshSet.";

// MeshSet::set_current_mesh
const char* PYMS_SET_CURRENT_MESH =
	"Selects as current mesh the mesh having the given ID. Raises a :py:exc:`PyMeshLabException` "
	"if the given ID is not found in the MeshSet.";

// MeshSet::current_mesh
const char* PYMS_CURRENT_MESH =
	"Returns the current mesh of the MeshSet. Raises a :py:exc:`PyMeshLabException` if the MeshSet "
	"has no current mesh (zero meshes).";

// MeshSet::current_mesh_id
const char* PYMS_CURRENT_MESH_ID =
	"Returns the id of the current mesh of the MeshSet. Raises a :py:exc:`PyMeshLabException` if "
	"the MeshSet has no current mesh (zero meshes).";

// MeshSet::mesh_id_exists
const char* PYMS_MESH_ID_EXISTS = "Returns true if the given id exists in the MeshSet.";

// MeshSet::mesh
const char* PYMS_MESH =
	"Returns a reference to the mesh having the given id in the MeshSet. Raises a "
	":py:exc:`PyMeshLabException` if the given ID is not found in  the MeshSet.";

// MeshSet::set_current_mesh_visibility
const char* PYMS_SET_CURRENT_MESH_VISIBILITY =
	"Sets the visibility of the current mesh according to the given boolean argument."
	"Raises a :py:exc:`PyMeshLabException` if the MeshSet has no current mesh (zero meshes).";

// MeshSet::set_mesh_visibility
const char* PYMS_SET_MESH_VISIBILITY =
	"Sets the visibility of the mesh with the given ID according to the given boolean argument."
	"Raises a :py:exc:`PyMeshLabException` if the given ID is not found in  the MeshSet.";

// MeshSet::set_current_mesh_visibility
const char* PYMS_IS_CURRENT_MESH_VISIBLE =
	"Returns a boolean indicating whether the current mesh is visible or not."
	"Raises a :py:exc:`PyMeshLabException` if the MeshSet has no current mesh (zero meshes).";

// MeshSet::set_current_mesh_visibility
const char* PYMS_IS_MESH_VISIBLE =
	"Returns a boolean indicating whether the mesh with the given ID is visible or not."
	"Raises a :py:exc:`PyMeshLabException` if the given ID is not found in the MeshSet.";

// MeshSet::load_new_mesh
const char* PYMS_LOAD_NEW_MESH =
	"Loads the mesh in the given filename and adds the mesh in the MeshSet. The loaded mesh "
	"becomes the current one. This method accepts a list of parameters that depends on the format "
	"of the file that is being loaded. The list of possible parameters is listed in the "
	"::ref:`load_mesh_parameters` page. Raises a :py:exc:`PyMeshLabException` if the file is not "
	"found, if the format of the file is not known by PyMeshLab or if there was an error while "
	"loading the file.";

// MeshSet::save_current_mesh
const char* PYMS_SAVE_CURRENT_MESH =
	"Saves the current mesh in the MeshSet in a file having the given file name. This method "
	"accepts a list of parameters that depends on the format of the file that is being saved. The "
	"list of possible parameters is listed in the :ref:`save_mesh_parameters` page. Raises a "
	":py:exc:`PyMeshLabException` if the MeshSet has no current selected mesh, if the format of "
	"the file is not known by PyMeshLab or if there was an error while writing the file.";

// MeshSet::load_new_raster
const char* PYMS_LOAD_NEW_RASTER =
	"Loads the raster in the given filename and adds the raster in the MeshSet. The loaded raster "
	"becomes the current one. This method accepts a list of parameters that depends on the format "
	"of the file that is being loaded. The list of possible parameters is listed in the "
	":ref:`load_raster_parameters` page. Raises a :py:exc:`PyMeshLabException` if the file is not "
	"found, if the format of the file is not known by PyMeshLab or if there was an error while "
	"loading the file.";

// MeshSet::add_mesh
const char* PYMS_ADD_MESH =
	"Adds a **copy** of the given mesh in the current MeshSet, with the given name. By default, "
	"the added mesh will be set as the current mesh. This behaviour can be changed by setting the "
	"arg ``set_as_current`` to ``False``. If the name argument is left empty, the newly added mesh "
	"will have the same name of the mesh argument.";

// MeshSet::clear
const char* PYMS_CLEAR = "Clears the meshset, deleting all its content.";

// MeshSet::load_project
const char* PYMS_LOAD_PROJECT =
	"Loads a project from the given file name(s) and stores it in the MeshSet. This function can "
	"accept a string as a single filename, or a list of strings if the project is composed of more "
	"than one file. E.g. ``ms.load_project(['bundle.rd.out', 'cams.txt'])``.";

// MeshSet::save_project
const char* PYMS_SAVE_PROJECT =
	"Saves the content of the MeshSet in a file having the given file name.";

// MeshSet::apply_filter
const char* PYMS_APPLY_FILTER =
	"Applies the filter having the given filter name in the MeshSet. Updates the current filter "
	"script, pushing the applied filter with the given parameters. Returns a dictionary containing "
	"pairs of [string - value] returned by the applied filter. See the :ref:`filter_list` page to "
	"a list of all the possible filters that can be applied using this function.";

// MeshSet::load_filter_script
const char* PYMS_LOAD_FILTER_SCRIPT = "Loads from a .mlx file the current filter script.";

// MeshSet::save_filter_script
const char* PYMS_SAVE_FILTER_SCRIPT = "Saves in a .mlx file the current filter script.";

// MeshSet::clear_filter_script
const char* PYMS_CLEAR_FILTER_SCRIPT = "Clears the current filter script.";

// MeshSet::apply_filter_script
const char* PYMS_APPLY_FILTER_SCRIPT =
	"Applies all the filters currently present in the filter script.";

// MeshSet::print_status
const char* PYMS_PRINT_STATUS =
	"Prints the status of the MeshSet (number of meshes, and for every mesh its ID, its label and "
	"its full name.)";

// MeshSet::filter_parameter_values
const char* PYMS_FILTER_PARAMETER_VALUES =
	"Returns a dictionary containing the parameters and their values that would be used by the "
	"given filter if the 'apply_filter' function is called in the current MeshSet. This function "
	"is useful to check which default values are set with the current status of the MeshSet. It "
	"takes also a (possibly empty) dictionary of parameters that could be set by the user: in this "
	"case, the output value of these parameters should be the same as input. This function works "
	"also for the 'save mesh' functions, just giving the format of the file as parameter instead "
	"of the filter name. This is useful for example when saving into a format that supports "
	"exporting custom parameters, which may have names that can be known only at runtime.";

// MeshSet::print_filter_parameter_list
const char* PYMS_PRINT_FILTER_PARAMETER_LIST =
	"Prints the list of the parameters of the given filter, with their default values.";

// MeshSet::print_current_filter_script
const char* PYMS_PRINT_FILTER_SCIRPT =
	"Prints all the filters present on the current filter script, with all the parameters and "
	"their values.";

} // namespace doc
} // namespace pymeshlab

#endif // PYMESHLAB_PYMESHSET_DOC_H
