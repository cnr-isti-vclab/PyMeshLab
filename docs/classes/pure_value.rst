.. _pure_value:

=========
PureValue
=========

The PureValue class is a simple class that allows to pass some parameters to
filters as a an PureValue and it is basically used to distinguish to
parameters that can have values represented with the PercentageValue class.

Here is a simple example of usage of the class:

.. code-block:: python

   ms = pymeshlab.MeshSet()
   [...]
   ms.generate_resampled_uniform_mesh(cellsize=PureValue(0.01), offset=PureValue(1))

This class is necessary to distinguish between relative PercentageValue objects and
PureValue object. Before version 2021.10, instead of this class, the type
float was used, leading to unwanted errors by the users. The usage of this class
makes sure that the user knows what type of value is passing to parameters that
could accept both pure values or percentages w.r.t. some other measures.

Check the :ref:`apply_filter_parameters_percentage` tutorial for further examples.

.. autoclass:: pmeshlab.PureValue
   :special-members:
   :members:
