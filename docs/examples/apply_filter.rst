.. apply_filter:

============
apply_filter
============

This example shows how to apply a filter using the :py:meth:`pmeshlab.MeshSet.apply_filter` function of the :ref:`meshset` class.
This specific test applies the filter ``convex_hull``, which uses as input the current mesh of the MeshSet, and it creates a new one that is the convex hull of the input mesh. The filter does not take any parameter, and automatically changes the current mesh of the MeshSet when it is executed.

This script can be executed by running the following command:

.. code-block:: none

   pytest --pyargs pymeshlab -k 'convex_hull'

**tests/test_convex_hull.py**

.. include:: ../../pymeshlab/tests/test_convex_hull.py
   :literal:
