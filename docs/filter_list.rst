.. _filter_list:

List of Filters
===============

apply_filter parameters
-----------------------

Here are listed all the filter names that can be given as paramter to the function :py:meth:`pmeshlab.MeshSet.apply_filter`.

Please note: some filter parameters depend on the mesh(es) used as input of the filter. Default values listed here are computed on a 1x1x1 cube (pymeshlab/tests/sample/cube.obj), and they will be computed on the input mesh if they are left as default.

.. data:: alpha_complex_shape

   *MeshLab filter name*: 'Alpha Complex/Shape'

   .. raw:: html

      Calculate the <b>Alpha Shape</b> of the mesh(Edelsbrunner and P.Mucke 1994) with Qhull library (http://www.qhull.org/). <br><br>From a given finite point set in the space it computes 'the shape' of the set.The Alpha Shape is the boundary of the alpha complex, that is a subcomplex of the Delaunay triangulation of the given point set.<br>For a given value of 'alpha', the alpha complex includes all the simplices in the Delaunay triangulation which have an empty circumsphere with radius equal or smaller than 'alpha'.<br>The filter inserts the minimum value of alpha (the circumradius of the triangle) in attribute Quality foreach face.</p>

   **Parameters:**

   ``alpha : Percentage = 1%``

      .. raw:: html

         <i>Alpha value</i>: Compute the alpha value as percentage of the diagonal of the bbox

   ``filtering : str = 'Alpha Complex' (or int = 0)``

      Possible enum values:

         0. ``'Alpha Complex'``
         1. ``'Alpha Shape'``

      .. raw:: html

         <i>Get:</i>: Select the output. The Alpha Shape is the boundary of the Alpha Complex

.. data:: ambient_occlusion

   *MeshLab filter name*: 'Ambient Occlusion'

   .. raw:: html

      Compute ambient occlusions values; it takes a number of well distributed view direction and for point of the surface it computes how many time it is visible from these directions. This value is saved into quality and automatically mapped into a gray shade. The average direction is saved into an attribute named 'BentNormal'</p>

   **Parameters:**

   ``occmode : str = 'per-Vertex' (or int = 0)``

      Possible enum values:

         0. ``'per-Vertex'``
         1. ``'per-Face (deprecated)'``

      .. raw:: html

         <i>Occlusion mode:</i>: Occlusion may be calculated per-vertex or per-face, color and quality will be saved in the chosen component.

   ``dirbias : float = 0``

      .. raw:: html

         <i>Directional Bias [0..1]</i>: The balance between a uniform and a directionally biased set of lighting direction<br>: - 0 means light came only uniformly from any direction<br> - 1 means that all the light cames from the specified cone of directions <br> - other values mix the two set of lighting directions

   ``reqviews : int = 128``

      .. raw:: html

         <i>Requested views</i>: Number of different views uniformly placed around the mesh. More views means better accuracy at the cost of increased calculation time

   ``conedir : numpy.ndarray[numpy.float32[3]] = [0, 1, 0]``

      .. raw:: html

         <i>Lighting Direction</i>: Number of different views placed around the mesh. More views means better accuracy at the cost of increased calculation time

   ``coneangle : float = 30``

      .. raw:: html

         <i>Cone amplitude</i>: Number of different views uniformly placed around the mesh. More views means better accuracy at the cost of increased calculation time

   ``usegpu : bool = false``

      .. raw:: html

         <i>Use GPU acceleration</i>: Only works for per-vertex AO. In order to use GPU-Mode, your hardware must support FBOs, FP32 Textures and Shaders. Normally increases the performance by a factor of 4x-5x

   ``depthtexsize : int = 512``

      .. raw:: html

         <i>Depth texture size(should be 2^n)</i>: Defines the depth texture size used to compute occlusion from each point of view. Higher values means better accuracy usually with low impact on performance

.. data:: annulus

   *MeshLab filter name*: 'Annulus'

   .. raw:: html

      Create an Annulus e.g. a flat region bounded by two concentric circles, or a holed disk.</p>

   **Parameters:**

   ``internalradius : float = 0.5``

      .. raw:: html

         <i>Internal Radius</i>: Internal Radius of the annulus

   ``externalradius : float = 1``

      .. raw:: html

         <i>External Radius</i>: Externale Radius of the annulus

   ``sides : int = 32``

      .. raw:: html

         <i>Sides</i>: Number of the sides of the poligonal approximation of the annulus

.. data:: box_cube

   *MeshLab filter name*: 'Box/Cube'

   .. raw:: html

      Create a Box, Cube, Hexahedron. You can specify the side length.</p>

   **Parameters:**

   ``size : float = 1``

      .. raw:: html

         <i>Scale factor</i>: Scales the new mesh

.. data:: build_a_polyline_from_selected_edges

   *MeshLab filter name*: 'Build a Polyline from Selected Edges'

   .. raw:: html

      Create a new Layer with an edge mesh composed only by the selected edges of the current mesh</p>

.. data:: change_the_current_layer

   *MeshLab filter name*: 'Change the current layer'

   .. raw:: html

      Change the current layer to a chosen one</p>

   **Parameters:**

   ``layer : int = 0``

      .. raw:: html

         <i>Layer Name</i>: The name of the current layer

.. data:: change_visibility_of_layers

   *MeshLab filter name*: 'Change Visibility of layer(s)'

   .. raw:: html

      Make layer(s) visible/invisible. Useful for scripting.</p>

   **Parameters:**

   ``layer : int = 0``

      .. raw:: html

         <i>Layer Name</i>: The name of the layer that has to change visibility. If second parameter is not empty, this parameter is ignored

   ``lname : str = ''``

      .. raw:: html

         <i>Substring match</i>: Apply visibility to all layers with name substring matching the entered string. If not empty, the first parameter is ignored.

   ``ismeshvisible : bool = true``

      .. raw:: html

         <i>Visible</i>: It makes the selected layer(s) visible or invisible.

.. data:: clamp_vertex_quality

   *MeshLab filter name*: 'Clamp Vertex Quality'

   .. raw:: html

      Clamp vertex quality values to a given range according to specific values or to percentiles</p>

   **Parameters:**

   ``minval : float = 3.40282e+38``

      .. raw:: html

         <i>Min</i>: The value that will be mapped with the lower end of the scale (blue)

   ``maxval : float = -3.40282e+38``

      .. raw:: html

         <i>Max</i>: The value that will be mapped with the upper end of the scale (red)

   ``perc : float (bounded) = 0 [min: 0; max: 100]``

      .. raw:: html

         <i>Percentile Crop [0..100]</i>: If not zero this value will be used for a percentile cropping of the quality values.<br> If this parameter is set to a value <i>P</i> then the two values <i>V_min,V_max</i> for which <i>P</i>% of the vertices have a quality <b>lower or greater</b> than <i>V_min,V_max</i> are used as min/max values for clamping.<br><br> The automated percentile cropping is very useful for automatically discarding outliers.

   ``zerosym : bool = false``

      .. raw:: html

         <i>Zero Symmetric</i>: If true the min max range will be enlarged to be symmetric (so that green is always Zero)

.. data:: close_holes

   *MeshLab filter name*: 'Close Holes'

   .. raw:: html

      Close holes smaller than a given threshold</p>

   **Parameters:**

   ``maxholesize : int = 30``

      .. raw:: html

         <i>Max size to be closed </i>: The size is expressed as number of edges composing the hole boundary

   ``selected : bool = false``

      .. raw:: html

         <i>Close holes with selected faces</i>: Only the holes with at least one of the boundary faces selected are closed

   ``newfaceselected : bool = true``

      .. raw:: html

         <i>Select the newly created faces</i>: After closing a hole the faces that have been created are left selected. Any previous selection is lost. Useful for example for smoothing the newly created holes.

   ``selfintersection : bool = true``

      .. raw:: html

         <i>Prevent creation of selfIntersecting faces</i>: When closing an holes it tries to prevent the creation of faces that intersect faces adjacent to the boundary of the hole. It is an heuristic, non intersetcting hole filling can be NP-complete.

.. data:: clustered_vertex_sampling

   *MeshLab filter name*: 'Clustered Vertex Sampling'

   .. raw:: html

      Create a new layer populated with a subsampling of the vertices of the current mesh; the subsampling is driven by a simple one-per-gridded cell strategy.</p>

   **Parameters:**

   ``threshold : Percentage = 1%``

      .. raw:: html

         <i>Cell Size</i>: The size of the cell of the clustering grid. Smaller the cell finer the resulting mesh. For obtaining a very coarse mesh use larger values.

   ``sampling : str = 'Closest to center' (or int = 1)``

      Possible enum values:

         0. ``'Average'``
         1. ``'Closest to center'``

      .. raw:: html

         <i>Representative Strategy:</i>: <b>Average</b>: for each cell we take the average of the sample falling into. The resulting point is a new point.<br><b>Closest to center</b>: for each cell we take the sample that is closest to the center of the cell. Chosen vertices are a subset of the original ones.

   ``selected : bool = false``

      .. raw:: html

         <i>Only on Selection</i>: If true only for the filter is applied only on the selected subset of the mesh.

.. data:: color_noise

   *MeshLab filter name*: 'Color noise'

   .. raw:: html

      Adds to the color the requested amount of bits of noise. Bits of noise are added independently for each RGB channel.</p>

   **Parameters:**

   ``noisebits : int = 1``

      .. raw:: html

         <i>Noise bits:</i>: Bits of noise added to each RGB channel. Example: 3 noise bits adds three random offsets in the [-4,+4] interval to each RGB channels.

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: colorize_by_border_distance

   *MeshLab filter name*: 'Colorize by border distance'

   .. raw:: html

      Store in the quality field the geodesic distance from borders and color the mesh accordingly.</p>

.. data:: colorize_by_face_quality

   *MeshLab filter name*: 'Colorize by face Quality'

   .. raw:: html

      Color faces depending on their quality field (manually equalized).</p>

   **Parameters:**

   ``minval : float = 3.40282e+38``

      .. raw:: html

         <i>Min</i>: The value that will be mapped with the lower end of the scale (blue)

   ``maxval : float = -3.40282e+38``

      .. raw:: html

         <i>Max</i>: The value that will be mapped with the upper end of the scale (red)

   ``perc : float (bounded) = 0 [min: 0; max: 100]``

      .. raw:: html

         <i>Percentile Crop [0..100]</i>: If not zero this value will be used for a percentile cropping of the quality values.<br> If this parameter is set to a value <i>P</i> then the two values <i>V_min,V_max</i> for which <i>P</i>% of the faces have a quality <b>lower or greater</b> than <i>V_min,V_max</i> are used as min/max values for clamping.<br><br> The automated percentile cropping is very useful for automatically discarding outliers.

   ``zerosym : bool = false``

      .. raw:: html

         <i>Zero Symmetric</i>: If true the min max range will be enlarged to be symmetric (so that green is always Zero)

.. data:: colorize_by_geodesic_distance_from_a_given_point

   *MeshLab filter name*: 'Colorize by geodesic distance from a given point'

   .. raw:: html

      Store in the quality field the geodesic distance from a given point on the mesh surface and color the mesh accordingly.</p>

   **Parameters:**

   ``startpoint : numpy.ndarray[numpy.float32[3]] = [1, 1, 1]``

      .. raw:: html

         <i>Starting point</i>: The starting point from which geodesic distance has to be computed. If it is not a surface vertex, the closest vertex to the specified point is used as starting seed point.

   ``maxdistance : Percentage = 50%``

      .. raw:: html

         <i>Max Distance</i>: If not zero it indicates a cut off value to be used during geodesic distance computation.

.. data:: colorize_by_geodesic_distance_from_the_selected_points

   *MeshLab filter name*: 'Colorize by geodesic distance from the selected points'

   .. raw:: html

      Store in the quality field the geodesic distance from the selected points on the mesh surface and color the mesh accordingly.</p>

   **Parameters:**

   ``maxdistance : Percentage = 50%``

      .. raw:: html

         <i>Max Distance</i>: If not zero it indicates a cut off value to be used during geodesic distance computation.

.. data:: colorize_by_vertex_quality

   *MeshLab filter name*: 'Colorize by vertex Quality'

   .. raw:: html

      Color vertices depending on their quality field (manually equalized).</p>

   **Parameters:**

   ``minval : float = 3.40282e+38``

      .. raw:: html

         <i>Min</i>: The value that will be mapped with the lower end of the scale (blue)

   ``maxval : float = -3.40282e+38``

      .. raw:: html

         <i>Max</i>: The value that will be mapped with the upper end of the scale (red)

   ``perc : float (bounded) = 0 [min: 0; max: 100]``

      .. raw:: html

         <i>Percentile Crop [0..100]</i>: If not zero this value will be used for a percentile cropping of the quality values.<br> If this parameter is set to a value <i>P</i> then the two values <i>V_min,V_max</i> for which <i>P</i>% of the vertices have a quality <b>lower or greater</b> than <i>V_min,V_max</i> are used as min/max values for clamping.<br><br> The automated percentile cropping is very useful for automatically discarding outliers.

   ``zerosym : bool = false``

      .. raw:: html

         <i>Zero Symmetric</i>: If true the min max range will be enlarged to be symmetric (so that green is always Zero)

.. data:: colorize_curvature_apss

   *MeshLab filter name*: 'Colorize curvature (APSS)'

   .. raw:: html

      Colorize the vertices of a mesh or point set using the curvature of the underlying surface.<br><br>This is the <i>algebraic point set surfaces</i> (APSS) variant which is based on the local fitting of algebraic spheres. It requires points equipped with oriented normals. <br>For all the details about APSS see: <br> Guennebaud and Gross, 'Algebraic Point Set Surfaces', Siggraph 2007, and<br>Guennebaud et al., 'Dynamic Sampling and Rendering of APSS', Eurographics 2008</p>

   **Parameters:**

   ``selectiononly : bool = false``

      .. raw:: html

         <i>Selection only</i>: If checked, only selected vertices will be projected.

   ``filterscale : float = 2``

      .. raw:: html

         <i>MLS - Filter scale</i>: Scale of the spatial low pass filter.<br>It is relative to the radius (local point spacing) of the vertices.

   ``projectionaccuracy : float = 0.0001``

      .. raw:: html

         <i>Projection - Accuracy (adv)</i>: Threshold value used to stop the projections.<br>This value is scaled by the mean point spacing to get the actual threshold.

   ``maxprojectioniters : int = 15``

      .. raw:: html

         <i>Projection - Max iterations (adv)</i>: Max number of iterations for the projection.

   ``sphericalparameter : float = 1``

      .. raw:: html

         <i>MLS - Spherical parameter</i>: Control the curvature of the fitted spheres: 0 is equivalent to a pure plane fit,1 to a pure spherical fit, values between 0 and 1 gives intermediate results,while other real values might give interesting results, but take care with extremesettings !

   ``curvaturetype : str = 'Mean' (or int = 0)``

      Possible enum values:

         0. ``'Mean'``
         1. ``'Gauss'``
         2. ``'K1'``
         3. ``'K2'``
         4. ``'ApproxMean'``

      .. raw:: html

         <i>Curvature type</i>: The type of the curvature to plot.<br>ApproxMean uses the radius of the fitted sphere as an approximation of the mean curvature.

.. data:: colorize_curvature_rimls

   *MeshLab filter name*: 'Colorize curvature (RIMLS)'

   .. raw:: html

      Colorize the vertices of a mesh or point set using the curvature of the underlying surface.<br><br>This is the Robust Implicit MLS (RIMLS) variant which is an extension of Implicit MLS preserving sharp features using non linear regression. For more details see: <br>Oztireli, Guennebaud and Gross, 'Feature Preserving Point Set Surfaces based on Non-Linear Kernel Regression' Eurographics 2009.</p>

   **Parameters:**

   ``selectiononly : bool = false``

      .. raw:: html

         <i>Selection only</i>: If checked, only selected vertices will be projected.

   ``filterscale : float = 2``

      .. raw:: html

         <i>MLS - Filter scale</i>: Scale of the spatial low pass filter.<br>It is relative to the radius (local point spacing) of the vertices.

   ``projectionaccuracy : float = 0.0001``

      .. raw:: html

         <i>Projection - Accuracy (adv)</i>: Threshold value used to stop the projections.<br>This value is scaled by the mean point spacing to get the actual threshold.

   ``maxprojectioniters : int = 15``

      .. raw:: html

         <i>Projection - Max iterations (adv)</i>: Max number of iterations for the projection.

   ``sigman : float = 0.75``

      .. raw:: html

         <i>MLS - Sharpness</i>: Width of the filter used by the normal refitting weight.This weight function is a Gaussian on the distance between two unit vectors:the current gradient and the input normal. Therefore, typical value range between 0.5 (sharp) to 2 (smooth).

   ``maxrefittingiters : int = 3``

      .. raw:: html

         <i>MLS - Max fitting iterations</i>: Max number of fitting iterations. (0 or 1 is equivalent to the standard IMLS)

   ``curvaturetype : str = 'Mean' (or int = 0)``

      Possible enum values:

         0. ``'Mean'``
         1. ``'Gauss'``
         2. ``'K1'``
         3. ``'K2'``

      .. raw:: html

         <i>Curvature type</i>: The type of the curvature to plot.

.. data:: compact_faces

   *MeshLab filter name*: 'Compact faces'

   .. raw:: html

      Compact all the faces that have been deleted and put them to the end of the vector</p>

.. data:: compact_vertices

   *MeshLab filter name*: 'Compact vertices'

   .. raw:: html

      Compact all the vertices that have been deleted and put them to the end of the vector</p>

.. data:: compute_area_perimeter_of_selection

   *MeshLab filter name*: 'Compute Area/Perimeter of selection'

   .. raw:: html

      Compute area and perimeter of the FACE selection. Open the layer dialog to see the results.</p>

.. data:: compute_curvature_principal_directions

   *MeshLab filter name*: 'Compute curvature principal directions'

   .. raw:: html

      Compute the principal directions of curvature with several algorithms</p>

   **Parameters:**

   ``method : str = 'Pseudoinverse Quadric Fitting' (or int = 3)``

      Possible enum values:

         0. ``'Taubin approximation'``
         1. ``'Principal Component Analysis'``
         2. ``'Normal Cycles'``
         3. ``'Pseudoinverse Quadric Fitting'``

      .. raw:: html

         <i>Method:</i>: Choose a method

   ``curvcolormethod : str = 'Mean Curvature' (or int = 0)``

      Possible enum values:

         0. ``'Mean Curvature'``
         1. ``'Gaussian Curvature'``
         2. ``'Min Curvature'``
         3. ``'Max Curvature'``
         4. ``'Shape Index'``
         5. ``'CurvedNess'``
         6. ``'None'``

      .. raw:: html

         <i>Quality/Color Mapping</i>: Choose the curvature that is mapped into quality and visualized as per vertex color.

   ``autoclean : bool = true``

      .. raw:: html

         <i>Remove Unreferenced Vertices</i>: If selected, before starting the filter will remove anyy unreference vertex (for which curvature values are not defined)

.. data:: compute_geometric_measures

   *MeshLab filter name*: 'Compute Geometric Measures'

   .. raw:: html

      Compute a set of geometric measures of a mesh/pointcloud. Bounding box extents and diagonal, principal axis, thin shell barycenter (mesh only), vertex barycenter and quality-weighted barycenter (pointcloud only), surface area (mesh only), volume (closed mesh) and Inertia tensor Matrix (closed mesh). Open the layer dialog to see the results.</p>

.. data:: compute_normals_for_point_sets

   *MeshLab filter name*: 'Compute normals for point sets'

   .. raw:: html

      Compute the normals of the vertices of a mesh without exploiting the triangle connectivity, useful for dataset with no faces</p>

   **Parameters:**

   ``k : int = 10``

      .. raw:: html

         <i>Neighbour num</i>: The number of neighbors used to estimate normals.

   ``smoothiter : int = 0``

      .. raw:: html

         <i>Smooth Iteration</i>: The number of smoothing iteration done on the p used to estimate and propagate normals.

   ``flipflag : bool = false``

      .. raw:: html

         <i>Flip normals w.r.t. viewpoint</i>: If the 'viewpoint' (i.e. scanner position) is known, it can be used to disambiguate normals orientation, so that all the normals will be oriented in the same direction.

   ``viewpos : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Viewpoint Pos.</i>: The viewpoint position can be set by hand (i.e. getting the current viewpoint) or it can be retrieved from mesh camera, if the viewpoint position is stored there.

.. data:: compute_planar_section

   *MeshLab filter name*: 'Compute Planar Section'

   .. raw:: html

      Compute the polyline representing a planar section (a slice) of a mesh; if the resulting polyline is closed the result is filled and also a triangular mesh representing the section is saved</p>

   **Parameters:**

   ``planeaxis : str = 'X Axis' (or int = 0)``

      Possible enum values:

         0. ``'X Axis'``
         1. ``'Y Axis'``
         2. ``'Z Axis'``
         3. ``'Custom Axis'``

      .. raw:: html

         <i>Plane perpendicular to</i>: The Slicing plane will be done perpendicular to the axis

   ``customaxis : numpy.ndarray[numpy.float32[3]] = [0, 1, 0]``

      .. raw:: html

         <i>Custom axis</i>: Specify a custom axis, this is only valid if the above parameter is set to Custom

   ``planeoffset : float = 0``

      .. raw:: html

         <i>Cross plane offset</i>: Specify an offset of the cross-plane. The offset corresponds to the distance from the point specified in the plane reference parameter. By default (Cross plane offset == 0)

   ``relativeto : str = 'Origin' (or int = 2)``

      Possible enum values:

         0. ``'Bounding box center'``
         1. ``'Bounding box min'``
         2. ``'Origin'``

      .. raw:: html

         <i>plane reference</i>: Specify the reference from which the planes are shifted

   ``createsectionsurface : bool = false``

      .. raw:: html

         <i>Create also section surface</i>: If selected, in addition to a layer with the section polyline, it will be created also a layer with a triangulated version of the section polyline. This only works if the section polyline is closed

   ``splitsurfacewithsection : bool = false``

      .. raw:: html

         <i>Create also split surfaces</i>: If selected, it will create two layers with the portion of the mesh under and over the section plane. It requires manifoldness of the mesh.

.. data:: compute_topological_measures

   *MeshLab filter name*: 'Compute Topological Measures'

   .. raw:: html

      Compute a set of topological measures over a mesh.</p>

.. data:: compute_topological_measures_for_quad_meshes

   *MeshLab filter name*: 'Compute Topological Measures for Quad Meshes'

   .. raw:: html

      Compute a set of topological measures over a quad mesh.</p>

.. data:: conditional_face_selection

   *MeshLab filter name*: 'Conditional Face Selection'

   .. raw:: html

      Boolean function using muparser lib to perform faces selection over current mesh.<br><br>It's possible to use parenthesis <b>()</b>, and predefined operators:<br><b>&&</b> (logic and), <b>||</b> (logic or), <b>&lt;</b>, <b>&lt;=</b>, <b>></b>, <b>>=</b>, <b>!=</b> (not equal), <b>==</b> (equal), <b>_?_:_</b> (c/c++ ternary operator)<br><br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

   **Parameters:**

   ``condselect : str = '(fi == 0)'``

      .. raw:: html

         <i>boolean function</i>: type a boolean function that will be evaluated in order to select a subset of faces<br>

.. data:: conditional_vertex_selection

   *MeshLab filter name*: 'Conditional Vertex Selection'

   .. raw:: html

      Boolean function using muparser lib to perform vertex selection over current mesh.<br><br>It's possible to use parenthesis <b>()</b>, and predefined operators:<br><b>&&</b> (logic and), <b>||</b> (logic or), <b>&lt;</b>, <b>&lt;=</b>, <b>></b>, <b>>=</b>, <b>!=</b> (not equal), <b>==</b> (equal), <b>_?_:_</b> (c/c++ ternary operator)<br><br>It's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``condselect : str = '(q < 0)'``

      .. raw:: html

         <i>boolean function</i>: type a boolean function that will be evaluated in order to select a subset of vertices<br>example: (y > 0) and (ny > 0)

.. data:: cone

   *MeshLab filter name*: 'Cone'

   .. raw:: html

      Create a Cone</p>

   **Parameters:**

   ``r0 : float = 1``

      .. raw:: html

         <i>Radius 1</i>: Radius of the bottom circumference

   ``r1 : float = 2``

      .. raw:: html

         <i>Radius 2</i>: Radius of the top circumference

   ``h : float = 3``

      .. raw:: html

         <i>Height</i>: Height of the Cone

   ``subdiv : int = 36``

      .. raw:: html

         <i>Side</i>: Number of sides of the polygonal approximation of the cone

.. data:: convert_pervertex_uv_into_perwedge_uv

   *MeshLab filter name*: 'Convert PerVertex UV into PerWedge UV'

   .. raw:: html

      Converts per Vertex Texture Coordinates to per Wedge Texture Coordinates. It does not merge superfluous vertices...</p>

.. data:: convert_perwedge_uv_into_pervertex_uv

   *MeshLab filter name*: 'Convert PerWedge UV into PerVertex UV'

   .. raw:: html

      Converts per Wedge Texture Coordinates to per Vertex Texture Coordinates splitting vertices with not coherent Wedge coordinates.</p>

.. data:: convex_hull

   *MeshLab filter name*: 'Convex Hull'

   .. raw:: html

      Calculate the <b>convex hull</b> with Qhull library (http://www.qhull.org/html/qconvex.htm).<br><br> The convex hull of a set of points is the boundary of the minimal convex set containing the given non-empty finite set of points.</p>

.. data:: craters_generation

   *MeshLab filter name*: 'Craters Generation'

   .. raw:: html

      Generates craters onto a mesh using radial functions.<br />There must be at least two layers to apply this filter:<br /><ul>    <li>the layer that contains the target mesh; we assume that this mesh is sufficiently refined;</li>    <li>the layer that contains the samples which represent the central points of craters.</li></ul>There are three radial functions available to generate craters, two of which are Gaussian and Multiquadric, and the third is a variant of multiquadric. Blending functions are also provided to blend the crater elevation towards the mesh surface. If you want the preview to work, be sure to select the target mesh layer before launching the filter. You can select this layer by clicking on it in the layer dialog.</p>

   **Parameters:**

   ``target_mesh : int = 0``

      .. raw:: html

         <i>Target mesh:</i>: The mesh on which craters will be generated.

   ``samples_mesh : int = 0``

      .. raw:: html

         <i>Samples layer:</i>: The samples that represent the central points of craters.

   ``seed : int = 0``

      .. raw:: html

         <i>Seed:</i>: The seed with which the random number generator is initialized. The random generator generates radius and depth for each crater into the given range.

   ``smoothingsteps : int = 5``

      .. raw:: html

         <i>Normals smoothing steps:</i>: Vertex normals are smoothed this number of times before generating craters.

   ``rbf : str = 'f2 (Multiquadric)' (or int = 1)``

      Possible enum values:

         0. ``'f1 (Gaussian)'``
         1. ``'f2 (Multiquadric)'``
         2. ``'f3'``

      .. raw:: html

         <i>Radial function:</i>: The radial function used to generate craters.

   ``min_radius : float (bounded) = 0.1 [min: 0; max: 1]``

      .. raw:: html

         <i>Min crater radius:</i>: Defines the minimum radius of craters in range [0, 1]. Values near 0 mean very small craters.

   ``max_radius : float (bounded) = 0.35 [min: 0; max: 1]``

      .. raw:: html

         <i>Max crater radius:</i>: Defines the maximum radius of craters in range [0, 1]. Values near 1 mean very large craters.

   ``min_depth : float (bounded) = 0.05 [min: 0; max: 1]``

      .. raw:: html

         <i>Min crater depth:</i>: Defines the minimum depth of craters in range [0, 1].

   ``max_depth : float (bounded) = 0.15 [min: 0; max: 1]``

      .. raw:: html

         <i>Max crater depth:</i>: Defines the maximum depth of craters in range [0, 1]. Values near 1 mean very deep craters.

   ``elevation : float (bounded) = 0.4 [min: 0; max: 1]``

      .. raw:: html

         <i>Elevation:</i>: Defines how much the crater rise itself from the mesh surface, giving an "impact-effect".

   ``blend : str = 'f3 blending' (or int = 3)``

      Possible enum values:

         0. ``'Exponential blending'``
         1. ``'Linear blending'``
         2. ``'Gaussian blending'``
         3. ``'f3 blending'``

      .. raw:: html

         <i>Blending algorithm:</i>: The algorithm that is used to blend the perturbation towards the mesh surface.

   ``blendthreshold : float (bounded) = 0.8 [min: 0; max: 1]``

      .. raw:: html

         <i>Blending threshold:</i>: The fraction of craters radius beyond which the radial function is replaced with the blending function.

   ``successiveimpacts : bool = true``

      .. raw:: html

         <i>Successive impacts</i>: If not checked, the impact-effects of generated craters will be superimposed with each other.

   ``ppnoise : bool = true``

      .. raw:: html

         <i>Postprocessing noise</i>: Slightly perturbates the craters with a noise function.

   ``invert : bool = false``

      .. raw:: html

         <i>Invert perturbation</i>: If checked, inverts the sign of radial perturbation to create bumps instead of craters.

   ``save_as_quality : bool = false``

      .. raw:: html

         <i>Save as vertex quality</i>: Saves the perturbation as vertex quality.

.. data:: create_selection_perimeter_polyline

   *MeshLab filter name*: 'Create Selection Perimeter Polyline'

   .. raw:: html

      Create a new Layer with the perimeter polyline(s) of the selection borders</p>

.. data:: create_solid_wireframe

   *MeshLab filter name*: 'Create Solid Wireframe'

   .. raw:: html

      </p>

   **Parameters:**

   ``edgecylflag : bool = true``

      .. raw:: html

         <i>Edge -> Cyl.</i>: If True all the edges are converted into cylinders.

   ``edgecylradius : Percentage = 1%``

      .. raw:: html

         <i>Edge Cylinder Rad.</i>: The radius of the cylinder replacing each edge.

   ``vertcylflag : bool = false``

      .. raw:: html

         <i>Vertex -> Cyl.</i>: If True all the vertices are converted into cylinders.

   ``vertcylradius : Percentage = 1%``

      .. raw:: html

         <i>Vertex Cylinder Rad.</i>: The radius of the cylinder replacing each vertex.

   ``vertsphflag : bool = true``

      .. raw:: html

         <i>Vertex -> Sph.</i>: If True all the vertices are converted into sphere.

   ``vertsphradius : Percentage = 1%``

      .. raw:: html

         <i>Vertex Sphere Rad.</i>: The radius of the sphere replacing each vertex.

   ``faceextflag : bool = true``

      .. raw:: html

         <i>Face -> Prism</i>: If True all the faces are converted into prism.

   ``faceextheight : Percentage = 0.5%``

      .. raw:: html

         <i>Face Prism Height</i>: The Height of the prism that is substitued with each face.

   ``faceextinset : Percentage = 0.5%``

      .. raw:: html

         <i>Face Prism Inset</i>: The inset radius of each prism, e.g. how much it is moved toward the inside each vertex on the border of the prism.

   ``edgefauxflag : bool = true``

      .. raw:: html

         <i>Ignore faux edges</i>: If true only the Non-Faux edges will be considered for conversion.

   ``cylindersidenum : int = 16``

      .. raw:: html

         <i>Cylinder Side</i>: Number of sides of the cylinder (both edge and vertex).

.. data:: cross_field_creation

   *MeshLab filter name*: 'Cross Field Creation'

   .. raw:: html

      </p>

   **Parameters:**

   ``crosstype : str = 'Linear Y' (or int = 0)``

      Possible enum values:

         0. ``'Linear Y'``
         1. ``'Radial'``
         2. ``'Curvature'``

      .. raw:: html

         <i>Cross Type</i>:

.. data:: csg_operation

   *MeshLab filter name*: 'CSG Operation'

   .. raw:: html

      Constructive Solid Geometry operation filter.<br>For more details see: <br><i>C. Rocchini, P. Cignoni, F. Ganovelli, C. Montani, P. Pingi and R.Scopigno, </i><br><b>'Marching Intersections: an Efficient Resampling Algorithm for Surface Management'</b><br>In Proceedings of Shape Modeling International (SMI) 2001</p>

   **Parameters:**

   ``firstmesh : int = 0``

      .. raw:: html

         <i>First Mesh</i>: The first operand of the CSG operation

   ``secondmesh : int = 0``

      .. raw:: html

         <i>Second Mesh</i>: The second operand of the CSG operation

   ``delta : Percentage = 1%``

      .. raw:: html

         <i>Spacing between sampling lines</i>: This parameter controls the accuracy of the result and the speed of the computation.The time and memory needed to perform the operation usually scale as the reciprocal square of this value.For optimal results, this value should be at most half the the smallest feature (i.e. the highest frequency) you want to reproduce.

   ``subdelta : int = 32``

      .. raw:: html

         <i>Discretization points per sample interval</i>: This is the number of points between the sampling lines to which the vertices can be rounded.Increasing this can marginally increase the precision and decrease the speed of the operation.

   ``operator : str = 'Intersection' (or int = 0)``

      Possible enum values:

         0. ``'Intersection'``
         1. ``'Union'``
         2. ``'Difference'``

      .. raw:: html

         <i>Operator</i>: Intersection takes the volume shared between the two meshes; Union takes the volume included in at least one of the two meshes; Difference takes the volume included in the first mesh but not in the second one

.. data:: curvature_flipping_optimization

   *MeshLab filter name*: 'Curvature flipping optimization'

   .. raw:: html

      Mesh optimization by edge flipping, to improve local mesh curvature</p>

   **Parameters:**

   ``selection : bool = false``

      .. raw:: html

         <i>Update selection</i>: Apply edge flip optimization on selected faces only

   ``pthreshold : float = 1``

      .. raw:: html

         <i>Angle Thr (deg)</i>: To avoid excessive flipping/swapping we consider only couple of faces with a significant diedral angle (e.g. greater than the indicated threshold).

   ``curvtype : str = 'mean' (or int = 0)``

      Possible enum values:

         0. ``'mean'``
         1. ``'norm squared'``
         2. ``'absolute'``

      .. raw:: html

         <i>Curvature metric</i>: <p style='white-space:pre'>Choose a metric to compute surface curvature on vertices<br>H = mean curv, K = gaussian curv, A = area per vertex<br><br>1: Mean curvature = H<br>2: Norm squared mean curvature = (H * H) / A<br>3: Absolute curvature:<br>     if(K >= 0) return 2 * H<br>     else return 2 * sqrt(H ^ 2 - A * K)

.. data:: cut_mesh_along_crease_edges

   *MeshLab filter name*: 'Cut mesh along crease edges'

   .. raw:: html

      Cut the mesh along crease edges, duplicating the vertices as necessary. Crease (or sharp) edges are defined according to the variation of normal of the adjacent faces.</p>

   **Parameters:**

   ``angledeg : float = 90``

      .. raw:: html

         <i>Crease Angle (degree)</i>: If the angle between the normals of two adjacent faces is <b>larger</b> that this threshold the edge is considered a creased and the mesh is cut along it.

.. data:: define_new_per_face_attribute

   *MeshLab filter name*: 'Define New Per Face Attribute'

   .. raw:: html

      Add a new Per-Face attribute to current mesh.<br>You can specify custom name and a function to generate attribute's value<br>It's possible to use per-face variables in the expression:<br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br><font color="#FF0000">The attribute name specified below can be used in other filter function</font></p>

   **Parameters:**

   ``name : str = 'Radiosity'``

      .. raw:: html

         <i>Name</i>: the name of new attribute. you can access attribute in other filters through this name

   ``expr : str = 'fi'``

      .. raw:: html

         <i>Function =</i>: function to calculate custom attribute value for each face

.. data:: define_new_per_vertex_attribute

   *MeshLab filter name*: 'Define New Per Vertex Attribute'

   .. raw:: html

      Add a new Per-Vertex scalar attribute to current mesh and fill it with the defined function.<br>The name specified below can be used in other filter functionIt's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``name : str = 'Radiosity'``

      .. raw:: html

         <i>Name</i>: the name of new attribute. you can access attribute in other filters through this name

   ``expr : str = 'x'``

      .. raw:: html

         <i>Function =</i>: function to calculate custom attribute value for each vertex

.. data:: delaunay_triangulation

   *MeshLab filter name*: 'Delaunay Triangulation'

   .. raw:: html

      Calculate the <b>Delaunay triangulation</b> with Qhull library (http://www.qhull.org/html/qdelaun.htm).<br><br>The Delaunay triangulation DT(P) of a set of points P in d-dimensional spaces is a triangulation of the convex hull such that no point in P is inside the circum-sphere of any simplex in DT(P).<br> </p>

.. data:: delete_all_faces

   *MeshLab filter name*: 'Delete ALL Faces'

   .. raw:: html

      Delete ALL faces, turning the mesh into a pointcloud. May be applied also to all visible layers.</p>

   **Parameters:**

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected, the filter will be applied to all visible mesh Layers.

.. data:: delete_all_non_selected_rasters

   *MeshLab filter name*: 'Delete all Non Selected Rasters'

   .. raw:: html

      All non selected raster layers are deleted</p>

.. data:: delete_all_non_visible_mesh_layers

   *MeshLab filter name*: 'Delete all non visible Mesh Layers'

   .. raw:: html

      All the non visible mesh layers are deleted</p>

.. data:: delete_current_mesh

   *MeshLab filter name*: 'Delete Current Mesh'

   .. raw:: html

      The current mesh layer is deleted</p>

.. data:: delete_current_raster

   *MeshLab filter name*: 'Delete Current Raster'

   .. raw:: html

      The current raster layer is deleted</p>

.. data:: delete_selected_faces

   *MeshLab filter name*: 'Delete Selected Faces'

   .. raw:: html

      Delete the current set of selected faces, vertices that remains unreferenced are not deleted.</p>

.. data:: delete_selected_faces_and_vertices

   *MeshLab filter name*: 'Delete Selected Faces and Vertices'

   .. raw:: html

      Delete the current set of selected faces and all the vertices surrounded by that faces.</p>

.. data:: delete_selected_vertices

   *MeshLab filter name*: 'Delete Selected Vertices'

   .. raw:: html

      Delete the current set of selected vertices; faces that share one of the deleted vertices are deleted too.</p>

.. data:: depth_complexity

   *MeshLab filter name*: 'Depth complexity'

   .. raw:: html

      Calculate the depth complexity of the mesh, that is: the maximum number of layers that a ray can hit while traversing the mesh. To have a correct value, you should specify and high value in the peeling iteration parameter. You can read the result in the MeshLab log window. <b>If warnings are not present, you have the exact value, otherwise try increasing the peeling iteration parameter. After having calculated the correct value,you can ignore further warnings that you may get using that value.</b>. </p>

   **Parameters:**

   ``onprimitive : str = 'On vertices' (or int = 0)``

      Possible enum values:

         0. ``'On vertices'``
         1. ``'On Faces'``

      .. raw:: html

         <i>Metric:</i>: Choose whether to trace rays from faces or from vertices.

   ``numberrays : int = 128``

      .. raw:: html

         <i>Number of rays: </i>: The number of rays that will be casted around the normals.

   ``depthtexturesize : int = 512``

      .. raw:: html

         <i>Depth texture size</i>: Size of the depth texture for depth peeling. Higher resolutions provide better sampling of the mesh, with a small performance penalty.

   ``peelingiteration : int = 10``

      .. raw:: html

         <i>Peeling Iteration</i>: Number of depth peeling iteration. Actually is the maximum number of layers that a ray can hit while traversing the mesh. For example, in the case of a sphere, you should specify 2 in this parameter. For a torus, specify 4. <b>For more complex geometry you should run the depth complexity filter to know the exact value</b>.

   ``peelingtolerance : float = 1e-07``

      .. raw:: html

         <i>Peeling Tolerance</i>: Depth tolerance used during depth peeling. This is the threshold used to differentiate layers between each others.Two elements whose distance is below this value will be considered as belonging to the same layer.

.. data:: depth_smooth

   *MeshLab filter name*: 'Depth Smooth'

   .. raw:: html

      A laplacian smooth that is constrained to move vertices only in one given direction (usually the viewer direction).</p>

   **Parameters:**

   ``stepsmoothnum : int = 3``

      .. raw:: html

         <i>Smoothing steps</i>: The number of times that the whole algorithm (normal smoothing + vertex fitting) is iterated.

   ``viewpoint : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Viewpoint</i>: The position of the view point that is used to get the constraint direction.

   ``delta : Percentage = 100%``

      .. raw:: html

         <i>Strength</i>: How much smoothing is applied: 0 (no smooth) e 1 (full smooth)

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selection</i>: If checked the filter is performed only on the selected area

.. data:: dilate_selection

   *MeshLab filter name*: 'Dilate Selection'

   .. raw:: html

      Dilate (expand) the current set of selected faces.</p>

.. data:: directional_geom_preserv

   *MeshLab filter name*: 'Directional Geom. Preserv.'

   .. raw:: html

      Store and Blend the current geometry with the result of another previous smoothing processing step. This is useful to limit the influence of any smoothing algorithm along the viewing direction. This is useful to cope with the biased distribution of measuring error in many scanning devices, because TOF scanners usually have very good <i>x,y</i>accuracy but suffer of greater depth errors.</p>

   **Parameters:**

   ``step : str = 'Store Vertex Position' (or int = 0)``

      Possible enum values:

         0. ``'Store Vertex Position'``
         1. ``'Blend Vertex Position'``

      .. raw:: html

         <i>Step:</i>: The purpose of this filter is to <b>constrain</b> any smoothing algorithm to moving vertices only along a give line of sight.<br> First you should store current vertex position, than after applying  one of the many smoothing algorithms you should re start this filter and blend the original positions with the smoothed results.<br>Given a view point  <i>vp</i> , the smoothed vertex position <i>vs</i> and the original position  <i>v</i>, The new vertex position is computed as the projection of  <i>vs</i> on the line  connecting  <i>v</i>  and <i>vp</i>.

   ``viewpoint : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Viewpoint</i>: The position of the view point that is used to get the constraint direction.

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selected faces</i>: If checked the filter is performed only on the selected faces

.. data:: discrete_curvatures

   *MeshLab filter name*: 'Discrete Curvatures'

   .. raw:: html

      Colorize according to various discrete curvature computed as described in:<br>'<i>Discrete Differential-Geometry Operators for Triangulated 2-Manifolds</i>' <br>M. Meyer, M. Desbrun, P. Schroder, A. H. Barr</p>

   **Parameters:**

   ``curvaturetype : str = 'Mean Curvature' (or int = 0)``

      Possible enum values:

         0. ``'Mean Curvature'``
         1. ``'Gaussian Curvature'``
         2. ``'RMS Curvature'``
         3. ``'ABS Curvature'``

      .. raw:: html

         <i>Type:</i>: Choose the curvature value that you want transferred onto the scalar Quality.Mean (H) and Gaussian (K) curvature are computed according the technique described in the Desbrun et al. paper.<br>Absolute curvature is defined as |H|+|K| and RMS curvature as sqrt(4* H^2 - 2K) as explained in <br><i>Improved curvature estimationfor watershed segmentation of 3-dimensional meshes </i> by S. Pulla, A. Razdan, G. Farin.

.. data:: disk_vertex_coloring

   *MeshLab filter name*: 'Disk Vertex Coloring'

   .. raw:: html

      Given a Mesh <b>M</b> and a Pointset <b>P</b>, The filter project each vertex of P over M and color M according to the Euclidean distance from these projected points. Projection and coloring are done on a per vertex basis.</p>

   **Parameters:**

   ``coloredmesh : int = 0``

      .. raw:: html

         <i>To be Colored Mesh</i>: The mesh whose surface is colored. For each vertex of this mesh we decide the color according the below parameters.

   ``vertexmesh : int = 0``

      .. raw:: html

         <i>Vertex Mesh</i>: The mesh whose vertices are used as seed points for the color computation. These seeds point are projected onto the above mesh.

   ``radius : float (bounded) = 0.34641 [min: 0; max: 1.1547]``

      .. raw:: html

         <i>Radius</i>: the radius of the spheres centered in the VertexMesh seeds

   ``sampleradius : bool = false``

      .. raw:: html

         <i>Use sample radius</i>: Use the radius that is stored in each sample of the vertex mesh. Useful for displaing the variable disk sampling results

   ``approximategeodetic : bool = false``

      .. raw:: html

         <i>Use Approximate Geodetic</i>: Use the Approximate Geodetic Metric instead of the Euclidean distance. Approximate geodetic metric uses the normals between the two points to weight the euclidean distance.

.. data:: distance_from_reference_mesh

   *MeshLab filter name*: 'Distance from Reference Mesh'

   .. raw:: html

      Compute the signed/unsigned (per vertex) distance between a mesh/pointcloud and a reference mesh/pointcloud. Distance is stored in vertex quality.</p>

   **Parameters:**

   ``measuremesh : int = 0``

      .. raw:: html

         <i>Measured Mesh/PointCloud</i>: The Mesh/Pointcloud that is measured, vertex by vertex, computing distance from the REFERENCE mesh/pointcloud.

   ``refmesh : int = 0``

      .. raw:: html

         <i>Reference Mesh/PointCloud</i>: The Mesh/Pointcloud that is used as a reference, to measure distance from.

   ``signeddist : bool = true``

      .. raw:: html

         <i>Compute Signed Distance</i>: If TRUE, the distance is signed; if FALSE, it will compute the distance absolute value.

   ``maxdist : Percentage = 100%``

      .. raw:: html

         <i>Max Distance [abs]</i>: Search is interrupted when nothing is found within this distance range [+maxDistance -maxDistance].

.. data:: dodecahedron

   *MeshLab filter name*: 'Dodecahedron'

   .. raw:: html

      Create an Dodecahedron</p>

.. data:: duplicate_current_layer

   *MeshLab filter name*: 'Duplicate Current layer'

   .. raw:: html

      Create a new layer containing the same model as the current one</p>

.. data:: dust_accumulation

   *MeshLab filter name*: 'Dust Accumulation'

   .. raw:: html

      Simulate dust accumulation over the mesh generating a cloud of points lying on the current mesh</p>

   **Parameters:**

   ``dust_dir : numpy.ndarray[numpy.float32[3]] = [0, 1, 0]``

      .. raw:: html

         <i>Direction</i>: Direction of the dust source

   ``nparticles : int = 3``

      .. raw:: html

         <i>max particles x face</i>: Max Number of Dust Particles to Generate Per Face

   ``slippiness : float = 1``

      .. raw:: html

         <i>s</i>: The surface slippines(large s means less sticky)

   ``adhesion : float = 0.2``

      .. raw:: html

         <i>k</i>: Factor to model the general adhesion

   ``draw_texture : bool = false``

      .. raw:: html

         <i>Draw Dust</i>: create a new texture saved in dirt_texture.png

.. data:: equalize_vertex_color

   *MeshLab filter name*: 'Equalize Vertex Color'

   .. raw:: html

      The filter equalizes the colors histogram. It is a kind of automatic regulation of contrast; the colors histogram is expanded to fit all the range of colors.</p>

   **Parameters:**

   ``rch : bool = true``

      .. raw:: html

         <i>Red Channel:</i>: Select the red channel.

   ``gch : bool = true``

      .. raw:: html

         <i>Green Channel:</i>: Select the green channel.

   ``bch : bool = true``

      .. raw:: html

         <i>Blue Channel:</i>: Select the blue channel.<br><br>If no channel is selected<br>filter works on Lightness.

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: erode_selection

   *MeshLab filter name*: 'Erode Selection'

   .. raw:: html

      Erode (reduce) the current set of selected faces.</p>

.. data:: estimate_radius_from_density

   *MeshLab filter name*: 'Estimate radius from density'

   .. raw:: html

      Estimate the local point spacing (aka radius) around each vertex using a basic estimate of the local density.</p>

   **Parameters:**

   ``nbneighbors : int = 16``

      .. raw:: html

         <i>Number of neighbors</i>: Number of neighbors used to estimate the local density. Larger values lead to smoother variations.

.. data:: export_active_rasters_cameras_to_file

   *MeshLab filter name*: 'Export active rasters cameras to file'

   .. raw:: html

      Export active cameras to file, in the .out or Agisoft .xml formats</p>

   **Parameters:**

   ``exportfile : str = 'Bundler .out' (or int = 0)``

      Possible enum values:

         0. ``'Bundler .out'``
         1. ``'Agisoft xml'``

      .. raw:: html

         <i>Output format</i>: Choose the output format, The filter enables to export the cameras to both Bundler and Agisoft Photoscan.

   ``newname : str = 'cameras'``

      .. raw:: html

         <i>Export file name (the right extension will be added at the end)</i>: Name of the output file, it will be saved in the same folder as the project file

.. data:: export_to_sketchfab

   *MeshLab filter name*: 'Export to Sketchfab'

   .. raw:: html

      Upload the current layer on Sketchfab. It requires that you have an account and that you set your private API token in the preferences of MeshLab.</p>

   **Parameters:**

   ``sketchfabkeycode : str = '00000000'``

      .. raw:: html

         <i>Sketch Fab Code</i>: Mandatory.

   ``title : str = 'MeshLabModel'``

      .. raw:: html

         <i>Title</i>: Mandatory.

   ``description : str = 'A model generated with meshlab'``

      .. raw:: html

         <i>Description</i>: Mandatory. A short description of the model that is uploaded.

   ``tags : str = 'meshlab'``

      .. raw:: html

         <i>Tags</i>: Mandatory. Tags must be separated by a space. Typical tags usually used by MeshLab users: scan, photogrammetry.

   ``isprivate : bool = false``

      .. raw:: html

         <i>Private</i>: This parameter can be true only for PRO account.

   ``ispublished : bool = false``

      .. raw:: html

         <i>Publish</i>: If true the model will be published immediately.

   ``autorotate : bool = true``

      .. raw:: html

         <i>Auto Rotate</i>: If true the model rotated by 90 degree on the X axis to maintain similar default orientation.

   ``saveapisetting : bool = false``

      .. raw:: html

         <i>Save SketchFab Code</i>: Saves the API SketchFab code into the MeshLab settings, allowing to load it as default value every time you run this filter.

.. data:: fit_a_plane_to_selection

   *MeshLab filter name*: 'Fit a plane to selection'

   .. raw:: html

      Create a quad on the plane fitting the selection</p>

   **Parameters:**

   ``extent : float = 1``

      .. raw:: html

         <i>Extent (with respect to selection)</i>: How large is the plane, with respect to the size of the selection: 1.0 means as large as the selection, 1.1 means 10% larger thena the selection

   ``subdiv : int = 3``

      .. raw:: html

         <i>Plane XY subivisions</i>: Subdivision steps of plane borders

   ``hasuv : bool = false``

      .. raw:: html

         <i>UV parametrized</i>: The created plane has an UV parametrization

   ``orientation : str = 'quasi-Straight Fit' (or int = 0)``

      Possible enum values:

         0. ``'quasi-Straight Fit'``
         1. ``'Best Fit'``
         2. ``'XZ Parallel'``
         3. ``'YZ Parallel'``
         4. ``'YX Parallel'``

      .. raw:: html

         <i>Plane orientation</i>: Orientation:<b>quasi-Straight Fit</b>: The fitting plane will be oriented (as much as possible) straight with the axeses.<br><b>Best Fit</b>: The fitting plane will be oriented and sized trying to best fit to the selected area.<br><b>-- Parallel</b>: The fitting plane will be oriented with a side parallel with the chosen plane. WARNING: do not use if the selection is exactly parallel to a plane.<br>

.. data:: flatten_visible_layers

   *MeshLab filter name*: 'Flatten Visible Layers'

   .. raw:: html

      Flatten all or only the visible layers into a single new mesh. <br> Transformations are preserved. Existing layers can be optionally deleted</p>

   **Parameters:**

   ``mergevisible : bool = true``

      .. raw:: html

         <i>Merge Only Visible Layers</i>: If true, flatten only visible layers, otherwise, all layers are used

   ``deletelayer : bool = true``

      .. raw:: html

         <i>Delete Layers </i>: Delete all the layers used as source in flattening. <br>If all layers are visible only a single layer will remain after the invocation of this filter

   ``mergevertices : bool = true``

      .. raw:: html

         <i>Merge duplicate vertices</i>: Merge the vertices that are duplicated among different layers. <br><br>Very useful when the layers are spliced portions of a single big mesh.

   ``alsounreferenced : bool = false``

      .. raw:: html

         <i>Keep unreferenced vertices</i>: Do not discard unreferenced vertices from source layers<br><br>Necessary for point-cloud layers

.. data:: fractal_displacement

   *MeshLab filter name*: 'Fractal Displacement'

   .. raw:: html

      Generates a fractal terrain perturbation with five different algorithms.<br />Some good parameter values to start with are:<br /><table align="center">    <tr style="border:1px solid black">        <td> - </td>        <td align="center"> Seed </td>        <td align="center"> Octaves </td>        <td align="center"> Lacunarity </td>        <td align="center"> Fractal increment </td>        <td align="center"> Offset </td>        <td align="center"> Gain </td>    </tr>    <tr>        <td>fBM</td>        <td align="center">1</td>        <td align="center">10</td>        <td align="center">2</td>        <td align="center">1.2</td>        <td align="center">-</td>        <td align="center">-</td>    </tr>    <tr>        <td>Standard multifractal</td>        <td align="center">1</td>        <td align="center">8</td>        <td align="center">2</td>        <td align="center">0.9</td>        <td align="center">0.9</td>        <td align="center">-</td>    </tr>    <tr>        <td>Heterogeneous multifractal</td>        <td align="center">1</td>        <td align="center">8</td>        <td align="center">3</td>        <td align="center">0.9</td>        <td align="center">0.4</td>        <td align="center">-</td>    </tr>    <tr>        <td>Hybrid multifractal</td>        <td align="center">1</td>        <td align="center">8</td>        <td align="center">4</td>        <td align="center">0.1</td>        <td align="center">0.3</td>        <td align="center">-</td>    </tr>    <tr>        <td>Ridged multifractal</td>        <td align="center">2</td>        <td align="center">8</td>        <td align="center">4</td>        <td align="center">0.5</td>        <td align="center">0.9</td>        <td align="center">2</td>    </tr></table><br /><br />Detailed algorithms descriptions can be found in:<br /><i>Ebert, D.S., Musgrave, F.K., Peachey, D., Perlin, K., and Worley, S.</i><br /><b>Texturing and Modeling: A Procedural Approach</b><br />Morgan Kaufmann Publishers Inc., San Francisco, CA, USA, 2002.<br><br /><br />Hint: search a good compromise between offset and height factor parameter.</p>

   **Parameters:**

   ``maxheight : Percentage = 4%``

      .. raw:: html

         <i>Max height:</i>: Defines the maximum height for the perturbation.

   ``scale : float (bounded) = 1 [min: 0; max: 10]``

      .. raw:: html

         <i>Scale factor:</i>: Scales the fractal perturbation in and out. Values larger than 1 mean zoom out; values smaller than one mean zoom in.

   ``smoothingsteps : int = 5``

      .. raw:: html

         <i>Normals smoothing steps:</i>: Face normals will be smoothed to make the perturbation more homogeneous. This parameter represents the number of smoothing steps.

   ``seed : float = 2``

      .. raw:: html

         <i>Seed:</i>: By varying this seed, the terrain morphology will change.<br>Don't change the seed if you want to refine the current terrain morphology by changing the other parameters.

   ``algorithm : str = 'Ridged multifractal terrain' (or int = 4)``

      Possible enum values:

         0. ``'fBM (fractal Brownian Motion)'``
         1. ``'Standard multifractal'``
         2. ``'Heterogeneous multifractal'``
         3. ``'Hybrid multifractal terrain'``
         4. ``'Ridged multifractal terrain'``

      .. raw:: html

         <i>Algorithm</i>: The algorithm with which the fractal terrain will be generated.

   ``octaves : float (bounded) = 8 [min: 1; max: 20]``

      .. raw:: html

         <i>Octaves:</i>: The number of Perlin noise frequencies that will be used to generate the terrain. Reasonable values are in range [2,9].

   ``lacunarity : float = 4``

      .. raw:: html

         <i>Lacunarity:</i>: The gap between noise frequencies. This parameter is used in conjunction with fractal increment to compute the spectral weights that contribute to the noise in each octave.

   ``fractalincrement : float = 0.2``

      .. raw:: html

         <i>Fractal increment:</i>: This parameter defines how rough the generated terrain will be. The range of reasonable values changes according to the used algorithm, however you can choose it in range [0.2, 1.5].

   ``offset : float = 0.9``

      .. raw:: html

         <i>Offset:</i>: This parameter controls the multifractality of the generated terrain. If offset is low, then the terrain will be smooth.

   ``gain : float = 2.5``

      .. raw:: html

         <i>Gain:</i>: Ignored in all the algorithms except the ridged one. This parameter defines how hard the terrain will be.

   ``saveasquality : bool = false``

      .. raw:: html

         <i>Save as vertex quality</i>: Saves the perturbation value as vertex quality.

.. data:: fractal_terrain

   *MeshLab filter name*: 'Fractal Terrain'

   .. raw:: html

      Generates a fractal terrain perturbation with five different algorithms.<br />Some good parameter values to start with are:<br /><table align="center">    <tr style="border:1px solid black">        <td> - </td>        <td align="center"> Seed </td>        <td align="center"> Octaves </td>        <td align="center"> Lacunarity </td>        <td align="center"> Fractal increment </td>        <td align="center"> Offset </td>        <td align="center"> Gain </td>    </tr>    <tr>        <td>fBM</td>        <td align="center">1</td>        <td align="center">10</td>        <td align="center">2</td>        <td align="center">1.2</td>        <td align="center">-</td>        <td align="center">-</td>    </tr>    <tr>        <td>Standard multifractal</td>        <td align="center">1</td>        <td align="center">8</td>        <td align="center">2</td>        <td align="center">0.9</td>        <td align="center">0.9</td>        <td align="center">-</td>    </tr>    <tr>        <td>Heterogeneous multifractal</td>        <td align="center">1</td>        <td align="center">8</td>        <td align="center">3</td>        <td align="center">0.9</td>        <td align="center">0.4</td>        <td align="center">-</td>    </tr>    <tr>        <td>Hybrid multifractal</td>        <td align="center">1</td>        <td align="center">8</td>        <td align="center">4</td>        <td align="center">0.1</td>        <td align="center">0.3</td>        <td align="center">-</td>    </tr>    <tr>        <td>Ridged multifractal</td>        <td align="center">2</td>        <td align="center">8</td>        <td align="center">4</td>        <td align="center">0.5</td>        <td align="center">0.9</td>        <td align="center">2</td>    </tr></table><br /><br />Detailed algorithms descriptions can be found in:<br /><i>Ebert, D.S., Musgrave, F.K., Peachey, D., Perlin, K., and Worley, S.</i><br /><b>Texturing and Modeling: A Procedural Approach</b><br />Morgan Kaufmann Publishers Inc., San Francisco, CA, USA, 2002.<br></p>

   **Parameters:**

   ``steps : int = 8``

      .. raw:: html

         <i>Subdivision steps:</i>: Defines the detail of the generated terrain. Allowed values are in range [2,9]. Use values from 6 to 9 to obtain reasonable results.

   ``maxheight : float (bounded) = 0.2 [min: 0; max: 1]``

      .. raw:: html

         <i>Max height:</i>: Defines the maximum perturbation height as a fraction of the terrain's side.

   ``scale : float (bounded) = 1 [min: 0; max: 10]``

      .. raw:: html

         <i>Scale factor:</i>: Scales the fractal perturbation in and out. Values larger than 1 mean zoom out; values smaller than one mean zoom in.

   ``seed : float = 2``

      .. raw:: html

         <i>Seed:</i>: By varying this seed, the terrain morphology will change.<br>Don't change the seed if you want to refine the current terrain morphology by changing the other parameters.

   ``algorithm : str = 'Ridged multifractal terrain' (or int = 4)``

      Possible enum values:

         0. ``'fBM (fractal Brownian Motion)'``
         1. ``'Standard multifractal'``
         2. ``'Heterogeneous multifractal'``
         3. ``'Hybrid multifractal terrain'``
         4. ``'Ridged multifractal terrain'``

      .. raw:: html

         <i>Algorithm</i>: The algorithm with which the fractal terrain will be generated.

   ``octaves : float (bounded) = 8 [min: 1; max: 20]``

      .. raw:: html

         <i>Octaves:</i>: The number of Perlin noise frequencies that will be used to generate the terrain. Reasonable values are in range [2,9].

   ``lacunarity : float = 4``

      .. raw:: html

         <i>Lacunarity:</i>: The gap between noise frequencies. This parameter is used in conjunction with fractal increment to compute the spectral weights that contribute to the noise in each octave.

   ``fractalincrement : float = 0.5``

      .. raw:: html

         <i>Fractal increment:</i>: This parameter defines how rough the generated terrain will be. The range of reasonable values changes according to the used algorithm, however you can choose it in range [0.2, 1.5].

   ``offset : float = 0.9``

      .. raw:: html

         <i>Offset:</i>: This parameter controls the multifractality of the generated terrain. If offset is low, then the terrain will be smooth.

   ``gain : float = 2.5``

      .. raw:: html

         <i>Gain:</i>: Ignored in all the algorithms except the ridged one. This parameter defines how hard the terrain will be.

   ``saveasquality : bool = false``

      .. raw:: html

         <i>Save as vertex quality</i>: Saves the perturbation value as vertex quality.

.. data:: generate_scalar_harmonic_field

   *MeshLab filter name*: 'Generate Scalar Harmonic Field'

   .. raw:: html

      Generates a scalar harmonic field over the mesh. Input scalar values must be assigned to two vertices as Dirichlet boundary conditions. Applying the filter, a discrete Laplace operator generates the harmonic field values for all the mesh vertices, which are stored in the <a href='https://stackoverflow.com/questions/58610746'>quality per vertex attribute</a> of the mesh.<br>For more details see:<b>Dynamic Harmonic Fields for Surface Processing</b> by <i>Kai Xua, Hao Zhang, Daniel Cohen-Or, Yueshan Xionga</i>. Computers & Graphics, 2009 <br><a href='https://doi.org/10.1016/j.cag.2009.03.022'>doi:10.1016/j.cag.2009.03.022</a></p>

   **Parameters:**

   ``point1 : numpy.ndarray[numpy.float32[3]] = [1, 1, 1]``

      .. raw:: html

         <i>Point 1</i>: A vertex on the mesh that represent one harmonic field boundary condition.

   ``point2 : numpy.ndarray[numpy.float32[3]] = [-1, -1, -1]``

      .. raw:: html

         <i>Point 2</i>: A vertex on the mesh that represent one harmonic field boundary condition.

   ``value1 : float (bounded) = 0 [min: 0; max: 1]``

      .. raw:: html

         <i>value for the 1st point</i>: Harmonic field value for the vertex.

   ``value2 : float (bounded) = 1 [min: 0; max: 1]``

      .. raw:: html

         <i>value for the 2nd point</i>: Harmonic field value for the vertex.

   ``colorize : bool = true``

      .. raw:: html

         <i>Colorize</i>: Colorize the mesh to provide an indication of the obtained harmonic field.

.. data:: geometric_cylindrical_unwrapping

   *MeshLab filter name*: 'Geometric Cylindrical Unwrapping'

   .. raw:: html

      Unwrap the geometry of current mesh along a clylindrical equatorial projection. The cylindrical projection axis is centered on the origin and directed along the vertical <b>Y</b> axis.</p>

   **Parameters:**

   ``startangle : float = 0``

      .. raw:: html

         <i>Start angle (deg)</i>: The starting angle of the unrolling process.

   ``endangle : float = 360``

      .. raw:: html

         <i>End angle (deg)</i>: The ending angle of the unrolling process. Quality threshold for penalizing bad shaped faces.<br>The value is in the range [0..1]<br> 0 accept any kind of face (no penalties),<br> 0.5  penalize faces with quality < 0.5, proportionally to their shape<br>

   ``radius : float = 0``

      .. raw:: html

         <i>Projection Radius</i>: If non zero, this parameter specifies the desired radius of the reference cylinder used for the projection. Changing this parameter affect the <b>X</b> horizontal scaling of the resulting mesh. If zero (default) the average distance of the mesh from the axis is chosen.

.. data:: global_registration

   *MeshLab filter name*: 'Global registration'

   .. raw:: html

      Compute the rigid transformation aligning two 3d objects.</p>

   **Parameters:**

   ``refmesh : int = 0``

      .. raw:: html

         <i>Reference Mesh</i>: Reference point-cloud or mesh

   ``targetmesh : int = 0``

      .. raw:: html

         <i>Target Mesh</i>: Point-cloud or mesh to be aligned to the reference

   ``overlap : Percentage = 50%``

      .. raw:: html

         <i>Overlap Ratio</i>: Overlap ratio between the two clouds (command line option: -o)

   ``delta : float = 0.1``

      .. raw:: html

         <i>Registration tolerance</i>: Tolerance value for the congruent set exploration and LCP computation (command line option: -d)

   ``nbsamples : int = 200``

      .. raw:: html

         <i>Number of samples</i>: Number of samples used in each mesh (command line option: -n)

   ``norm_diff : float = -1``

      .. raw:: html

         <i>Filter: difference of normal (degrees)</i>: Allowed difference of normals allowed between corresponding pairs of points(command line option: -a)

   ``color_diff : float = -1``

      .. raw:: html

         <i>Filter: difference color</i>: Allowed difference of colors allowed between corresponding pairs of points(command line option: -c)

   ``max_time_seconds : int = 10000``

      .. raw:: html

         <i>Max. Computation time, in seconds</i>: Stop the computation before the end of the exploration (command line option: -t)

   ``usesuper4pcs : bool = true``

      .. raw:: html

         <i>Use Super4PCS</i>: When disable, use 4PCS algorithm (command line option: -x

.. data:: gpu_filter_example_

   *MeshLab filter name*: 'GPU Filter Example '

   .. raw:: html

      Small useless filter added only to show how to work with a gl render context inside a filter.</p>

   **Parameters:**

   ``imagebackgroundcolor : Color = [50; 50; 50; 255]``

      .. raw:: html

         <i>Image Background Color</i>: The color used as image background.

   ``imagewidth : int = 512``

      .. raw:: html

         <i>Image Width</i>: The width in pixels of the produced image.

   ``imageheight : int = 512``

      .. raw:: html

         <i>Image Height</i>: The height in pixels of the produced image.

   ``imagefilename : str = 'gpu_generated_image.png'``

      .. raw:: html

         <i>Base Image File Name</i>: The file name used to save the image.

.. data:: grid_generator

   *MeshLab filter name*: 'Grid Generator'

   .. raw:: html

      Generate a new 2D Grid mesh with number of vertices on X and Y axis specified by user with absolute length/height.<br>It's possible to center Grid on origin.</p>

   **Parameters:**

   ``numvertx : int = 10``

      .. raw:: html

         <i>num vertices on x</i>: number of vertices on x. it must be positive

   ``numverty : int = 10``

      .. raw:: html

         <i>num vertices on y</i>: number of vertices on y. it must be positive

   ``absscalex : float = 0.3``

      .. raw:: html

         <i>x scale</i>: absolute scale on x (float)

   ``absscaley : float = 0.3``

      .. raw:: html

         <i>y scale</i>: absolute scale on y (float)

   ``center : bool = false``

      .. raw:: html

         <i>centered on origin</i>: center grid generated by filter on origin.<br>Grid is first generated and than moved into origin (using muparser lib to perform fast calc on every vertex)

.. data:: hausdorff_distance

   *MeshLab filter name*: 'Hausdorff Distance'

   .. raw:: html

      Compute the Hausdorff Distance between two layers, sampling one of the two and finding for each sample the closest point over the other mesh.</p>

   **Parameters:**

   ``sampledmesh : int = 0``

      .. raw:: html

         <i>Sampled Mesh</i>: The mesh whose surface is sampled. For each sample we search the closest point on the Target Mesh.

   ``targetmesh : int = 0``

      .. raw:: html

         <i>Target Mesh</i>: The mesh that is sampled for the comparison.

   ``savesample : bool = false``

      .. raw:: html

         <i>Save Samples</i>: Save the position and distance of all the used samples on both the two surfaces, creating two new layers with two point clouds representing the used samples.

   ``samplevert : bool = true``

      .. raw:: html

         <i>Sample Vertices</i>: For the search of maxima it is useful to sample vertices and edges of the mesh with a greater care. It is quite probably the the farthest points falls along edges or on mesh vertices, and with uniform montecarlo sampling approachesthe probability of taking a sample over a vertex or an edge is theoretically null.<br>On the other hand this kind of sampling could make the overall sampling distribution slightly biased and slightly affects the cumulative results.

   ``sampleedge : bool = false``

      .. raw:: html

         <i>Sample Edges</i>: See the above comment.

   ``samplefauxedge : bool = false``

      .. raw:: html

         <i>Sample FauxEdge</i>: See the above comment.

   ``sampleface : bool = false``

      .. raw:: html

         <i>Sample Faces</i>: See the above comment.

   ``samplenum : int = 0``

      .. raw:: html

         <i>Number of samples</i>: The desired number of samples. It can be smaller or larger than the mesh size, and according to the chosen sampling strategy it will try to adapt.

   ``maxdist : Percentage = 50%``

      .. raw:: html

         <i>Max Distance</i>: Sample points for which we do not find anything within this distance are rejected and not considered neither for averaging nor for max.

.. data:: hc_laplacian_smooth

   *MeshLab filter name*: 'HC Laplacian Smooth'

   .. raw:: html

      HC Laplacian Smoothing. Extended version of Laplacian Smoothing based on the article: <br><b>Improved Laplacian Smoothing of Noisy Surface Meshes</b> by <i>Vollmer, Mencl and Müller</i>. EUROGRAPHICS Volume 18 (1999), Number 3, 131-138.<br><a href='https://doi.org/10.1111/1467-8659.00334'>doi:10.1111/1467-8659.00334</a></p>

.. data:: icosahedron

   *MeshLab filter name*: 'Icosahedron'

   .. raw:: html

      Create an Icosahedron</p>

.. data:: image_alignment_mutual_information

   *MeshLab filter name*: 'Image alignment: Mutual Information'

   .. raw:: html

      Register an image on a 3D model using Mutual Information. This filter is an implementation of Corsini et al. 'Image-to-geometry registration: a mutual information method exploiting illumination-related geometric properties', 2009, <a href="http://vcg.isti.cnr.it/Publications/2009/CDPS09/" target="_blank">Get link</a></p>

   **Parameters:**

   ``rendering_mode : str = 'Combined' (or int = 0)``

      Possible enum values:

         0. ``'Combined'``
         1. ``'Normal map'``
         2. ``'Color per vertex'``
         3. ``'Specular'``
         4. ``'Silhouette'``
         5. ``'Specular combined'``

      .. raw:: html

         <i>Rendering mode:</i>: Rendering modes

   ``shot : Shotf [still unsupported] = None``

      .. raw:: html

         <i>Starting shot</i>: If the point of view has been set by hand, it must be retrieved from current trackball

   ``estimate_focal : bool = false``

      .. raw:: html

         <i>Estimate focal length</i>: Estimate focal length: if not checked, only extrinsic parameters are estimated

   ``fine : bool = true``

      .. raw:: html

         <i>Fine Alignment</i>: Fine alignment: the perturbations applied to reach the alignment are smaller

   ``numofiterations : int = 100``

      .. raw:: html

         <i>Max iterations</i>: Maximum number of iterations

   ``tolerance : float = 0.1``

      .. raw:: html

         <i>Tolerance</i>: Threshold to stop convergence

   ``expectedvariance : float = 2``

      .. raw:: html

         <i>Expected Variance</i>: Expected Variance

   ``backgroundweight : int = 2``

      .. raw:: html

         <i>Background Weight</i>: Weight of background pixels (1, as all the other pixels; 2, one half of the other pixels etc etc)

.. data:: image_registration_global_refinement_using_mutual_information

   *MeshLab filter name*: 'Image Registration: Global refinement using Mutual Information'

   .. raw:: html

      Calculate a global refinement of image registration, in order to obtain a better alignment of fine detail. It will refine only the shots associated to the active rasters, the non-active ones will be used but not refined. This filter is an implementation of Dellepiane et al. 'Global refinement of image-to-geometry registration for color projection', 2013, and it was used in Corsini et al 'Fully Automatic Registration of Image Sets on Approximate Geometry', 2013. Please cite!</p>

   **Parameters:**

   ``renderingmode : str = 'Combined' (or int = 0)``

      Possible enum values:

         0. ``'Combined'``
         1. ``'Normal map'``
         2. ``'Color per vertex'``
         3. ``'Specular'``
         4. ``'Silhouette'``
         5. ``'Specular combined'``

      .. raw:: html

         <i>Rendering mode:</i>: Rendering modes

   ``max_number_of_refinement_steps : int = 5``

      .. raw:: html

         <i>Maximum number of minimizations step</i>: Maximum number of minimizations step on the global graph

   ``threshold_for_refinement_convergence : float = 1.2``

      .. raw:: html

         <i>Threshold for refinement convergence (in pixels)</i>: The threshold (average quadratic variation in the projection on image plane of some samples of the mesh before and after each step of refinement) that stops the refinement

   ``pre_alignment : bool = false``

      .. raw:: html

         <i>Pre-alignment step</i>: Pre-alignment step

   ``estimate_focal : bool = true``

      .. raw:: html

         <i>Estimate focal length</i>: Estimate focal length

   ``fine : bool = true``

      .. raw:: html

         <i>Fine Alignment</i>: Fine alignment

.. data:: implicit_surface

   *MeshLab filter name*: 'Implicit Surface'

   .. raw:: html

      Generate a new mesh that corresponds to the 0 valued isosurface defined by the scalar field generated by the given expression</p>

   **Parameters:**

   ``voxelsize : float = 0.05``

      .. raw:: html

         <i>Size of Voxel</i>: Size of the voxel that is used by for the grid where the field is sampled. Smaller this value, higher precision, but higher processing times.

   ``minx : float = -1``

      .. raw:: html

         <i>Min X</i>: Range where the field is sampled

   ``miny : float = -1``

      .. raw:: html

         <i>Min Y</i>: Range where the field is sampled

   ``minz : float = -1``

      .. raw:: html

         <i>Min Z</i>: Range where the field is sampled

   ``maxx : float = 1``

      .. raw:: html

         <i>Max X</i>: Range where the field is sampled

   ``maxy : float = 1``

      .. raw:: html

         <i>Max Y</i>: Range where the field is sampled

   ``maxz : float = 1``

      .. raw:: html

         <i>Max Z</i>: Range where the field is sampled

   ``expr : str = 'x*x+y*y+z*z-0.5'``

      .. raw:: html

         <i>Function =</i>: This expression is evaluated for each voxel of the grid. The surface passing through the zero valued points of this field is then extracted using marching cube.

.. data:: import_cameras_for_active_rasters_from_file

   *MeshLab filter name*: 'Import cameras for active rasters from file'

   .. raw:: html

      Import cameras for active rasters from .out or Agisoft .xml formats</p>

   **Parameters:**

   ``importfile : str = ''``

      .. raw:: html

         <i>Choose the camera file to be imported</i>: It's possible to import both Bundler .out and Agisoft .xml files. In both cases, distortion parameters won't be imported. In the case of Agisoft, it's necessary to undistort the images before exporting the xml file

.. data:: invert_faces_orientation

   *MeshLab filter name*: 'Invert Faces Orientation'

   .. raw:: html

      Invert faces orientation, flipping the normals of the mesh. <br>If requested, it tries to guess the right orientation; mainly it decide to flip all the faces if the minimum/maximum vertices have not outward point normals for a few directions.<br>Works well for single component watertight objects.</p>

   **Parameters:**

   ``forceflip : bool = true``

      .. raw:: html

         <i>Force Flip</i>: If selected, the normals will always be flipped; otherwise, the filter tries to set them outside

   ``onlyselected : bool = false``

      .. raw:: html

         <i>Flip only selected faces</i>: If selected, only selected faces will be affected

.. data:: invert_selection

   *MeshLab filter name*: 'Invert Selection'

   .. raw:: html

      Invert the current set of selected faces/vertices.</p>

   **Parameters:**

   ``invfaces : bool = false``

      .. raw:: html

         <i>Invert Faces</i>: If true the filter will invert the set of selected faces.

   ``invverts : bool = false``

      .. raw:: html

         <i>Invert Vertices</i>: If true the filter will invert the set of selected vertices.

.. data:: iso_parametrization_build_atlased_mesh

   *MeshLab filter name*: 'Iso Parametrization Build Atlased Mesh'

   .. raw:: html

      The filter build a new mesh with a standard atlased per wedge texture. The atlas is simply done by exploiting the low distortion, coarse, regular, mesh of the abstract domain<br>For more details see: <br><b>N. Pietroni, M. Tarini and P. Cignoni</b>, <br><a href="http://vcg.isti.cnr.it/Publications/2010/PTC10/">'Almost isometric mesh parameterization through abstract domains'</a> <br>IEEE Transaction of Visualization and Computer Graphics, 2010</p>

   **Parameters:**

   ``bordersize : float (bounded) = 0.1 [min: 0.01; max: 0.5]``

      .. raw:: html

         <i>BorderSize ratio</i>: This parameter controls the amount of space that must be left between each diamond when building the atlas.It directly affects how many triangle are split during this conversion. <br>In abstract parametrization mesh triangles can naturally cross the triangles of the abstract domain, so when converting to a standard parametrization we must cut all the triangles that protrudes outside each diamond more than the specified threshold.The unit of the threshold is in percentage of the size of the diamond,The bigger the threshold the less triangles are split, but the more UV space is used (wasted).

.. data:: iso_parametrization_main

   *MeshLab filter name*: 'Iso Parametrization: Main'

   .. raw:: html

      The filter builds the abstract domain mesh representing the Isoparameterization of a watertight two-manifold triangular mesh. <br>This abstract mesh can be used to uniformly remesh the input mesh, or to build a atlased texture parametrization. Abstract Mesh can be also loaded and saved. <br>In short this filter build a very coarse almost regular triangulation such that original mesh can be reprojected from this abstract mesh with minimal distortion.<br>For more details see: <br><b>N. Pietroni, M. Tarini and P. Cignoni</b>, <br><a href="http://vcg.isti.cnr.it/Publications/2010/PTC10/">'Almost isometric mesh parameterization through abstract domains'</a> <br>IEEE Transaction of Visualization and Computer Graphics, 2010</p>

   **Parameters:**

   ``targetabstractminfacenum : int = 150``

      .. raw:: html

         <i>AM  Min Size</i>: This number and the following one indicate the range face number of the abstract mesh that is used for the parametrization process.<br>The algorithm will choose the best abstract mesh with the number of triangles within the specified interval.<br>If the mesh has a very simple structure this range can be very low and strict;for a roughly spherical object if you can specify a range of [8,8] faces you get a octahedral abstract mesh, e.g. a geometry image.<br>Large numbers (greater than 400) are usually not of practical use.

   ``targetabstractmaxfacenum : int = 200``

      .. raw:: html

         <i>AM Max Size</i>: Please notice that a large interval requires huge amount of memory to be allocated, in order save the intermediate results. <br>An interval of 50 should be fine.

   ``stopcriteria : str = 'Area + Angle' (or int = 1)``

      Possible enum values:

         0. ``'Best Heuristic'``
         1. ``'Area + Angle'``
         2. ``'Regularity'``
         3. ``'L2'``

      .. raw:: html

         <i>Optimization Criteria</i>: Choose a metric to stop the parametrization within the interval<br>1: Best Heuristic : stop considering both isometry and number of faces of base domain<br>2: Area + Angle : stop at minimum area and angle distorsion<br>3: Regularity : stop at minimum number of irregular vertices<br>4: L2 : stop at minimum OneWay L2 Stretch Eff

   ``convergencespeed : int = 1``

      .. raw:: html

         <i>Convergence Precision</i>: This parameter controls the convergence speed/precision of the optimization of the texture coordinates. Larger the number slower the processing and ,eventually, slightly better results

   ``doublestep : bool = true``

      .. raw:: html

         <i>Double Step</i>: Use this bool to divide the parameterization in 2 steps. Double step makes the overall process faster and robust.<br> Consider to disable this bool in case the object has topologycal noise or small handles.

   ``absloadname : str = ''``

      .. raw:: html

         <i>Load AM</i>: The filename of the abstract mesh that has to be loaded. If empty, the abstract mesh will be computed according to the above parameters (suggested extension '.abs').

   ``abssavename : str = ''``

      .. raw:: html

         <i>Save AM</i>: The filename where the computed abstract mesh will be saved. If empty, nothing will be done.

.. data:: iso_parametrization_remeshing

   *MeshLab filter name*: 'Iso Parametrization Remeshing'

   .. raw:: html

      Uniform Remeshing based on Isoparameterization, each triangle of the domain is recursively subdivided. <br>For more details see: <br><b>N. Pietroni, M. Tarini and P. Cignoni</b>, <br><a href="http://vcg.isti.cnr.it/Publications/2010/PTC10/">'Almost isometric mesh parameterization through abstract domains'</a> <br>IEEE Transaction of Visualization and Computer Graphics, 2010</p>

   **Parameters:**

   ``samplingrate : int = 10``

      .. raw:: html

         <i>Sampling Rate</i>: This specify the sampling rate for remeshing. Must be greater than 2

.. data:: iso_parametrization_transfer_between_meshes

   *MeshLab filter name*: 'Iso Parametrization transfer between meshes'

   .. raw:: html

      Transfer the Isoparametrization between two meshes, the two meshes must be reasonably similar and well aligned. It is useful to transfer back an isoparam onto the original mesh after having computed it on a dummy, clean watertight model.<br>For more details see: <br><b>N. Pietroni, M. Tarini and P. Cignoni</b>, <br><a href="http://vcg.isti.cnr.it/Publications/2010/PTC10/">'Almost isometric mesh parameterization through abstract domains'</a> <br>IEEE Transaction of Visualization and Computer Graphics, 2010</p>

   **Parameters:**

   ``sourcemesh : int = 0``

      .. raw:: html

         <i>Source Mesh</i>: The mesh already having an Isoparameterization

   ``targetmesh : int = 0``

      .. raw:: html

         <i>Target Mesh</i>: The mesh to be Isoparameterized

.. data:: laplacian_smooth

   *MeshLab filter name*: 'Laplacian Smooth'

   .. raw:: html

      Laplacian smooth. Average each vertex position with weighted positions of neighbour vertices.<br><b>Laplacian Mesh Processing</b> by <i>Olga Sorkine</i>. EUROGRAPHICS 2005<br><a href='http://dx.doi.org/10.2312/egst.20051044'>doi:10.2312/egst.20051044</a></p>

   **Parameters:**

   ``stepsmoothnum : int = 3``

      .. raw:: html

         <i>Smoothing steps</i>: The number of times that the whole algorithm (normal smoothing + vertex fitting) is iterated.

   ``boundary : bool = true``

      .. raw:: html

         <i>1D Boundary Smoothing</i>: Smooth boundary edges only by themselves (e.g. the polyline forming the boundary of the mesh is independently smoothed). This can reduce the shrinking on the border but can have strange effects on very small boundaries.

   ``cotangentweight : bool = true``

      .. raw:: html

         <i>Cotangent weighting</i>: Use cotangent weighting scheme for the averaging of the position. Otherwise the simpler umbrella scheme (1 if the edge is present) is used.

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selection</i>: If checked the filter is performed only on the selected area

.. data:: laplacian_smooth_surface_preserving

   *MeshLab filter name*: 'Laplacian Smooth (surface preserving)'

   .. raw:: html

      Laplacian smooth with limited surface modification: move each vertex in the average position of neighbors vertices, only if the new position still (almost) lies on original surface</p>

   **Parameters:**

   ``selection : bool = false``

      .. raw:: html

         <i>Update selection</i>: Apply laplacian smooth on selected faces only

   ``angledeg : float = 0.5``

      .. raw:: html

         <i>Max Normal Dev (deg)</i>: maximum mean normal angle displacement (degrees) from old to new faces

   ``iterations : int = 1``

      .. raw:: html

         <i>Iterations</i>: number of laplacian smooth iterations in every run

.. data:: marching_cubes_apss

   *MeshLab filter name*: 'Marching Cubes (APSS)'

   .. raw:: html

      Extract the iso-surface (as a mesh) of a MLS surface defined by the current point set (or mesh)using the marching cubes algorithm. The coarse extraction is followed by an accurate projectionstep onto the MLS, and an extra zero removal procedure.<br><br>This is the <i>algebraic point set surfaces</i> (APSS) variant which is based on the local fitting of algebraic spheres. It requires points equipped with oriented normals. <br>For all the details about APSS see: <br> Guennebaud and Gross, 'Algebraic Point Set Surfaces', Siggraph 2007, and<br>Guennebaud et al., 'Dynamic Sampling and Rendering of APSS', Eurographics 2008</p>

   **Parameters:**

   ``filterscale : float = 2``

      .. raw:: html

         <i>MLS - Filter scale</i>: Scale of the spatial low pass filter.<br>It is relative to the radius (local point spacing) of the vertices.

   ``projectionaccuracy : float = 0.0001``

      .. raw:: html

         <i>Projection - Accuracy (adv)</i>: Threshold value used to stop the projections.<br>This value is scaled by the mean point spacing to get the actual threshold.

   ``maxprojectioniters : int = 15``

      .. raw:: html

         <i>Projection - Max iterations (adv)</i>: Max number of iterations for the projection.

   ``sphericalparameter : float = 1``

      .. raw:: html

         <i>MLS - Spherical parameter</i>: Control the curvature of the fitted spheres: 0 is equivalent to a pure plane fit,1 to a pure spherical fit, values between 0 and 1 gives intermediate results,while other real values might give interesting results, but take care with extremesettings !

   ``accuratenormal : bool = true``

      .. raw:: html

         <i>Accurate normals</i>: If checked, use the accurate MLS gradient instead of the local approximationto compute the normals.

   ``resolution : int = 200``

      .. raw:: html

         <i>Grid Resolution</i>: The resolution of the grid on which we run the marching cubes.This marching cube is memory friendly, so you can safely set large values up to 1000 or even more.

.. data:: marching_cubes_rimls

   *MeshLab filter name*: 'Marching Cubes (RIMLS)'

   .. raw:: html

      Extract the iso-surface (as a mesh) of a MLS surface defined by the current point set (or mesh)using the marching cubes algorithm. The coarse extraction is followed by an accurate projectionstep onto the MLS, and an extra zero removal procedure.<br><br>This is the Robust Implicit MLS (RIMLS) variant which is an extension of Implicit MLS preserving sharp features using non linear regression. For more details see: <br>Oztireli, Guennebaud and Gross, 'Feature Preserving Point Set Surfaces based on Non-Linear Kernel Regression' Eurographics 2009.</p>

   **Parameters:**

   ``filterscale : float = 2``

      .. raw:: html

         <i>MLS - Filter scale</i>: Scale of the spatial low pass filter.<br>It is relative to the radius (local point spacing) of the vertices.

   ``projectionaccuracy : float = 0.0001``

      .. raw:: html

         <i>Projection - Accuracy (adv)</i>: Threshold value used to stop the projections.<br>This value is scaled by the mean point spacing to get the actual threshold.

   ``maxprojectioniters : int = 15``

      .. raw:: html

         <i>Projection - Max iterations (adv)</i>: Max number of iterations for the projection.

   ``sigman : float = 0.75``

      .. raw:: html

         <i>MLS - Sharpness</i>: Width of the filter used by the normal refitting weight.This weight function is a Gaussian on the distance between two unit vectors:the current gradient and the input normal. Therefore, typical value range between 0.5 (sharp) to 2 (smooth).

   ``maxrefittingiters : int = 3``

      .. raw:: html

         <i>MLS - Max fitting iterations</i>: Max number of fitting iterations. (0 or 1 is equivalent to the standard IMLS)

   ``resolution : int = 200``

      .. raw:: html

         <i>Grid Resolution</i>: The resolution of the grid on which we run the marching cubes.This marching cube is memory friendly, so you can safely set large values up to 1000 or even more.

.. data:: matrix_freeze_current_matrix

   *MeshLab filter name*: 'Matrix: Freeze Current Matrix'

   .. raw:: html

      Freeze the current transformation matrix into the coordinates of the vertices of the mesh (and set this matrix to the identity). In other words it applies in a definetive way the current matrix to the vertex coordinates.</p>

   **Parameters:**

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: matrix_invert_current_matrix

   *MeshLab filter name*: 'Matrix: Invert Current Matrix'

   .. raw:: html

      Invert the current transformation matrix. The current transformation is reversed, becoming its opposite.</p>

   **Parameters:**

   ``freeze : bool = true``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: matrix_reset_current_matrix

   *MeshLab filter name*: 'Matrix: Reset Current Matrix'

   .. raw:: html

      Set the current transformation matrix to the Identity. </p>

   **Parameters:**

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: matrix_set_copy_transformation

   *MeshLab filter name*: 'Matrix: Set/Copy Transformation'

   .. raw:: html

      Set the current transformation matrix by filling it, or copying from another layer.</p>

   **Parameters:**

   ``transformmatrix : numpy.ndarray[numpy.float32[4, 4]] = [[1, 0, 0, 0],[0, 1, 0, 0],[0, 0, 1, 0],[0, 0, 0, 1]]``

      .. raw:: html

         <i></i>:

   ``compose : bool = false``

      .. raw:: html

         <i>Compose with current</i>: If selected, the new matrix will be composed with the current one (matrix=new*old)

   ``freeze : bool = true``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected, the filter will be applied to all visible mesh layers

.. data:: matrix_set_from_translation_rotation_scale

   *MeshLab filter name*: 'Matrix: Set from translation/rotation/scale'

   .. raw:: html

      Set the current transformation matrix starting from parameters: [XYZ] translation, [XYZ] Euler angles rotation and [XYZ] scaling.</p>

   **Parameters:**

   ``translationx : float = 0``

      .. raw:: html

         <i>X Translation</i>: Translation factor on X axis

   ``translationy : float = 0``

      .. raw:: html

         <i>Y Translation</i>: Translation factor on Y axis

   ``translationz : float = 0``

      .. raw:: html

         <i>Z Translation</i>: Translation factor on Z axis

   ``rotationx : float = 0``

      .. raw:: html

         <i>X Rotation</i>: Rotation angle on X axis

   ``rotationy : float = 0``

      .. raw:: html

         <i>Y Rotation</i>: Rotation angle on Y axis

   ``rotationz : float = 0``

      .. raw:: html

         <i>Z Rotation</i>: Rotation angle on Z axis

   ``scalex : float = 1``

      .. raw:: html

         <i>X Scale</i>: Scaling factor on X axis

   ``scaley : float = 1``

      .. raw:: html

         <i>Y Scale</i>: Scaling factor on Y axis

   ``scalez : float = 1``

      .. raw:: html

         <i>Z Scale</i>: Scaling factor on Z axis

   ``compose : bool = false``

      .. raw:: html

         <i>Compose with current</i>: If selected, the new matrix will be composed with the current one (matrix=new*old)

   ``freeze : bool = true``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: merge_close_vertices

   *MeshLab filter name*: 'Merge Close Vertices'

   .. raw:: html

      Merge together all the vertices that are nearer than the specified threshold. Like a unify duplicated vertices but with some tolerance.</p>

   **Parameters:**

   ``threshold : Percentage = 1%``

      .. raw:: html

         <i>Merging distance</i>: All the vertices that closer than this threshold are merged together. Use very small values, default values is 1/10000 of bounding box diagonal.

.. data:: merge_wedge_texture_coord

   *MeshLab filter name*: 'Merge Wedge Texture Coord'

   .. raw:: html

      Merge together per-wedge texture coords that are very close. Used to correct apparent texture seams that can arise from numerical approximations when saving in ascii formats.</p>

   **Parameters:**

   ``mergethr : float = 0.0001``

      .. raw:: html

         <i>Merging Threshold</i>: All the per-wedge texture coords that are on the same vertex and are distant less then the given threshold are merged together. It can be used to remove the fake texture seams that arise from error. Distance is in texture space (the default, 1e-4, corresponds to one texel on a 10kx10x texture)

.. data:: mesh_element_sampling

   *MeshLab filter name*: 'Mesh Element Sampling'

   .. raw:: html

      Create a new layer populated with a point sampling of the current mesh; at most one sample for each element of the mesh is created. Samples are taking in a uniform way, one for each element (vertex/edge/face); all the elements have the same probability of being chosen.</p>

   **Parameters:**

   ``sampling : str = 'Vertex' (or int = 0)``

      Possible enum values:

         0. ``'Vertex'``
         1. ``'Edge'``
         2. ``'Face'``

      .. raw:: html

         <i>Element to sample:</i>: Choose what mesh element has to be used for the subsampling. At most one point sample will be added for each one of the chosen elements

   ``samplenum : int = 0``

      .. raw:: html

         <i>Number of samples</i>: The desired number of elements that must be chosen. Being a subsampling of the original elements if this number should not be larger than the number of elements of the original mesh.

.. data:: mls_projection_apss

   *MeshLab filter name*: 'MLS projection (APSS)'

   .. raw:: html

      Project a mesh (or a point set) onto the MLS surface defined by itself or another point set.<br><br>This is the <i>algebraic point set surfaces</i> (APSS) variant which is based on the local fitting of algebraic spheres. It requires points equipped with oriented normals. <br>For all the details about APSS see: <br> Guennebaud and Gross, 'Algebraic Point Set Surfaces', Siggraph 2007, and<br>Guennebaud et al., 'Dynamic Sampling and Rendering of APSS', Eurographics 2008</p>

   **Parameters:**

   ``controlmesh : int = 0``

      .. raw:: html

         <i>Point set</i>: The point set (or mesh) which defines the MLS surface.

   ``proxymesh : int = 0``

      .. raw:: html

         <i>Proxy Mesh</i>: The mesh that will be projected/resampled onto the MLS surface.

   ``selectiononly : bool = false``

      .. raw:: html

         <i>Selection only</i>: If checked, only selected vertices will be projected.

   ``filterscale : float = 2``

      .. raw:: html

         <i>MLS - Filter scale</i>: Scale of the spatial low pass filter.<br>It is relative to the radius (local point spacing) of the vertices.

   ``projectionaccuracy : float = 0.0001``

      .. raw:: html

         <i>Projection - Accuracy (adv)</i>: Threshold value used to stop the projections.<br>This value is scaled by the mean point spacing to get the actual threshold.

   ``maxprojectioniters : int = 15``

      .. raw:: html

         <i>Projection - Max iterations (adv)</i>: Max number of iterations for the projection.

   ``sphericalparameter : float = 1``

      .. raw:: html

         <i>MLS - Spherical parameter</i>: Control the curvature of the fitted spheres: 0 is equivalent to a pure plane fit,1 to a pure spherical fit, values between 0 and 1 gives intermediate results,while other real values might give interesting results, but take care with extremesettings !

   ``accuratenormal : bool = true``

      .. raw:: html

         <i>Accurate normals</i>: If checked, use the accurate MLS gradient instead of the local approximationto compute the normals.

   ``maxsubdivisions : int = 0``

      .. raw:: html

         <i>Refinement - Max subdivisions</i>: Max number of subdivisions.

   ``thangleindegree : float = 2``

      .. raw:: html

         <i>Refinement - Crease angle (degree)</i>: Threshold angle between two faces controlling the refinement.

.. data:: mls_projection_rimls

   *MeshLab filter name*: 'MLS projection (RIMLS)'

   .. raw:: html

      Project a mesh (or a point set) onto the MLS surface defined by itself or another point set.<br><br>This is the Robust Implicit MLS (RIMLS) variant which is an extension of Implicit MLS preserving sharp features using non linear regression. For more details see: <br>Oztireli, Guennebaud and Gross, 'Feature Preserving Point Set Surfaces based on Non-Linear Kernel Regression' Eurographics 2009.</p>

   **Parameters:**

   ``controlmesh : int = 0``

      .. raw:: html

         <i>Point set</i>: The point set (or mesh) which defines the MLS surface.

   ``proxymesh : int = 0``

      .. raw:: html

         <i>Proxy Mesh</i>: The mesh that will be projected/resampled onto the MLS surface.

   ``selectiononly : bool = false``

      .. raw:: html

         <i>Selection only</i>: If checked, only selected vertices will be projected.

   ``filterscale : float = 2``

      .. raw:: html

         <i>MLS - Filter scale</i>: Scale of the spatial low pass filter.<br>It is relative to the radius (local point spacing) of the vertices.

   ``projectionaccuracy : float = 0.0001``

      .. raw:: html

         <i>Projection - Accuracy (adv)</i>: Threshold value used to stop the projections.<br>This value is scaled by the mean point spacing to get the actual threshold.

   ``maxprojectioniters : int = 15``

      .. raw:: html

         <i>Projection - Max iterations (adv)</i>: Max number of iterations for the projection.

   ``sigman : float = 0.75``

      .. raw:: html

         <i>MLS - Sharpness</i>: Width of the filter used by the normal refitting weight.This weight function is a Gaussian on the distance between two unit vectors:the current gradient and the input normal. Therefore, typical value range between 0.5 (sharp) to 2 (smooth).

   ``maxrefittingiters : int = 3``

      .. raw:: html

         <i>MLS - Max fitting iterations</i>: Max number of fitting iterations. (0 or 1 is equivalent to the standard IMLS)

   ``maxsubdivisions : int = 0``

      .. raw:: html

         <i>Refinement - Max subdivisions</i>: Max number of subdivisions.

   ``thangleindegree : float = 2``

      .. raw:: html

         <i>Refinement - Crease angle (degree)</i>: Threshold angle between two faces controlling the refinement.

.. data:: montecarlo_sampling

   *MeshLab filter name*: 'Montecarlo Sampling'

   .. raw:: html

      Create a new layer populated with a point sampling of the current mesh; samples are generated in a randomly uniform way, or with a distribution biased by the per-vertex quality values of the mesh.</p>

   **Parameters:**

   ``samplenum : int = 0``

      .. raw:: html

         <i>Number of samples</i>: The desired number of samples. It can be smaller or larger than the mesh size, and according to the chosen sampling strategy it will try to adapt.

   ``weighted : bool = false``

      .. raw:: html

         <i>Quality Weighted Sampling</i>: Use per vertex quality to drive the vertex sampling. The number of samples falling in each face is proportional to the face area multiplied by the average quality of the face vertices.

   ``perfacenormal : bool = false``

      .. raw:: html

         <i>Per-Face Normal</i>: If true for each sample we take the normal of the sampled face, otherwise the normal interpolated from the vertex normals.

   ``radiusvariance : float = 1``

      .. raw:: html

         <i>Radius Variance</i>: The radius of the disk is allowed to vary between r/var and r*var. If this parameter is 1 the sampling is the same of the Poisson Disk Sampling

   ``exactnum : bool = true``

      .. raw:: html

         <i>Exact Sample Number</i>: If the required total number of samples is not a strict exact requirement we can exploit a different algorithmbased on the choice of the number of samples inside each triangle by a random Poisson-distributed number with mean equal to the expected number of samples times the area of the triangle over the surface of the whole mesh.

   ``edgesampling : bool = false``

      .. raw:: html

         <i>Sample CreaseEdge Only</i>: Restrict the sampling process to the crease edges only. Useful to sample in a more accurate way the feature edges of a mechanical mesh.

.. data:: move_selected_faces_to_another_layer

   *MeshLab filter name*: 'Move selected faces to another layer'

   .. raw:: html

      Selected faces are moved (or duplicated) in a new layer. Warning! per-vertex and per-face user defined attributes will not be transferred.</p>

   **Parameters:**

   ``deleteoriginal : bool = true``

      .. raw:: html

         <i>Delete original selection</i>: Deletes the original selected faces/vertices, thus splitting the mesh among layers. <br><br>if false, the selected faces/vertices are duplicated in the new layer

.. data:: move_selected_vertices_to_another_layer

   *MeshLab filter name*: 'Move selected vertices to another layer'

   .. raw:: html

      Selected vertices are moved (or duplicated) in a new layer. Warning! per-vertex user defined attributes will not be transferred.</p>

   **Parameters:**

   ``deleteoriginal : bool = true``

      .. raw:: html

         <i>Delete original selection</i>: Deletes the original selected faces/vertices, thus splitting the mesh among layers. <br><br>if false, the selected faces/vertices are duplicated in the new layer

.. data:: noisy_isosurface

   *MeshLab filter name*: 'Noisy Isosurface'

   .. raw:: html

      Create a isosurface perturbed by a noisy isosurface.</p>

   **Parameters:**

   ``resolution : int = 64``

      .. raw:: html

         <i>Grid Resolution</i>: Resolution of the side of the cubic grid used for the volume creation

.. data:: normalize_face_normals

   *MeshLab filter name*: 'Normalize Face Normals'

   .. raw:: html

      Normalize Face Normal Lengths to unit vectors.</p>

.. data:: normalize_vertex_normals

   *MeshLab filter name*: 'Normalize Vertex Normals'

   .. raw:: html

      Normalize Vertex Normal Lengths to unit vectors.</p>

.. data:: octahedron

   *MeshLab filter name*: 'Octahedron'

   .. raw:: html

      Create an Octahedron</p>

.. data:: parameterization__texturing_from_registered_rasters

   *MeshLab filter name*: 'Parameterization + texturing from registered rasters'

   .. raw:: html

      The mesh is parameterized and textured by creating some patches that correspond to projection of portions of surfaces onto the set of registered rasters.</p>

   **Parameters:**

   ``texturesize : int = 1024``

      .. raw:: html

         <i>Texture size</i>: Specifies the dimension of the generated texture

   ``texturename : str = 'texture.png'``

      .. raw:: html

         <i>Texture name</i>: Specifies the name of the file into which the texture image will be saved

   ``colorcorrection : bool = true``

      .. raw:: html

         <i>Color correction</i>: If true, the final texture is corrected so as to ensure seamless transitions

   ``colorcorrectionfiltersize : int = 1``

      .. raw:: html

         <i>Color correction filter</i>: It is the radius (in pixel) of the kernel that is used to compute the difference between corresponding texels in different rasters. Default is 1 that generate a 3x3 kernel. Highest values increase the robustness of the color correction process in the case of strong image-to-geometry misalignments

   ``usedistanceweight : bool = true``

      .. raw:: html

         <i>Use distance weight</i>: Includes a weight accounting for the distance to the camera during the computation of reference images

   ``useimgborderweight : bool = true``

      .. raw:: html

         <i>Use image border weight</i>: Includes a weight accounting for the distance to the image border during the computation of reference images

   ``usealphaweight : bool = false``

      .. raw:: html

         <i>Use image alpha weight</i>: If true, alpha channel of the image is used as additional weight. In this way it is possible to mask-out parts of the images that should not be projected on the mesh. Please note this is not a transparency effect, but just influences the weigthing between different images

   ``cleanisolatedtriangles : bool = true``

      .. raw:: html

         <i>Clean isolated triangles</i>: Remove all patches compound of a single triangle by aggregating them to adjacent patches

   ``stretchingallowed : bool = false``

      .. raw:: html

         <i>UV stretching</i>: If true, texture coordinates are stretched so as to cover the full interval [0,1] for both directions

   ``texturegutter : int = 4``

      .. raw:: html

         <i>Texture gutter</i>: Extra boundary to add to each patch before packing in texture space (in pixels)

.. data:: parameterization_from_registered_rasters

   *MeshLab filter name*: 'Parameterization from registered rasters'

   .. raw:: html

      The mesh is parameterized by creating some patches that correspond to projection of portions of surfaces onto the set of registered rasters.</p>

   **Parameters:**

   ``usedistanceweight : bool = true``

      .. raw:: html

         <i>Use distance weight</i>: Includes a weight accounting for the distance to the camera during the computation of reference images

   ``useimgborderweight : bool = true``

      .. raw:: html

         <i>Use image border weight</i>: Includes a weight accounting for the distance to the image border during the computation of reference images

   ``usealphaweight : bool = false``

      .. raw:: html

         <i>Use image alpha weight</i>: If true, alpha channel of the image is used as additional weight. In this way it is possible to mask-out parts of the images that should not be projected on the mesh. Please note this is not a transparency effect, but just influences the weigthing between different images

   ``cleanisolatedtriangles : bool = true``

      .. raw:: html

         <i>Clean isolated triangles</i>: Remove all patches compound of a single triangle by aggregating them to adjacent patches

   ``stretchingallowed : bool = false``

      .. raw:: html

         <i>UV stretching</i>: If true, texture coordinates are stretched so as to cover the full interval [0,1] for both directions

   ``texturegutter : int = 4``

      .. raw:: html

         <i>Texture gutter</i>: Extra boundary to add to each patch before packing in texture space (in pixels)

.. data:: parametrization_flat_plane

   *MeshLab filter name*: 'Parametrization: Flat Plane'

   .. raw:: html

      Builds a trivial flat-plane parametrization.</p>

   **Parameters:**

   ``projectionplane : str = 'XY' (or int = 0)``

      Possible enum values:

         0. ``'XY'``
         1. ``'XZ'``
         2. ``'YZ'``

      .. raw:: html

         <i>Projection plane</i>: Choose the projection plane

   ``aspectratio : bool = false``

      .. raw:: html

         <i>Preserve Ratio</i>: If checked the resulting parametrization will preserve the original apsect ratio of the model otherwise it will fill up the whole 0..1 uv space

   ``sidegutter : float = 0``

      .. raw:: html

         <i>Side Gutter</i>: Leave an empty space around the parametrization area of the specified size (in texture space); accepted range [0.0 - 0.5].

.. data:: parametrization_trivial_per_triangle

   *MeshLab filter name*: 'Parametrization: Trivial Per-Triangle'

   .. raw:: html

      Builds a trivial triangle-by-triangle parametrization. <br> Two methods are provided, the first maps maps all triangles into equal sized triangles, while the second one adapt the size of the triangles in texture space to their original size.</p>

   **Parameters:**

   ``sidedim : int = 0``

      .. raw:: html

         <i>Quads per line</i>: Indicates how many triangles have to be put on each line (every quad contains two triangles)<br>Leave 0 for automatic calculation

   ``textdim : int = 1024``

      .. raw:: html

         <i>Texture Dimension (px)</i>: Gives an indication on how big the texture is

   ``border : int = 2``

      .. raw:: html

         <i>Inter-Triangle border (px)</i>: Specifies how many pixels to be left between triangles in parametrization domain

   ``method : str = 'Space-optimizing' (or int = 1)``

      Possible enum values:

         0. ``'Basic'``
         1. ``'Space-optimizing'``

      .. raw:: html

         <i>Method</i>: Choose space optimizing to map smaller faces into smaller triangles in parametrizazion domain

.. data:: parametrization_voronoi_atlas

   *MeshLab filter name*: 'Parametrization: Voronoi Atlas'

   .. raw:: html

      Build an atlased parametrization based on a geodesic voronoi partitioning of the surface and parametrizing each region using Harmonic Mapping. For the  parametrization of the disk like voronoi regions the used method is: <br><b>Ulrich Pinkall, Konrad Polthier</b><br>											<i>Computing Discrete Minimal Surfaces and Their Conjugates</i> <br>											Experimental Mathematics, Vol 2 (1), 1993<br> .</p>

   **Parameters:**

   ``regionnum : int = 10``

      .. raw:: html

         <i>Approx. Region Num</i>: An estimation of the number of regions that must be generated. Smaller regions could lead to parametrizations with smaller distortion.

   ``overlapflag : bool = false``

      .. raw:: html

         <i>Overlap</i>: If checked the resulting parametrization will be composed by <i>overlapping</i> regions, e.g. the resulting mesh will have duplicated faces: each region will have a ring of ovelapping duplicate faces that will ensure that border regions will be parametrized in the atlas twice. This is quite useful for building mipmap robust atlases

.. data:: per_face_color_function

   *MeshLab filter name*: 'Per Face Color Function'

   .. raw:: html

      Color function using muparser lib to generate new RGBA color for every face<br>Red, Green, Blue and Alpha channels may be defined specifying a function in their respective fields.<br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

   **Parameters:**

   ``r : str = '255'``

      .. raw:: html

         <i>func r = </i>: function to generate Red component. Expected Range 0-255

   ``g : str = '0'``

      .. raw:: html

         <i>func g = </i>: function to generate Green component. Expected Range 0-255

   ``b : str = '255'``

      .. raw:: html

         <i>func b = </i>: function to generate Blue component. Expected Range 0-255

   ``a : str = '255'``

      .. raw:: html

         <i>func alpha = </i>: function to generate Alpha component. Expected Range 0-255

   ``onselected : bool = false``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected faces

.. data:: per_face_quality_according_to_triangle_shape_and_aspect_ratio

   *MeshLab filter name*: 'Per Face Quality according to Triangle shape and aspect ratio'

   .. raw:: html

      Compute a quality and colorize faces depending on triangle shape:<ol><li>area/max side of triangle<li>ratio inradius/circumradius (radii of incircle and circumcircle)<li>Mean ratio of triangle = area/(a*a + b*b + c*c)<li>Area<li>Texture Angle Distortion. Difference between angle in 3D space and texture space<li>Texture Area Distortion. Difference between area in 3D space and texture space<li>Polygonal Planarity (max distance to support plane)<li>Polygonal Planarity (relative distance to support plane)</ol></p>

   **Parameters:**

   ``metric : str = 'area/max side' (or int = 0)``

      Possible enum values:

         0. ``'area/max side'``
         1. ``'inradius/circumradius'``
         2. ``'Mean ratio'``
         3. ``'Area'``
         4. ``'Texture Angle Distortion'``
         5. ``'Texture Area Distortion'``
         6. ``'Polygonal planarity (max)'``
         7. ``'Polygonal planarity (relative)'``

      .. raw:: html

         <i>Metric:</i>: Choose a metric to compute triangle quality.

.. data:: per_face_quality_function

   *MeshLab filter name*: 'Per Face Quality Function'

   .. raw:: html

      Quality function using muparser to generate new Quality for every face<br>Insert three function each one for quality of the three vertex of a face<br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

   **Parameters:**

   ``q : str = 'x0+y0+z0'``

      .. raw:: html

         <i>func q0 = </i>: function to generate new Quality foreach face

   ``normalize : bool = false``

      .. raw:: html

         <i>normalize</i>: if checked normalize all quality values in range [0..1]

   ``map : bool = false``

      .. raw:: html

         <i>map into color</i>: if checked map quality generated values into per-vertex color

   ``onselected : bool = false``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected faces

.. data:: per_face_quality_histogram

   *MeshLab filter name*: 'Per Face Quality Histogram'

   .. raw:: html

      Compute an histogram of the values of the per-face quality.</p>

   **Parameters:**

   ``histmin : float = 3.40282e+38``

      .. raw:: html

         <i>Hist Min</i>: The faces are displaced of a vector whose norm is bounded by this value

   ``histmax : float = -3.40282e+38``

      .. raw:: html

         <i>Hist Max</i>: The faces are displaced of a vector whose norm is bounded by this value

   ``areaweighted : bool = false``

      .. raw:: html

         <i>Area Weighted</i>: If false, the histogram will report the number of faces with quality values falling in each bin of the histogram. If true each bin of the histogram will report the approximate area of the mesh with that range of values.

   ``binnum : int = 20``

      .. raw:: html

         <i>Bin number</i>: The number of bins of the histogram. E.g. the number of intervals in which the min..max range is subdivided into.

.. data:: per_face_quality_stat

   *MeshLab filter name*: 'Per Face Quality Stat'

   .. raw:: html

      Compute some aggregate statistics over the per vertex quality, like Min, Max, Average, StdDev and Variance.</p>

.. data:: per_vertex_color_function

   *MeshLab filter name*: 'Per Vertex Color Function'

   .. raw:: html

      Color function using muparser lib to generate new RGBA color for every vertex<br>Red, Green, Blue and Alpha channels may be defined specifying a function in their respective fields.<br>It's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``x : str = '255'``

      .. raw:: html

         <i>func r = </i>: function to generate Red component. Expected Range 0-255

   ``y : str = '255'``

      .. raw:: html

         <i>func g = </i>: function to generate Green component. Expected Range 0-255

   ``z : str = '0'``

      .. raw:: html

         <i>func b = </i>: function to generate Blue component. Expected Range 0-255

   ``a : str = '255'``

      .. raw:: html

         <i>func alpha = </i>: function to generate Alpha component. Expected Range 0-255

   ``onselected : bool = false``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: per_vertex_geometric_function

   *MeshLab filter name*: 'Per Vertex Geometric Function'

   .. raw:: html

      Geometric function using muparser lib to generate new Coord<br>You can change x,y,z for every vertex according to the function specified.<br>It's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``x : str = 'x'``

      .. raw:: html

         <i>func x = </i>: insert function to generate new coord for x

   ``y : str = 'y'``

      .. raw:: html

         <i>func y = </i>: insert function to generate new coord for y

   ``z : str = 'sin(x+y)'``

      .. raw:: html

         <i>func z = </i>: insert function to generate new coord for z

   ``onselected : bool = false``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: per_vertex_normal_function

   *MeshLab filter name*: 'Per Vertex Normal Function'

   .. raw:: html

      Normal function using muparser to generate new Normal for every vertex<br>It's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``x : str = '-nx'``

      .. raw:: html

         <i>func nx = </i>: insert function to generate new x for the normal

   ``y : str = '-ny'``

      .. raw:: html

         <i>func ny = </i>: insert function to generate new y for the normal

   ``z : str = '-nz'``

      .. raw:: html

         <i>func nz = </i>: insert function to generate new z for the normal

   ``onselected : bool = false``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: per_vertex_quality_function

   *MeshLab filter name*: 'Per Vertex Quality Function'

   .. raw:: html

      Quality function using muparser to generate new Quality for every vertex<br>It's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``q : str = 'vi'``

      .. raw:: html

         <i>func q = </i>: function to generate new Quality for every vertex

   ``normalize : bool = false``

      .. raw:: html

         <i>normalize</i>: if checked normalize all quality values in range [0..1]

   ``map : bool = false``

      .. raw:: html

         <i>map into color</i>: if checked map quality generated values into per-vertex color

   ``onselected : bool = false``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: per_vertex_quality_histogram

   *MeshLab filter name*: 'Per Vertex Quality Histogram'

   .. raw:: html

      Compute an histogram of the values of the per-vertex quality. It can be useful to evaluate the distribution of the quality value over the surface. It can be discrete (e.g. based on vertex count or area weighted).</p>

   **Parameters:**

   ``histmin : float = 3.40282e+38``

      .. raw:: html

         <i>Hist Min</i>: The vertex are displaced of a vector whose norm is bounded by this value

   ``histmax : float = -3.40282e+38``

      .. raw:: html

         <i>Hist Max</i>: The vertex are displaced of a vector whose norm is bounded by this value

   ``areaweighted : bool = false``

      .. raw:: html

         <i>Area Weighted</i>: If false, the histogram will report the number of vertices with quality values falling in each bin of the histogram. If true each bin of the histogram will report the approximate area of the mesh with that range of values. Area is computed by assigning to each vertex one third of the area all the incident triangles.

   ``binnum : int = 20``

      .. raw:: html

         <i>Bin number</i>: The number of bins of the histogram. E.g. the number of intervals in which the min..max range is subdivided into.

.. data:: per_vertex_quality_stat

   *MeshLab filter name*: 'Per Vertex Quality Stat'

   .. raw:: html

      Compute some aggregate statistics over the per vertex quality, like Min, Max, Average, StdDev and Variance.</p>

.. data:: per_vertex_texture_function

   *MeshLab filter name*: 'Per Vertex Texture Function'

   .. raw:: html

      Texture function using muparser to generate new texture coords for every vertex<br>It's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``u : str = 'x'``

      .. raw:: html

         <i>func u = </i>: function to generate u texture coord. Expected Range 0-1

   ``v : str = 'y'``

      .. raw:: html

         <i>func v = </i>: function to generate v texture coord. Expected Range 0-1

   ``onselected : bool = false``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: per_wedge_texture_function

   *MeshLab filter name*: 'Per Wedge Texture Function'

   .. raw:: html

      Texture function using muparser to generate new per wedge tex coords for every face<br>Insert six functions each u v for each one of the three vertex of a face<br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

   **Parameters:**

   ``u0 : str = 'x0'``

      .. raw:: html

         <i>func u0 = </i>: function to generate u texture coord. of wedge 0. Expected Range 0-1

   ``v0 : str = 'y0'``

      .. raw:: html

         <i>func v0 = </i>: function to generate v texture coord. of wedge 0. Expected Range 0-1

   ``u1 : str = 'x1'``

      .. raw:: html

         <i>func u1 = </i>: function to generate u texture coord. of wedge 1. Expected Range 0-1

   ``v1 : str = 'y1'``

      .. raw:: html

         <i>func v1 = </i>: function to generate v texture coord. of wedge 1. Expected Range 0-1

   ``u2 : str = 'x2'``

      .. raw:: html

         <i>func u2 = </i>: function to generate u texture coord. of wedge 2. Expected Range 0-1

   ``v2 : str = 'y2'``

      .. raw:: html

         <i>func v2 = </i>: function to generate v texture coord. of wedge 2. Expected Range 0-1

   ``onselected : bool = false``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected faces

.. data:: perlin_color

   *MeshLab filter name*: 'Perlin color'

   .. raw:: html

      Paints the mesh using PerlinColor function. The color assigned to vertices depends on their position in the space; it means that near vertices will be painted with similar colors.</p>

   **Parameters:**

   ``color1 : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>Color 1:</i>: Sets the first color to mix with Perlin Noise function.

   ``color2 : Color = [255; 255; 255; 255]``

      .. raw:: html

         <i>Color 2:</i>: Sets the second color to mix with Perlin Noise function.

   ``freq : float (bounded) = 10 [min: 0.1; max: 100]``

      .. raw:: html

         <i>Frequency:</i>: Frequency of the Perlin Noise function, expressed as multiples of mesh bbox (frequency 10 means a noise period of bbox diagonal / 10). High frequencies produces many small splashes of colours, while low frequencies produces few big splashes.

   ``offset : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Offset</i>: This values is the XYZ frequency offset of the Noise function (offset 1 means 1 period shift).

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: permesh_color_scattering

   *MeshLab filter name*: 'PerMesh Color Scattering'

   .. raw:: html

      Assigns a random color to each visible mesh layer in the document. Colors change every time the filter is executed, but are always chosen so that they differ as much as possible.</p>

   **Parameters:**

   ``seed : int = 0``

      .. raw:: html

         <i>Seed</i>: Random seed used to generate scattered colors. Zero means totally random (each time the filter is started it generates a different result)

.. data:: planar_flipping_optimization

   *MeshLab filter name*: 'Planar flipping optimization'

   .. raw:: html

      Mesh optimization by edge flipping, to improve local triangle quality</p>

   **Parameters:**

   ``selection : bool = false``

      .. raw:: html

         <i>Update selection</i>: Apply edge flip optimization on selected faces only

   ``pthreshold : float = 1``

      .. raw:: html

         <i>Planar threshold (deg)</i>: angle threshold for planar faces (degrees)

   ``planartype : str = 'area/max side' (or int = 0)``

      Possible enum values:

         0. ``'area/max side'``
         1. ``'inradius/circumradius'``
         2. ``'mean ratio'``
         3. ``'delaunay'``
         4. ``'topology'``

      .. raw:: html

         <i>Planar metric</i>: <p style='white-space:pre'>Choose a metric to define the planar flip operation<br><br>Triangle quality based<br>1: minimum ratio height/edge among the edges<br>2: ratio between radii of incenter and circumcenter<br>3: 2*sqrt(a, b)/(a+b), a, b the eigenvalues of M^tM,<br>     M transform triangle into equilateral<br><br>Others<br>4: Fix the Delaunay condition between two faces<br>5: Do the flip to improve local topology<br>

   ``iterations : int = 1``

      .. raw:: html

         <i>Post optimization relax iter</i>: number of a planar laplacian smooth iterations that have to be performed after every run

.. data:: point_cloud_simplification

   *MeshLab filter name*: 'Point Cloud Simplification'

   .. raw:: html

      Create a new layer populated with a simplified version of the current point cloud.</p>

   **Parameters:**

   ``samplenum : int = 1000``

      .. raw:: html

         <i>Number of samples</i>: The desired number of samples. The ray of the disk is calculated according to the sampling density.

   ``radius : Percentage = 0%``

      .. raw:: html

         <i>Explicit Radius</i>: If not zero this parameter override the previous parameter to allow exact radius specification

   ``bestsampleflag : bool = true``

      .. raw:: html

         <i>Best Sample Heuristic</i>: If true it will use a simple heuristic for choosing the samples. At a small cost (it can slow a bit the process) it usually improve the maximality of the generated sampling.

   ``bestsamplepool : int = 10``

      .. raw:: html

         <i>Best Sample Pool Size</i>: Used only if the Best Sample Flag is true. It control the number of attempt that it makes to get the best sample. It is reasonable that it is smaller than the Montecarlo oversampling factor.

   ``exactnumflag : bool = false``

      .. raw:: html

         <i>Exact number of samples</i>: If requested it will try to do a dicotomic search for the best poisson disk radius that will generate the requested number of samples with a tolerance of the 0.5%. Obviously it takes much longer.

.. data:: points_cloud_movement

   *MeshLab filter name*: 'Points Cloud Movement'

   .. raw:: html

      Simulate the movement of a points cloud over a mesh</p>

   **Parameters:**

   ``gravity_dir : numpy.ndarray[numpy.float32[3]] = [0, -1, 0]``

      .. raw:: html

         <i>g</i>: Direction of gravity

   ``force_dir : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>force</i>: Direction of the force acting on the points cloud

   ``steps : int = 1``

      .. raw:: html

         <i>s</i>: Simulation Steps

   ``adhesion : float (bounded) = 1 [min: 0; max: 1]``

      .. raw:: html

         <i>adhesion</i>: Factor to model the general adhesion.

   ``velocity : float = 0``

      .. raw:: html

         <i>v</i>: Initial velocity of the particle

   ``mass : float = 1``

      .. raw:: html

         <i>m</i>: Mass of the particle

   ``colorize_mesh : bool = false``

      .. raw:: html

         <i>Map to Color</i>: Color the mesh with colors based on the movement of the particle

.. data:: points_on_a_sphere

   *MeshLab filter name*: 'Points on a Sphere'

   .. raw:: html

      Create a spherical point cloud, it can be random or regularly distributed.</p>

   **Parameters:**

   ``pointnum : int = 100``

      .. raw:: html

         <i>Point Num</i>: Number of points (approximate).

   ``spheregentech : str = 'Octahedron' (or int = 3)``

      Possible enum values:

         0. ``'Montecarlo'``
         1. ``'Poisson Sampling'``
         2. ``'DiscoBall'``
         3. ``'Octahedron'``
         4. ``'Fibonacci'``

      .. raw:: html

         <i>Generation Technique:</i>: Generation Technique:<b>Montecarlo</b>: The points are randomly generated with an uniform distribution.<br><b>Poisson Disk</b>: The points are to follow a poisson disk distribution.<br><b>Disco Ball</b> Dave Rusin's disco ball algorithm for the regular placement of points on a sphere is used. <br><b>Recursive Octahedron</b> Points are generated on the vertex of a recursively subdivided octahedron <br><b>Fibonacci</b> .

.. data:: poisson_disk_sampling

   *MeshLab filter name*: 'Poisson-disk Sampling'

   .. raw:: html

      Create a new layer populated with a point sampling of the current mesh;samples are generated according to a Poisson-disk distribution, using the algorithm described in:<br><b>'Efficient and Flexible Sampling with Blue Noise Properties of Triangular Meshes'</b><br> Massimiliano Corsini, Paolo Cignoni, Roberto Scopigno<br>IEEE TVCG 2012</p>

   **Parameters:**

   ``samplenum : int = 1000``

      .. raw:: html

         <i>Number of samples</i>: The desired number of samples. The ray of the disk is calculated according to the sampling density.

   ``radius : Percentage = 0%``

      .. raw:: html

         <i>Explicit Radius</i>: If not zero this parameter override the previous parameter to allow exact radius specification

   ``montecarlorate : int = 20``

      .. raw:: html

         <i>MonterCarlo OverSampling</i>: The over-sampling rate that is used to generate the initial Montecarlo samples (e.g. if this parameter is <i>K</i> means that<i>K</i> x <i>poisson sample</i> points will be used). The generated Poisson-disk samples are a subset of these initial Montecarlo samples. Larger this number slows the process but make it a bit more accurate.

   ``savemontecarlo : bool = false``

      .. raw:: html

         <i>Save Montecarlo</i>: If true, it will generate an additional Layer with the montecarlo sampling that was pruned to build the poisson distribution.

   ``approximategeodesicdistance : bool = false``

      .. raw:: html

         <i>Approximate Geodesic Distance</i>: If true Poisson Disc distances are computed using an approximate geodesic distance, e.g. an euclidean distance weighted by a function of the difference between the normals of the two points.

   ``subsample : bool = false``

      .. raw:: html

         <i>Base Mesh Subsampling</i>: If true the original vertices of the base mesh are used as base set of points. In this case the SampleNum should be obviously much smaller than the original vertex number.<br>Note that this option is very useful in the case you want to subsample a dense point cloud.

   ``refineflag : bool = false``

      .. raw:: html

         <i>Refine Existing Samples</i>: If true the vertices of the below mesh are used as starting vertices, and they will utterly refined by adding more and more points until possible.

   ``refinemesh : int = 0``

      .. raw:: html

         <i>Samples to be refined</i>: Used only if the above option is checked.

   ``bestsampleflag : bool = true``

      .. raw:: html

         <i>Best Sample Heuristic</i>: If true it will use a simple heuristic for choosing the samples. At a small cost (it can slow a bit the process) it usually improve the maximality of the generated sampling.

   ``bestsamplepool : int = 10``

      .. raw:: html

         <i>Best Sample Pool Size</i>: Used only if the Best Sample Flag is true. It control the number of attempt that it makes to get the best sample. It is reasonable that it is smaller than the Montecarlo oversampling factor.

   ``exactnumflag : bool = false``

      .. raw:: html

         <i>Exact number of samples</i>: If requested it will try to do a dicotomic search for the best poisson disk radius that will generate the requested number of samples with a tolerance of the 0.5%. Obviously it takes much longer.

   ``radiusvariance : float = 1``

      .. raw:: html

         <i>Radius Variance</i>: The radius of the disk is allowed to vary between r and r*var. If this parameter is 1 the sampling is the same of the Poisson Disk Sampling

.. data:: project_active_rasters_color_to_current_mesh

   *MeshLab filter name*: 'Project active rasters color to current mesh'

   .. raw:: html

      Color information from all the active rasters is perspective-projected on the current mesh using basic weighting</p>

   **Parameters:**

   ``deptheta : float = 0.5``

      .. raw:: html

         <i>depth threshold</i>: threshold value for depth buffer projection (shadow buffer)

   ``onselection : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If true, projection is only done for selected vertices

   ``useangle : bool = true``

      .. raw:: html

         <i>use angle weight</i>: If true, color contribution is weighted by pixel view angle

   ``usedistance : bool = true``

      .. raw:: html

         <i>use distance weight</i>: If true, color contribution is weighted by pixel view distance

   ``useborders : bool = true``

      .. raw:: html

         <i>use image borders weight</i>: If true, color contribution is weighted by pixel distance from image boundaries

   ``usesilhouettes : bool = true``

      .. raw:: html

         <i>use depth discontinuities weight</i>: If true, color contribution is weighted by pixel distance from depth discontinuities (external and internal silhouettes)

   ``usealpha : bool = false``

      .. raw:: html

         <i>use image alpha weight</i>: If true, alpha channel of the image is used as additional weight. In this way it is possible to mask-out parts of the images that should not be projected on the mesh. Please note this is not a transparency effect, but just influences the weigthing between different images

   ``blankcolor : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>Color for unprojected areas</i>: Areas that cannot be projected willb e filled using this color. If R=0 G=0 B=0 A=0 old color is preserved

.. data:: project_active_rasters_color_to_current_mesh_filling_the_texture

   *MeshLab filter name*: 'Project active rasters color to current mesh, filling the texture'

   .. raw:: html

      Color information from all the active rasters is perspective-projected on the current mesh, filling the texture, using basic weighting</p>

   **Parameters:**

   ``textname : str = 'cube_color.png'``

      .. raw:: html

         <i>Texture file</i>: The texture file to be created

   ``texsize : int = 1024``

      .. raw:: html

         <i>pixel size of texture image</i>: pixel size of texture image, the image will be a square tsize X tsize, most applications do require that tsize is a power of 2

   ``dorefill : bool = true``

      .. raw:: html

         <i>fill atlas gaps</i>: If true, unfilled areas of the mesh are interpolated, to avoid visible seams while mipmapping

   ``deptheta : float = 0.5``

      .. raw:: html

         <i>depth threshold</i>: threshold value for depth buffer projection (shadow buffer)

   ``onselection : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If true, projection is only done for selected vertices

   ``useangle : bool = true``

      .. raw:: html

         <i>use angle weight</i>: If true, color contribution is weighted by pixel view angle

   ``usedistance : bool = true``

      .. raw:: html

         <i>use distance weight</i>: If true, color contribution is weighted by pixel view distance

   ``useborders : bool = true``

      .. raw:: html

         <i>use image borders weight</i>: If true, color contribution is weighted by pixel distance from image boundaries

   ``usesilhouettes : bool = true``

      .. raw:: html

         <i>use depth discontinuities weight</i>: If true, color contribution is weighted by pixel distance from depth discontinuities (external and internal silhouettes)

   ``usealpha : bool = false``

      .. raw:: html

         <i>use image alpha weight</i>: If true, alpha channel of the image is used as additional weight. In this way it is possible to mask-out parts of the images that should not be projected on the mesh. Please note this is not a transparency effect, but just influences the weigthing between different images

.. data:: project_current_raster_color_to_current_mesh

   *MeshLab filter name*: 'Project current raster color to current mesh'

   .. raw:: html

      Color information from the current raster is perspective-projected on the current mesh</p>

   **Parameters:**

   ``usedepth : bool = true``

      .. raw:: html

         <i>Use depth for projection</i>: If true, depth is used to restrict projection on visible faces

   ``deptheta : float = 0.5``

      .. raw:: html

         <i>depth threshold</i>: threshold value for depth buffer projection (shadow buffer)

   ``onselection : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If true, projection is only done for selected vertices

   ``blankcolor : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>Color for unprojected areas</i>: Areas that cannot be projected willb e filled using this color. If R=0 G=0 B=0 A=0 old color is preserved

.. data:: quality_from_raster_coverage_face

   *MeshLab filter name*: 'Quality from raster coverage (Face)'

   .. raw:: html

      Compute a quality value representing the number of images into which each face of the active mesh is visible.</p>

   **Parameters:**

   ``normalizequality : bool = false``

      .. raw:: html

         <i>Normalize</i>: Rescale quality values to the range [0,1]

.. data:: quality_from_raster_coverage_vertex

   *MeshLab filter name*: 'Quality from raster coverage (Vertex)'

   .. raw:: html

      Compute a quality value representing the number of images into which each vertex of the active mesh is visible.</p>

   **Parameters:**

   ``normalizequality : bool = false``

      .. raw:: html

         <i>Normalize</i>: Rescale quality values to the range [0,1]

.. data:: quality_mapper_applier

   *MeshLab filter name*: 'Quality Mapper applier'

   .. raw:: html

      The filter maps quality levels into colors using a colorband built from a transfer function (may be loaded from an external file) and colorizes the mesh vertices. The minimum, medium and maximum quality values can be set by user to obtain a custom quality range for mapping</p>

   **Parameters:**

   ``minqualityval : float = 3.40282e+38``

      .. raw:: html

         <i>Minimum mesh quality</i>: The specified quality value is mapped in the <b>lower</b> end of the chosen color scale. Default value: the minimum quality value found on the mesh.

   ``maxqualityval : float = -3.40282e+38``

      .. raw:: html

         <i>Maximum mesh quality</i>: The specified quality value is mapped in the <b>upper</b> end of the chosen color scale. Default value: the maximum quality value found on the mesh.

   ``midhandlepos : float = 50``

      .. raw:: html

         <i>Gamma biasing (0..100)</i>: Defines a gamma compression of the quality values, by setting the position of the middle of the color scale. Value is defined as a percentage (0..100). Default value is 50, that corresponds to a linear mapping.

   ``brightness : float = 1``

      .. raw:: html

         <i>Mesh brightness</i>: must be between 0 and 2. 0 represents a completely dark mesh, 1 represents a mesh colorized with original colors, 2 represents a completely bright mesh

   ``tfslist : str = 'Meshlab RGB' (or int = 1)``

      Possible enum values:

         0. ``'Custom Transfer Function File'``
         1. ``'Meshlab RGB'``
         2. ``'RGB'``
         3. ``'French RGB'``
         4. ``'Red Scale'``
         5. ``'Green Scale'``
         6. ``'Blue Scale'``
         7. ``'Flat'``
         8. ``'Saw 4'``
         9. ``'Saw 8'``
         10. ``'Grey Scale'``

      .. raw:: html

         <i>Transfer Function type to apply to filter</i>: Choose the Transfer Function to apply to the filter

   ``csvfilename : str = ''``

      .. raw:: html

         <i>Custom TF Filename</i>: Filename of the transfer function to be loaded, used only if you have chosen the Custom Transfer Function. Write the full path of the qmap file, or save the file in the same folder of the current mesh, and write only the name of the qmap file. Only the RGB mapping will be imported from the qmap file

.. data:: random_component_color

   *MeshLab filter name*: 'Random Component Color'

   .. raw:: html

      Colorize each connected component randomly.</p>

.. data:: random_face_color

   *MeshLab filter name*: 'Random Face Color'

   .. raw:: html

      Colorize Faces randomly. If internal edges are present they are used. Useful for quads.</p>

.. data:: random_vertex_displacement

   *MeshLab filter name*: 'Random Vertex Displacement'

   .. raw:: html

      Move the vertices of the mesh of a random quantity.</p>

   **Parameters:**

   ``updatenormals : bool = true``

      .. raw:: html

         <i>Recompute normals</i>: Toggle the recomputation of the normals after the random displacement.<br><br>If disabled the face normals will remains unchanged resulting in a visually pleasant effect.

   ``displacement : Percentage = 1%``

      .. raw:: html

         <i>Max displacement</i>: The vertex are displaced of a vector whose norm is bounded by this value

.. data:: re_compute_face_normals

   *MeshLab filter name*: 'Re-Compute Face Normals'

   .. raw:: html

      Recompute face normals as the normal of the plane of the face.<br>See <a href='https://math.stackexchange.com/questions/305642/'>How to find surface normal of a triangle</a></p>

.. data:: re_compute_per_polygon_face_normals

   *MeshLab filter name*: 'Re-Compute Per-Polygon Face Normals'

   .. raw:: html

      Recompute face normals as the average of the normals of the triangles that builds a polygon. Useful for showing uniformly shaded quad or polygonal meshes represented using <a href='https://stackoverflow.com/questions/59392193'>faux edges</a>.</p>

.. data:: re_compute_vertex_normals

   *MeshLab filter name*: 'Re-Compute Vertex Normals'

   .. raw:: html

      Recompute vertex normals according to four different schemes:<br>1) Simple (no weights) average of normals of the incident faces <br>2) Area weighted average of normals of the incident faces <br>3) Angle weighted sum of normals of the incident faces according to the article <b>[1]</b>. Probably this is the best all-purpose choice. It could slightly bias the result for degenerate, fat triangles.<br>4) Weighted sum of normals of the incident faces, as defined by article <b>[2]</b>. The weight for each wedge is the cross product of the two edges over the product of the square of the two edge lengths.According to the original article it is perfect only for spherical surface, but it should perform well also in practice.<br>[1]: <b>Computing Vertex Normals from Polygonal Facet</b> by <i>G Thurmer and CA Wuthrich</i>, JGT volume3, num 1. 1998<br><a href='https://doi.org/10.1080/10867651.1998.10487487'>doi:10.1080/10867651.1998.10487487</a><br>[2]: <b>Weights for Computing Vertex Normals from Facet Normals</b> by <i>Nelson Max</i>, JGT vol4, num 2. 1999<br><a href='https://doi.org/10.1080/10867651.1999.10487501'>doi:10.1080/10867651.1999.10487501</a></p>

   **Parameters:**

   ``weightmode : str = 'Simple Average' (or int = 0)``

      Possible enum values:

         0. ``'Simple Average'``
         1. ``'By Angle'``
         2. ``'By Area'``
         3. ``'As defined by N. Max'``

      .. raw:: html

         <i>Weighting Mode:</i>:

.. data:: re_orient_all_faces_coherentely

   *MeshLab filter name*: 'Re-Orient all faces coherentely'

   .. raw:: html

      Re-orient in a consistent way all the faces of the mesh. <br>The filter visits a mesh face to face, reorienting any unvisited face so that it is coherent to the already visited faces. If the surface is orientable it will end with a consistent orientation of all the faces. If the surface is not orientable (e.g. it is non manifold or non orientable like a moebius strip) the filter will not build a consistent orientation simply because it is not possible. The filter can end up in a consistent orientation that can be exactly the opposite of the expected one; in that case simply invert the whole mesh orientation.</p>

.. data:: re_orient_vertex_normals_using_cameras

   *MeshLab filter name*: 'Re-Orient vertex normals using cameras'

   .. raw:: html

      Reorient vertex normals using cameras. For this  filter to work the mesh needs to have the attribute 'correspondences' which is only created when loading Bundler files (.out projects)</p>

.. data:: refine_user_defined

   *MeshLab filter name*: 'Refine User-Defined'

   .. raw:: html

      Refine current mesh with user defined parameters.<br>Specify a Boolean Function needed to select which edges will be cut for refinement purpose.<br>Each edge is identified with first and second vertex.<br>Arguments accepted are first and second vertex attributes:<br><br>It's possible to use parenthesis <b>()</b>, and predefined operators:<br><b>&&</b> (logic and), <b>||</b> (logic or), <b>&lt;</b>, <b>&lt;=</b>, <b>></b>, <b>>=</b>, <b>!=</b> (not equal), <b>==</b> (equal), <b>_?_:_</b> (c/c++ ternary operator)<br><br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

   **Parameters:**

   ``condselect : str = '(q0 >= 0 && q1 >= 0)'``

      .. raw:: html

         <i>boolean function</i>: type a boolean function that will be evaluated on every edge

   ``x : str = '(x0+x1)/2'``

      .. raw:: html

         <i>x =</i>: function to generate x coord of new vertex in [x0,x1].<br>For example (x0+x1)/2

   ``y : str = '(y0+y1)/2'``

      .. raw:: html

         <i>y =</i>: function to generate x coord of new vertex in [y0,y1].<br>For example (y0+y1)/2

   ``z : str = '(z0+z1)/2'``

      .. raw:: html

         <i>z =</i>: function to generate x coord of new vertex in [z0,z1].<br>For example (z0+z1)/2

.. data:: regular_recursive_sampling

   *MeshLab filter name*: 'Regular Recursive Sampling'

   .. raw:: html

      The bbox is recursively partitioned in a octree style, center of bbox are considered, when the center is nearer to the surface than a given thr it is projected on it. It works also for building offsetted samples.</p>

   **Parameters:**

   ``cellsize : Percentage = 2%``

      .. raw:: html

         <i>Precision</i>: Size of the cell, the default is 1/50 of the box diag. Smaller cells give better precision at a higher computational cost. Remember that halving the cell size means that you build a volume 8 times larger.

   ``offset : Percentage = 50%``

      .. raw:: html

         <i>Offset</i>: Offset of the created surface (i.e. distance of the created surface from the original one).<br>If offset is zero, the created surface passes on the original mesh itself. Values greater than zero mean an external surface, and lower than zero mean an internal surface.<br> In practice this value is the threshold passed to the Marching Cube algorithm to extract the isosurface from the distance field representation.

.. data:: remeshing_isotropic_explicit_remeshing

   *MeshLab filter name*: 'Remeshing: Isotropic Explicit Remeshing'

   .. raw:: html

      Perform a explicit remeshing of a triangular mesh, by repeatedly applying edge flip, collapse, relax and refine to improve aspect ratio (triangle quality) and topological regularity.</p>

   **Parameters:**

   ``iterations : int = 3``

      .. raw:: html

         <i>Iterations</i>: Number of iterations of the remeshing operations to repeat on the mesh.

   ``adaptive : bool = false``

      .. raw:: html

         <i>Adaptive remeshing</i>: Toggles adaptive isotropic remeshing.

   ``selectedonly : bool = false``

      .. raw:: html

         <i>Remesh only selected faces</i>: If checked the remeshing operations will be applied only to the selected faces.

   ``targetlen : Percentage = 1%``

      .. raw:: html

         <i>Target Length</i>: Sets the target length for the remeshed mesh edges.

   ``featuredeg : float = 30``

      .. raw:: html

         <i>Crease Angle</i>: Minimum angle between faces of the original to consider the shared edge as a feature to be preserved.

   ``checksurfdist : bool = true``

      .. raw:: html

         <i>Check Surface Distance</i>: If toggled each local operation must deviate from original mesh by [Max. surface distance]

   ``maxsurfdist : Percentage = 1%``

      .. raw:: html

         <i>Max. Surface Distance</i>: Maximal surface deviation allowed for each local operation

   ``splitflag : bool = true``

      .. raw:: html

         <i>Refine Step</i>: If checked the remeshing operations will include a refine step.

   ``collapseflag : bool = true``

      .. raw:: html

         <i>Collapse Step</i>: If checked the remeshing operations will include a collapse step.

   ``swapflag : bool = true``

      .. raw:: html

         <i>Edge-Swap Step</i>: If checked the remeshing operations will include a edge-swap step, aimed at improving the vertex valence of the resulting mesh.

   ``smoothflag : bool = true``

      .. raw:: html

         <i>Smooth Step</i>: If checked the remeshing operations will include a smoothing step, aimed at relaxing the vertex positions in a Laplacian sense.

   ``reprojectflag : bool = true``

      .. raw:: html

         <i>Reproject Step</i>: If checked the remeshing operations will include a step to reproject the mesh vertices on the original surface.

.. data:: remove_duplicate_faces

   *MeshLab filter name*: 'Remove Duplicate Faces'

   .. raw:: html

      Delete all the duplicate faces. Two faces are considered equal if they are composed by the same set of vertices, regardless of the order of the vertices.</p>

.. data:: remove_duplicate_vertices

   *MeshLab filter name*: 'Remove Duplicate Vertices'

   .. raw:: html

      Check for every vertex on the mesh: if there are two vertices with same coordinates they are merged into a single one.</p>

.. data:: remove_isolated_folded_faces_by_edge_flip

   *MeshLab filter name*: 'Remove Isolated Folded Faces by Edge Flip'

   .. raw:: html

      Delete all the single folded faces. A face is considered folded if its normal is opposite to all the adjacent faces. It is removed by flipping it against the face f adjacent along the edge e such that the vertex opposite to e fall inside f</p>

.. data:: remove_isolated_pieces_wrt_diameter

   *MeshLab filter name*: 'Remove Isolated pieces (wrt Diameter)'

   .. raw:: html

      Delete isolated connected components whose diameter is smaller than the specified constant</p>

   **Parameters:**

   ``mincomponentdiag : Percentage = 10%``

      .. raw:: html

         <i>Enter max diameter of isolated pieces</i>: Delete all the connected components (floating pieces) with a diameter smaller than the specified one

   ``removeunref : bool = true``

      .. raw:: html

         <i>Remove unfreferenced vertices</i>: if true, the unreferenced vertices remaining after the face deletion are removed.

.. data:: remove_isolated_pieces_wrt_face_num

   *MeshLab filter name*: 'Remove Isolated pieces (wrt Face Num.)'

   .. raw:: html

      Delete isolated connected components composed by a limited number of triangles</p>

   **Parameters:**

   ``mincomponentsize : int = 25``

      .. raw:: html

         <i>Enter minimum conn. comp size:</i>: Delete all the connected components (floating pieces) composed by a number of triangles smaller than the specified one

   ``removeunref : bool = true``

      .. raw:: html

         <i>Remove unfreferenced vertices</i>: if true, the unreferenced vertices remaining after the face deletion are removed.

.. data:: remove_t_vertices_by_edge_collapse

   *MeshLab filter name*: 'Remove T-Vertices by Edge Collapse'

   .. raw:: html

      Delete t-vertices from the mesh by collapsing the shortest of the incident edges</p>

   **Parameters:**

   ``threshold : float = 40``

      .. raw:: html

         <i>Ratio</i>: Detects faces where the base/height ratio is lower than this value

   ``repeat : bool = true``

      .. raw:: html

         <i>Iterate until convergence</i>: Iterates the algorithm until it reaches convergence

.. data:: remove_t_vertices_by_edge_flip

   *MeshLab filter name*: 'Remove T-Vertices by Edge Flip'

   .. raw:: html

      Delete t-vertices by flipping the opposite edge on the degenerate face if the triangulation quality improves</p>

   **Parameters:**

   ``threshold : float = 40``

      .. raw:: html

         <i>Ratio</i>: Detects faces where the base/height ratio is lower than this value

   ``repeat : bool = true``

      .. raw:: html

         <i>Iterate until convergence</i>: Iterates the algorithm until it reaches convergence

.. data:: remove_unreferenced_vertices

   *MeshLab filter name*: 'Remove Unreferenced Vertices'

   .. raw:: html

      Check for every vertex on the mesh: if it is NOT referenced by a face, removes it</p>

.. data:: remove_vertices_wrt_quality

   *MeshLab filter name*: 'Remove Vertices wrt Quality'

   .. raw:: html

      Delete all the vertices with a quality lower smaller than the specified constant</p>

   **Parameters:**

   ``maxqualitythr : Percentage = -nan%``

      .. raw:: html

         <i>Delete all vertices with quality under:</i>:

.. data:: remove_zero_area_faces

   *MeshLab filter name*: 'Remove Zero Area Faces'

   .. raw:: html

      Remove null faces (the one with area equal to zero)</p>

.. data:: rename_current_mesh

   *MeshLab filter name*: 'Rename Current Mesh'

   .. raw:: html

      Explicitly change the label shown for a given mesh</p>

   **Parameters:**

   ``newname : str = 'cube'``

      .. raw:: html

         <i>New Label</i>: New Label for the mesh

.. data:: rename_current_raster

   *MeshLab filter name*: 'Rename Current Raster'

   .. raw:: html

      Explicitly change the label shown for a given raster</p>

   **Parameters:**

   ``newname : str = ''``

      .. raw:: html

         <i>New Label</i>: New Label for the raster

.. data:: repair_non_manifold_edges_by_removing_faces

   *MeshLab filter name*: 'Repair non Manifold Edges by removing faces'

   .. raw:: html

      For each non Manifold edge it iteratively deletes the smallest area face until it becomes 2-Manifold.</p>

.. data:: repair_non_manifold_edges_by_splitting_vertices

   *MeshLab filter name*: 'Repair non Manifold Edges by splitting vertices'

   .. raw:: html

      Remove all non manifold edges splitting vertices. Each non manifold edges chain will become a border</p>

.. data:: repair_non_manifold_vertices_by_splitting

   *MeshLab filter name*: 'Repair non Manifold Vertices by splitting'

   .. raw:: html

      Split non Manifold vertices until it becomes 2-Manifold.</p>

   **Parameters:**

   ``vertdispratio : float = 0``

      .. raw:: html

         <i>Vertex Displacement Ratio</i>: When a vertex is split it is moved along the average vector going from its position to the baricyenter of the FF connected faces sharing it

.. data:: saturate_vertex_quality

   *MeshLab filter name*: 'Saturate Vertex Quality'

   .. raw:: html

      Saturate vertex quality, so that for each vertex the gradient of the quality is lower than the given threshold value (in absolute value)<br>The saturation is done in a conservative way (quality is always decreased and never increased)</p>

   **Parameters:**

   ``gradientthr : float = 1``

      .. raw:: html

         <i>Gradient Threshold</i>: The maximum value admitted for the quality gradient (in absolute value)

   ``updatecolor : bool = false``

      .. raw:: html

         <i>Update ColorMap</i>: if true the color ramp is computed again

.. data:: scaledependent_laplacian_smooth

   *MeshLab filter name*: 'ScaleDependent Laplacian Smooth'

   .. raw:: html

      Scale Dependent Laplacian Smoothing, extended version of Laplacian Smoothing based on the Fujiwara extended umbrella operator.<br><b>Implicit Fairing of Irregular Meshes using Diffusion and Curvature Flow</b> by <i>Desbrun, Meyer, Schroeder and Barr</i>. SIGGRAPH 1999<br><a href='https://doi.org/10.1145/311535.311576'>doi:10.1145/311535.311576</a></p>

   **Parameters:**

   ``stepsmoothnum : int = 3``

      .. raw:: html

         <i>Smoothing steps</i>: The number of times that the whole algorithm (normal smoothing + vertex fitting) is iterated.

   ``delta : Percentage = 1%``

      .. raw:: html

         <i>delta</i>:

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selected faces</i>: If checked the filter is performed only on the selected faces

.. data:: select_all

   *MeshLab filter name*: 'Select All'

   .. raw:: html

      Select all the faces/vertices of the current mesh.</p>

   **Parameters:**

   ``allfaces : bool = true``

      .. raw:: html

         <i>Select all Faces</i>: If true the filter will select all the faces.

   ``allverts : bool = true``

      .. raw:: html

         <i>Select all Vertices</i>: If true the filter will select all the vertices.

.. data:: select_border

   *MeshLab filter name*: 'Select Border'

   .. raw:: html

      Select vertices and faces on the boundary.</p>

.. data:: select_by_face_quality

   *MeshLab filter name*: 'Select by Face Quality'

   .. raw:: html

      Select all the faces/vertices with within the specified face quality range.</p>

   **Parameters:**

   ``minq : float (bounded) = 1.70141e+38 [min: 3.40282e+38; max: -3.40282e+38]``

      .. raw:: html

         <i>Min Quality</i>: Minimum acceptable quality value

   ``maxq : float (bounded) = -1.70141e+38 [min: 3.40282e+38; max: -3.40282e+38]``

      .. raw:: html

         <i>Max Quality</i>: Maximum acceptable quality value

   ``inclusive : bool = true``

      .. raw:: html

         <i>Inclusive Sel.</i>: If true only the vertices with <b>all</b> the adjacent faces within the specified range are selected. Otherwise any vertex with at least one face within the range is selected.

.. data:: select_by_vertex_quality

   *MeshLab filter name*: 'Select by Vertex Quality'

   .. raw:: html

      Select all the faces/vertices within the specified vertex quality range.</p>

   **Parameters:**

   ``minq : float (bounded) = 1.70141e+38 [min: 3.40282e+38; max: -3.40282e+38]``

      .. raw:: html

         <i>Min Quality</i>: Minimum acceptable quality value

   ``maxq : float (bounded) = -1.70141e+38 [min: 3.40282e+38; max: -3.40282e+38]``

      .. raw:: html

         <i>Max Quality</i>: Maximum acceptable quality value

   ``inclusive : bool = true``

      .. raw:: html

         <i>Inclusive Sel.</i>: If true only the faces with <b>all</b> the vertices within the specified range are selected. Otherwise any face with at least one vertex within the range is selected.

.. data:: select_connected_faces

   *MeshLab filter name*: 'Select Connected Faces'

   .. raw:: html

      Expand the current face selection so that it includes all the faces in the connected components where there is at least a selected face.</p>

.. data:: select_crease_edges

   *MeshLab filter name*: 'Select Crease Edges'

   .. raw:: html

      It select the crease edges of a mesh according to edge dihedral angle.<br>Angle between face normal is considered signed according to convexity/concavity.Convex angles are positive and concave are negative.</p>

   **Parameters:**

   ``angledegneg : float = -45``

      .. raw:: html

         <i>Concave Angle Thr. (deg)</i>: Concave Dihedral Angle threshold for considering an edge a crease. If the normals between two faces forms an concave diheadral angle smaller than the threshold the edge is considered a crease.

   ``angledegpos : float = 45``

      .. raw:: html

         <i>Convex Angle Thr. (deg)</i>: The angle threshold for considering an edge a crease. If the normals between two faces forms an angle larger than the threshold the edge is considered a crease.

.. data:: select_faces_by_color

   *MeshLab filter name*: 'Select Faces by Color'

   .. raw:: html

      Select part of the mesh based on its color.</p>

   **Parameters:**

   ``color : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>Color To Select</i>: Color that you want to be selected.

   ``colorspace : str = 'HSV' (or int = 0)``

      Possible enum values:

         0. ``'HSV'``
         1. ``'RGB'``

      .. raw:: html

         <i>Pick Color Space</i>: The color space that the sliders will manipulate.

   ``inclusive : bool = true``

      .. raw:: html

         <i>Inclusive Sel.</i>: If true only the faces with <b>all</b> the vertices within the specified range are selected. Otherwise any face with at least one vertex within the range is selected.

   ``percentrh : float (bounded) = 0.2 [min: 0; max: 1]``

      .. raw:: html

         <i>Variation from Red or Hue</i>: A float between 0 and 1 that represents the percent variation from this color that will be selected.  For example if the R was 200 and you put 0.1 then any color with R 200+-25.5 will be selected.

   ``percentgs : float (bounded) = 0.2 [min: 0; max: 1]``

      .. raw:: html

         <i>Variation from Green or Saturation</i>: A float between 0 and 1 that represents the percent variation from this color that will be selected.  For example if the R was 200 and you put 0.1 then any color with R 200+-25.5 will be selected.

   ``percentbv : float (bounded) = 0.2 [min: 0; max: 1]``

      .. raw:: html

         <i>Variation from Blue or Value</i>: A float between 0 and 1 that represents the percent variation from this color that will be selected.  For example if the R was 200 and you put 0.1 then any color with R 200+-25.5 will be selected.

.. data:: select_faces_by_view_angle

   *MeshLab filter name*: 'Select Faces by view angle'

   .. raw:: html

      Select faces according to the angle between their normal and the view direction. It is used in range map processing to select and delete steep faces parallel to viewdirection.</p>

   **Parameters:**

   ``anglelimit : float (bounded) = 75 [min: 0; max: 180]``

      .. raw:: html

         <i>angle threshold (deg)</i>: faces with normal at higher angle w.r.t. the view direction are selected

   ``usecamera : bool = false``

      .. raw:: html

         <i>Use ViewPoint from Mesh Camera</i>: Uses the ViewPoint from the camera associated to the current mesh<br> if there is no camera, an error occurs

   ``viewpoint : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>ViewPoint</i>: if UseCamera is true, this value is ignored

.. data:: select_faces_from_vertices

   *MeshLab filter name*: 'Select Faces from Vertices'

   .. raw:: html

      Select faces from selected vertices.</p>

   **Parameters:**

   ``inclusive : bool = true``

      .. raw:: html

         <i>Strict Selection</i>: If true only the faces with <b>all</b> selected vertices are selected. Otherwise any face with at least one selected vertex will be selected.

.. data:: select_faces_with_edges_longer_than

   *MeshLab filter name*: 'Select Faces with edges longer than...'

   .. raw:: html

      Select all triangles having an edge with length greater or equal than a given threshold.</p>

   **Parameters:**

   ``threshold : float (bounded) = 0.0173205 [min: 0; max: 1.73205]``

      .. raw:: html

         <i>Edge Threshold</i>: All the faces with an edge <b>longer</b> than this threshold will be deleted. Useful for removing long skinny faces obtained by bad triangulation of range maps.

.. data:: select_folded_faces

   *MeshLab filter name*: 'Select Folded Faces'

   .. raw:: html

      Select the folded faces created by the Quadric Edge Collapse decimation. The face is selected if the angle between the face normal and the normal of the best fitting plane of the neighbor vertices is above the selected threshold.</p>

   **Parameters:**

   ``anglethreshold : float (bounded) = 160 [min: 90; max: 180]``

      .. raw:: html

         <i>Angle Threshold</i>: Angle between the face and the best fitting plane of the neighbours vertices. If it is above the threshold the face is selected.

.. data:: select_non_manifold_edges_

   *MeshLab filter name*: 'Select non Manifold Edges '

   .. raw:: html

      Select the faces and the vertices incident on non manifold edges (e.g. edges where more than two faces are incident); note that this function select the components that are related to non manifold edges. The case of non manifold vertices is specifically managed by the pertinent filter.</p>

.. data:: select_non_manifold_vertices

   *MeshLab filter name*: 'Select non Manifold Vertices'

   .. raw:: html

      Select the non manifold vertices that do not belong to non manifold edges. For example two cones connected by their apex. Vertices incident on non manifold edges are ignored.</p>

