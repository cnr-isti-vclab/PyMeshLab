.. _custom_mesh_attributes:

======================
Custom Mesh Attributes
======================

This example shows how to create new user defined attributes that can be associated to vertices or faces of a Mesh, using the ``define_new_per_vertex_attribute`` filter. These attributes can be then extracted and saved in a ``numpy.array``.

This script can be executed by running the following command:

.. code-block:: none

   pytest --pyargs pymeshlab -k 'example_custom_mesh_attributes'

**tests/example_custom_mesh_attributes.py**

.. include:: ../../pymeshlab/tests/example_custom_mesh_attributes.py
   :literal:
