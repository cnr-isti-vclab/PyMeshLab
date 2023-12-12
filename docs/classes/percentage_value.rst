.. _percentage_value:

===============
PercentageValue
===============

The PercentageValue class is a simple class that allows to pass some parameters to
filters as a Percentage of something (specified on the documentation of every
filter). A PercentageValue object contains a single float value bounded between 0
and 100.

Here is a simple example of usage of the class:

.. code-block:: python

   ms = pymeshlab.MeshSet()
   [...]
   ms.generate_resampled_uniform_mesh(cellsize=PercentageValue(2.0), offset=PercentageValue(30.0))

In this case the filter will make an uniform resampling of the input mesh using a grid with a cell size of 2% of the diagonal of the bounding box of the mesh.
This class is necessary to distinguish between relative Percentage values and
absolute values (which are of type :ref:`pure_value`).

Check the :ref:`apply_filter_parameters_percentage` tutorial for further examples.

.. autoclass:: pmeshlab.PercentageValue
   :special-members:
   :members:
