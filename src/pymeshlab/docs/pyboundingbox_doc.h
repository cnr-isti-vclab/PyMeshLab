#ifndef PYMESHLAB_PYBOUNDINGBOX_DOC_H
#define PYMESHLAB_PYBOUNDINGBOX_DOC_H

namespace pymeshlab {
namespace doc {

//BoundingBox::__init__
const char* PYBB_INIT =
		"Creates an invalid Bounding Box (min: [1,1,1], max:[-1,-1,-1]).";

//BoundingBox::diagonal
const char* PYBB_DIAGONAL =
		"Returns the diagonal of the Bounding Box.";

//BoundingBox::dim_x
const char* PYBB_DIM_X =
		"Returns the X size of the Bounding Box.";

//BoundingBox::dim_y
const char* PYBB_DIM_Y =
		"Returns the Y size of the Bounding Box.";

//BoundingBox::dim_z
const char* PYBB_DIM_Z =
		"Returns the Z size of the Bounding Box.";

}
}

#endif // PYMESHLAB_PYBOUNDINGBOX_DOC_H
