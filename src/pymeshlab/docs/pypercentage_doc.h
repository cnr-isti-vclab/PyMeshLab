#ifndef PYMESHLAB_PYPERCENTAGE_DOC_H
#define PYMESHLAB_PYPERCENTAGE_DOC_H

namespace pymeshlab {
namespace doc {

//InvalidPercentageException
const char* PYEXC_INV_PER =
		"Exception raised when an invalid value (not between 0 and 100) "
		"is set in a :py:class:`Percentage` object.";

//Percentage::__init__
const char* PYPER_INIT =
		"Constructor of the :py:class:`Percentage` class. Takes as input a float "
		"value between 0 and 100 (default: 0) and initializes the percentage. "
		"Raises a :py:exc:`InvalidPercentageException` if the value is not between "
		"0 and 100.";

//Percentage::value
const char* PYPER_VALUE =
		"Returns the value of the percentage [0-100].";

//Percentage::set_value
const char* PYPER_SET_VALUE =
		"Sets the value of the percentage. Raises a "
		":py:exc:`InvalidPercentageException` if the value is not between "
		"0 and 100.";
}
}


#endif // PYMESHLAB_PYPERCENTAGE_DOC_H
