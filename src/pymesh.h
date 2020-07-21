#ifndef PYMESH_H
#define PYMESH_H

#include <pybind11/pybind11.h>

namespace pymeshlab {

void initMesh(pybind11::module& m);

}

#endif // PYMESH_H
