.. apply_filter_parameters_percentage:

===================================
apply_filter parameters: Percentage
===================================

This example shows how to pass a Percentage as a parameter to a filter through the :py:meth:`pmeshlab.MeshSet.apply_filter` function.
This type of values can actually be passed in two different ways: as an absolute value or as a Percentage of something else.
See :ref:`percentage` for more details.

This script can be executed by running the following command:

.. code-block:: none

   pytest --pyargs pymeshlab -k 'remove_isolated_pieces_diameter'

**tests/test_remove_isolated_pieces_diameter.py**

.. include:: ../../pymeshlab/tests/test_remove_isolated_pieces_diameter.py
   :literal:
