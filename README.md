# PyMeshLab

![BuildAndTestUbuntu](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/BuildAndTestUbuntu/badge.svg)
![BuildAndTestMacOS](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/BuildAndTestMacOS/badge.svg)

PyMeshLab is a Python library that interfaces to [MeshLab](https://github.com/cnr-isti-vclab/meshlab), the popular open source application for editing and processing large 3D triangle meshes. Python bindings are generated using [pybind11](https://github.com/pybind/pybind11).

# Build PyMeshLab

Clone this repository with the `--recursive` flag, needed to clone also MeshLab and pybind11 repositories:

```
git clone --recursive https://github.com/cnr-isti-vclab/PyMeshLab.git
```
The only dependencies that PyMeshLab requires in order to be built are Qt >= 5.9 and Python >= 3.6.

PyMeshLab requires a properly MeshLab build. We suggest to use the `install/[platform]/build_meshlab.sh` script that takes care to build, deploy and then copy all MeshLab files inside the `PyMeshLab/lib` directory. For example, on linux:

```
sh install/linux/build_meshlab.sh
```

...

# License

 The Meshlab source is released under the [GPL License](LICENSE).
 
# Copyright

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

# Contacts

 - Paolo Cignoni (paolo.cignoni (at) isti.cnr.it)
 - Alessandro Muntoni (alessandro.muntoni (at) isti.cnr.it)

# Feedback

For documented and repeatable bugs, feature requests, etc., please use the [GitHub issues](https://github.com/cnr-isti-vclab/PyMeshLab/issues).
