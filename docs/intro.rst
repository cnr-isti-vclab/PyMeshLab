.. _intro:

Getting Started
===============

The main class of PyMeshLab is the :ref:`meshset` class. It represents the current state of MeshLab (containing a set of meshes, rasters...). See the documentation of the :ref:`meshset` class for more details.

After installing PyMeshLab through pip:

.. code-block:: python

   import pymeshlab
   ms = pymeshlab.MeshSet()

You can load, save meshes and apply MeshLab filters:

.. code-block:: python

   ms.load_new_mesh('airplane.obj')
   ms.convex_hull()
   ms.save_current_mesh('convex_hull.ply')

You can list all the available filters and theirs parameters:

.. code-block:: python

   ms.print_filter_list()
   ms.print_filter_parameter_list('surface_reconstruction_screened_poisson')

And apply filters with your parameters:

.. code-block:: python

   ms.noisy_isosurface(resolution=128)

Most of the MeshLab filters will change in some way the state of the MeshSet. The behaviour of how filters change the state is the same of what
happens when applying the same filter in MeshLab.
Some filters may return values, and these values are placed in a dictionary that is returned by the called method:

.. code-block:: python

   out_dict = ms.compute_geometric_measures()
   print(out_dict['surface_area'])

For further example usage of the libraries, check the :ref:`tutorials` page, which provides several use case examples of PyMeshLab.

To run the PyMeshLab tests, you can use ``pytest``:

.. code-block:: shell

   pip3 install pytest
   pytest --pyargs pymeshlab
