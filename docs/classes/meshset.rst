.. _meshset:

=======
MeshSet
=======

The MeshSet class is allows to collect a set of Meshes,
where every Mesh corresponds to a layer of MeshLab.
From this class, you can apply all the filters of meshlab
by calling the :py:meth:`meshlab.MeshSet.apply_filter` method.

In every non-empty MeshSet, there is a selected mesh, that
can be accessed using the method 'current_mesh'.

.. autoclass:: meshlab.MeshSet
   :members:
