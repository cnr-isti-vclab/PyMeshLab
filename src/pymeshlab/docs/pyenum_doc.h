#ifndef PYMESHLAB_PYENUM_DOC_H
#define PYMESHLAB_PYENUM_DOC_H

namespace pymeshlab {
namespace doc {

//InvalidEnumException
const char* PYEXC_INV_ENUM =
		"Exception raised when an invalid enum value "
		"is used as argument of a filter.";

//Enum::__init__
const char* PYENUM_INIT =
		"Constructor of the :py:class:`Enum` class. Takes as input a string "
		"value and initializes the enum. ";

//Enum::value
const char* PYENUM_VALUE =
		"Returns the value of the enum as a string.";

}
}

#endif // PYMESHLAB_PYENUM_DOC_H
