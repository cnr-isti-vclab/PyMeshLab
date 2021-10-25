.. _io_format_list:

List of I/O Formats
===================

.. _load_mesh_parameters:

load mesh parameters
--------------------

Here are listed all the file formats that can be loaded usingthe functions :py:meth:`pmeshlab.MeshSet.load_new_mesh` and :py:meth:`pmeshlab.MeshSet.load_current_mesh`, with all the possible parameters that can be accepted by these functions.

.. data:: 3ds
   :noindex:

   .. raw:: html

      Load 3DS format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.3DS'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``load_in_a_single_layer : bool = False``

      .. raw:: html

         <i>Load in a single layer</i>: 3DS files may contain more than one mesh. If this parameter is set to false, all the meshes contained in the file will be merged in a single mesh.

.. data:: apts
   :noindex:

   .. raw:: html

      Load apts format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.apts'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: asc
   :noindex:

   .. raw:: html

      Load ASC format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.ASC'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``rowtoskip : int = 0``

      .. raw:: html

         <i>Header Row to be skipped</i>: The number of lines that must be skipped at the beginning of the file.

   ``triangulate : bool = True``

      .. raw:: html

         <i>Grid triangulation</i>: if true it assumes that the points are arranged in a complete xy grid and it tries to perform a naive height field triangulation of the input data.  Length of the lines is detected automatically by searching x jumps. If the input point cloud data is not arranged as a xy regular height field, no triangles are created.

.. data:: bre
   :noindex:

   .. raw:: html

      Load BRE format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.BRE'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``pointsonly : bool = False``

      .. raw:: html

         <i>only import points</i>: Just import points, without triangulation

   ``unify_vertices : bool = True``

      .. raw:: html

         <i>Unify Duplicated Vertices in BRE files</i>: The BRE format is not an vertex-indexed format. Each triangle is composed by independent vertices, so, usually, duplicated vertices should be unified

.. data:: ctm
   :noindex:

   .. raw:: html

      Load CTM format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.CTM'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: dae
   :noindex:

   .. raw:: html

      Load DAE format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.DAE'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: e57
   :noindex:

   .. raw:: html

      Load E57 format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.E57'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: es
   :noindex:

   .. raw:: html

      Load ES format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.ES'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``seed : int = 1``

      .. raw:: html

         <i>Seed for random mesh generation</i>: write a seed for the random generation of the mesh

   ``maxrec : int = 0``

      .. raw:: html

         <i>set the maximum recursion</i>: the mesh is built recursively according to the productions of the grammar, so a limit is needed. If set to 0 meshlab will generate the mesh according to the maximum recursion set in the file

   ``sphereres : int = 1``

      .. raw:: html

         <i>set maximum resolution of sphere primitives, it must be included between 1 and 4</i>: increasing the resolution of the spheres will improve the quality of the mesh 

   ``maxobj : int = 0``

      .. raw:: html

         <i>set the maximum number of object to be rendered</i>: you can set a limit to the maximum number of primitives rendered. If set to 0 meshlab will generate the mesh according to the input file

.. data:: fbx
   :noindex:

   .. raw:: html

      Load FBX format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.FBX'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: glb
   :noindex:

   .. raw:: html

      Load GLB format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.GLB'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``load_in_a_single_layer : bool = False``

      .. raw:: html

         <i>Load in a single layer</i>: GLTF files may contain more than one mesh. If this parameter is set to false, all the meshes contained in the file will be merged in a single mesh.

.. data:: gltf
   :noindex:

   .. raw:: html

      Load GLTF format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.GLTF'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``load_in_a_single_layer : bool = False``

      .. raw:: html

         <i>Load in a single layer</i>: GLTF files may contain more than one mesh. If this parameter is set to false, all the meshes contained in the file will be merged in a single mesh.

