.. _absolute_value:

=============
AbsoluteValue
=============

The AbsoluteValue class is a simple class that allows to pass some parameters to
filters as a an AbsoluteValue and it is basically used to distinguish to
parameters that can have values represented with the Percentage class.

Here is a simple example of usage of the class:

.. code-block:: python

   ms = pymeshlab.MeshSet()
   [...]
   ms.generate_resampled_uniform_mesh(cellsize=AbsoluteValue(0.01), offset=AbsoluteValue(1))

This class is necessary to distinguish between relative Percentage values and
AbsoluteValue object. Before version 2021.10, instead of this class, the type
float was used, leading to unwanted errors by the users. The usage of this class
makes sure that the user knows what type of value is passing to parameters that
could accept both absolute values or percentages w.r.t. some other measures.

Check the :ref:`apply_filter_parameters_percentage` tutorial for further examples.

.. autoclass:: pmeshlab.AbsoluteValue
   :special-members:
   :members:
