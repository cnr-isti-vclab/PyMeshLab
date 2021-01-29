.. _apply_filter_parameters_check_default_values:

=============================================
Apply Filter Parameters: check default values
=============================================

Sometime could be useful to check the default values that would be set to filter parameters. In fact, some filter set default values depending, for example, on the input mesh of the filter, or on the entire MeshSet. This is useful especially for parameters that would depend on features of the mesh like number of vertices or faces, bounding box diagonal...
PyMeshLab provides a MeshSet function that returns in a dictionary all the parameters of a filter and their default values that would be used if the filter would be applied in the current MeshSet.

This script can be executed by running the following command:

.. code-block:: none

   pytest --pyargs pymeshlab -k 'apply_filter_parameters_check_default_values'

**tests/example_apply_filter_parameters_check_default_values.py**

.. include:: ../../pymeshlab/tests/example_apply_filter_parameters_check_default_values.py
   :literal:
