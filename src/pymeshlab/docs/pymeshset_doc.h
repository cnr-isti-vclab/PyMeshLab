#ifndef PYMESHLAB_PYMESHSET_DOC_H
#define PYMESHLAB_PYMESHSET_DOC_H

namespace pymeshlab {
namespace doc {

//MeshSet::__init__
const char* PYMS_INIT_VERB =
		"Initializes a MeshSet, setting the verbosity with the given value "
		"(default is ``False``).";

//MeshSet::set_verbosity
const char* PYMS_SET_VERBOSITY_DOC =
		"Sets the verbosity when using the MeshSet class. When set to true, all"
		" the logs that usually are printed in the bottom left of MeshLab, "
		"will be printed when filters are applied.";

//MeshSet::size
const char* PYMS_SIZE_DOC =
		"Returns the number of meshes contained in the MeshSet.";

//MeshSet::set_current_mesh
const char* PYMS_SET_CURRENT_MESH =
		"Selects as current mesh the mesh having the given ID. Raises a "
		":py:exc:`PyMeshLabException` if the given ID is not found in the MeshSet.";

//MeshSet::current_mesh
const char* PYMS_CURRENT_MESH =
		"Returns the current selected mesh of the MeshSet. Raises a "
		":py:exc:`PyMeshLabException` if the MeshSet has no selected mesh.";

//MeshSet::current_mesh_id
const char* PYMS_CURRENT_MESH_ID =
		"Returns the id of the current selected mesh of the MeshSet. Raises a "
		":py:exc:`PyMeshLabException` if the MeshSet has no selected mesh.";

//MeshSet::mesh_id_exists
const char* PYMS_MESH_ID_EXISTS =
		"Returns true if the given id exists in the MeshSet.";

//MeshSet::mesh
const char* PYMS_MESH =
		"Returns a reference to the mesh having the given id in the MeshSet. "
		"Raises a :py:exc:`PyMeshLabException` if the given ID is not found in "
		" the MeshSet.";

//MeshSet::load_new_mesh
const char* PYMS_LOAD_NEW_MESH =
		"Loads the mesh in the given filename and adds the mesh in the MeshSet. "
		"The loaded mesh becomes the current selected one. "
		"Raises a :py:exc:`PyMeshLabException` if the file is not found, if the "
		"format of the file is not known by PyMeshLab or if there was an error "
		"while loading the file.";

//MeshSet::load_current_mesh
const char* PYMS_LOAD_CURRENT_MESH =
		"Loads the mesh in the given filename and sets the mesh to current position "
		"in the MeshSet. The loaded mesh remains the current selected one. "
		"Raises a :py:exc:`PyMeshLabException` if the file is not found, if the "
		"format of the file is not known by PyMeshLab or if there was an error "
		"while loading the file.";

//MeshSet::save_current_mesh
const char* PYMS_SAVE_CURRENT_MESH =
		"Saves the current selected mesh in the MeshSet in a file having the "
		"given file name. Raises a :py:exc:`PyMeshLabException` if the MeshSet "
		"has no current selected mesh, if the format of the file is not known "
		"by PyMeshLab or if there was an error while writing the file.";

//MeshSet::save_mesh
const char* PYMS_ADD_MESH =
		"Adds a **copy** of the given mesh in the current MeshSet, with the given "
		"name. By default, the added mesh will be set as the current mesh. "
		"This behaviour can be changed by setting the arg ``set_as_current`` to "
		"``False``.";

//MeshSet::clear
const char* PYMS_CLEAR = 
		"Clears the meshset, deleting all its content.";

//MeshSet::load_project
const char* PYMS_LOAD_PROJECT =
		"Loads a project from the given file name and stores it in the MeshSet.";

//MeshSet::save_project
const char* PYMS_SAVE_PROJECT =
		"Saves the content of the MeshSet in a file having the given file name.";

//MeshSet::apply_filter
const char* PYMS_APPLY_FILTER =
		"Applies the filter having the given filter name in the MeshSet. "
		"Updates the current filter script, pushing the applied filter with the "
		"given parameters. "
		"See the :ref:`filter_list` page to a list of all the possible filters "
		"that can be applied using this function.";

//MeshSet::load_filter_script
const char* PYMS_LOAD_FILTER_SCRIPT =
		"Loads from a .mlx file the current filter script.";

//MeshSet::save_filter_script
const char* PYMS_SAVE_FILTER_SCRIPT =
		"Saves in a .mlx file the current filter script.";

//MeshSet::clear_filter_script
const char* PYMS_CLEAR_FILTER_SCRIPT =
		"Clears the current filter script.";

//MeshSet::apply_filter_script
const char* PYMS_APPLY_FILTER_SCRIPT =
		"Applies all the filters currently present in the filter script.";

//MeshSet::print_status
const char* PYMS_PRINT_STATUS =
		"Prints the status of the MeshSet (number of meshes, and for every mesh "
		"its ID, its label and its full name.)";

//MeshSet::print_plugin_list
const char* PYMS_PRINT_PLUGIN_LIST =
		"Prints all the meshlab plugins loaded in the current session of PyMeshLab.";

//MeshSet::print_filter_list
const char* PYMS_PRINT_FILTER_LIST =
		"Prints the list of all the filters that can be applied in the MeshSet.";

//MeshSet::print_filter_parameter_list
const char* PYMS_PRINT_FILTER_PARAMETER_LIST =
		"Prints the list of the parameters of the given filter, with their "
		"default values.";

//MeshSet::print_current_filter_script
const char* PYMS_PRINT_CURRENT_FILTER_SCIRPT =
		"Prints all the filters present on the current filter script, with all "
		"the parameters and their values.";
}
}

#endif // PYMESHLAB_PYMESHSET_DOC_H
