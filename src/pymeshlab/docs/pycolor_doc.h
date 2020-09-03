#ifndef PYMESHLAB_PYCOLOR_DOC_H
#define PYMESHLAB_PYCOLOR_DOC_H

namespace pymeshlab {
namespace doc {

//Color::__init__
const char* PYCOLOR_INIT_RGB =
		"Constructs a color with the int RGB values r, g, b, and the alpha-channel "
		"(transparency) value of 255.";

//Color::__init__
const char* PYCOLOR_INIT_RGBA =
		"Constructs a color with the int RGB values r, g, b, and the alpha-channel "
		"(transparency) value of a.";

//Color::red
const char* PYCOLOR_RED =
		"Returns the red color component of this color as integer.";

//Color::green
const char* PYCOLOR_GREEN =
		"Returns the green color component of this color as integer.";

//Color::blue
const char* PYCOLOR_BLUE =
		"Returns the blue color component of this color as integer.";

//Color::alpha
const char* PYCOLOR_ALPHA =
		"Returns the alpha color component of this color as integer.";

//Color::red_f
const char* PYCOLOR_REDF =
		"Returns the red color component of this color as float.";

//Color::green_f
const char* PYCOLOR_GREENF =
		"Returns the green color component of this color as float.";

//Color::blue_f
const char* PYCOLOR_BLUEF =
		"Returns the blue color component of this color as float.";

//Color::alpha_f
const char* PYCOLOR_ALPHAF =
		"Returns the alpha color component of this color as float.";

//Color::set_red
const char* PYCOLOR_SET_RED =
		"Sets the red color component of this color to r. Integer "
		"components are specified in the range 0-255.";

//Color::set_green
const char* PYCOLOR_SET_GREEN =
		"Sets the green color component of this color to g. Integer "
		"components are specified in the range 0-255.";

//Color::set_blue
const char* PYCOLOR_SET_BLUE =
		"Sets the blue color component of this color to b. Integer "
		"components are specified in the range 0-255.";

//Color::set_alpha
const char* PYCOLOR_SET_ALPHA =
		"Sets the alpha color component of this color to a. Integer "
		"components are specified in the range 0-255.";

//Color::set_red_f
const char* PYCOLOR_SET_REDF =
		"Sets the red color component of this color to r. Float "
		"components are specified in the range 0-1.";

//Color::set_green_f
const char* PYCOLOR_SET_GREENF =
		"Sets the green color component of this color to g. Float "
		"components are specified in the range 0-1.";

//Color::set_blue_f
const char* PYCOLOR_SET_BLUEF =
		"Sets the blue color component of this color to b. Float "
		"components are specified in the range 0-1.";

//Color::set_alpha_f
const char* PYCOLOR_SET_ALPHAF =
		"Sets the alpha color component of this color to a. Float "
		"components are specified in the range 0-1.";


}
}

#endif // PYMESHLAB_PYCOLOR_DOC_H
