##Build PyMeshLab

###Requirements

To be built, PyMeshLab requires a C++11 compiler (gcc, clang and MSVC are supported), CMake >= 3.9, Python >= 3.6 and Qt >= 5.12.

###Clone

Clone this repository with the `--recursive` flag, needed to clone also MeshLab and pybind11 repositories:

```
git clone --recursive https://github.com/cnr-isti-vclab/PyMeshLab.git
```

###Build

To build PyMeshLab, just run:

```
mkdir src/build
cd src/build
cmake ..
make
make install
```

or, on Windows:
```
mkdir src\build
cd src\build
cmake -G "NMake Makefiles" ..
nmake
nmake install
```

By default, PyMeshLab will be installed inside the `pymeshlab` directory of the repo.
Therefore, after installed, you can just cd to the root of this repository and then `import pymeshlab` from a python shell.

##Deploy PyMeshLab

By executing the above instruction, the installed pymeshlab directory will not be a self-contained pymeshlab directorty (it will depend on Qt libs that are installed in the system). To make pymeshlab portable, we provide some scripts that you can find in the `scripts` directory in the root of this repo.

```
sh scripts/[platform]/1_build.sh
sh scripts/[platform]/2_deploy.sh
```

For more details, please take a look at the [Github Actions Workflows](https://github.com/cnr-isti-vclab/PyMeshLab/tree/master/.github/workflows) that build and run tests automatically in all the platforms.