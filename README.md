# PyMeshLab

![BuildAndTestUbuntu](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/BuildAndTestUbuntu/badge.svg)
![BuildAndTestMacOS](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/BuildAndTestMacOS/badge.svg)
![BuildAndTestWindows](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/BuildAndTestWindows/badge.svg)

PyMeshLab is a Python library that interfaces to [MeshLab](https://github.com/cnr-isti-vclab/meshlab), the popular open source application for editing and processing large 3D triangle meshes. Python bindings are generated using [pybind11](https://github.com/pybind/pybind11).

## Run PyMeshLab

To use PyMeshLab, you can download the [last release](https://github.com/cnr-isti-vclab/PyMeshLab/releases) or the [last artifact](https://github.com/cnr-isti-vclab/PyMeshLab/actions) according to your platform and your python version. Extract the archive in a folder called `PyMeshLab`, then from outside the folder:
```
python
>>> from PyMeshLab import pymeshlab
```
To run the tests, after cloning this repo, you can extract the downloaded archive inside the `PyMeshLab` folder, and then from the outside folder:
```
python run_tests.py
```

## Build PyMeshLab

Clone this repository with the `--recursive` flag, needed to clone also MeshLab and pybind11 repositories:

```
git clone --recursive https://github.com/cnr-isti-vclab/PyMeshLab.git
```
The only dependencies that PyMeshLab requires in order to be built are Qt >= 5.9 and Python >= 3.5.

PyMeshLab requires a properly MeshLab build. We suggest to use the `install/[platform]/build_meshlab.[sh/ps1]` script that takes care to build, deploy and then copy all MeshLab files inside the `PyMeshLab/lib` directory. For example, on Linux:

```
sh install/linux/build_meshlab.sh
```
or Windows:
```
.\install\windows\build_meshlab.ps1
```
Then, you can build PyMeshLab:
```
sh install/linux/build_pymeshlab.sh
```
or Windows:
```
.\install\windows\build_pymeshlab.ps1
```
these script will place the library inside the `PyMeshLab` folder of this repository.

For more details, please take a look at the [Github Actions Workflows](https://github.com/cnr-isti-vclab/PyMeshLab/tree/master/.github/workflows) that build and run tests automatically in all the platforms.
...

## License

 The PyMeshlab source is released under the [GPL License](LICENSE).
 
## Copyright

```
   PyMeshLab
   All rights reserved.

   VCGLib  http://www.vcglib.net                                     o o
   Visual and Computer Graphics Library                            o     o
                                                                  _   O  _
   Paolo Cignoni                                                    \/)\/
   Visual Computing Lab  http://vcg.isti.cnr.it                    /\/|
   ISTI - Italian National Research Council                           |
   Copyright(C) 2005-2018                                             \
```

## Contacts

 - Paolo Cignoni (paolo.cignoni (at) isti.cnr.it)
 - Alessandro Muntoni (alessandro.muntoni (at) isti.cnr.it)

## Feedback

For documented and repeatable bugs, feature requests, etc., please use the [GitHub issues](https://github.com/cnr-isti-vclab/PyMeshLab/issues).
