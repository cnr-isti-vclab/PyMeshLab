#ifndef PYMESHLAB_PYXCEPTIONS_DOC_H
#define PYMESHLAB_PYXCEPTIONS_DOC_H

namespace pymeshlab {
namespace doc {

//PyMeshLabException
const char* PYEXC_MLEXC =
		"Generic PyMeshLab exception.";

//InvalidPercentageException
const char* PYEXC_INV_PER =
		"Exception raised when an invalid value (not between 0 and 100) "
		"is set in a :py:class:`Percentage` object.";

//InvalidEnumException
const char* PYEXC_INV_ENUM =
		"Exception raised when an invalid enum value "
		"is used as argument of a filter.";

}
}

#endif // PYMESHLAB_PYXCEPTIONS_DOC_H
