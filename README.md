# PyMeshLab

![Linux](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/Linux/badge.svg)
![MacOS](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/MacOS/badge.svg)
![Windows](https://github.com/cnr-isti-vclab/PyMeshLab/workflows/Windows/badge.svg)

[![Documentation Status](https://readthedocs.org/projects/pymeshlab/badge/?version=latest)](https://pymeshlab.readthedocs.io/en/latest/?badge=latest)

PyMeshLab is a Python library that interfaces to [MeshLab](https://github.com/cnr-isti-vclab/meshlab), the popular open source application for editing and processing large 3D triangle meshes. Python bindings are generated using [pybind11](https://github.com/pybind/pybind11).

## Documentation

You can find the official documentation [here](https://pymeshlab.readthedocs.io/).

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

And apply filters with your parameters:
```
ms.apply_filter('noisy_isosurface', resolution=128)
```

You can find all the names and parameters of the filters in the [List of Filters](https://pymeshlab.readthedocs.io/en/latest/filter_list.html) page of the documentaiton.

To run the tests:
```
pip3 install pytest
pytest --pyargs pymeshlab
```

## Build PyMeshLab

See the [`src`](src/README.md) folder that contains the instructions to build PyMeshLab.

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
