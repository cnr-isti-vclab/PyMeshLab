.. _meshset:

=======
MeshSet
=======

The MeshSet class represents a container that allows to collect a set of Meshes,
where every Mesh corresponds to a layer of MeshLab. Every mesh has an unique ID
that identifies it inside the MeshSet.

In every non-empty MeshSet, there is a current mesh, that
can be accessed using the method :py:meth:`pmeshlab.MeshSet.current_mesh`.

From the MeshSet class, you can apply all the filters of MeshLab
by calling the associated methods. In this page are listed all the methods of the
MeshSet class except the methods associated to filters. For the list of these methods,
please refer to the :ref:`filter_list` page. Sometimes, filters change the current mesh when applied, setting it to their output.
The behaviour is always the same of MeshLab.

Note that the MeshSet class is not thread safe: it is not safe to run multiple filters in parallel on the same MeshSet object.

.. autoclass:: pmeshlab.MeshSet
   :special-members:
   :members:


   .. py:method:: show_polyscope() -> None

      Shows a polyscope window (https://polyscope.run/py/) of the current MeshSet, rendering all the meshes contained
      in it. Requires the polyscope package (``pip install polyscope``).