.. data:: obj
   :noindex:

   .. raw:: html

      Load OBJ format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.OBJ'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: off
   :noindex:

   .. raw:: html

      Load OFF format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.OFF'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: pdb
   :noindex:

   .. raw:: html

      Load PDB format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.PDB'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``usecolors : bool = True``

      .. raw:: html

         <i>Use Atoms colors</i>: Atoms are colored according to atomic type

   ``justpoints : bool = False``

      .. raw:: html

         <i>SURFACE: Atoms as Points</i>: Atoms are created as points, no surface is built. Overrides all subsequential surface parameters

   ``justspheres : bool = True``

      .. raw:: html

         <i>SURFACE: Atoms as Spheres</i>: Atoms are created as intersecting spheres, no interpolation surface is built. Overrides all subsequential surface parameters

   ``interpspheres : bool = False``

      .. raw:: html

         <i>SURFACE: Atoms as Jointed Spheres</i>: Atoms are created as spheres, joining surface is built. Overrides all subsequential surface parameters

   ``metaballs : bool = False``

      .. raw:: html

         <i>SURFACE: Atoms as Metaballs</i>: Atoms are created as blobby interpolation surface, refer to BLINN Metaballs article. Overrides all subsequential surface parameters

   ``voxelsize : float = 0.25``

      .. raw:: html

         <i>Surface Resolution</i>: is used by Jointed Spheres and Metaball

   ``blobby : float = 2``

      .. raw:: html

         <i>Blobbyness factor</i>: is used by Metaball

.. data:: ply
   :noindex:

   .. raw:: html

      Load PLY format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.PLY'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: pts
   :noindex:

   .. raw:: html

      Load pts format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.pts'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: ptx
   :noindex:

   .. raw:: html

      Load PTX format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.PTX'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``meshindex : int = 0``

      .. raw:: html

         <i>Index of Range Map to be Imported</i>: PTX files may contain more than one range map. 0 is the first range map. If the number if higher than the actual mesh number, the import will fail

   ``pointsonly : bool = True``

      .. raw:: html

         <i>Keep only points</i>: Import points a point cloud only, with radius and normals, no triangulation involved, isolated points and points with normals with steep angles are removed.

   ``usecolor : bool = True``

      .. raw:: html

         <i>import color</i>: Read color from PTX, if color is not present, uses reflectance instead

   ``flipfaces : bool = False``

      .. raw:: html

         <i>LEICA: flip normal direction</i>: LEICA PTX exporter goes counterclockwise, FARO PTX exporter goes clockwise

   ``pointcull : bool = True``

      .. raw:: html

         <i>delete unsampled points</i>: Deletes unsampled points in the grid that are normally located in [0,0,0]

   ``anglecull : bool = True``

      .. raw:: html

         <i>Cull faces by angle</i>: short

   ``angle : float = 85``

      .. raw:: html

         <i>Angle limit for face culling</i>: short

.. data:: qobj
   :noindex:

   .. raw:: html

      Load QOBJ format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.QOBJ'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: stl
   :noindex:

   .. raw:: html

      Load STL format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.STL'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``unify_vertices : bool = True``

      .. raw:: html

         <i>Unify Duplicated Vertices in STL files</i>: The STL format is not an vertex-indexed format. Each triangle is composed by independent vertices, so, usually, duplicated vertices should be unified

.. data:: tri
   :noindex:

   .. raw:: html

      Load TRI format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.TRI'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: txt
   :noindex:

   .. raw:: html

      Load TXT format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.TXT'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``rowtoskip : int = 0``

      .. raw:: html

         <i>Header Row to be skipped</i>: The number of lines that must be skipped at the beginning of the file. Generally, these files have one or more 'header' lines, before the point list

   ``strformat : str = 'X Y Z' (or int = 0)``

      Possible enum values:

         0. ``'X Y Z'``
         1. ``'X Y Z Reflectance'``
         2. ``'X Y Z Reflectance R G B'``
         3. ``'X Y Z Reflectance Nx Ny Nz'``
         4. ``'X Y Z Reflectance R G B Nx Ny Nz'``
         5. ``'X Y Z Reflectance Nx Ny Nz R G B'``
         6. ``'X Y Z R G B'``
         7. ``'X Y Z R G B Reflectance'``
         8. ``'X Y Z R G B Reflectance Nx Ny Nz'``
         9. ``'X Y Z R G B Nx Ny Nz Reflectance'``
         10. ``'X Y Z Nx Ny Nz'``
         11. ``'X Y Z Nx Ny Nz R G B Reflectance'``
         12. ``'X Y Z Nx Ny Nz Reflectance R G B'``

      .. raw:: html

         <i>Point format</i>: Which values are specified for each point, and in which order.

   ``separator : str = ';' (or int = 0)``

      Possible enum values:

         0. ``';'``
         1. ``','``
         2. ``'SPACE'``

      .. raw:: html

         <i>Separator</i>: The separator between individual values in the point(s) description.

   ``rgbmode : str = '[0-255]' (or int = 0)``

      Possible enum values:

         0. ``'[0-255]'``
         1. ``'[0.0-1.0]'``

      .. raw:: html

         <i>Color format</i>: Colors may be specified in the [0-255] or [0.0-1.0] interval.

   ``onerror : str = 'skip' (or int = 0)``

      Possible enum values:

         0. ``'skip'``
         1. ``'stop'``

      .. raw:: html

         <i>On Parsing Error</i>: When a line is not properly parsed, it is possible to 'skip' it and continue with the following lines, or 'stop' importing at that point

.. data:: vmi
   :noindex:

   .. raw:: html

      Load VMI format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.VMI'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: wrl
   :noindex:

   .. raw:: html

      Load WRL format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.WRL'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: x3d
   :noindex:

   .. raw:: html

      Load X3D format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.X3D'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: x3dv
   :noindex:

   .. raw:: html

      Load X3DV format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.X3DV'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: xyz
   :noindex:

   .. raw:: html

      Load xyz format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.xyz'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. _save_mesh_parameters:

save mesh parameters
--------------------

Here are listed all the file formats that can be saved usingthe function :py:meth:`pmeshlab.MeshSet.save_current_mesh`, with all the possible parameters that can be accepted by these functions.

.. data:: 3ds
   :noindex:

   .. raw:: html

      Save 3DS format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.3DS'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_face_color : bool = True``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_face_normal : bool = True``

      .. raw:: html

         <i>Save Face Normal</i>: Save Face Normal

   ``save_wedge_texcoord : bool = True``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = True``

      .. raw:: html

         <i>Save Wedge Normal</i>: Save Wedge Normal

.. data:: ctm
   :noindex:

   .. raw:: html

      Save CTM format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.CTM'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``lossless : bool = False``

      .. raw:: html

         <i>LossLess compression</i>: If true it does not apply any lossy compression technique.

   ``relativeprecisionparam : float = 0.0001``

      .. raw:: html

         <i>Relative Coord Precision</i>: When using a lossy compression this number control the introduced error and hence the compression factor.It is a number relative to the average edge length. (e.g. the default means that the error should be roughly 1/10000 of the average edge length)

   ``save_vertex_quality : bool = True``

      .. raw:: html

         <i>Save Vertex Quality</i>: Save Vertex Quality

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

.. data:: dae
   :noindex:

   .. raw:: html

      Save DAE format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.DAE'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = True``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = True``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_wedge_texcoord : bool = True``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = True``

      .. raw:: html

         <i>Save Wedge Normal</i>: Save Wedge Normal

.. data:: dxf
   :noindex:

   .. raw:: html

      Save DXF format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.DXF'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

.. data:: e57
   :noindex:

   .. raw:: html

      Save E57 format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.E57'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_vertex_quality : bool = True``

      .. raw:: html

         <i>Save Vertex Quality</i>: Save Vertex Quality

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_normal : bool = True``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

.. data:: idtf
   :noindex:

   .. raw:: html

      Save IDTF format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.IDTF'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``position_val : numpy.ndarray[numpy.float64[3]] = [0, 0, -1.73205]``

      .. raw:: html

         <i>Camera Position</i>: The position in which the camera is set. The default value is derived by the 3d mesh's bounding box.

   ``target_val : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Camera target point</i>: The point towards the camera is seeing. The default value is derived by the 3d mesh's bounding box.

   ``fov_val : float = 60``

      .. raw:: html

         <i>Camera's FOV Angle 0..180</i>: Camera's FOV Angle. The values' range is between 0-180 degree. The default value is 60.

   ``compression_val : int = 500``

      .. raw:: html

         <i>U3D quality 0..1000</i>: U3D mesh's compression ratio. The values' range is between 0-1000 degree. The default value is 500.

   ``save_vertex_color : bool = False``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_normal : bool = False``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_face_color : bool = False``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_wedge_texcoord : bool = True``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = True``

      .. raw:: html

         <i>Save Wedge Normal</i>: Save Wedge Normal

.. data:: json
   :noindex:

   .. raw:: html

      Save JSON format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.JSON'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = True``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = True``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

.. data:: nxs
   :noindex:

   .. raw:: html

      Save NXS format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.NXS'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``node_faces : int = 32768``

      .. raw:: html

         <i>Node faces</i>: Number of faces per patch, (min ~1000, max 32768)<br>This parameter controls the granularity of the multiresolution: smaller values result in smaller changes (less 'pop').Small nodes are less efficient in rendering and compression.<br>Meshes with very large textures and few vertices benefit from small nodes.

   ``top_node_faces : int = 4096``

      .. raw:: html

         <i>Top node faces</i>: Number of triangles in the top node. Controls the size of the smallest LOD. Higher values will delay the first rendering but with higher quality.

   ``tex_quality : int = 95``

      .. raw:: html

         <i>JPEG texture quality [0-100]</i>: jpg texture quality

   ``ram : int = 2000``

      .. raw:: html

         <i>Ram buffer</i>: Max ram used in MegaBytes (WARNING: just an approximation)

   ``skiplevels : int = 0``

      .. raw:: html

         <i>Skip levels</i>: Decimation skipped for n levels. Use for meshes with large textures and very few vertices.

   ``origin : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Origin</i>: new origin for the model

   ``center : bool = False``

      .. raw:: html

         <i>Center</i>: Set origin in the bounding box center

   ``pow_2_textures : bool = False``

      .. raw:: html

         <i>Pow 2 textures</i>: Create textures to be power of 2

   ``deepzoom : bool = False``

      .. raw:: html

         <i>Deepzoom</i>: Save each node and texture to a separated file. Used for server which do not support http range requests (206). Will generate MANY files.

   ``adaptive : float (bounded) = 0.333 [min: 0; max: 1]``

      .. raw:: html

         <i>Adaptive</i>: Split nodes adaptively. Different settings might help with very uneven distribution of geometry.

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = True``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = False``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_wedge_texcoord : bool = True``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

