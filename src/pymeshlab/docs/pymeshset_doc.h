#ifndef PYMESHLAB_PYMESHSET_DOC_H
#define PYMESHLAB_PYMESHSET_DOC_H

namespace pymeshlab {
namespace doc {

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
        "Selects as current mesh the mesh having the given ID. Raises "
        "a :py:exc:`PyMeshLabException` if the given ID is not found in the MeshSet.";

//MeshSet::current_mesh
const char* PYMS_CURRENT_MESH =
        "Returns the current selected mesh of the MeshSet. Throws a "
        "PyMeshLabException if the MeshSet has no selected mesh.";
}
}

#endif // PYMESHLAB_PYMESHSET_DOC_H
