## Build PyMeshLab

### Build scripts

We provide a set of platform dependent scripts that should make easier to build PyMeshLab. Scripts can be found [here](../scripts/).
Otherwise, if you want to build manually PyMeshLab, you can follow these instructions.

### Source code

The main `CMakeLists.txt` file is placed in the root directory of this repository.

The C++ source code of pymeshlab is contained inside the `src/pymeshlab` directory. To see how it is organized, see the contained [README.md](src/pymeshlab/README.md).
Inside the src directory there are also two directories:
- `meshlab`: contains the subrepository of MeshLab;
- `utilities`: contains some utilities necessary to deploy pymeshlab on specific platforms.

### Requirements

To be built, PyMeshLab requires a C++14 compiler (gcc, clang and MSVC are supported), CMake >= 3.18, Python >= 3.7 and Qt = 5.15.
There are also some other platform-dependedent dependencies, that can be installed easily using package managers (`apt-get`, `brew` and `choco`).
For more details, see the script `0_setup_env.h` contained into the directory `scripts/[platform]/`.
For Windows, note that we use a `bash` script, therefore it needs to be run in a Linux subsystem environment.

### Clone

Clone this repository with the `--recursive` flag, needed to clone also MeshLab and pybind11:

```
git clone --recursive https://github.com/cnr-isti-vclab/PyMeshLab.git
```

### Build

To build PyMeshLab, just run:

```
mkdir build
cd build
cmake -GNinja ..
ninja
ninja install
```

By default, PyMeshLab will be installed inside the `pymeshlab` directory of the repo.
Therefore, after installed, you can just cd to the root of this repository and then `import pymeshlab` from a python shell.

### Build options

By default, the scripts listed above will build a pymeshlab python module.
There are two additional options in the CMake configuration:

- `PYMESHLAB_BUILD_DEBUG` (default: `OFF`): if set to `ON`, pymeshlab will be built in debug mode, and instead of building `pymeshlab/main.cpp`, the file `pymeshlab/debug_main.cpp` will be built . This file contains a `main` function set to call pymeshlab functions under C++ and therefore allows to debug pymeshlab under a full C++ environment;
- `PYMESHLAB_UPDATE_DOC` (default: `OFF`): if set to `ON`, pymeshlab will be built but with `pymeshlab/doc_main.cpp` instead of `pymeshlab/main.cpp`. This build system will generate an executable that will automatically update the file `docs/filter_list.rst`, containing the documentation of the pymeshlab filter.

## Deploy PyMeshLab

By executing the above instructions, the installed pymeshlab directory will not be a self-contained pymeshlab directory (it will depend on Qt libs that are installed in the system). To make pymeshlab portable, we provide some scripts that you can find in the `scripts` directory in the root of this repo.

```
sh scripts/[platform]/1_build.sh
sh scripts/[platform]/2_deploy.sh
```

For more details, please take a look at the relative [readme](../scripts/README.md) and at the [Github Actions Workflows](https://github.com/cnr-isti-vclab/PyMeshLab/tree/master/.github/workflows) that use them to automatically build PyMeshLab in all the platforms.
