.. _changelog:

..    include:: <isonum.txt>

=========
Changelog
=========

2022.2
-------

   * based on MeshLab 2022.02
   * all filters renamed, old filter names are now deprecated
   * throw exception when a parameter name is not found (was just a print before)
   * possibility to iterate over a MeshSet
   * Mesh class now allows to access to id, visibility, label and trasform matrix of the Mesh
   * possibility to construct a Mesh having edges
   * possibility to get textures from a Mesh
   * bounded floats arguments in filters now are clamped in the [min-max] interval
   * bugfixes
   * possibility to show a `polyscope <https://polyscope.run/py/>`_ gui of the content of the MeshSet
   * new plugin filter parametrization for harmonic and lscm parametrization computation
   * possibility to search for filters using ``pymeshlab.search()`` function
   * possibility to set verbosity just for printing parameters when executing a filter

2021.10
-------

   * based on MeshLab 2021.10
   * new methods to Mesh class:

      * possibility to add custom point attributes to meshes
      * possibility to get polygonal faces
      * possibility to get edges
      * possibility to get vertex and face curvature principal directions
      * possibility to add vertex and face colors from matrix

   * Percentage parameters do not accept anymore float arguments anymore, but only objects of type `Percentage` or `AbsoluteValue`
   * removed libopengl.so dependency on linux
   * get min and max from BoundingBox class
   * possibility to manage mesh visibility from MeshSet
   * possibility to save custom attributed into ply files
   * new filters:

      * nxs_build
      * nxs_compress
      * global_align_meshes
      * icp_between_meshes
      * overlapping_meshes
      * define_new_per_face_custom_point_attribute
      * define_new_per_vertex_custom_point_attribute

   * removed filters:

      * change_the_current_layer
      * change_visibility_of_layers
      * compact_faces
      * compact_vertices
      * cross_field_creation
      * select_folded_faces
      * vertex_color_noise

   * unified filters:

      * repair_non_manifold_edges_by_removing_faces and repair_non_manifold_edges_by_splitting_vertices |rarr| repair_non_manifold_edges
      * remove_t_vertices_by_edge_collapse and remove_t_vertices_by_edge_flip |rarr| remove_t_vertices

   * renamed filters:

      * define_new_per_face_attribute |rarr| define_new_per_face_custom_scalar_attribute
      * define_new_per_vertex_attribute |rarr| define_new_per_vertex_custom_scalar_attribute
      * directional_geom_preserv |rarr| directional_geometry_preservation
      * select_visible_points |rarr| select_convex_hull_visible_points
      * \select_non_manifold_edges_ |rarr| select_non_manifold_edges

   * bugfixes

2021.07
-------

  * based on MeshLab 2021.07
  * import/export of e57 file format
  * import of gltf/glb file format
  * export of nxs/nxz file format
  * new mesh boolean filters
  * possibility to add custom attributes to meshes
  * possibility to create polygonal meshes
  * possibility to choose if save textures when saving mesh
  * added some dunder methods to MeshSet class
  * bugfixes


0.2.1
-----

**05/2021**

   * based on MeshLab 2021.05
   * bugfixes
   * possibility to export per wedge texcoords from meshes
   * possibility to laod MeshLab plugins at runtime with ``pymeshlab.load_plugin('<myplugin>')``


0.2
---

**02/2021**

  * run filters methods directly from MeshSet (e.g. ``ms.convex_hull()`` instead of ``ms.apply_filter('convex_hull'))``
  * create new Mesh takes custom per vertex and per face quality values
  * plugins that need GLContext work now
  * possibility to enable cpu opengl on windows with ``pymeshlab.use_cpu_opengl()``
  * bugfix on input file parameters
  * other small bugfixes and performance improvements


0.1.9
-----

**01/2021**

  * possibility to get the default parameter values used when applying a filter
  * possibility to get user defined attributes of meshes
  * new tutorial section in the documentation
  * bugfixes;
  * FilterMeasure Plugin return all the values;
  * new minor functionalities;


0.1.8
-----

**01/2021**

   * bugfixes;
   * FilterMeasure Plugin return values as dictionary;
   * better management of double precision parameter values;
   * improved documentation;
   * new minor functionalities;


0.1.7
-----

**12/2020**

   * bugfixes;
   * MeshSet allows to load rasters;
   * support to python 3.9;
   * wheels available!


0.1.6
-----

**11/2020**

   * the build system is now cmake
   * meshlab libraries and filters use now double precision
   * ``apply_filter`` now supports mesh parameters through MeshSet ids
   * ``apply_filter`` returns a dictionary that could contain set of values, depending on the run filter. Right now, the only filter that returns values is the hausdorff_distance filter
   * some methods have been renamed for more consistence
   * python 3.5 not supported anymore
   * bugfixes


0.1.5
-----

**09/2020**

   *  ``apply_filter`` now supports other type of parameters:

      *  enum
      *  filename

   *  possibility to add Meshes in a MeshSet
   *  possibility to clear a MeshSet
   *  possibility to import Meshes from numpy arrays
   *  bugfixes


0.1.4
-----

**09/2020**

``apply_filter`` now supports other type of parameters:

   * bounded float
   * Color
   * 3D Point (as one dimension numpy array of 3 elements)
   * 4x4 Matrix (as two dimensions numpy array of 4x4 elements)

Documentation of all the filters and their parameters have been added to the docs, which can be found at https://pymeshlab.readthedocs.io/en/latest/index.html

0.1.3
-----

**08/2020**

   * Support to MeshLab's MLX filter scripts
   * various bugfixes


0.1.2
-----

**08/2020**

   * Numpy becomes a dependency
   * Support to filter_select plugin
   * Possibility to load and save mlp and other project files supported by MeshLab
   * Mesh data can be exported to numpy arrays


0.1.1
-----

**07/2020**

Possibility to load/save meshes, and apply filters.

.. code-block:: python

   import pymeshlab
   ms = pymeshlab.MeshSet()
   ms.load_mesh('airplane.obj')
   ms.apply_filter('convex_hull')
   ms.save_mesh('convex_hull.ply')

You can list all the available filters:

.. code-block:: python

   ms.print_filter_list()

and print all the parameters needed by a filter:

.. code-block:: python

   ms.print_filter_parameter_list('surface_reconstruction_screened_poisson')

and apply filters with parameters:

.. code-block:: python

   ms.apply_filter('noisy_isosurface', resolution=128)

Right now, 4 types of parameters are supported: ``bool``, ``int``, ``float``, ``str``


0.1
---

**07/2020**

First PyMeshLab release.
First interfaces to the following classes:

   * Mesh
   * MeshSet

Possibility to load and a save a mesh using I/O meshlab plugins:

.. code-block:: python

   import pymeshlab as ml
   ms = ml.MeshSet()
   ms.load_mesh('airplane.obj')
   ms.load_mesh('bone.ply')

   mesh = md.current_mesh() #bone.ply
   print(mesh.vertex_number())
   md.save_mesh('bone.obj')
