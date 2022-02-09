.. _index:

=========
PyMeshLab
=========

PyMeshLab is a Python library that interfaces to `MeshLab`_, the popular open source application for editing and processing large 3D triangle meshes. Python bindings are generated using `pybind11`_.

.. _MeshLab: https://github.com/cnr-isti-vclab/meshlab
.. _pybind11: https://github.com/pybind/pybind11

.. toctree::
   :maxdepth: 1

   about

Filters renaming
================

Starting from version 2022.2 PyMeshLab filter names have been renamed in order to be more explanatory on the operation they perform.
Old filter names have been deprecated and will be removed starting from the next version of PyMeshLab.
To automatically rename the filters called in your python script, you can run the following lines:

.. code-block:: python

   import pymeshlab
   pymeshlab.replace_pymeshlab_filter_names('/path/to/my/script.py') # replace single script

   # or
   pymeshlab.replace_pymeshlab_filter_names('/path/to/my/dir/') # replace all *.py and *.ipynb scripts in dir

Contents
========


.. toctree::
   :maxdepth: 1

   installation
   intro
   filter_scripts
   classes
   filter_list
   io_format_list
   tutorials
   changelog

References
==========

.. image:: https://zenodo.org/badge/DOI/10.5281/zenodo.4438750.svg
    :target: https://doi.org/10.5281/zenodo.4438750

Please, when using this tool, cite:

.. code-block:: latex

   @software{pymeshlab,
     author       = {Alessandro Muntoni and Paolo Cignoni},
     title        = {{PyMeshLab}},
     month        = jan,
     year         = 2021,
     publisher    = {Zenodo},
     doi          = {10.5281/zenodo.4438750}
   }
