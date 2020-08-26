.. _meshset:

=======
MeshSet
=======

The MeshSet class represents a container that allows to collect a set of Meshes,
where every Mesh corresponds to a layer of MeshLab.
From this class, you can apply all the filters of meshlab
by calling the :py:meth:`meshlab.MeshSet.apply_filter` method.

In every non-empty MeshSet, there is a selected mesh, that
can be accessed using the method :py:meth:`meshlab.MeshSet.current_mesh`.

.. autoclass:: meshlab.MeshSet
   :special-members:
   :members:
