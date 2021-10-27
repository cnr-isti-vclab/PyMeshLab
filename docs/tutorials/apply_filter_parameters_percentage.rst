.. _apply_filter_parameters_percentage:

===================================
Apply Filter Parameters: Percentage
===================================

This example shows how to pass a Percentage as a parameter to a filter.
This type of values can actually be passed in two different ways: as an
AbsoluteValue or as a Percentage of something else.
Before version 2021.10, instead of AbsoluteValue, the type
float was used, leading to unwanted errors by the users. The usage of the class
AbsoluteValue makes sure that the user knows what type of value is passing to
parameters that could accept both absolute values or percentages w.r.t. some
other measures.
See :ref:`percentage` and :ref:`absolute_value` for more details.

This script can be executed by running the following command:

.. code-block:: none

   pytest --pyargs pymeshlab -k 'apply_filter_parameters_percentage'

**tests/example_apply_filter_parameters_percentage.py**

.. include:: ../../pymeshlab/tests/example_apply_filter_parameters_percentage.py
   :literal:
