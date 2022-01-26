.. _apply_filter:

==============
Apply a Filter
==============

This example shows how to apply a filter from an instance of the :ref:`meshset` class.
This specific test applies the filter ``generate_convex_hull``, which uses as input the current mesh of the MeshSet, and it creates a new one that is the convex hull of the input mesh. The filter does not take any parameter, and automatically changes the current mesh of the MeshSet when it is executed.

This script can be executed by running the following command:

.. code-block:: none

   pytest --pyargs pymeshlab -k 'apply_filter'

**tests/example_apply_filter.py**

.. include:: ../../pymeshlab/tests/example_apply_filter.py
   :literal:
