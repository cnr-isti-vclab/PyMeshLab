#ifndef PYMESHLAB_PYEXCEPTIONS_H
#define PYMESHLAB_PYEXCEPTIONS_H

#include <pybind11/pybind11.h>

namespace pymeshlab {

void initExceptions(pybind11::module& m);

}
#endif // PYMESHLAB_PYEXCEPTIONS_H
