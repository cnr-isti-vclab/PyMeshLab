.. _apply_filter_parameters_percentage:

==========================================
Apply Filter Parameters: Ranged Percentage
==========================================

This example shows how to pass a ranged percentage as a parameter to a filter. 
This is useful when you have no clue on the size or the units used and you want to perform some computations that depends on theactual size of the object. 
Typical example is the size small floating pieces that you want to delete in a noisy mesh. 

This type of values can actually be passed in two different ways: as an
PureValue (e.g. the actual size of the object you want to be reomved) or as a PercentageValue like 10.0 that, in that specific case, will denote that you will remove the object whose size is 10% of the diagonal of the bounding box of the affected mesh. The range on which the filter operates is automatically computed by the filter itself and described in the documentation of the filter. 
 
Note: before version  2022.xx Name Change 
Note: before version 2021.10, instead of AbsoluteValue, the type
float was used, leading to unwanted errors by the users. The usage of this classes makes sure that the user knows what type of value is passing to
parameters that could accept both pure values or percentages w.r.t. some range.
See :ref:`percentage` and :ref:`absolute_value` for more details.

This script can be executed by running the following command:

.. code-block:: none

   pytest --pyargs pymeshlab -k 'apply_filter_parameters_percentage'

**tests/example_apply_filter_parameters_percentage.py**

.. include:: ../../pymeshlab/tests/example_apply_filter_parameters_percentage.py
   :literal:
