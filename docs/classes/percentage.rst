.. _percentage:

==========
Percentage
==========

The Percentage class is a simple class that allows to pass some parameters to
filters as a Percentage of something (specified on the documentation of every
filter). A Percentage object contains a single float value bounded between 0
and 100.

Here is a simple example of usage of the class:

.. code-block:: python

   ms = pymeshlab.MeshSet()
   [...]
   ms.uniform_mesh_resampling(cellsize=Percentage(0.01), offset=1)

This class is necessary to distinguish between relative Percentage values and
absolute values (which are of type :ref:`absolute_value`).

Check the :ref:`apply_filter_parameters_percentage` tutorial for further examples.

.. autoclass:: pmeshlab.Percentage
   :special-members:
   :members:
