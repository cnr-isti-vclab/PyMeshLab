## Build and Deploy PyMeshLab scripts

This directory contains a set of scripts for automatically build and deploy pymeshlab.
Before using them, be sure to install on your system:

* GCC, Clang or MSVC with c++14 support
* CMake >= 3.9
* Python >= 3.6
* Qt = 5.15

For every platform there are two main scripts:

* `1_build.sh`: this script will build PyMeshLab and then install int in the `pymeshlab` directory of the repository;
* `2_deploy.sh`: this script will deploy PyMeshLab starting from the installed `pymeshlab` directory.

At the end, the `pymeshlab` directory will be a self contained python module.

### `1_build.sh`
You can run this script in the following way:
```
sh 1_build.sh
```

The script accepts the following arguments (default directories are relative to the root of the repository):

* `-b=buid/path` or `--build_path=build/path`: the path where PyMeshLab will be built. Default is `src/build`;
* `-i=install/path` or `--install_path=install/path`: the path where PyMeshLab will be installed. Default is `pymeshlab`;
* `-jX`: parameter used for multicore compilation, where `X` is the number of cores used to build PyMeshLab. Default is `-j4`;
* `--no-build-meshla`: option used to just build PyMeshLab without building all the MeshLab libraries and plugins. When this option is selected, the build system will expect in the build directory to find all the MeshLab libraries and plugins already built and placed in the right positions (depending on the OS). This option is mainly used for fast compilation under development, or to speed up automatic builds of PyMeshLab;
* `--debug`: used to build PyMeshLab with debug symbols.

### `2_deploy.sh`
You can run this script in the following way:
```
sh 2_deploy.sh
```
The only argument that accepts the script is the path on which PyMeshLab has been installed by the `1_build.sh` script (with no arguments, it will be the `pymeshlab` directory).
Example:
```
sh 2_deploy.sh my/install/path
```


### OS Dependent Notes
#### Linux
The `2_deploy.sh` script can be run only on the "oldest supported linux distro", due to the usage of the tool [linuxdeployqt](https://github.com/probonopd/linuxdeployqt). For more deetails see [here](https://github.com/probonopd/linuxdeployqt/issues/340).

#### MacOS
The build script for MacOS will generate an appbundle called "dummybin.app" (the cmake option `BUILD_DUMMY_BIN_MAC_DEPLOY` is set to `ON`). This is necessary to deploy PyMeshLab, since the tool `macdeployqt` just works with appbundles. The deploy script will then move all the required files outside the `dummybin.app` package, and then delete it.

#### Windows
Windows scripts are **bash scripts**. Be sure to run them in a linux subsystem.