.. data:: select_none

   *MeshLab filter name*: 'Select None'

   .. raw:: html

      Clear the current set of selected faces/vertices.</p>

   **Parameters:**

   ``allfaces : bool = true``

      .. raw:: html

         <i>De-select all Faces</i>: If true the filter will de-select all the faces.

   ``allverts : bool = true``

      .. raw:: html

         <i>De-select all Vertices</i>: If true the filter will de-select all the vertices.

.. data:: select_outliers

   *MeshLab filter name*: 'Select Outliers'

   .. raw:: html

      Select the vertex classified as outlier using Local Outlier Propabilty measure described in:<br> <b>'LoOP: Local Outlier Probabilities'</b> Kriegel et al.<br>CIKM 2009</p>

   **Parameters:**

   ``propthreshold : float (bounded) = 0.8 [min: 0; max: 1]``

      .. raw:: html

         <i>Probability</i>: Threshold to select the vertex. The vertex is selected if the LoOP value is above the threshold.

   ``knearest : int = 32``

      .. raw:: html

         <i>Number of neighbors</i>: Number of neighbours used to compute the LoOP

.. data:: select_problematic_faces

   *MeshLab filter name*: 'Select 'problematic' faces'

   .. raw:: html

      Select faces with 'problems', like normal inverted w.r.t the surrounding areas, or extremely elongated</p>

   **Parameters:**

   ``usear : bool = true``

      .. raw:: html

         <i>select by Aspect Ratio</i>: if true, faces with aspect ratio below the limit will be selected

   ``aratio : float (bounded) = 0.02 [min: 0; max: 1]``

      .. raw:: html

         <i>Aspect Ratio</i>: Triangle face aspect ratio [1 (equilateral) - 0 (line)]: face will be selected if BELOW this threshold

   ``usenf : bool = false``

      .. raw:: html

         <i>select by Normal Angle</i>: if true, adjacent faces with normals forming an angle above the limit will be selected

   ``nfratio : float (bounded) = 60 [min: 0; max: 180]``

      .. raw:: html

         <i>Angle flip</i>: angle between the adjacent faces: face will be selected if ABOVE this threshold

.. data:: select_self_intersecting_faces

   *MeshLab filter name*: 'Select Self Intersecting Faces'

   .. raw:: html

      Select only self intersecting faces.</p>

.. data:: select_small_disconnected_component

   *MeshLab filter name*: 'Select small disconnected component'

   .. raw:: html

      Select the small disconnected components of a mesh.</p>

   **Parameters:**

   ``nbfaceratio : float = 0.1``

      .. raw:: html

         <i>Small component ratio</i>: This ratio (between 0 and 1) defines the meaning of <i>small</i> as the threshold ratio between the number of facesof the largest component and the other ones. A larger value will select more components.

   ``nonclosedonly : bool = false``

      .. raw:: html

         <i>Select only non closed components</i>:

.. data:: select_vertex_texture_seams

   *MeshLab filter name*: 'Select Vertex Texture Seams'

   .. raw:: html

      Colorize only border edges.</p>

.. data:: select_vertices_from_faces

   *MeshLab filter name*: 'Select Vertices from Faces'

   .. raw:: html

      Select vertices from selected faces.</p>

   **Parameters:**

   ``inclusive : bool = true``

      .. raw:: html

         <i>Strict Selection</i>: If true only the vertices with <b>all</b> the incident face selected are selected. Otherwise any vertex with at least one incident selected face will be selected.

.. data:: select_visible_points

   *MeshLab filter name*: 'Select Visible Points'

   .. raw:: html

      Select the <b>visible points</b> in a point cloud, as viewed from a given viewpoint.<br>It uses the Qhull library (http://www.qhull.org/ <br><br>The algorithm used (Katz, Tal and Basri 2007) determines visibility without reconstructing a surface or estimating normals.A point is considered visible if its transformed point lies on the convex hull of a transformed points cloud from the original mesh points.</p>

   **Parameters:**

   ``radiusthreshold : float (bounded) = 0 [min: 0; max: 7]``

      .. raw:: html

         <i>radius threshold </i>: Bounds the radius of the sphere used to select visible points.It is used to adjust the radius of the sphere (calculated as distance between the center and the farthest point from it) according to the following equation: <br>radius = radius * pow(10,threshold); <br>As the radius increases more points are marked as visible.Use a big threshold for dense point clouds, a small one for sparse clouds.

   ``usecamera : bool = false``

      .. raw:: html

         <i>Use ViewPoint from Mesh Camera</i>: Uses the ViewPoint from the camera associated to the current mesh<br> if there is no camera, an error occurs

   ``viewpoint : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>ViewPoint</i>: if UseCamera is true, this value is ignored

   ``convex_hullfp : bool = false``

      .. raw:: html

         <i>Show Partial Convex Hull of flipped points</i>: Show Partial Convex Hull of the transformed point cloud

   ``triangvp : bool = false``

      .. raw:: html

         <i>Show a triangulation of the visible points</i>: Show a triangulation of the visible points

.. data:: set_mesh_camera

   *MeshLab filter name*: 'Set Mesh Camera'

   .. raw:: html

      This filter allows one to set a shot for the current mesh</p>

   **Parameters:**

   ``shot : Shotf [still unsupported] = None``

      .. raw:: html

         <i>New shot</i>: This filter allows one to set a shot for the current mesh.

.. data:: set_raster_camera

   *MeshLab filter name*: 'Set Raster Camera'

   .. raw:: html

      This filter allows one to set a shot for the current mesh</p>

   **Parameters:**

   ``shot : Shotf [still unsupported] = None``

      .. raw:: html

         <i>New shot</i>: This filter allows one to set a shot for the current raster.

.. data:: set_texture

   *MeshLab filter name*: 'Set Texture'

   .. raw:: html

      Set a texture associated with current mesh parametrization.<br>If the texture provided exists, then it will be simply associated to the current mesh; else a dummy texture will be created and saved in the same directory of the mesh if exists, or in the default system picture directory.</p>

   **Parameters:**

   ``textname : str = 'cube.png'``

      .. raw:: html

         <i>Texture file</i>: If the file exists it will be associated to the mesh else a dummy one will be created

   ``textdim : int = 1024``

      .. raw:: html

         <i>Texture Dimension (px)</i>: If the named texture doesn't exists the dummy one will be squared with this size

.. data:: shape_diameter_function

   *MeshLab filter name*: 'Shape Diameter Function'

   .. raw:: html

      Calculate the SDF (<b>shape diameter function</b>) on the mesh, you can visualize the result colorizing the mesh. The SDF is a scalar function on the mesh surface and represents the neighborhood diameter of the object at each point. Given a point on the mesh surface,several rays are sent inside a cone, centered around the point's inward-normal, to the other side of the mesh. The result is a weighted sum of all rays lengths. For further details, see the reference paper:<br><b>Shapira Shamir Cohen-Or,<br>Consistent Mesh Partitioning and Skeletonisation using the shaper diamter function, Visual Comput. J. (2008)</b> </p>

   **Parameters:**

   ``onprimitive : str = 'On vertices' (or int = 0)``

      Possible enum values:

         0. ``'On vertices'``
         1. ``'On Faces'``

      .. raw:: html

         <i>Metric:</i>: Choose whether to trace rays from faces or from vertices.

   ``numberrays : int = 128``

      .. raw:: html

         <i>Number of rays: </i>: The number of rays that will be casted around the normals.

   ``depthtexturesize : int = 512``

      .. raw:: html

         <i>Depth texture size</i>: Size of the depth texture for depth peeling. Higher resolutions provide better sampling of the mesh, with a small performance penalty.

   ``peelingiteration : int = 10``

      .. raw:: html

         <i>Peeling Iteration</i>: Number of depth peeling iteration. Actually is the maximum number of layers that a ray can hit while traversing the mesh. For example, in the case of a sphere, you should specify 2 in this parameter. For a torus, specify 4. <b>For more complex geometry you should run the depth complexity filter to know the exact value</b>.

   ``peelingtolerance : float = 1e-07``

      .. raw:: html

         <i>Peeling Tolerance</i>: Depth tolerance used during depth peeling. This is the threshold used to differentiate layers between each others.Two elements whose distance is below this value will be considered as belonging to the same layer.

   ``coneangle : float = 120``

      .. raw:: html

         <i>Cone amplitude</i>: Cone amplitude around normals in degrees. Rays are traced within this cone.

   ``removefalse : bool = true``

      .. raw:: html

         <i>Remove false intersections</i>: For eachray we check the normal at the point of intersection,and ignore intersections where the normal at the intersectionpoints is in the same direction as the point-of-origin(the same direction is defined as an angle difference lessthan 90)

   ``removeoutliers : bool = false``

      .. raw:: html

         <i>Remove outliers</i>: The outliers removal is made on the fly with a supersampling of the depth buffer. For each ray that we trace, we take multiple depth values near the point of intersection and we output only the median of these values. Some mesh can benefit from this additional calculation.

.. data:: simplification_clustering_decimation

   *MeshLab filter name*: 'Simplification: Clustering Decimation'

   .. raw:: html

      Collapse vertices by creating a three dimensional grid enveloping the mesh and discretizes them based on the cells of this grid</p>

   **Parameters:**

   ``threshold : Percentage = 1%``

      .. raw:: html

         <i>Cell Size</i>: The size of the cell of the clustering grid. Smaller the cell finer the resulting mesh. For obtaining a very coarse mesh use larger values.

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: simplification_edge_collapse_for_marching_cube_meshes

   *MeshLab filter name*: 'Simplification: Edge Collapse for Marching Cube meshes'

   .. raw:: html

      A simplification/cleaning algorithm that works ONLY on meshes generated by Marching Cubes algorithm.</p>

.. data:: simplification_quadric_edge_collapse_decimation

   *MeshLab filter name*: 'Simplification: Quadric Edge Collapse Decimation'

   .. raw:: html

      Simplify a mesh using a Quadric based Edge Collapse Strategy; better than clustering but slower</p>

   **Parameters:**

   ``targetfacenum : int = 0``

      .. raw:: html

         <i>Target number of faces</i>: The desired final number of faces.

   ``targetperc : float = 0``

      .. raw:: html

         <i>Percentage reduction (0..1)</i>: If non zero, this parameter specifies the desired final size of the mesh as a percentage of the initial size.

   ``qualitythr : float = 0.3``

      .. raw:: html

         <i>Quality threshold</i>: Quality threshold for penalizing bad shaped faces.<br>The value is in the range [0..1]<br> 0 accept any kind of face (no penalties),<br> 0.5  penalize faces with quality < 0.5, proportionally to their shape<br>

   ``preserveboundary : bool = false``

      .. raw:: html

         <i>Preserve Boundary of the mesh</i>: The simplification process tries to do not affect mesh boundaries during simplification

   ``boundaryweight : float = 1``

      .. raw:: html

         <i>Boundary Preserving Weight</i>: The importance of the boundary during simplification. Default (1.0) means that the boundary has the same importance of the rest. Values greater than 1.0 raise boundary importance and has the effect of removing less vertices on the border. Admitted range of values (0,+inf).

   ``preservenormal : bool = false``

      .. raw:: html

         <i>Preserve Normal</i>: Try to avoid face flipping effects and try to preserve the original orientation of the surface

   ``preservetopology : bool = false``

      .. raw:: html

         <i>Preserve Topology</i>: Avoid all the collapses that should cause a topology change in the mesh (like closing holes, squeezing handles, etc). If checked the genus of the mesh should stay unchanged.

   ``optimalplacement : bool = true``

      .. raw:: html

         <i>Optimal position of simplified vertices</i>: Each collapsed vertex is placed in the position minimizing the quadric error.<br> It can fail (creating bad spikes) in case of very flat areas. <br>If disabled edges are collapsed onto one of the two original vertices and the final mesh is composed by a subset of the original vertices.

   ``planarquadric : bool = false``

      .. raw:: html

         <i>Planar Simplification</i>: Add additional simplification constraints that improves the quality of the simplification of the planar portion of the mesh, as a side effect, more triangles will be preserved in flat areas (allowing better shaped triangles).

   ``planarweight : float = 0.001``

      .. raw:: html

         <i>Planar Simp. Weight</i>: How much we should try to preserve the triangles in the planar regions. If you lower this value planar areas will be simplified more.

   ``qualityweight : bool = false``

      .. raw:: html

         <i>Weighted Simplification</i>: Use the Per-Vertex quality as a weighting factor for the simplification. The weight is used as a error amplification value, so a vertex with a high quality value will not be simplified and a portion of the mesh with low quality values will be aggressively simplified.

   ``autoclean : bool = true``

      .. raw:: html

         <i>Post-simplification cleaning</i>: After the simplification an additional set of steps is performed to clean the mesh (unreferenced vertices, bad faces, etc)

   ``selected : bool = false``

      .. raw:: html

         <i>Simplify only selected faces</i>: The simplification is applied only to the selected set of faces.<br> Take care of the target number of faces!

.. data:: simplification_quadric_edge_collapse_decimation_with_texture

   *MeshLab filter name*: 'Simplification: Quadric Edge Collapse Decimation (with texture)'

   .. raw:: html

      Simplify a textured mesh using a Quadric based Edge Collapse Strategy preserving UV parametrization; better than clustering but slower</p>

   **Parameters:**

   ``targetfacenum : int = 0``

      .. raw:: html

         <i>Target number of faces</i>:

   ``targetperc : float = 0``

      .. raw:: html

         <i>Percentage reduction (0..1)</i>: If non zero, this parameter specifies the desired final size of the mesh as a percentage of the initial mesh.

   ``qualitythr : float = 0.3``

      .. raw:: html

         <i>Quality threshold</i>: Quality threshold for penalizing bad shaped faces.<br>The value is in the range [0..1]<br> 0 accept any kind of face (no penalties),<br> 0.5  penalize faces with quality < 0.5, proportionally to their shape<br>

   ``extratcoordw : float = 1``

      .. raw:: html

         <i>Texture Weight</i>: Additional weight for each extra Texture Coordinates for every (selected) vertex

   ``preserveboundary : bool = false``

      .. raw:: html

         <i>Preserve Boundary of the mesh</i>: The simplification process tries not to destroy mesh boundaries

   ``boundaryweight : float = 1``

      .. raw:: html

         <i>Boundary Preserving Weight</i>: The importance of the boundary during simplification. Default (1.0) means that the boundary has the same importance of the rest. Values greater than 1.0 raise boundary importance and has the effect of removing less vertices on the border. Admitted range of values (0,+inf).

   ``optimalplacement : bool = true``

      .. raw:: html

         <i>Optimal position of simplified vertices</i>: Each collapsed vertex is placed in the position minimizing the quadric error.<br> It can fail (creating bad spikes) in case of very flat areas. <br>If disabled edges are collapsed onto one of the two original vertices and the final mesh is composed by a subset of the original vertices.

   ``preservenormal : bool = false``

      .. raw:: html

         <i>Preserve Normal</i>: Try to avoid face flipping effects and try to preserve the original orientation of the surface

   ``planarquadric : bool = false``

      .. raw:: html

         <i>Planar Simplification</i>: Add additional simplification constraints that improves the quality of the simplification of the planar portion of the mesh.

   ``selected : bool = false``

      .. raw:: html

         <i>Simplify only selected faces</i>: The simplification is applied only to the selected set of faces.<br> Take care of the target number of faces!

.. data:: smooth_face_normals

   *MeshLab filter name*: 'Smooth Face Normals'

   .. raw:: html

      Laplacian smooth of the face normals, without touching the position of the vertices.</p>

.. data:: smooth_laplacian_face_color

   *MeshLab filter name*: 'Smooth: Laplacian Face Color'

   .. raw:: html

      Laplacian Smooth Face Color</p>

   **Parameters:**

   ``iteration : int = 1``

      .. raw:: html

         <i>Iteration</i>: the number of iteration of the smoothing algorithm

.. data:: smooth_laplacian_vertex_color

   *MeshLab filter name*: 'Smooth: Laplacian Vertex Color'

   .. raw:: html

      Laplacian Smooth Vertex Color</p>

   **Parameters:**

   ``iteration : int = 1``

      .. raw:: html

         <i>Iteration</i>: the number of iteration of the smoothing algorithm

.. data:: smooth_vertex_quality

   *MeshLab filter name*: 'Smooth Vertex Quality'

   .. raw:: html

      Laplacian smooth of the <a href='https://stackoverflow.com/questions/58610746'>quality per vertex</a> values.</p>

.. data:: smooths_normals_on_a_point_sets

   *MeshLab filter name*: 'Smooths normals on a point sets'

   .. raw:: html

      Smooth the normals of the vertices of a mesh without exploiting the triangle connectivity, useful for dataset with no faces</p>

   **Parameters:**

   ``k : int = 10``

      .. raw:: html

         <i>Number of neighbors</i>: The number of neighbors used to smooth normals.

   ``usedist : bool = false``

      .. raw:: html

         <i>Weight using neighbour distance</i>: If selected, the neighbour normals are waighted according to their distance

.. data:: snap_mismatched_borders

   *MeshLab filter name*: 'Snap Mismatched Borders'

   .. raw:: html

      Try to snap together adjacent borders that are slightly mismatched.<br>This situation can happen on badly triangulated adjacent patches defined by high order surfaces.<br>For each border vertex the filter snap it onto the closest boundary edge only if it is closest of <i>edge_length*threshold</i>. When vertex is snapped the corresponding face is split and a new vertex is created.</p>

   **Parameters:**

   ``edgedistratio : float = 0.01``

      .. raw:: html

         <i>Edge Distance Ratio</i>: Collapse edge when the edge / distance ratio is greater than this value. E.g. for default value 1000 two straight border edges are collapsed if the central vertex dist from the straight line composed by the two edges less than a 1/1000 of the sum of the edges length. Larger values enforce that only vertices very close to the line are removed.

   ``unifyvertices : bool = true``

      .. raw:: html

         <i>UnifyVertices</i>: if true the snap vertices are weld together.

.. data:: sphere

   *MeshLab filter name*: 'Sphere'

   .. raw:: html

      Create a Sphere, whose topology is obtained as regular subdivision of an icosahedron.</p>

   **Parameters:**

   ``radius : float = 1``

      .. raw:: html

         <i>Radius</i>: Radius of the sphere

   ``subdiv : int = 3``

      .. raw:: html

         <i>Subdiv. Level</i>: Number of the recursive subdivision of the surface. Default is 3 (a sphere approximation composed by 1280 faces).<br>Admitted values are in the range 0 (an icosahedron) to 8 (a 1.3 MegaTris approximation of a sphere)

.. data:: sphere_cap

   *MeshLab filter name*: 'Sphere Cap'

   .. raw:: html

      Create a Sphere Cap, or spherical dome, subtended by a cone of given angle</p>

   **Parameters:**

   ``angle : float = 60``

      .. raw:: html

         <i>Angle</i>: Angle of the cone subtending the cap. It must be < 180

   ``subdiv : int = 3``

      .. raw:: html

         <i>Subdiv. Level</i>: Number of the recursive subdivision of the surface. Default is 3 (a sphere approximation composed by 1280 faces).<br>Admitted values are in the range 0 (an icosahedron) to 8 (a 1.3 MegaTris approximation of a sphere)

.. data:: split_in_connected_components

   *MeshLab filter name*: 'Split in Connected Components'

   .. raw:: html

      Split current Layer into many layers, one for each connected components</p>

.. data:: stratified_triangle_sampling

   *MeshLab filter name*: 'Stratified Triangle Sampling'

   .. raw:: html

      Create a new layer populated with a point sampling of the current mesh; to generate multiple samples inside a triangle each triangle is subdivided according to various <i>stratified</i> strategies. Distribution is often biased by triangle shape.</p>

   **Parameters:**

   ``samplenum : int = 100000``

      .. raw:: html

         <i>Number of samples</i>: The desired number of samples. It can be smaller or larger than the mesh size, and according to the chosen sampling strategy it will try to adapt.

   ``sampling : str = 'Similar Triangle' (or int = 0)``

      Possible enum values:

         0. ``'Similar Triangle'``
         1. ``'Dual Similar Triangle'``
         2. ``'Long Edge Subdiv'``
         3. ``'Sample Edges'``
         4. ``'Sample NonFaux Edges'``

      .. raw:: html

         <i>Element to sample:</i>: <b>Similar Triangle</b>: each triangle is subdivided into similar triangles and the internal vertices of these triangles are considered. This sampling leave space around edges and vertices for separate sampling of these entities.<br><b>Dual Similar Triangle</b>: each triangle is subdivided into similar triangles and the internal vertices of these triangles are considered.  <br><b>Long Edge Subdiv</b> each triangle is recursively subdivided along the longest edge. <br><b>Sample Edges</b> Only the edges of the mesh are uniformly sampled. <br><b>Sample NonFaux Edges</b> Only the non-faux edges of the mesh are uniformly sampled.

   ``random : bool = false``

      .. raw:: html

         <i>Random Sampling</i>: if true, for each (virtual) face we draw a random point, otherwise we pick the face midpoint.

.. data:: structure_synth_mesh_creation

   *MeshLab filter name*: 'Structure Synth Mesh Creation'

   .. raw:: html

      Structure Synth mesh creation based on Eisen Script.<br> For further instruction visit http://structuresynth.sourceforge.net/reference.php</p>

   **Parameters:**

   ``grammar : str = 'set maxdepth 40 R1 R2 rule R1 { { x 1 rz 6 ry 6 s 0.99 } R1 { s 2 } sphere } rule R2 {{ x -1 rz 6 ry 6 s 0.99 } R2 { s 2 } sphere} '``

      .. raw:: html

         <i>Eisen Script grammar</i>: Write a grammar according to Eisen Script specification and using the primitives box, sphere, mesh, dot and triangle

   ``seed : int = 1``

      .. raw:: html

         <i>seed for random construction</i>: Seed needed to build the mesh

   ``sphereres : int = 1``

      .. raw:: html

         <i>set maximum resolution of sphere primitives, it must be included between 1 and 4</i>: increasing the resolution of the spheres will improve the quality of the mesh

.. data:: subdivision_surfaces_butterfly_subdivision

   *MeshLab filter name*: 'Subdivision Surfaces: Butterfly Subdivision'

   .. raw:: html

      Apply Butterfly Subdivision Surface algorithm. It is an interpolated refinement method, defined on arbitrary triangular meshes. The scheme is known to be C1 but not C2 on regular meshes<br></p>

   **Parameters:**

   ``iterations : int = 3``

      .. raw:: html

         <i>Iterations</i>: Number of time the model is subdivided.

   ``threshold : Percentage = 1%``

      .. raw:: html

         <i>Edge Threshold</i>: All the edges <b>longer</b> than this threshold will be refined.<br>Setting this value to zero will force an uniform refinement.

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: subdivision_surfaces_catmull_clark

   *MeshLab filter name*: 'Subdivision Surfaces: Catmull-Clark'

   .. raw:: html

      Apply the Catmull-Clark Subdivision Surfaces. Note that position of the new vertices is simply linearly interpolated. If the mesh is triangle based (no <a href='https://stackoverflow.com/questions/59392193'>faux edges</a>) it generates a quad mesh, otherwise it honores it the faux-edge bits</p>

.. data:: subdivision_surfaces_loop

   *MeshLab filter name*: 'Subdivision Surfaces: Loop'

   .. raw:: html

      Apply Loop's Subdivision Surface algorithm. It is an approximant refinement method and it works for every triangle and has rules for extraordinary vertices.<br></p>

   **Parameters:**

   ``loopweight : str = 'Loop' (or int = 0)``

      Possible enum values:

         0. ``'Loop'``
         1. ``'Enhance regularity'``
         2. ``'Enhance continuity'``

      .. raw:: html

         <i>Weighting scheme</i>: Change the weights used. Allows one to optimize some behaviors over others.

   ``iterations : int = 3``

      .. raw:: html

         <i>Iterations</i>: Number of time the model is subdivided.

   ``threshold : Percentage = 1%``

      .. raw:: html

         <i>Edge Threshold</i>: All the edges <b>longer</b> than this threshold will be refined.<br>Setting this value to zero will force an uniform refinement.

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: subdivision_surfaces_ls3_loop

   *MeshLab filter name*: 'Subdivision Surfaces: LS3 Loop'

   .. raw:: html

      Apply LS3 Subdivision Surface algorithm using Loop's weights. This refinement method take normals into account. <br>See:<i>Boye', S. Guennebaud, G. & Schlick, C.</i> <br><b>Least squares subdivision surfaces</b><br>Computer Graphics Forum, 2010.<br/><br/>Alternatives weighting schemes are based on the paper: <i>Barthe, L. & Kobbelt, L.</i><br><b>Subdivision scheme tuning around extraordinary vertices</b><br>Computer Aided Geometric Design, 2004, 21, 561-583.<br/>The current implementation of these schemes don't handle vertices of valence > 12</p>

   **Parameters:**

   ``loopweight : str = 'Loop' (or int = 0)``

      Possible enum values:

         0. ``'Loop'``
         1. ``'Enhance regularity'``
         2. ``'Enhance continuity'``

      .. raw:: html

         <i>Weighting scheme</i>: Change the weights used. Allows one to optimize some behaviors over others.

   ``iterations : int = 3``

      .. raw:: html

         <i>Iterations</i>: Number of time the model is subdivided.

   ``threshold : Percentage = 1%``

      .. raw:: html

         <i>Edge Threshold</i>: All the edges <b>longer</b> than this threshold will be refined.<br>Setting this value to zero will force an uniform refinement.

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: subdivision_surfaces_midpoint

   *MeshLab filter name*: 'Subdivision Surfaces: Midpoint'

   .. raw:: html

      Apply a plain subdivision scheme where every edge is split on its midpoint. Useful to uniformly refine a mesh substituting each triangle with four smaller triangles.</p>

   **Parameters:**

   ``iterations : int = 3``

      .. raw:: html

         <i>Iterations</i>: Number of time the model is subdivided.

   ``threshold : Percentage = 1%``

      .. raw:: html

         <i>Edge Threshold</i>: All the edges <b>longer</b> than this threshold will be refined.<br>Setting this value to zero will force an uniform refinement.

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: surface_reconstruction_ball_pivoting

   *MeshLab filter name*: 'Surface Reconstruction: Ball Pivoting'

   .. raw:: html

      Given a point cloud with normals it reconstructs a surface using the <b>Ball Pivoting Algorithm</b>.Starting with a seed triangle, the BPA algorithm  pivots a ball of the given radius around the already formed edgesuntil it touches another point, forming another triangle. The process continues until all reachable edges have been tried.This surface reconstruction algorithm uses the existing points without creating new ones. Works better with uniformly sampled point clouds. If needed first perform a poisson disk subsampling of the point cloud. <br>Bernardini F., Mittleman J., Rushmeier H., Silva C., Taubin G.<br><b>The ball-pivoting algorithm for surface reconstruction.</b><br>IEEE TVCG 1999</p>

   **Parameters:**

   ``ballradius : Percentage = 0%``

      .. raw:: html

         <i>Pivoting Ball radius (0 autoguess)</i>: The radius of the ball pivoting (rolling) over the set of points. Gaps that are larger than the ball radius will not be filled; similarly the small pits that are smaller than the ball radius will be filled.

   ``clustering : float = 20``

      .. raw:: html

         <i>Clustering radius (% of ball radius)</i>: To avoid the creation of too small triangles, if a vertex is found too close to a previous one, it is clustered/merged with it.

   ``creasethr : float = 90``

      .. raw:: html

         <i>Angle Threshold (degrees)</i>: If we encounter a crease angle that is too large we should stop the ball rolling

   ``deletefaces : bool = false``

      .. raw:: html

         <i>Delete initial set of faces</i>: if true all the initial faces of the mesh are deleted and the whole surface is rebuilt from scratch. Otherwise the current faces are used as a starting point. Useful if you run the algorithm multiple times with an increasing ball radius.

.. data:: surface_reconstruction_screened_poisson

   *MeshLab filter name*: 'Surface Reconstruction: Screened Poisson'

   .. raw:: html

      This surface reconstruction algorithm creates watertight surfaces from oriented point sets.<br>The filter uses the original code of Michael Kazhdan and Matthew Bolitho implementing the algorithm described in the following paper:<br><i>Michael Kazhdan, Hugues Hoppe</i>,<br><b>"Screened Poisson surface reconstruction"</b><br></p>

   **Parameters:**

   ``visiblelayer : bool = false``

      .. raw:: html

         <i>Merge all visible layers</i>: Enabling this flag means that all the visible layers will be used for providing the points.

   ``depth : int = 8``

      .. raw:: html

         <i>Reconstruction Depth</i>: This integer is the maximum depth of the tree that will be used for surface reconstruction. Running at depth d corresponds to solving on a voxel grid whose resolution is no larger than 2^d x 2^d x 2^d. Note that since the reconstructor adapts the octree to the sampling density, the specified reconstruction depth is only an upper bound. The default value for this parameter is 8.

   ``fulldepth : int = 5``

      .. raw:: html

         <i>Adaptive Octree Depth</i>: This integer specifies the depth beyond depth the octree will be adapted. At coarser depths, the octree will be complete, containing all 2^d x 2^d x 2^d nodes. The default value for this parameter is 5.

   ``cgdepth : int = 0``

      .. raw:: html

         <i>Conjugate Gradients Depth</i>: This integer is the depth up to which a conjugate-gradients solver will be used to solve the linear system. Beyond this depth Gauss-Seidel relaxation will be used. The default value for this parameter is 0.

   ``scale : float = 1.1``

      .. raw:: html

         <i>Scale Factor</i>: This floating point value specifies the ratio between the diameter of the cube used for reconstruction and the diameter of the samples' bounding cube. The default value is 1.1.

   ``samplespernode : float = 1.5``

      .. raw:: html

         <i>Minimum Number of Samples</i>: This floating point value specifies the minimum number of sample points that should fall within an octree node as the octree construction is adapted to sampling density. For noise-free samples, small values in the range [1.0 - 5.0] can be used. For more noisy samples, larger values in the range [15.0 - 20.0] may be needed to provide a smoother, noise-reduced, reconstruction. The default value is 1.5.

   ``pointweight : float = 4``

      .. raw:: html

         <i>Interpolation Weight</i>: This floating point value specifies the importants that interpolation of the point samples is given in the formulation of the screened Poisson equation. The results of the original (unscreened) Poisson Reconstruction can be obtained by setting this value to 0. The default value for this parameter is 4.

   ``iters : int = 8``

      .. raw:: html

         <i>Gauss-Seidel Relaxations</i>: This integer value specifies the number of Gauss-Seidel relaxations to be performed at each level of the hierarchy. The default value for this parameter is 8.

   ``confidence : bool = false``

      .. raw:: html

         <i>Confidence Flag</i>: Enabling this flag tells the reconstructor to use the quality as confidence information; this is done by scaling the unit normals with the quality values. When the flag is not enabled, all normals are normalized to have unit-length prior to reconstruction.

   ``preclean : bool = false``

      .. raw:: html

         <i>Pre-Clean</i>: Enabling this flag force a cleaning pre-pass on the data removing all unreferenced vertices or vertices with null normals.

.. data:: surface_reconstruction_vcg

   *MeshLab filter name*: 'Surface Reconstruction: VCG'

   .. raw:: html

      The surface reconstrction algorithm that have been used for a long time inside the ISTI-Visual Computer Lab.It is mostly a variant of the Curless et al. e.g. a volumetric approach with some original weighting schemes,a different expansion rule, and another approach to hole filling through volume dilation/relaxations.<br>The filter is applied to <b>ALL</b> the visible layers. In practice, all the meshes/point clouds that are currently <i>visible</i> are used to build the volumetric distance field.</p>

   **Parameters:**

   ``voxsize : Percentage = 1%``

      .. raw:: html

         <i>Voxel Side</i>: VoxelSide

   ``subdiv : int = 1``

      .. raw:: html

         <i>SubVol Splitting</i>: The level of recursive splitting of the subvolume reconstruction process. A value of '3' means that a 3x3x3 regular space subdivision is created and the reconstruction process generate 8 matching meshes. It is useful for reconsruction objects at a very high resolution. Default value (1) means no splitting.

   ``geodesic : float = 2``

      .. raw:: html

         <i>Geodesic Weighting</i>: The influence of each range map is weighted with its geodesic distance from the borders. In this way when two (or more ) range maps overlaps their contribution blends smoothly hiding possible misalignments.

   ``openresult : bool = true``

      .. raw:: html

         <i>Show Result</i>: if not checked the result is only saved into the current directory

   ``smoothnum : int = 1``

      .. raw:: html

         <i>Volume Laplacian iter</i>: How many volume smoothing step are performed to clean out the eventually noisy borders

   ``widenum : int = 3``

      .. raw:: html

         <i>Widening</i>:  How many voxel the field is expanded. Larger this value more holes will be filled

   ``mergecolor : bool = false``

      .. raw:: html

         <i>Vertex Splatting</i>: This option use a different way to build up the volume, instead of using rasterization of the triangular face it splat the vertices into the grids. It works under the assumption that you have at least one sample for each voxel of your reconstructed volume.

   ``simplification : bool = false``

      .. raw:: html

         <i>Post Merge simplification</i>: After the merging an automatic simplification step is performed.

   ``normalsmooth : int = 3``

      .. raw:: html

         <i>PreSmooth iter</i>: How many times, before converting meshes into volume, the normal of the surface are smoothed. It is useful only to get more smooth expansion in case of noisy borders.

.. data:: taubin_smooth

   *MeshLab filter name*: 'Taubin Smooth'

   .. raw:: html

      The &lambda;-&mu; Taubin smoothing, combines two steps of low-pass filtering for each iteration. Based on the article:<br><b>A signal processing approach to fair surface design</b> by <i>Gabriel Taubin</i>, SIGGRAPH 1995<br><a href='https://doi.org/10.1145/218380.218473'>doi:10.1145/218380.218473</a></p>

   **Parameters:**

   ``lambda_ : float = 0.5``

      .. raw:: html

         <i>Lambda</i>: The lambda parameter of the Taubin Smoothing algorithm

   ``mu : float = -0.53``

      .. raw:: html

         <i>mu</i>: The mu parameter of the Taubin Smoothing algorithm

   ``stepsmoothnum : int = 10``

      .. raw:: html

         <i>Smoothing steps</i>: The number of times that the taubin smoothing is iterated. Usually it requires a larger number of iteration than the classical laplacian

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selected faces</i>: If checked the filter is performed only on the selected faces

.. data:: tetrahedron

   *MeshLab filter name*: 'Tetrahedron'

   .. raw:: html

      Create a Tetrahedron</p>

.. data:: texel_sampling

   *MeshLab filter name*: 'Texel Sampling'

   .. raw:: html

      Create a new layer with a point sampling of the current mesh, a sample for each texel of the mesh is generated</p>

   **Parameters:**

   ``texturew : int = 512``

      .. raw:: html

         <i>Texture Width</i>: A sample for each texel is generated, so the desired texture size is need, only samples for the texels falling inside some faces are generated.<br> Setting this param to 256 means that you get at most 256x256 = 65536 samples).<br>If this parameter is 0 the size of the current texture is chosen.

   ``textureh : int = 512``

      .. raw:: html

         <i>Texture Height</i>: A sample for each texel is generated, so the desired texture size is need, only samples for the texels falling inside some faces are generated.<br> Setting this param to 256 means that you get at most 256x256 = 65536 samples)

   ``texturespace : bool = false``

      .. raw:: html

         <i>UV Space Sampling</i>: The generated texel samples have their UV coords as point positions. The resulting point set is has a square domain, the texels/points, even if on a flat domain retain the original vertex normal to help a better perception of the original provenience.

   ``recovercolor : bool = false``

      .. raw:: html

         <i>RecoverColor</i>: The generated point cloud has the current texture color

.. data:: torus

   *MeshLab filter name*: 'Torus'

   .. raw:: html

      Create a Torus</p>

   **Parameters:**

   ``hradius : float = 3``

      .. raw:: html

         <i>Horizontal Radius</i>: Radius of the whole horizontal ring of the torus

   ``vradius : float = 1``

      .. raw:: html

         <i>Vertical Radius</i>: Radius of the vertical section of the ring

   ``hsubdiv : int = 24``

      .. raw:: html

         <i>Horizontal Subdivision</i>: Subdivision step of the ring

   ``vsubdiv : int = 12``

      .. raw:: html

         <i>Vertical Subdivision</i>: Number of sides of the polygonal approximation of the torus section

.. data:: transfer_color_face_to_vertex

   *MeshLab filter name*: 'Transfer Color: Face to Vertex'

   .. raw:: html

      Face to Vertex color transfer</p>

.. data:: transfer_color_mesh_to_face

   *MeshLab filter name*: 'Transfer Color: Mesh to Face'

   .. raw:: html

      Mesh to Face color transfer</p>

   **Parameters:**

   ``allvisiblemesh : bool = false``

      .. raw:: html

         <i>Apply to all Meshes</i>: If true the color mapping is applied to all the meshes.

.. data:: transfer_color_texture_to_vertex

   *MeshLab filter name*: 'Transfer Color: Texture to Vertex'

   .. raw:: html

      Texture to Vertex color transfer</p>

.. data:: transfer_color_vertex_to_face

   *MeshLab filter name*: 'Transfer Color: Vertex to Face'

   .. raw:: html

      Vertex to Face color transfer</p>

.. data:: transfer_texture_to_vertex_color_1_or_2_meshes

   *MeshLab filter name*: 'Transfer: Texture to Vertex Color (1 or 2 meshes)'

   .. raw:: html

      Generates Vertex Color values picking color from a texture (same mesh or another mesh).</p>

   **Parameters:**

   ``sourcemesh : int = 0``

      .. raw:: html

         <i>Source Mesh</i>: The mesh with associated texture that we want to sample from

   ``targetmesh : int = 0``

      .. raw:: html

         <i>Target Mesh</i>: The mesh whose vertex color will be filled according to source mesh texture

   ``upperbound : Percentage = 2%``

      .. raw:: html

         <i>Max Dist Search</i>: Sample points for which we do not find anything within this distance are rejected and not considered for recovering color

.. data:: transfer_vertex_attributes_to_texture_1_or_2_meshes

   *MeshLab filter name*: 'Transfer: Vertex Attributes to Texture (1 or 2 meshes)'

   .. raw:: html

      Transfer texture color, vertex color or normal from one mesh the texture of another mesh. This may be useful to restore detail lost in simplification, or resample a texture in a different parametrization.</p>

   **Parameters:**

   ``sourcemesh : int = 0``

      .. raw:: html

         <i>Source Mesh</i>: The mesh that contains the source data that we want to transfer

   ``targetmesh : int = 0``

      .. raw:: html

         <i>Target Mesh</i>: The mesh whose texture will be filled according to source mesh data

   ``attributeenum : str = 'Vertex Color' (or int = 0)``

      Possible enum values:

         0. ``'Vertex Color'``
         1. ``'Vertex Normal'``
         2. ``'Vertex Quality'``
         3. ``'Texture Color'``

      .. raw:: html

         <i>Color Data Source</i>: Choose what attribute has to be transferred onto the target texture. You can choose bettween Per vertex attributes (color,normal,quality) or to transfer color information from source mesh texture

   ``upperbound : Percentage = 2%``

      .. raw:: html

         <i>Max Dist Search</i>: Sample points for which we do not find anything within this distance are rejected and not considered for recovering data

   ``textname : str = 'cube_tex.png'``

      .. raw:: html

         <i>Texture file</i>: The texture file to be created

   ``textw : int = 1024``

      .. raw:: html

         <i>Texture width (px)</i>: The texture width

   ``texth : int = 1024``

      .. raw:: html

         <i>Texture height (px)</i>: The texture height

   ``overwrite : bool = false``

      .. raw:: html

         <i>Overwrite Target Mesh Texture</i>: if target mesh has a texture will be overwritten (with provided texture dimension)

   ``assign : bool = false``

      .. raw:: html

         <i>Assign Texture</i>: assign the newly created texture to target mesh

   ``pullpush : bool = true``

      .. raw:: html

         <i>Fill texture</i>: if enabled the unmapped texture space is colored using a pull push filling algorithm, if false is set to black

.. data:: transfer_vertex_color_to_texture

   *MeshLab filter name*: 'Transfer: Vertex Color to Texture'

   .. raw:: html

      Fills the specified texture using per-vertex color data of the mesh.</p>

   **Parameters:**

   ``textname : str = 'cube_tex.png'``

      .. raw:: html

         <i>Texture file</i>: The texture file to be created

   ``textw : int = 1024``

      .. raw:: html

         <i>Texture width (px)</i>: The texture width

   ``texth : int = 1024``

      .. raw:: html

         <i>Texture height (px)</i>: The texture height

   ``overwrite : bool = false``

      .. raw:: html

         <i>Overwrite texture</i>: if current mesh has a texture will be overwritten (with provided texture dimension)

   ``assign : bool = false``

      .. raw:: html

         <i>Assign texture</i>: assign the newly created texture

   ``pullpush : bool = true``

      .. raw:: html

         <i>Fill texture</i>: if enabled the unmapped texture space is colored using a pull push filling algorithm, if false is set to black

.. data:: transform_align_to_principal_axis

   *MeshLab filter name*: 'Transform: Align to Principal Axis'

   .. raw:: html

      Generate a matrix transformation that rotates the mesh aligning it to its principal axis of inertia.If the mesh is watertight the Itertia tensor is computed assuming the interior of the mesh has a uniform density.In case of an open mesh or a point clouds the inerta tensor is computed assuming each vertex is a constant puntual mass.</p>

   **Parameters:**

   ``pointsflag : bool = true``

      .. raw:: html

         <i>Use vertex</i>: If selected, only the vertices of the mesh are used to compute the Principal Axis. Mandatory for point clouds or for non water tight meshes

   ``freeze : bool = true``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: transform_flip_and_or_swap_axis

   *MeshLab filter name*: 'Transform: Flip and/or swap axis'

   .. raw:: html

      Generate a matrix transformation that flips each one of the axis or swaps a couple of axis. The listed transformations are applied in that order. This kind of transformation cannot be applied to set of Raster!</p>

   **Parameters:**

   ``flipx : bool = false``

      .. raw:: html

         <i>Flip X axis</i>: If selected the axis will be swapped (mesh mirrored along the YZ plane

   ``flipy : bool = false``

      .. raw:: html

         <i>Flip Y axis</i>: If selected the axis will be swapped (mesh mirrored along the XZ plane

   ``flipz : bool = false``

      .. raw:: html

         <i>Flip Z axis</i>: If selected the axis will be swapped (mesh mirrored along the XY plane

   ``swapxy : bool = false``

      .. raw:: html

         <i>Swap X-Y axis</i>: If selected the two axis will be swapped. All the swaps are performed in this order

   ``swapxz : bool = false``

      .. raw:: html

         <i>Swap X-Z axis</i>: If selected the two axis will be swapped. All the swaps are performed in this order

   ``swapyz : bool = false``

      .. raw:: html

         <i>Swap Y-Z axis</i>: If selected the two axis will be swapped. All the swaps are performed in this order

   ``freeze : bool = true``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: transform_rotate

   *MeshLab filter name*: 'Transform: Rotate'

   .. raw:: html

      Generate a matrix transformation that rotates the mesh. The mesh can be rotated around one of the axis or a given axis and w.r.t. to the origin or the baricenter, or a given point.</p>

   **Parameters:**

   ``rotaxis : str = 'X axis' (or int = 0)``

      Possible enum values:

         0. ``'X axis'``
         1. ``'Y axis'``
         2. ``'Z axis'``
         3. ``'custom axis'``

      .. raw:: html

         <i>Rotation on:</i>: Choose a method

   ``rotcenter : str = 'origin' (or int = 0)``

      Possible enum values:

         0. ``'origin'``
         1. ``'barycenter'``
         2. ``'custom point'``

      .. raw:: html

         <i>Center of rotation:</i>: Choose a method

   ``angle : float (bounded) = 0 [min: -360; max: 360]``

      .. raw:: html

         <i>Rotation Angle</i>: Angle of rotation (in <b>degree</b>). If snapping is enabled this value is rounded according to the snap value

   ``customaxis : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom axis</i>: This rotation axis is used only if the 'custom axis' option is chosen.

   ``customcenter : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom center</i>: This rotation center is used only if the 'custom point' option is chosen.

   ``snapflag : bool = false``

      .. raw:: html

         <i>Snap angle</i>: If selected, before starting the filter will remove any unreferenced vertex (for which curvature values are not defined)

   ``snapangle : float = 30``

      .. raw:: html

         <i>Snapping Value</i>: This value is used to snap the rotation angle (i.e. if the snapping value is 30, 227 becomes 210).

   ``freeze : bool = true``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: transform_rotate_camera_or_set_of_cameras

   *MeshLab filter name*: 'Transform: Rotate Camera or set of cameras'

   .. raw:: html

      Rotate the camera, or all the cameras of the project. The selected raster is the reference if viewpoint rotation is selected.</p>

   **Parameters:**

   ``camera : str = 'Raster Camera' (or int = 0)``

      Possible enum values:

         0. ``'Raster Camera'``
         1. ``'Mesh Camera'``

      .. raw:: html

         <i>Camera type</i>: Choose the camera to scale

   ``rotaxis : str = 'X axis' (or int = 0)``

      Possible enum values:

         0. ``'X axis'``
         1. ``'Y axis'``
         2. ``'Z axis'``
         3. ``'custom axis'``

      .. raw:: html

         <i>Rotation on:</i>: Choose a method

   ``rotcenter : str = 'origin' (or int = 0)``

      Possible enum values:

         0. ``'origin'``
         1. ``'camera viewpoint'``
         2. ``'custom point'``

      .. raw:: html

         <i>Center of rotation:</i>: Choose a method

   ``angle : float (bounded) = 0 [min: -360; max: 360]``

      .. raw:: html

         <i>Rotation Angle</i>: Angle of rotation (in <b>degree</b>). If snapping is enabled this value is rounded according to the snap value

   ``customaxis : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom axis</i>: This rotation axis is used only if the 'custom axis' option is chosen.

   ``customcenter : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom center</i>: This rotation center is used only if the 'custom point' option is chosen.

   ``toallraster : bool = false``

      .. raw:: html

         <i>Apply to all active Raster layers</i>: Apply the same scaling to all the active Raster layers: it is taken into account only if 'Raster Camera' is selected

   ``toall : bool = false``

      .. raw:: html

         <i>Apply to all active Raster and visible Mesh layers</i>: Apply the same scaling to all the layers, including any visible 3D layer

.. data:: transform_rotate_to_fit_to_a_plane

   *MeshLab filter name*: 'Transform: Rotate to Fit to a plane'

   .. raw:: html

      Generate a matrix transformation that rotates the mesh so that the selection fits one of the main planes XY YZ ZX. May also translate such that the selection centroid rest on the origin. It reports on the log the average error of the fitting (in mesh units).</p>

   **Parameters:**

   ``targetplane : str = 'XY plane' (or int = 0)``

      Possible enum values:

         0. ``'XY plane'``
         1. ``'YZ plane'``
         2. ``'ZX plane'``

      .. raw:: html

         <i>Rotate to fit:</i>: Choose the plane where the selection will fit

   ``rotaxis : str = 'any axis' (or int = 0)``

      Possible enum values:

         0. ``'any axis'``
         1. ``'X axis'``
         2. ``'Y axis'``
         3. ``'Z axis'``

      .. raw:: html

         <i>Rotate on:</i>: Choose on which axis do the rotation: 'any axis' guarantee the best fit of the selection to the plane, only use X,Y or Z it if you want to preserve that specific axis.

   ``toorigin : bool = true``

      .. raw:: html

         <i>Move to Origin</i>: Also apply a translation, such that the centroid of selection rests on the Origin

   ``freeze : bool = true``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: transform_scale_camera_or_set_of_cameras

   *MeshLab filter name*: 'Transform: Scale Camera or set of cameras'

   .. raw:: html

      Scale the camera, or all the cameras of the project. The selected raster is the reference if viewpoint scaling is selected.</p>

   **Parameters:**

   ``camera : str = 'Raster Camera' (or int = 0)``

      Possible enum values:

         0. ``'Raster Camera'``
         1. ``'Mesh Camera'``

      .. raw:: html

         <i>Camera type</i>: Choose the camera to scale

   ``scalecenter : str = 'origin' (or int = 0)``

      Possible enum values:

         0. ``'origin'``
         1. ``'camera viewpoint'``
         2. ``'custom point'``

      .. raw:: html

         <i>Center of scaling:</i>: Choose a method

   ``customcenter : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom center</i>: This scaling center is used only if the 'custom point' option is chosen.

   ``scale : float = 1``

      .. raw:: html

         <i>Scale factor</i>: The scale factor that has to be applied to the camera

   ``toallraster : bool = false``

      .. raw:: html

         <i>Apply to all active Raster layers</i>: Apply the same scaling to all the active Raster layers: it is taken into account only if 'Raster Camera' is selected

   ``toall : bool = false``

      .. raw:: html

         <i>Apply to all active Raster and visible Mesh layers</i>: Apply the same scaling to all the layers, including any visible 3D layer

.. data:: transform_scale_normalize

   *MeshLab filter name*: 'Transform: Scale, Normalize'

   .. raw:: html

      Generate a matrix transformation that scale the mesh. The mesh can be also automatically scaled to a unit side box. </p>

   **Parameters:**

   ``axisx : float = 1``

      .. raw:: html

         <i>X Axis</i>: Scaling

   ``axisy : float = 1``

      .. raw:: html

         <i>Y Axis</i>: Scaling

   ``axisz : float = 1``

      .. raw:: html

         <i>Z Axis</i>: Scaling

   ``uniformflag : bool = true``

      .. raw:: html

         <i>Uniform Scaling</i>: If selected an uniform scaling (the same for all the three axis) is applied (the X axis value is used)

   ``scalecenter : str = 'origin' (or int = 0)``

      Possible enum values:

         0. ``'origin'``
         1. ``'barycenter'``
         2. ``'custom point'``

      .. raw:: html

         <i>Center of scaling:</i>: Choose a method

   ``customcenter : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom center</i>: This scaling center is used only if the 'custom point' option is chosen.

   ``unitflag : bool = false``

      .. raw:: html

         <i>Scale to Unit bbox</i>: If selected, the object is scaled to a box whose sides are at most 1 unit length

   ``freeze : bool = true``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: transform_the_camera_extrinsics_or_all_the_cameras_of_the_project

   *MeshLab filter name*: 'Transform the camera extrinsics, or all the cameras of the project.'

   .. raw:: html

      Transform the camera extrinsics, or all the cameras of the project.</p>

   **Parameters:**

   ``transformmatrix : numpy.ndarray[numpy.float32[4, 4]] = [[1, 0, 0, 0],[0, 1, 0, 0],[0, 0, 1, 0],[0, 0, 0, 1]]``

      .. raw:: html

         <i></i>:

   ``camera : str = 'Raster Camera' (or int = 0)``

      Possible enum values:

         0. ``'Raster Camera'``
         1. ``'Mesh Camera'``

      .. raw:: html

         <i>Camera type</i>: Choose the camera to scale

   ``behaviour : str = 'The matrix is the transformation to apply to the extrinsics' (or int = 0)``

      Possible enum values:

         0. ``'The matrix is the transformation to apply to the extrinsics'``
         1. ``'The matrix represent the new extrinsics'``

      .. raw:: html

         <i>Matrix semantic</i>: What the matrix is used for

   ``toallraster : bool = false``

      .. raw:: html

         <i>Apply to all active Raster layers</i>: Apply the same scaling to all the active Raster layers: it is taken into account only if 'Raster Camera' is selected

   ``toall : bool = false``

      .. raw:: html

         <i>Apply to all active Raster and visible Mesh layers</i>: Apply the same scaling to all the layers, including any visible 3D layer

.. data:: transform_translate_camera_or_set_of_cameras

   *MeshLab filter name*: 'Transform: Translate Camera or set of cameras'

   .. raw:: html

      Translate the camera, or all the cameras of the project.</p>

   **Parameters:**

   ``camera : str = 'Raster Camera' (or int = 0)``

      Possible enum values:

         0. ``'Raster Camera'``
         1. ``'Mesh Camera'``

      .. raw:: html

         <i>Camera type</i>: Choose the camera to scale

   ``axisx : float (bounded) = 0 [min: -1000; max: 1000]``

      .. raw:: html

         <i>X Axis</i>: Absolute translation amount along the X axis

   ``axisy : float (bounded) = 0 [min: -1000; max: 1000]``

      .. raw:: html

         <i>Y Axis</i>: Absolute translation amount along the Y axis

   ``axisz : float (bounded) = 0 [min: -1000; max: 1000]``

      .. raw:: html

         <i>Z Axis</i>: Absolute translation amount along the Z axis

   ``centerflag : bool = false``

      .. raw:: html

         <i>translate viewpoint position to the origin</i>: If selected, the camera viewpoint is translated to the origin

   ``toallraster : bool = false``

      .. raw:: html

         <i>Apply to all active Raster layers</i>: Apply the same scaling to all the active Raster layers: it is taken into account only if 'Raster Camera' is selected

   ``toall : bool = false``

      .. raw:: html

         <i>Apply to all active Raster and Mesh layers</i>: Apply the same scaling to all the layers, including any visible 3D layer

.. data:: transform_translate_center_set_origin

   *MeshLab filter name*: 'Transform: Translate, Center, set Origin'

   .. raw:: html

      Generate a matrix transformation that translate the mesh. The mesh can be translated around one of the axis or a given axis and w.r.t. to the origin or the baricenter, or a given point.</p>

   **Parameters:**

   ``traslmethod : str = 'XYZ translation' (or int = 0)``

      Possible enum values:

         0. ``'XYZ translation'``
         1. ``'Center on Scene BBox'``
         2. ``'Center on Layer BBox'``
         3. ``'Set new Origin'``

      .. raw:: html

         <i>Transformation:</i>: [XYZ translation] adds X,Y and Z offset to Layer transformation, [Center on BBox] moves Layer Origin to the Bounding Box center, [Set new Origin] moves Layer Origin to a specific point

   ``axisx : float (bounded) = 0 [min: -17.3205; max: 17.3205]``

      .. raw:: html

         <i>X Axis</i>: when using [XYZ translation], amount of translation along the X axis (in model units)

   ``axisy : float (bounded) = 0 [min: -17.3205; max: 17.3205]``

      .. raw:: html

         <i>Y Axis</i>: when using [XYZ translation], amount of translation along the Y axis (in model units)

   ``axisz : float (bounded) = 0 [min: -17.3205; max: 17.3205]``

      .. raw:: html

         <i>Z Axis</i>: when using [XYZ translation], amount of translation along the Z axis (in model units)

   ``neworigin : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>New Origin:</i>: when using [Set new Origin], this is the location of the new Origin.

   ``freeze : bool = true``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = false``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: tri_to_quad_by_4_8_subdivision

   *MeshLab filter name*: 'Tri to Quad by 4-8 Subdivision'

   .. raw:: html

      Convert a tri mesh into a quad mesh by applying a 4-8 subdivision scheme.It introduces less overhead than the plain Catmull-Clark Subdivision Surfaces(it adds only a single vertex for each triangle instead of four).<br> See: <br><b>4-8 Subdivision</b><br> <i>Luiz Velho, Denis Zorin </i><br>CAGD, volume 18, Issue 5, Pages 397-427. </p>

.. data:: tri_to_quad_by_smart_triangle_pairing

   *MeshLab filter name*: 'Tri to Quad by smart triangle pairing'

   .. raw:: html

      Convert a tri-mesh into a quad mesh by pairing triangles.</p>

.. data:: turn_into_a_pure_triangular_mesh

   *MeshLab filter name*: 'Turn into a Pure-Triangular mesh'

   .. raw:: html

      Convert into a tri-mesh by splitting any polygonal face.</p>

.. data:: turn_into_quad_dominant_mesh

   *MeshLab filter name*: 'Turn into Quad-Dominant mesh'

   .. raw:: html

      Convert a tri-mesh into a quad-dominant mesh by pairing suitable triangles.</p>

   **Parameters:**

   ``level : str = 'Fewest triangles' (or int = 0)``

      Possible enum values:

         0. ``'Fewest triangles'``
         1. ``'(in between)'``
         2. ``'Better quad shape'``

      .. raw:: html

         <i>Optimize For:</i>: Choose any of three different greedy strategies.

.. data:: twostep_smooth

   *MeshLab filter name*: 'TwoStep Smooth'

   .. raw:: html

      Two Steps Smoothing, a feature preserving/enhancing fairing filter based on two stages:<ol><li>Normal Smoothing, where similar normals are averaged together.<li>Vertex reposition, where vertices are moved to fit on the new normals.</ol><b>A Comparison of Mesh Smoothing Methods</b> by <i>A. Belyaev and Y. Ohtake</i>. Proc. Israel-Korea Bi-National Conf. Geometric Modeling and Computer Graphics, pp. 83-87, 2003.<br><a href='https://www.researchgate.net/publication/47861030_A_comparison_of_mesh_smoothing_methods'>publication</a></p>

   **Parameters:**

   ``stepsmoothnum : int = 3``

      .. raw:: html

         <i>Smoothing steps</i>: The number of times that the whole algorithm (normal smoothing + vertex fitting) is iterated.

   ``normalthr : float = 60``

      .. raw:: html

         <i>Feature Angle Threshold (deg)</i>: Specify a threshold angle (0..90) for features that you want to be preserved.<br>Features forming angles LARGER than the specified threshold will be preserved. <br> 0 -> no smoothing <br> 90 -> all faces will be smoothed

   ``stepnormalnum : int = 20``

      .. raw:: html

         <i>Normal Smoothing steps</i>: Number of iterations of normal smoothing step. The larger the better and (the slower)

   ``stepfitnum : int = 20``

      .. raw:: html

         <i>Vertex Fitting steps</i>: Number of iterations of the vertex fitting procedure.

   ``selected : bool = false``

      .. raw:: html

         <i>Affect only selected faces</i>: If checked the filter is performed only on the selected faces

.. data:: uniform_mesh_resampling

   *MeshLab filter name*: 'Uniform Mesh Resampling'

   .. raw:: html

      Create a new mesh that is a resampled version of the current one.<br>The resampling is done by building a uniform volumetric representation where each voxel contains the signed distance from the original surface. The resampled surface is reconstructed using the <b>marching cube</b> algorithm over this volume.</p>

   **Parameters:**

   ``cellsize : Percentage = 2%``

      .. raw:: html

         <i>Precision</i>: Size of the cell, the default is 1/50 of the box diag. Smaller cells give better precision at a higher computational cost. Remember that halving the cell size means that you build a volume 8 times larger.

   ``offset : Percentage = 50%``

      .. raw:: html

         <i>Offset</i>: Offset of the created surface (i.e. distance of the created surface from the original one).<br>If offset is zero, the created surface passes on the original mesh itself. Values greater than zero mean an external surface, and lower than zero mean an internal surface.<br> In practice this value is the threshold passed to the Marching Cube algorithm to extract the isosurface from the distance field representation.

   ``mergeclosevert : bool = false``

      .. raw:: html

         <i>Clean Vertices</i>: If true the mesh generated by MC will be cleaned by unifying vertices that are almost coincident

   ``discretize : bool = false``

      .. raw:: html

         <i>Discretize</i>: If true the position of the intersected edge of the marching cube grid is not computed by linear interpolation, but it is placed in fixed middle position. As a consequence the resampled object will look severely aliased by a stairstep appearance.<br>Useful only for simulating the output of 3D printing devices.

   ``multisample : bool = false``

      .. raw:: html

         <i>Multi-sample</i>: If true the distance field is more accurately compute by multisampling the volume (7 sample for each voxel). Much slower but less artifacts.

   ``absdist : bool = false``

      .. raw:: html

         <i>Absolute Distance</i>: If true a <b> not</b> signed distance field is computed. In this case you have to choose a not zero Offset and a double surface is built around the original surface, inside and outside. Is useful to convrt thin floating surfaces into <i> solid, thick meshes.</i>. t

.. data:: unsharp_mask_color

   *MeshLab filter name*: 'UnSharp Mask Color'

   .. raw:: html

      Apply Unsharp filter to the vertex color, putting in more evidence color variations.<br>See <a href='https://en.wikipedia.org/wiki/Unsharp_masking'>Unsharp Masking</a></p>

   **Parameters:**

   ``weight : float = 0.3``

      .. raw:: html

         <i>Unsharp Weight</i>: the unsharp weight <i>w<sub><big>u</big></sub></i> in the unsharp mask equation: <br> <i>w<sub><big>o</big></sub>orig + w<sub><big>u</big></sub> (orig - lowpass)</i><br>

   ``weightorig : float = 1``

      .. raw:: html

         <i>Original Color Weight</i>: How much the original signal is used, e.g. the weight <i>w<sub><big>o</big></sub></i> in the above unsharp mask equation<br> Usually you should not need to change the default 1.0 value.

   ``iterations : int = 5``

      .. raw:: html

         <i>Smooth Iterations</i>: number of iterations of laplacian smooth in every run

.. data:: unsharp_mask_geometry

   *MeshLab filter name*: 'UnSharp Mask Geometry'

   .. raw:: html

      Apply Unsharp filter to geometric shape, putting in more evidence ridges and valleys variations.<br><a href='https://en.wikipedia.org/wiki/Unsharp_masking'>Unsharp Masking</a></p>

   **Parameters:**

   ``weight : float = 0.3``

      .. raw:: html

         <i>Unsharp Weight</i>: the unsharp weight <i>w<sub><big>u</big></sub></i> in the unsharp mask equation: <br> <i>w<sub><big>o</big></sub>orig + w<sub><big>u</big></sub> (orig - lowpass)</i><br>

   ``weightorig : float = 1``

      .. raw:: html

         <i>Original Weight</i>: How much the original signal is used, e.g. the weight <i>w<sub><big>o</big></sub></i> in the above unsharp mask equation<br> Usually you should not need to change the default 1.0 value.

   ``iterations : int = 5``

      .. raw:: html

         <i>Smooth Iterations</i>: number of iterations of laplacian smooth in every run

.. data:: unsharp_mask_normals

   *MeshLab filter name*: 'UnSharp Mask Normals'

   .. raw:: html

      Unsharp mask filtering of the normals per face, putting in more evidence normal variations.<br><b>A simple normal enhancement technique for interactive non-photorealistic renderings</b> by <i>Cignoni, Scopigno and Tarini</i>, Comput Graph, 29 (1) (2005)<br><a href='https://doi.org/10.1016/j.cag.2004.11.012'>doi:10.1016/j.cag.2004.11.012</a></p>

   **Parameters:**

   ``recalc : bool = false``

      .. raw:: html

         <i>Recompute Normals</i>: Recompute normals from scratch before the unsharp masking

   ``weight : float = 0.3``

      .. raw:: html

         <i>Unsharp Weight</i>: the unsharp weight <i>w<sub><big>u</big></sub></i> in the unsharp mask equation: <br> <i>w<sub><big>o</big></sub>orig + w<sub><big>u</big></sub> (orig - lowpass)</i><br>

   ``weightorig : float = 1``

      .. raw:: html

         <i>Original Weight</i>: How much the original signal is used, e.g. the weight <i>w<sub><big>o</big></sub></i> in the above unsharp mask equation.<br> Usually you should not need to change the default 1.0 value.

   ``iterations : int = 5``

      .. raw:: html

         <i>Smooth Iterations</i>: number of laplacian face smooth iterations in every run

.. data:: unsharp_mask_quality

   *MeshLab filter name*: 'UnSharp Mask Quality'

   .. raw:: html

      Apply Unsharp filter to values of <a href='https://stackoverflow.com/questions/58610746'>quality per vertex</a>.<br>See <a href='https://en.wikipedia.org/wiki/Unsharp_masking'>Unsharp Masking</a></p>

   **Parameters:**

   ``weight : float = 0.3``

      .. raw:: html

         <i>Unsharp Weight</i>: the unsharp weight <i>w<sub><big>u</big></sub></i> in the unsharp mask equation: <br> <i>w<sub><big>o</big></sub>orig + w<sub><big>u</big></sub> (orig - lowpass)</i><br>

   ``weightorig : float = 1``

      .. raw:: html

         <i>Original Weight</i>: How much the original signal is used, e.g. the weight <i>w<sub><big>o</big></sub></i> in the above unsharp mask equation<br> Usually you should not need to change the default 1.0 value.

   ``iterations : int = 5``

      .. raw:: html

         <i>Smooth Iterations</i>: number of iterations of laplacian smooth in every run

.. data:: vertex_attribute_seam

   *MeshLab filter name*: 'Vertex Attribute Seam'

   .. raw:: html

      Make all selected vertex attributes connectivity-independent:<br/>vertices are duplicated whenever two or more selected wedge or face attributes do not match.<br/>This is particularly useful for GPU-friendly mesh layout, where a single index must be used to access all required vertex attributes.</p>

   **Parameters:**

   ``normalmode : str = 'None' (or int = 0)``

      Possible enum values:

         0. ``'None'``
         1. ``'Vertex'``
         2. ``'Wedge'``
         3. ``'Face'``

      .. raw:: html

         <i>Normal Source:</i>: Choose a method

   ``colormode : str = 'None' (or int = 0)``

      Possible enum values:

         0. ``'None'``
         1. ``'Vertex'``
         2. ``'Wedge'``
         3. ``'Face'``

      .. raw:: html

         <i>Color Source:</i>: Choose a method

   ``texcoordmode : str = 'None' (or int = 0)``

      Possible enum values:

         0. ``'None'``
         1. ``'Vertex'``
         2. ``'Wedge'``

      .. raw:: html

         <i>Texcoord Source:</i>: Choose a method

.. data:: vertex_attribute_transfer

   *MeshLab filter name*: 'Vertex Attribute Transfer'

   .. raw:: html

      Transfer the chosen per-vertex attributes from one layer to another. Useful to transfer attributes to different representations of a same object.<br>For each vertex of the target mesh the closest point (not vertex!) on the source mesh is computed, and the requested interpolated attributes from that source point are copied into the target vertex.<br>The algorithm assumes that the two meshes are reasonably similar and aligned.</p>

   **Parameters:**

   ``sourcemesh : int = 0``

      .. raw:: html

         <i>Source Mesh</i>: The mesh that contains the source data that we want to transfer.

   ``targetmesh : int = 0``

      .. raw:: html

         <i>Target Mesh</i>: The mesh whose vertices will receive the data from the source.

   ``geomtransfer : bool = false``

      .. raw:: html

         <i>Transfer Geometry</i>: if enabled, the position of each vertex of the target mesh will be snapped onto the corresponding closest point on the source mesh

   ``normaltransfer : bool = false``

      .. raw:: html

         <i>Transfer Normal</i>: if enabled, the normal of each vertex of the target mesh will get the (interpolated) normal of the corresponding closest point on the source mesh

   ``colortransfer : bool = true``

      .. raw:: html

         <i>Transfer Color</i>: if enabled, the color of each vertex of the target mesh will become the color of the corresponding closest point on the source mesh

   ``qualitytransfer : bool = false``

      .. raw:: html

         <i>Transfer quality</i>: if enabled, the quality of each vertex of the target mesh will become the quality of the corresponding closest point on the source mesh

   ``selectiontransfer : bool = false``

      .. raw:: html

         <i>Transfer Selection</i>: if enabled,  each vertex of the target mesh will be selected if the corresponding closest point on the source mesh falls in a selected face

   ``qualitydistance : bool = false``

      .. raw:: html

         <i>Store dist. as quality</i>: if enabled, we store the distance of the transferred value as in the vertex quality

   ``upperbound : Percentage = 2%``

      .. raw:: html

         <i>Max Dist Search</i>: Sample points for which we do not find anything within this distance are rejected and not considered for recovering attributes.

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only transfer to selected vertices on TARGET mesh

.. data:: vertex_color_brightness_contrast_gamma

   *MeshLab filter name*: 'Vertex Color Brightness Contrast Gamma'

   .. raw:: html

      Change the color the vertices of the mesh adjusting brightness, contrast and gamma.</p>

   **Parameters:**

   ``brightness : float (bounded) = 0 [min: -255; max: 255]``

      .. raw:: html

         <i>Brightness:</i>: Sets the amount of brightness that will be added/subtracted to the colors.<br>Brightness = 255  ->  all white;<br>Brightness = -255  ->  all black;

   ``contrast : float (bounded) = 0 [min: -255; max: 255]``

      .. raw:: html

         <i>Contrast factor:</i>: Sets the amount of contrast of the mesh.

   ``gamma : float (bounded) = 1 [min: 0.1; max: 5]``

      .. raw:: html

         <i>Gamma:</i>: Sets the values of the exponent gamma.

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: vertex_color_colourisation

   *MeshLab filter name*: 'Vertex Color Colourisation'

   .. raw:: html

      Allows the application of a color to the mesh. In spite of the Fill operation, the color is blended with the mesh according to a given intensity.</p>

   **Parameters:**

   ``hue : float (bounded) = 0 [min: 0; max: 360]``

      .. raw:: html

         <i>Hue:</i>: Changes the hue of the mesh.

   ``saturation : float (bounded) = 100 [min: 0; max: 100]``

      .. raw:: html

         <i>Saturation:</i>: Changes the saturation of the mesh.

   ``luminance : float (bounded) = 50 [min: 0; max: 100]``

      .. raw:: html

         <i>Luminance:</i>: Changes the luminance of the mesh.

   ``intensity : float (bounded) = 50 [min: 0; max: 100]``

      .. raw:: html

         <i>Blending:</i>: Sets the blending factor used in adding the new color to the existing one.

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: vertex_color_desaturation

   *MeshLab filter name*: 'Vertex Color Desaturation'

   .. raw:: html

      The filter desaturates the colors of the mesh. This provides a simple way to convert a mesh in gray tones. The user can choose the desaturation method to apply; they are based on Lightness, Luminosity and Average.</p>

   **Parameters:**

   ``method : str = 'Lightness' (or int = 0)``

      Possible enum values:

         0. ``'Lightness'``
         1. ``'Luminosity'``
         2. ``'Average'``

      .. raw:: html

         <i>Desaturation method:</i>: Lightness is computed as (Max(r,g,b)+Min(r,g,b))/2<br>Luminosity is computed as 0.212*r + 0.715*g + 0.072*b<br>Average is computed as (r+g+b)/3

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: vertex_color_filling

   *MeshLab filter name*: 'Vertex Color Filling'

   .. raw:: html

      Fills the color of the vertices of the mesh with a color chosen by the user.</p>

   **Parameters:**

   ``color1 : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>Color:</i>: Sets the color to apply to vertices.

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: vertex_color_invert

   *MeshLab filter name*: 'Vertex Color Invert'

   .. raw:: html

      Inverts the colors of the vertices of the mesh.</p>

   **Parameters:**

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: vertex_color_levels_adjustment

   *MeshLab filter name*: 'Vertex Color Levels Adjustment'

   .. raw:: html

      The filter allows adjustment of color levels. It is a custom way to map an interval of color into another one. The user can set the input minimum and maximum levels, gamma and the output minimum and maximum levels (many tools call them respectively input black point, white point, gray point, output black point and white point).</p>

   **Parameters:**

   ``gamma : float (bounded) = 1 [min: 0.1; max: 5]``

      .. raw:: html

         <i>Gamma:</i>:

   ``in_min : float (bounded) = 0 [min: 0; max: 255]``

      .. raw:: html

         <i>Min input level:</i>:

   ``in_max : float (bounded) = 255 [min: 0; max: 255]``

      .. raw:: html

         <i>Max input level:</i>:

   ``out_min : float (bounded) = 0 [min: 0; max: 255]``

      .. raw:: html

         <i>Min output level:</i>:

   ``out_max : float (bounded) = 255 [min: 0; max: 255]``

      .. raw:: html

         <i>Max output level:</i>:

   ``rch : bool = true``

      .. raw:: html

         <i>Red Channel:</i>:

   ``gch : bool = true``

      .. raw:: html

         <i>Green Channel:</i>:

   ``bch : bool = true``

      .. raw:: html

         <i>Blue Channel:</i>:

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

   ``apply_to_all : bool = false``

      .. raw:: html

         <i>All visible layers</i>: if true, apply to all visible layers

.. data:: vertex_color_noise

   *MeshLab filter name*: 'Vertex Color Noise'

   .. raw:: html

      Randomly add a small amount of a random base color to the mesh</p>

   **Parameters:**

   ``basecolor : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>BaseColor</i>: The base color that is added to the mesh.

   ``percentage : float (bounded) = 0.5 [min: 0; max: 1]``

      .. raw:: html

         <i>Alpha</i>: The random color is blended with the current one with the specified alpha

   ``frequency : float (bounded) = 20 [min: 1; max: 200]``

      .. raw:: html

         <i>Noisy Frequency</i>: The frequency of the Noise on the mesh. Higher numbers means smaller spots.

.. data:: vertex_color_thresholding

   *MeshLab filter name*: 'Vertex Color Thresholding'

   .. raw:: html

      Colors the vertices of the mesh using two colors according to a lightness threshold (on the original color).</p>

   **Parameters:**

   ``color1 : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>Color 1:</i>: Sets the color to apply below the threshold.

   ``color2 : Color = [255; 255; 255; 255]``

      .. raw:: html

         <i>Color 2:</i>: Sets the color to apply above the threshold.

   ``threshold : float (bounded) = 128 [min: 0; max: 255]``

      .. raw:: html

         <i>Threshold:</i>: Vertices with color above the lightness threshold becomes Color 2, the others Color 1.

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: vertex_color_white_balance

   *MeshLab filter name*: 'Vertex Color White Balance'

   .. raw:: html

      The filter provides a standard white balance transformation. It is done correcting the RGB channels with a factor such that, the brighter color in the mesh, that is supposed to be white, becomes really white.</p>

   **Parameters:**

   ``color : Color = [255; 255; 255; 255]``

      .. raw:: html

         <i>Unbalanced white: </i>: The color that is supposed to be white.

   ``onselected : bool = false``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: vertex_linear_morphing

   *MeshLab filter name*: 'Vertex Linear Morphing'

   .. raw:: html

      Morph deformation of current mesh towards a target mesh with the same number of vertices and same vertex ordering. Each vertex of the source mesh is linearly interpolated towards the corresponding vertex on the target mesh using the formula:<p align='center'>result<sub><big>i</big></sub> = (1-&lambda;)*source<sub><big>i</big></sub> + &lambda;*target<sub><big>i</big></sub></p><b>Three-dimensional metamorphosis: a survey</b><br>by <i>F. Lazarus and A. Verroust</i>, Visual Computer, 1998<br><a href='https://doi.org/10.1007/s003710050149'>doi:10.1007/s003710050149</a></p>

   **Parameters:**

   ``targetmesh : int = 0``

      .. raw:: html

         <i>Target Mesh</i>: The mesh that is the morph target.

   ``percentmorph : float (bounded) = 0 [min: -150; max: 250]``

      .. raw:: html

         <i>% Morph</i>: The percent you want to morph towards (or away from) the target. <br>0 means current mesh <br>100 means targe mesh <br><0 and >100 linearly extrapolate between the two mesh <br>

.. data:: vertex_quality_from_camera

   *MeshLab filter name*: 'Vertex Quality from Camera'

   .. raw:: html

      Compute vertex quality using the camera definition, according to viewing angle or distance</p>

   **Parameters:**

   ``depth : bool = true``

      .. raw:: html

         <i>Depth</i>: Use depth as a factor.

   ``facing : bool = false``

      .. raw:: html

         <i>ViewAngle</i>: Use cosine of viewing angle as a factor.

   ``clip : bool = false``

      .. raw:: html

         <i>Clipping</i>: clip values outside the viewport to zero.

   ``normalize : bool = false``

      .. raw:: html

         <i>normalize</i>: if checked normalize all quality values in range [0..1]

   ``map : bool = false``

      .. raw:: html

         <i>map into color</i>: if checked map quality generated values into per-vertex color

.. data:: volumetric_obscurance

   *MeshLab filter name*: 'Volumetric obscurance'

   .. raw:: html

      Calculates obscurance coefficients for the mesh. Obscurance is introduced to avoid the disadvantages of both classical ambient term and ambient occlusion. In ambient occlusion, totally occluded parts of the mesh are black. Instead obscurance, despite still based on a perfectly diffuse light coming from everywhere, accounts for multiple bounces of indirect illumination by means of a function of both the openness of a point and the distance to his occluder (if any). Obscurance is inversely proportional to the number of ray casted from the point that hit an occluder and proportional to the distance a ray travels before hitting the occluder. You can control how much the distance factor influences the final result with the obscurance exponenent (see help below). Obscurance is a value in the range [0,1]. For further details see the reference paper:<br><b>Iones Krupkin Sbert Zhukov <br> Fast, Realistic Lighting for Video Games <br>IEEECG&A 2003</b> </p>

   **Parameters:**

   ``onprimitive : str = 'On vertices' (or int = 0)``

      Possible enum values:

         0. ``'On vertices'``
         1. ``'On Faces'``

      .. raw:: html

         <i>Metric:</i>: Choose whether to trace rays from faces or from vertices.

   ``numberrays : int = 128``

      .. raw:: html

         <i>Number of rays: </i>: The number of rays that will be casted around the normals.

   ``depthtexturesize : int = 512``

      .. raw:: html

         <i>Depth texture size</i>: Size of the depth texture for depth peeling. Higher resolutions provide better sampling of the mesh, with a small performance penalty.

   ``peelingiteration : int = 10``

      .. raw:: html

         <i>Peeling Iteration</i>: Number of depth peeling iteration. Actually is the maximum number of layers that a ray can hit while traversing the mesh. For example, in the case of a sphere, you should specify 2 in this parameter. For a torus, specify 4. <b>For more complex geometry you should run the depth complexity filter to know the exact value</b>.

   ``peelingtolerance : float = 1e-07``

      .. raw:: html

         <i>Peeling Tolerance</i>: Depth tolerance used during depth peeling. This is the threshold used to differentiate layers between each others.Two elements whose distance is below this value will be considered as belonging to the same layer.

   ``coneangle : float = 120``

      .. raw:: html

         <i>Cone amplitude</i>: Cone amplitude around normals in degrees. Rays are traced within this cone.

   ``obscuranceexponent : float = 0.1``

      .. raw:: html

         <i>Obscurance Exponent</i>: This parameter controls the spatial decay term in the obscurance formula. The greater the exponent, the greater the influence of distance; that is: even if a ray is blocked by an occluder its contribution to the obscurance term is non zero, but proportional to this parameter. It turs out that if you choose a value of zero, you get the standard ambient occlusion term. <b>(In this case, only a value of two, in the peeling iteration parameter, has a sense)</b>

.. data:: volumetric_sampling

   *MeshLab filter name*: 'Volumetric Sampling'

   .. raw:: html

      Compute a volumetric sampling over a watertight mesh.</p>

   **Parameters:**

   ``samplesurfradius : Percentage = 0.2%``

      .. raw:: html

         <i>Surface Sampling Radius</i>: Surface Sampling is used only as an optimization.

   ``samplevolnum : int = 200000``

      .. raw:: html

         <i>Volume Sample Num.</i>: Number of volumetric samples scattered inside the mesh and used for choosing the voronoi seeds and performing the Lloyd relaxation for having a centroidal voronoi diagram.

   ``poissonfiltering : bool = true``

      .. raw:: html

         <i>Poisson Filtering</i>: If true the base montecarlo sampling of the volume is filtered to get a poisson disk volumetric distribution.

   ``poissonradius : Percentage = 1%``

      .. raw:: html

         <i>Poisson Radius</i>: Number of voxel per side in the volumetric representation.

.. data:: voronoi_filtering

   *MeshLab filter name*: 'Voronoi Filtering'

   .. raw:: html

      Compute a <b>Voronoi filtering</b> (Amenta and Bern 1998) with Qhull library (http://www.qhull.org/). <br><br>The algorithm calculates a triangulation of the input point cloud without requiring vertex normals.It uses a subset of the Voronoi vertices to remove triangles from the Delaunay triangulation. <br>After computing the Voronoi diagram, foreach sample point it chooses the two farthest opposite Voronoi vertices.Then computes a Delaunay triangulation of the sample points and the selected Voronoi vertices, and keep only those triangles in witch all three vertices are sample points.</p>

   **Parameters:**

   ``threshold : float (bounded) = 10 [min: 0; max: 2000]``

      .. raw:: html

         <i>Pole Discard Thr</i>: Threshold used to discard the Voronoi vertices too far from the origin.We discard vertices are further than this factor times the bbox diagonal <br>Growing values of this value will add more Voronoi vertices for a better tightier surface reconstruction.On the other hand they will increase processing time and could cause numerical problems to the qhull library.<br>

.. data:: voronoi_sampling

   *MeshLab filter name*: 'Voronoi Sampling'

   .. raw:: html

      Compute a sampling over a mesh and perform a Lloyd relaxation.</p>

   **Parameters:**

   ``iternum : int = 10``

      .. raw:: html

         <i>Iteration</i>: number of iterations

   ``samplenum : int = 10``

      .. raw:: html

         <i>Sample Num.</i>: Number of samples

   ``radiusvariance : float = 1``

      .. raw:: html

         <i>Radius Variance</i>: The distance metric will vary along the surface between 1/x and x, linearly according to the scalar field specified by the quality.

   ``colorstrategy : str = 'Seed Distance' (or int = 1)``

      Possible enum values:

         0. ``'None'``
         1. ``'Seed Distance'``
         2. ``'Border Distance'``
         3. ``'Region Area'``

      .. raw:: html

         <i>Color Strategy</i>:

   ``distancetype : str = 'Euclidean' (or int = 0)``

      Possible enum values:

         0. ``'Euclidean'``
         1. ``'Quality Weighted'``
         2. ``'Anisotropic'``

      .. raw:: html

         <i>Distance Type</i>:

   ``preprocessflag : bool = false``

      .. raw:: html

         <i>Preprocessing</i>:

   ``refinefactor : int = 10``

      .. raw:: html

         <i>Refinement Factor</i>: To ensure good convergence the mesh should be more complex than the voronoi partitioning. This number affect how much the mesh is refined according to the required number of samples.

   ``perturbprobability : float = 0``

      .. raw:: html

         <i>Perturbation Probability</i>: To ensure good convergence the mesh should be more complex than the voronoi partitioning. This number affect how much the mesh is refined according to the required number of samples.

   ``perturbamount : float = 0.001``

      .. raw:: html

         <i>Perturbation Amount</i>: To ensure good convergence the mesh should be more complex than the voronoi partitioning. This number affect how much the mesh is refined according to the required number of samples.

   ``randomseed : int = 0``

      .. raw:: html

         <i>Random seed</i>: To ensure repeatability you can specify the random seed used. If 0 the random seed is tied to the current clock.

   ``relaxtype : str = 'Squared Distance' (or int = 1)``

      Possible enum values:

         0. ``'Geodesic'``
         1. ``'Squared Distance'``
         2. ``'Restricted'``

      .. raw:: html

         <i>Relax Type</i>: At each relaxation step we search for each voronoi region the new position of the seed. According to the classical LLoyd relaxation strategy it should have been placed onto the barycenter of the region. Over a surface we have two different strategies: <ul><li> Geodesic: the seed is placed onto the vertex that maximize the geodesic distance from the border of the region </li><li> Squared Distance: the seed is placed in the vertex that minimize the squared sum of the distances from all the pints of the region.</li><li> Restricted: the seed is placed in the barycenter of current voronoi region. Even if it is outside the surface. During the relaxation process the seed is free to move off the surface in a continuous way. Re-association to vertex is done at the end..</li></ul>

.. data:: voronoi_scaffolding

   *MeshLab filter name*: 'Voronoi Scaffolding'

   .. raw:: html

      Compute a volumetric sampling over a watertight mesh.</p>

   **Parameters:**

   ``samplesurfradius : Percentage = 1%``

      .. raw:: html

         <i>Surface Sampling Radius</i>: Surface Sampling is used only as an optimization.

   ``samplevolnum : int = 100000``

      .. raw:: html

         <i>Volume Sample Num.</i>: Number of volumetric samples scattered inside the mesh and used for choosing the voronoi seeds and performing the Lloyd relaxation for having a centroidal voronoi diagram.

   ``voxelres : int = 50``

      .. raw:: html

         <i>Volume Side Resolution</i>: Number of voxel per side in the volumetric representation.

   ``isothr : float = 1``

      .. raw:: html

         <i>Width of the entity (in voxel)</i>: Number of voxel per side in the volumetric representation.

   ``smoothstep : int = 3``

      .. raw:: html

         <i>Smooth Step</i>: Number of voxel per side in the volumetric representation.

   ``relaxstep : int = 5``

      .. raw:: html

         <i>Lloyd Relax Step</i>: Number of Lloyd relaxation step to get a better distribution of the voronoi seeds.

   ``surfflag : bool = true``

      .. raw:: html

         <i>Add original surface</i>: Number of voxel per side in the volumetric representation.

   ``elemtype : str = 'Edge' (or int = 1)``

      Possible enum values:

         0. ``'Seed'``
         1. ``'Edge'``
         2. ``'Face'``

      .. raw:: html

         <i>Voronoi Element</i>:

.. data:: voronoi_vertex_coloring

   *MeshLab filter name*: 'Voronoi Vertex Coloring'

   .. raw:: html

      Given a Mesh <b>M</b> and a Pointset <b>P</b>, The filter project each vertex of P over M and color M according to the geodesic distance from these projected points. Projection and coloring are done on a per vertex basis.</p>

   **Parameters:**

   ``coloredmesh : int = 0``

      .. raw:: html

         <i>To be Colored Mesh</i>: The mesh whose surface is colored. For each vertex of this mesh we decide the color according the below parameters.

   ``vertexmesh : int = 0``

      .. raw:: html

         <i>Vertex Mesh</i>: The mesh whose vertices are used as seed points for the color computation. These seeds point are projected onto the above mesh.

   ``backward : bool = false``

      .. raw:: html

         <i>BackDistance</i>: If true the mesh is colored according the distance from the frontier of the voonoi diagram induced by the VertexMesh seeds.

load parameters
---------------

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

   ``triangulate : bool = true``

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

   ``pointsonly : bool = false``

      .. raw:: html

         <i>only import points</i>: Just import points, without triangulation

   ``unify : bool = true``

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

   ``usecolors : bool = true``

      .. raw:: html

         <i>Use Atoms colors</i>: Atoms are colored according to atomic type

   ``justpoints : bool = false``

      .. raw:: html

         <i>SURFACE: Atoms as Points</i>: Atoms are created as points, no surface is built. Overrides all subsequential surface parameters

   ``justspheres : bool = true``

      .. raw:: html

         <i>SURFACE: Atoms as Spheres</i>: Atoms are created as intersecting spheres, no interpolation surface is built. Overrides all subsequential surface parameters

   ``interpspheres : bool = false``

      .. raw:: html

         <i>SURFACE: Atoms as Jointed Spheres</i>: Atoms are created as spheres, joining surface is built. Overrides all subsequential surface parameters

   ``metaballs : bool = false``

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

   ``pointsonly : bool = true``

      .. raw:: html

         <i>Keep only points</i>: Import points a point cloud only, with radius and normals, no triangulation involved, isolated points and points with normals with steep angles are removed.

   ``usecolor : bool = true``

      .. raw:: html

         <i>import color</i>: Read color from PTX, if color is not present, uses reflectance instead

   ``flipfaces : bool = false``

      .. raw:: html

         <i>LEICA: flip normal direction</i>: LEICA PTX exporter goes counterclockwise, FARO PTX exporter goes clockwise

   ``pointcull : bool = true``

      .. raw:: html

         <i>delete unsampled points</i>: Deletes unsampled points in the grid that are normally located in [0,0,0]

   ``anglecull : bool = true``

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

   ``meshlabiostlunifyvertices : bool = true``

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

save parameters
---------------

Here are listed all the file formats that can be saved usingthe function :py:meth:`pmeshlab.MeshSet.save_current_mesh`, with all the possible parameters that can be accepted by these functions.

.. data:: 3ds
   :noindex:

   .. raw:: html

      Save 3ds format.</p>

   **Parameters:**

   ``file_name : str = 'file_name.3ds'``

      .. raw:: html

         <i>File Name</i>: The name of the file to save

   ``save_face_color : bool = true``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_face_normal : bool = true``

      .. raw:: html

         <i>Save Face Normal</i>: Save Face Normal

   ``save_wedge_texcoord : bool = true``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = true``

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

   ``lossless : bool = false``

      .. raw:: html

         <i>LossLess compression</i>: If true it does not apply any lossy compression technique.

   ``relativeprecisionparam : float = 0.0001``

      .. raw:: html

         <i>Relative Coord Precision</i>: When using a lossy compression this number control the introduced error and hence the compression factor.It is a number relative to the average edge length. (e.g. the default means that the error should be roughly 1/10000 of the average edge length)

   ``save_vertex_quality : bool = true``

      .. raw:: html

         <i>Save Vertex Quality</i>: Save Vertex Quality

   ``save_vertex_color : bool = true``

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

   ``save_vertex_color : bool = true``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = true``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = true``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_wedge_texcoord : bool = true``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = true``

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

   ``position_val : numpy.ndarray[numpy.float32[3]] = [0, 0, -3.4641]``

      .. raw:: html

         <i>Camera Position</i>: The position in which the camera is set. The default value is derived by the 3d mesh's bounding box.

   ``target_val : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Camera target point</i>: The point towards the camera is seeing. The default value is derived by the 3d mesh's bounding box.

   ``fov_val : float = 60``

      .. raw:: html

         <i>Camera's FOV Angle 0..180</i>: Camera's FOV Angle. The values' range is between 0-180 degree. The default value is 60.

   ``compression_val : int = 500``

      .. raw:: html

         <i>U3D quality 0..1000</i>: U3D mesh's compression ratio. The values' range is between 0-1000 degree. The default value is 500.

   ``save_vertex_color : bool = false``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_normal : bool = false``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_face_color : bool = false``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_wedge_texcoord : bool = true``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = true``

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

   ``save_vertex_color : bool = true``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = true``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = true``

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

   ``save_vertex_color : bool = true``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = true``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = true``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_face_color : bool = true``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_wedge_texcoord : bool = true``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = true``

      .. raw:: html

         <i>Save Wedge Normal</i>: Save Wedge Normal

   ``save_polygonal : bool = true``

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

   ``save_vertex_color : bool = true``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = true``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_face_color : bool = true``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_polygonal : bool = true``

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

   ``binary : bool = true``

      .. raw:: html

         <i>Binary encoding</i>: Save the mesh using a binary encoding. If false the mesh is saved in a plain, readable ascii format.

   ``save_vertex_quality : bool = true``

      .. raw:: html

         <i>Save Vertex Quality</i>: Save Vertex Quality

   ``save_vertex_flag : bool = false``

      .. raw:: html

         <i>Save Vertex Flag</i>: Save Vertex Flag

   ``save_vertex_color : bool = true``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = true``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = false``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_vertex_radius : bool = true``

      .. raw:: html

         <i>Save Vertex Radius</i>: Save Vertex Radius

   ``save_face_quality : bool = true``

      .. raw:: html

         <i>Save Face Quality</i>: Save Face Quality

   ``save_face_flag : bool = false``

      .. raw:: html

         <i>Save Face Flag</i>: Save Face Flag

   ``save_face_color : bool = true``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_wedge_color : bool = true``

      .. raw:: html

         <i>Save Wedge Color</i>: Save Wedge Color

   ``save_wedge_texcoord : bool = true``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = true``

      .. raw:: html

         <i>Save Wedge Normal</i>: Save Wedge Normal

   ``save_polygonal : bool = true``

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

   ``binary : bool = true``

      .. raw:: html

         <i>Binary encoding</i>: Save the mesh using a binary encoding. If false the mesh is saved in a plain, readable ascii format.

   ``colormode : bool = true``

      .. raw:: html

         <i>Materialise Color Encoding</i>: Save the color using a binary encoding according to the Materialise's Magic style (e.g. RGB coding instead of BGR coding).

   ``save_face_color : bool = true``

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

   ``position_val : numpy.ndarray[numpy.float32[3]] = [0, 0, -3.4641]``

      .. raw:: html

         <i>Camera Position</i>: The position in which the camera is set. The default value is derived by the 3d mesh's bounding box.

   ``target_val : numpy.ndarray[numpy.float32[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Camera target point</i>: The point towards the camera is seeing. The default value is derived by the 3d mesh's bounding box.

   ``fov_val : float = 60``

      .. raw:: html

         <i>Camera's FOV Angle 0..180</i>: Camera's FOV Angle. The values' range is between 0-180 degree. The default value is 60.

   ``compression_val : int = 500``

      .. raw:: html

         <i>U3D quality 0..1000</i>: U3D mesh's compression ratio. The values' range is between 0-1000 degree. The default value is 500.

   ``save_vertex_color : bool = false``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_face_color : bool = false``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_wedge_texcoord : bool = true``

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

   ``save_vertex_color : bool = true``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_wedge_color : bool = true``

      .. raw:: html

         <i>Save Wedge Color</i>: Save Wedge Color

   ``save_wedge_texcoord : bool = true``

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

   ``save_vertex_color : bool = true``

      .. raw:: html

         <i>Save Vertex Color</i>: Save Vertex Color

   ``save_vertex_coord : bool = true``

      .. raw:: html

         <i>Save Vertex Coord</i>: Save Vertex Coord

   ``save_vertex_normal : bool = true``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

   ``save_face_color : bool = false``

      .. raw:: html

         <i>Save Face Color</i>: Save Face Color

   ``save_face_normal : bool = false``

      .. raw:: html

         <i>Save Face Normal</i>: Save Face Normal

   ``save_wedge_color : bool = false``

      .. raw:: html

         <i>Save Wedge Color</i>: Save Wedge Color

   ``save_wedge_texcoord : bool = false``

      .. raw:: html

         <i>Save Wedge TexCoord</i>: Save Wedge TexCoord

   ``save_wedge_normal : bool = false``

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

   ``save_vertex_normal : bool = true``

      .. raw:: html

         <i>Save Vertex Normal</i>: Save Vertex Normal

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