.. data:: nxz
   :noindex:

   .. raw:: html

      Save NXZ format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.NXZ'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``node_faces : int = 32768``

      .. raw:: html

         <i>Node faces</i>: Number of faces per patch, (min ~1000, max 32768)<br>This parameter controls the granularity of the multiresolution: smaller values result in smaller changes (less 'pop').Small nodes are less efficient in rendering and compression.<br>Meshes with very large textures and few vertices benefit from small nodes.

   ``top_node_faces : int = 4096``

      .. raw:: html

         <i>Top node faces</i>: Number of triangles in the top node. Controls the size of the smallest LOD. Higher values will delay the first rendering but with higher quality.

   ``tex_quality : int = 95``

      .. raw:: html

         <i>JPEG texture quality [0-100]</i>: jpg texture quality

   ``ram : int = 2000``

      .. raw:: html

         <i>Ram buffer</i>: Max ram used in MegaBytes (WARNING: just an approximation)

   ``skiplevels : int = 0``

      .. raw:: html

         <i>Skip levels</i>: Decimation skipped for n levels. Use for meshes with large textures and very few vertices.

   ``origin : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Origin</i>: new origin for the model

   ``center : bool = False``

      .. raw:: html

         <i>Center</i>: Set origin in the bounding box center

   ``pow_2_textures : bool = False``

      .. raw:: html

         <i>Pow 2 textures</i>: Create textures to be power of 2

   ``deepzoom : bool = False``

      .. raw:: html

         <i>Deepzoom</i>: Save each node and texture to a separated file. Used for server which do not support http range requests (206). Will generate MANY files.

   ``adaptive : float (bounded) = 0.333 [min: 0; max: 1]``

      .. raw:: html

         <i>Adaptive</i>: Split nodes adaptively. Different settings might help with very uneven distribution of geometry.

   ``nxz_vertex_quantization : float = 0``

      .. raw:: html

         <i>NXZ Vertex quantization</i>: absolute side of quantization grid (uses quantization factor, instead)

   ``vertex_bits : int = 0``

      .. raw:: html

         <i>Vertex bits</i>: number of bits in vertex coordinates when compressing (uses quantization factor, instead)

   ``quantization_factor : float = 0.1``

      .. raw:: html

         <i>Quantization factor</i>: Quantization as a factor of error

   ``luma_bits : int = 6``

      .. raw:: html

         <i>Luma bits</i>: Quantization of luma channel

   ``chroma_bits : int = 6``

      .. raw:: html

         <i>Chroma bits</i>: Quantization of chroma channel

   ``alpha_bits : int = 5``

      .. raw:: html

         <i>Alpha bits</i>: Quantization of alpha channel

   ``normal_bits : int = 10``

      .. raw:: html

         <i>Normal bits</i>: Quantization of normals

   ``textures_precision : float = 0.25``

      .. raw:: html

         <i>Textures precision</i>: Quantization of textures, precision in pixels per unit

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = True``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = False``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_wedge_texcoord : bool = True``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

.. data:: obj
   :noindex:

   .. raw:: html

      Save OBJ format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.OBJ'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = True``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = True``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_face_color : bool = True``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_wedge_texcoord : bool = True``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = True``

      .. raw:: html

         <i>Save Wedge Normal</i>: Save Wedge Normal

   ``save_polygonal : bool = True``

      .. raw:: html

         <i>Save Polygonal</i>: Save Polygonal

.. data:: off
   :noindex:

   .. raw:: html

      Save OFF format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.OFF'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = True``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_face_color : bool = True``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_polygonal : bool = True``

      .. raw:: html

         <i>Save Polygonal</i>: Save Polygonal

.. data:: ply
   :noindex:

   .. raw:: html

      Save PLY format.</p></br> Ply exporter also support saving custom attributes. You'll need to add an additional boolean parameter for each one of that you want to save, and use only non-capital letters for parameter names. These parameters have a prefix for each type of custom attribute:</br><ul>   <li><code>__ca_vs__</code>: Custom Attribute Vertex Scalar;</li>   <li><code>__ca_vp__</code>: Custom Attribute Vertex Point;</li>   <li><code>__ca_fs__</code>: Custom Attribute Face Scalar;</li>   <li><code>__ca_fp__</code>: Custom Attribute Face Point;</li></ul>For example, if your mesh has a custom per vertex scalar attribute called <code>MyAttribute</code>, you can save it in a ply file by calling:</br><code>ms.save_current_mesh(file_name='myfile.ply', __ca_vs__myattribute=True)</code></br> You can check the parameters available on a mesh by calling the MeshSet method <code>MeshSet.filter_parameter_values</code>, with first parameter <code>'ply'</code>.</p>

   **Parameters:**

   ``file_name : str = 'file_name.PLY'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``binary : bool = True``

      .. raw:: html

         <i>Binary encoding</i>: Save the mesh using a binary encoding. If false the mesh is saved in a plain, readable ascii format.

   ``save_vertex_quality : bool = True``

      .. raw:: html

         <i>Save Vertex Quality</i>: Save Vertex Quality

   ``save_vertex_flag : bool = False``

      .. raw:: html

         <i>Save Vertex Flag</i>: Save Vertex Flag

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = True``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = False``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_vertex_radius : bool = True``

      .. raw:: html

         <i>Save Vertex Radius</i>: Save Vertex Radius

   ``save_face_quality : bool = True``

      .. raw:: html

         <i>Save Face Quality</i>: Save Face Quality

   ``save_face_flag : bool = False``

      .. raw:: html

         <i>Save Face Flag</i>: Save Face Flag

   ``save_face_color : bool = True``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_wedge_color : bool = True``

      .. raw:: html

         <i>Save Wedge Color</i>: Save Wedge Color

   ``save_wedge_texcoord : bool = True``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = True``

      .. raw:: html

         <i>Save Wedge Normal</i>: Save Wedge Normal

