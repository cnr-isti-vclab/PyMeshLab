.. _apply_filter_output:

====================
Apply Filter: Output
====================

This example shows how to extract the output of a filter. The output of this method is a python dictionary.
Note: most of the filters do not return nothing. Only for some filters makes sense to return some values.

The output dictionary is always on the form ``[key - value]``, where the ``key`` is of ``str`` type and the ``value`` can be a ``boolean``, ``int``, ``float`` or a ``numpy.array`` depending on what is best to represent the returned value.
Right now the :ref:`filter_list` documentation lacks on if and what type of values a filter returns (we are sorry about that!). We will expand the documentation in the future; in the meantime we suggest to look for the name and type of values returned by running the desired filter from a python console.

This script can be executed by running the following command:

.. code-block:: none

   pytest --pyargs pymeshlab -k 'apply_filter_output'

**tests/example_apply_filter_output.py**

.. include:: ../../pymeshlab/tests/example_apply_filter_output.py
   :literal:
