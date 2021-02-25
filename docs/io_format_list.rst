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

      Load 3ds format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.3ds'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

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

      Load asc format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.asc'``

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

      Load bre format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.bre'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``pointsonly : bool = False``

      .. raw:: html

         <i>only import points</i>: Just import points, without triangulation

   ``unify : bool = True``

      .. raw:: html

         <i>Unify Duplicated Vertices</i>: The STL format is not an vertex-indexed format. Each triangle is composed by independent vertices, so, usually, duplicated vertices should be unified

.. data:: ctm
   :noindex:

   .. raw:: html

      Load ctm format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.ctm'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: dae
   :noindex:

   .. raw:: html

      Load dae format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.dae'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: es
   :noindex:

   .. raw:: html

      Load es format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.es'``

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

      Load fbx format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.fbx'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: obj
   :noindex:

   .. raw:: html

      Load obj format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.obj'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: off
   :noindex:

   .. raw:: html

      Load off format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.off'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: pdb
   :noindex:

   .. raw:: html

      Load pdb format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.pdb'``

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

      Load ply format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.ply'``

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

      Load ptx format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.ptx'``

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

      Load qobj format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.qobj'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: stl
   :noindex:

   .. raw:: html

      Load stl format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.stl'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

   ``meshlabiostlunifyvertices : bool = True``

      .. raw:: html

         <i>Unify Duplicated Vertices in STL files</i>: The STL format is not an vertex-indexed format. Each triangle is composed by independent vertices, so, usually, duplicated vertices should be unified

.. data:: tri
   :noindex:

   .. raw:: html

      Load tri format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.tri'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: txt
   :noindex:

   .. raw:: html

      Load txt format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.txt'``

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

      Load vmi format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.vmi'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: wrl
   :noindex:

   .. raw:: html

      Load wrl format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.wrl'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: x3d
   :noindex:

   .. raw:: html

      Load x3d format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.x3d'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: x3dv
   :noindex:

   .. raw:: html

      Load x3dv format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.x3dv'``

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

      Save 3ds format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.3ds'``

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

      Save ctm format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.ctm'``

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

      Save dae format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.dae'``

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

      Save dxf format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.dxf'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

.. data:: idtf
   :noindex:

   .. raw:: html

      Save idtf format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.idtf'``

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

      Save json format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.json'``

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

.. data:: obj
   :noindex:

   .. raw:: html

      Save obj format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.obj'``

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

      Save off format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.off'``

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

      Save ply format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.ply'``

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

   ``save_polygonal : bool = True``

      .. raw:: html

         <i>Save Polygonal</i>: Save Polygonal

.. data:: stl
   :noindex:

   .. raw:: html

      Save stl format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.stl'``

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

      Save u3d format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.u3d'``

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

      Save wrl format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.wrl'``

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

      Save x3d format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.x3d'``

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

.. data:: jpeg
   :noindex:

   .. raw:: html

      Load jpeg format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.jpeg'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: jpg
   :noindex:

   .. raw:: html

      Load jpg format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.jpg'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: png
   :noindex:

   .. raw:: html

      Load png format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.png'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

.. data:: xpm
   :noindex:

   .. raw:: html

      Load xpm format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.xpm'``

      .. raw:: html

         <i>File Name</i>: The name of the file to load

