# PyMeshLab

![BuildAndTestUbuntu](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/BuildAndTestUbuntu/badge.svg)
![BuildAndTestMacOS](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/BuildAndTestMacOS/badge.svg)
![BuildAndTestWindows](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/BuildAndTestWindows/badge.svg)

PyMeshLab is a Python library that interfaces to [MeshLab](https://github.com/cnr-isti-vclab/meshlab), the popular open source application for editing and processing large 3D triangle meshes. Python bindings are generated using [pybind11](https://github.com/pybind/pybind11).

## Install PyMeshLab

You can easily install PyMeshLab using pip:
```
pip3 install git+https://github.com/cnr-isti-vclab/PyMeshLab
```
### Note for MacOS
If you get the error ```urllib.error.URLError: SSL: CERTIFICATE_VERIFY_FAILED```, look for the file ```Certificates.command``` inside your python directory and double click on it!

## Run PyMeshLab

After installing PyMeshLab through pip:
```
python
>>> import pymeshlab as ml
>>> ms = ml.MeshSet()
```
You can load, save meshes and apply MeshLab filters:
```
ms.load_mesh('airplane.obj')
ms.apply_filter('convex_hull')
ms.save_mesh('convex_hull.ply')
```
You can list all the available filters and theirs parameters:
```
ms.print_filter_list()
ms.print_filter_parameter_list('surface_reconstruction_screened_poisson')
```
And apply filters with your parameters:
```
ms.apply_filter('noisy_isosurface', resolution=128)
```

To run the tests:
```
pip3 install pytest
pytest --pyargs pymeshlab
```

## Build PyMeshLab

Clone this repository with the `--recursive` flag, needed to clone also MeshLab and pybind11 repositories:

```
git clone --recursive https://github.com/cnr-isti-vclab/PyMeshLab.git
```
PyMeshLab requires Qt >= 5.9, Python >= 3.5, and a properly MeshLab build. We suggest to use the `install/[platform]/build_meshlab.[sh/ps1]` script that takes care to build, deploy and then copy all MeshLab files inside the `pymeshlab/lib` directory. For example, on Linux:

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
these script will place the meshlab module inside the `pymeshlab` folder of this repository.

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
   Copyright(C) 2020                                                  \
```

## Contacts

 - Paolo Cignoni (paolo.cignoni (at) isti.cnr.it)
 - Alessandro Muntoni (alessandro.muntoni (at) isti.cnr.it)

## Feedback

For documented and repeatable bugs, feature requests, etc., please use the [GitHub issues](https://github.com/cnr-isti-vclab/PyMeshLab/issues).
