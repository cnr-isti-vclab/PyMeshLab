#ifndef PYMESHLAB_PYPERCENTAGE_DOC_H
#define PYMESHLAB_PYPERCENTAGE_DOC_H

namespace pymeshlab {
namespace doc {

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
