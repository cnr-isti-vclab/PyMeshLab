# PyMeshLab source code

PyMeshLab is a C++ project, organized in the following directory tree:

- `pybind11`: this directory contains the submodule of the library [pybind11](https://github.com/pybind/pybind11), necessary to bind C++ code into python;
- `pymeshlab`: this directory contains the actual core of the library: where all the operations are executed;
- `bindings`: this directory contains the bindings between the functionalities implemented inside `pymeshlab` and the classes and functions that can be called from python;
- `docs`: this directory contains header files that contains strings used to document the python classes and functions.

There are two additional cpp files (`doc_main.cpp` and `debug_main.cpp`) that can be built only enabiling two CMake configurations:

- `BUILD_PYMESHLAB_DEBUG` (default: `OFF`): if set to `ON`, pymeshlab will be built in debug mode, and instead of building `pymeshlab/main.cpp`, the file `pymeshlab/debug_main.cpp` will be built . This file contains a `main` function set to call pymeshlab functions under C++ and therefore allows to debug pymeshlab under a full C++ environment;
- `BUILD_PYMESHLAB_UPDATE_DOC` (default: `OFF`): if set to `ON`, pymeshlab will be built but with `pymeshlab/doc_main.cpp` instead of `pymeshlab/main.cpp`. This build system will generate an executable that will automatically update the file `docs/filter_list.rst`, containing the documentation of the pymeshlab filter.