.. data:: stl
   :noindex:

   .. raw:: html

      Save STL format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.STL'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``binary : bool = True``

      .. raw:: html

         <i>Binary encoding</i>: Save the mesh using a binary encoding. If false the mesh is saved in a plain, readable ascii format.

   ``colormode : bool = True``

      .. raw:: html

         <i>Materialise Color Encoding</i>: Save the color using a binary encoding according to the Materialise's Magic style (e.g. RGB coding instead of BGR coding).

   ``save_face_color : bool = True``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

.. data:: u3d
   :noindex:

   .. raw:: html

      Save U3D format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.U3D'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``position_val : numpy.ndarray[numpy.float64[3]] = [0, 0, -1.73205]``

      .. raw:: html

         <i>Camera Position</i>: The position in which the camera is set. The default value is derived by the 3d mesh's bounding box.

   ``target_val : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Camera target point</i>: The point towards the camera is seeing. The default value is derived by the 3d mesh's bounding box.

   ``fov_val : float = 60``

      .. raw:: html

         <i>Camera's FOV Angle 0..180</i>: Camera's FOV Angle. The values' range is between 0-180 degree. The default value is 60.

   ``compression_val : int = 500``

      .. raw:: html

         <i>U3D quality 0..1000</i>: U3D mesh's compression ratio. The values' range is between 0-1000 degree. The default value is 500.

   ``save_vertex_color : bool = False``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_face_color : bool = False``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_wedge_texcoord : bool = True``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

.. data:: wrl
   :noindex:

   .. raw:: html

      Save WRL format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.WRL'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_wedge_color : bool = True``

      .. raw:: html

         <i>Save Wedge Color</i>: Save Wedge Color

   ``save_wedge_texcoord : bool = True``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

.. data:: x3d
   :noindex:

   .. raw:: html

      Save X3D format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.X3D'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_vertex_color : bool = True``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = True``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = True``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_face_color : bool = False``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_face_normal : bool = False``

      .. raw:: html

         <i>Save Face Normal</i>: Save Face Normal

   ``save_wedge_color : bool = False``

      .. raw:: html

         <i>Save Wedge Color</i>: Save Wedge Color

   ``save_wedge_texcoord : bool = False``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = False``

      .. raw:: html

         <i>Save Wedge Normal</i>: Save Wedge Normal

.. data:: xyz
   :noindex:

   .. raw:: html

      Save xyz format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.xyz'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_vertex_normal : bool = True``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

.. _load_raster_parameters:

load raster parameters
----------------------

Here are listed all the raster file formats that can be loaded usingthe functions :py:meth:`pmeshlab.MeshSet.load_new_raster`.

.. data:: BMP
   :noindex:

   .. raw:: html

      Load BMP format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.BMP'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: JPEG
   :noindex:

   .. raw:: html

      Load JPEG format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.JPEG'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: JPG
   :noindex:

   .. raw:: html

      Load JPG format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.JPG'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: PNG
   :noindex:

   .. raw:: html

      Load PNG format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.PNG'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: TGA
   :noindex:

   .. raw:: html

      Load TGA format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.TGA'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: TIF
   :noindex:

   .. raw:: html

      Load TIF format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.TIF'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: TIFF
   :noindex:

   .. raw:: html

      Load TIFF format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.TIFF'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: XBM
   :noindex:

   .. raw:: html

      Load XBM format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.XBM'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: XPM
   :noindex:

   .. raw:: html

      Load XPM format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.XPM'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

