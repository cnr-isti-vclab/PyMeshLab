.. _custom_mesh_attributes:

======================
Custom Mesh Attributes
======================

This example shows how to create new user defined attributes that can be associated to vertices or faces of a Mesh, using the filters:

   - ``compute_new_custom_scalar_attribute_per_vertex``
   - ``compute_new_custom_point_attribute_per_vertex``
   - ``compute_new_custom_scalar_attribute_per_face``
   - ``compute_new_custom_point_attribute_per_face``

These custom attributes can be then extracted and saved in a ``numpy.array``.

This script can be executed by running the following command:

.. code-block:: none

   pytest --pyargs pymeshlab -k 'example_custom_mesh_attributes'

**tests/example_custom_mesh_attributes.py**

.. include:: ../../pymeshlab/tests/example_custom_mesh_attributes.py
   :literal:
