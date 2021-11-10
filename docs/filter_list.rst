.. _filter_list:

List of Filters
===============

Here are listed all the filter names that can be given as a parameter to the function :py:meth:`pmeshlab.MeshSet.apply_filter`.

Each filter accepts a list of parameters, that can be semantically classified as follows:

   * `Boolean`: a classic ``bool`` value;
   * `Integer`: a classic ``int`` value;
   * `String`: a classic ``str`` value;
   * `Float`: a classic ``float`` value;
   * `Bounded Float`: a classic ``float`` that is expected to be bounded between a ``min`` and a ``max`` value; an out-of-bounds value will raise an exception;
   * `Percentage`: represents a parameter that is relative to some other measure, specified in the documentation of the filter. This parameter can be of two different types:

     * :py:class:`pmeshlab.Percentage` (recommended): the parameter will be treated as relative percentage value; see the documentation of the :py:class:`pmeshlab.Percentage` for further info;
     * :py:class:`pmeshlab.AbsoluteValue`: the parameter will be treated as absolute value; see the documentation of the :py:class:`pmeshlab.AbsoluteValue` for further info;

   * `Enum`: represents a parameter that can accept just one of a limited set of possible values. These values type can be ``int`` or ``str``; see the documentation of the specific filter for further info;
   * `Color`: represents a color, and the parameter can be of type  :py:class:`pmeshlab.Color`; see the documentation of the  :py:class:`pmeshlab.Color` for further info;
   * `3D Point (or 3D Vector)`: represents a 3D point or vector, and the parameter can be of type ``numpy.ndarray[numpy.float64[3]]`` (a numpy array containing three floats);
   * `4x4 Matrix`: represents a 4x4 Matrix of floats, and the parameter can be of type ``numpy.ndarray[numpy.float64[4, 4]]`` (a 4x4 numpy array of floats);
   * `Mesh`: represents a parameter that links to one of the meshes contained in the MeshSet on which the filter is applied. This parameter is of type ``int``, which indicates the ``id`` of the mesh in the MeshSet;
   * `File Name`: a classic ``str`` that represents the path of a file that is going to be saved or loaded by the filter. The string is expected to have at least an extension on its final characters; see the documentation of the specific filter for further info;
   * `Camera`: *still not supported*;

The :py:meth:`pmeshlab.MeshSet.apply_filter` returns a dictionary that may contain some values returned by the applied filter. Most of the filters do not return nothing, therefore the dictionary will be empty.

**Please note**: some filter parameters depend on the mesh(es) used as input of the filter. Default values listed here are computed on a 1x1x1 cube (pymeshlab/tests/sample/cube.obj), but their value will be computed on the input mesh if they are left as default.

Filter documentation
----------------------

.. data:: apply_cameras_extrinsics_transformation

   *MeshLab filter name*: 'Transform the camera extrinsics, or all the cameras of the project'

   .. raw:: html

      Transform the camera extrinsics, or all the cameras of the project.</p>

   **Parameters:**

   ``transformmatrix : numpy.ndarray[numpy.float64[4, 4]] = [[1, 0, 0, 0],[0, 1, 0, 0],[0, 0, 1, 0],[0, 0, 0, 1]]``

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

   ``toallraster : bool = False``

      .. raw:: html

         <i>Apply to all active Raster layers</i>: Apply the same scaling to all the active Raster layers: it is taken into account only if 'Raster Camera' is selected

   ``toall : bool = False``

      .. raw:: html

         <i>Apply to all active Raster and visible Mesh layers</i>: Apply the same scaling to all the layers, including any visible 3D layer

.. data:: apply_cameras_rotation

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

   ``customaxis : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom axis</i>: This rotation axis is used only if the 'custom axis' option is chosen.

   ``customcenter : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom center</i>: This rotation center is used only if the 'custom point' option is chosen.

   ``toallraster : bool = False``

      .. raw:: html

         <i>Apply to all active Raster layers</i>: Apply the same scaling to all the active Raster layers: it is taken into account only if 'Raster Camera' is selected

   ``toall : bool = False``

      .. raw:: html

         <i>Apply to all active Raster and visible Mesh layers</i>: Apply the same scaling to all the layers, including any visible 3D layer

.. data:: apply_cameras_scaling

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

   ``customcenter : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom center</i>: This scaling center is used only if the 'custom point' option is chosen.

   ``scale : float = 1``

      .. raw:: html

         <i>Scale factor</i>: The scale factor that has to be applied to the camera

   ``toallraster : bool = False``

      .. raw:: html

         <i>Apply to all active Raster layers</i>: Apply the same scaling to all the active Raster layers: it is taken into account only if 'Raster Camera' is selected

   ``toall : bool = False``

      .. raw:: html

         <i>Apply to all active Raster and visible Mesh layers</i>: Apply the same scaling to all the layers, including any visible 3D layer

.. data:: apply_cameras_translation

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

   ``centerflag : bool = False``

      .. raw:: html

         <i>translate viewpoint position to the origin</i>: If selected, the camera viewpoint is translated to the origin

   ``toallraster : bool = False``

      .. raw:: html

         <i>Apply to all active Raster layers</i>: Apply the same scaling to all the active Raster layers: it is taken into account only if 'Raster Camera' is selected

   ``toall : bool = False``

      .. raw:: html

         <i>Apply to all active Raster and Mesh layers</i>: Apply the same scaling to all the layers, including any visible 3D layer

.. data:: apply_color_brightness_contrast_gamma_per_vertex

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

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: apply_color_desaturation_per_vertex

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

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: apply_color_equalization_per_vertex

   *MeshLab filter name*: 'Equalize Vertex Color'

   .. raw:: html

      The filter equalizes the colors histogram. It is a kind of automatic regulation of contrast; the colors histogram is expanded to fit all the range of colors.</p>

   **Parameters:**

   ``rch : bool = True``

      .. raw:: html

         <i>Red Channel:</i>: Select the red channel.

   ``gch : bool = True``

      .. raw:: html

         <i>Green Channel:</i>: Select the green channel.

   ``bch : bool = True``

      .. raw:: html

         <i>Blue Channel:</i>: Select the blue channel.<br><br>If no channel is selected<br>filter works on Lightness.

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: apply_color_intensity_colourisation_per_vertex

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

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: apply_color_inverse_per_vertex

   *MeshLab filter name*: 'Vertex Color Invert'

   .. raw:: html

      Inverts the colors of the vertices of the mesh.</p>

   **Parameters:**

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: apply_color_laplacian_smoothing_per_face

   *MeshLab filter name*: 'Smooth: Laplacian Face Color'

   .. raw:: html

      Laplacian Smooth Face Color</p>

   **Parameters:**

   ``iteration : int = 1``

      .. raw:: html

         <i>Iteration</i>: the number of iteration of the smoothing algorithm

.. data:: apply_color_laplacian_smoothing_per_vertex

   *MeshLab filter name*: 'Smooth: Laplacian Vertex Color'

   .. raw:: html

      Laplacian Smooth Vertex Color</p>

   **Parameters:**

   ``iteration : int = 1``

      .. raw:: html

         <i>Iteration</i>: the number of iteration of the smoothing algorithm

.. data:: apply_color_level_adjustment_per_vertex

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

   ``rch : bool = True``

      .. raw:: html

         <i>Red Channel:</i>: 

   ``gch : bool = True``

      .. raw:: html

         <i>Green Channel:</i>: 

   ``bch : bool = True``

      .. raw:: html

         <i>Blue Channel:</i>: 

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

   ``apply_to_all : bool = False``

      .. raw:: html

         <i>All visible layers</i>: if true, apply to all visible layers

.. data:: apply_color_noising_per_vertex

   *MeshLab filter name*: 'Color noise'

   .. raw:: html

      Adds to the color the requested amount of bits of noise. Bits of noise are added independently for each RGB channel.</p>

   **Parameters:**

   ``noisebits : int = 1``

      .. raw:: html

         <i>Noise bits:</i>: Bits of noise added to each RGB channel. Example: 3 noise bits adds three random offsets in the [-4,+4] interval to each RGB channels.

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: apply_color_thresholding_per_vertex

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

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: apply_color_unsharp_mask_per_vertex

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

.. data:: apply_color_white_balance_per_vertex

   *MeshLab filter name*: 'Vertex Color White Balance'

   .. raw:: html

      The filter provides a standard white balance transformation. It is done correcting the RGB channels with a factor such that, the brighter color in the mesh, that is supposed to be white, becomes really white.</p>

   **Parameters:**

   ``color : Color = [255; 255; 255; 255]``

      .. raw:: html

         <i>Unbalanced white: </i>: The color that is supposed to be white.

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: apply_coord_craters_from_point_cloud

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

   ``successiveimpacts : bool = True``

      .. raw:: html

         <i>Successive impacts</i>: If not checked, the impact-effects of generated craters will be superimposed with each other.

   ``ppnoise : bool = True``

      .. raw:: html

         <i>Postprocessing noise</i>: Slightly perturbates the craters with a noise function.

   ``invert : bool = False``

      .. raw:: html

         <i>Invert perturbation</i>: If checked, inverts the sign of radial perturbation to create bumps instead of craters.

   ``save_as_quality : bool = False``

      .. raw:: html

         <i>Save as vertex quality</i>: Saves the perturbation as vertex quality.

.. data:: apply_coord_depth_smoothing

   *MeshLab filter name*: 'Depth Smooth'

   .. raw:: html

      A laplacian smooth that is constrained to move vertices only in one given direction (usually the viewer direction).</p>

   **Parameters:**

   ``stepsmoothnum : int = 3``

      .. raw:: html

         <i>Smoothing steps</i>: The number of times that the whole algorithm (normal smoothing + vertex fitting) is iterated.

   ``viewpoint : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Viewpoint</i>: The position of the view point that is used to get the constraint direction.

   ``delta : Percentage = 100%``

      .. raw:: html

         <i>Strength</i>: How much smoothing is applied: 0 (no smooth) e 1 (full smooth)

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selection</i>: If checked the filter is performed only on the selected area

.. data:: apply_coord_directional_preservation

   *MeshLab filter name*: 'Directional Geometry Preservation'

   .. raw:: html

      Blend through a given direction the geometry previously stored in a per vertex custom point attribute with the current geometry. This is useful to limit the influence of any smoothing algorithm along the viewing direction. This is useful to cope with the biased distribution of measuring error in many scanning devices, because TOF scanners usually have very good <i>x,y</i> accuracy but suffer of greater depth errors.</p>

   **Parameters:**

   ``attr_name : str = ''``

      .. raw:: html

         <i>Custom attribute name</i>: The name of the per vertex custom point attribute that contains the previous geometry.

   ``viewpoint : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Viewpoint</i>: The position of the view point that is used to get the constraint direction.

.. data:: apply_coord_fractal_displacement

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

   ``saveasquality : bool = False``

      .. raw:: html

         <i>Save as vertex quality</i>: Saves the perturbation value as vertex quality.

.. data:: apply_coord_hc_laplacian_smoothing

   *MeshLab filter name*: 'HC Laplacian Smooth'

   .. raw:: html

      HC Laplacian Smoothing. Extended version of Laplacian Smoothing based on the article: <br><b>Improved Laplacian Smoothing of Noisy Surface Meshes</b> by <i>Vollmer, Mencl and Müller</i>. EUROGRAPHICS Volume 18 (1999), Number 3, 131-138.<br><a href='https://doi.org/10.1111/1467-8659.00334'>doi:10.1111/1467-8659.00334</a></p>

.. data:: apply_coord_laplacian_smoothing

   *MeshLab filter name*: 'Laplacian Smooth'

   .. raw:: html

      Laplacian smooth. Average each vertex position with weighted positions of neighbour vertices.<br><b>Laplacian Mesh Processing</b> by <i>Olga Sorkine</i>. EUROGRAPHICS 2005<br><a href='http://dx.doi.org/10.2312/egst.20051044'>doi:10.2312/egst.20051044</a></p>

   **Parameters:**

   ``stepsmoothnum : int = 3``

      .. raw:: html

         <i>Smoothing steps</i>: The number of times that the whole algorithm (normal smoothing + vertex fitting) is iterated.

   ``boundary : bool = True``

      .. raw:: html

         <i>1D Boundary Smoothing</i>: Smooth boundary edges only by themselves (e.g. the polyline forming the boundary of the mesh is independently smoothed). This can reduce the shrinking on the border but can have strange effects on very small boundaries.

   ``cotangentweight : bool = True``

      .. raw:: html

         <i>Cotangent weighting</i>: Use cotangent weighting scheme for the averaging of the position. Otherwise the simpler umbrella scheme (1 if the edge is present) is used.

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selection</i>: If checked the filter is performed only on the selected area

.. data:: apply_coord_laplacian_smoothing_scale_dependent

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

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selected faces</i>: If checked the filter is performed only on the selected faces

.. data:: apply_coord_laplacian_smoothing_surface_preserving

   *MeshLab filter name*: 'Laplacian Smooth (surface preserving)'

   .. raw:: html

      Laplacian smooth with limited surface modification: move each vertex in the average position of neighbors vertices, only if the new position still (almost) lies on original surface</p>

   **Parameters:**

   ``selection : bool = False``

      .. raw:: html

         <i>Update selection</i>: Apply laplacian smooth on selected faces only

   ``angledeg : float = 0.5``

      .. raw:: html

         <i>Max Normal Dev (deg)</i>: maximum mean normal angle displacement (degrees) from old to new faces

   ``iterations : int = 1``

      .. raw:: html

         <i>Iterations</i>: number of laplacian smooth iterations in every run

.. data:: apply_coord_point_cloud_movement_over_mesh

   *MeshLab filter name*: 'Points Cloud Movement'

   .. raw:: html

      Simulate the movement of a point cloud over a mesh</p>

   **Parameters:**

   ``point_cloud : int = 0``

      .. raw:: html

         <i>Point cloud</i>: The point cloud that will be moved over the target mesh.

   ``target_mesh : int = 0``

      .. raw:: html

         <i>Target mesh</i>: Target mesh on which the point cloud will be moved.

   ``gravity_dir : numpy.ndarray[numpy.float64[3]] = [0, -1, 0]``

      .. raw:: html

         <i>g</i>: Direction of gravity

   ``force_dir : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

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

   ``colorize_mesh : bool = False``

      .. raw:: html

         <i>Map to Color</i>: Color the mesh with colors based on the movement of the particle

.. data:: apply_coord_random_displacement

   *MeshLab filter name*: 'Random Vertex Displacement'

   .. raw:: html

      Move the vertices of the mesh of a random quantity.</p>

   **Parameters:**

   ``updatenormals : bool = True``

      .. raw:: html

         <i>Recompute normals</i>: Toggle the recomputation of the normals after the random displacement.<br><br>If disabled the face normals will remains unchanged resulting in a visually pleasant effect.

   ``displacement : Percentage = 1%``

      .. raw:: html

         <i>Max displacement</i>: The vertex are displaced of a vector whose norm is bounded by this value

.. data:: apply_coord_taubin_smoothing

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

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selected faces</i>: If checked the filter is performed only on the selected faces

.. data:: apply_coord_two_steps_smoothing

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

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selected faces</i>: If checked the filter is performed only on the selected faces

.. data:: apply_coord_unsharp_mask

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

.. data:: apply_matrix_flip_or_swap_axis

   *MeshLab filter name*: 'Transform: Flip and/or swap axis'

   .. raw:: html

      Generate a matrix transformation that flips each one of the axis or swaps a couple of axis. The listed transformations are applied in that order. This kind of transformation cannot be applied to set of Raster!</p>

   **Parameters:**

   ``flipx : bool = False``

      .. raw:: html

         <i>Flip X axis</i>: If selected the axis will be swapped (mesh mirrored along the YZ plane

   ``flipy : bool = False``

      .. raw:: html

         <i>Flip Y axis</i>: If selected the axis will be swapped (mesh mirrored along the XZ plane

   ``flipz : bool = False``

      .. raw:: html

         <i>Flip Z axis</i>: If selected the axis will be swapped (mesh mirrored along the XY plane

   ``swapxy : bool = False``

      .. raw:: html

         <i>Swap X-Y axis</i>: If selected the two axis will be swapped. All the swaps are performed in this order

   ``swapxz : bool = False``

      .. raw:: html

         <i>Swap X-Z axis</i>: If selected the two axis will be swapped. All the swaps are performed in this order

   ``swapyz : bool = False``

      .. raw:: html

         <i>Swap Y-Z axis</i>: If selected the two axis will be swapped. All the swaps are performed in this order

   ``freeze : bool = True``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: apply_matrix_freeze

   *MeshLab filter name*: 'Matrix: Freeze Current Matrix'

   .. raw:: html

      Freeze the current transformation matrix into the coordinates of the vertices of the mesh (and set this matrix to the identity). In other words it applies in a definetive way the current matrix to the vertex coordinates.</p>

   **Parameters:**

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: apply_matrix_inverse

   *MeshLab filter name*: 'Matrix: Invert Current Matrix'

   .. raw:: html

      Invert the current transformation matrix. The current transformation is reversed, becoming its opposite.</p>

   **Parameters:**

   ``freeze : bool = True``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: apply_normal_normalization_per_face

   *MeshLab filter name*: 'Normalize Face Normals'

   .. raw:: html

      Normalize Face Normal Lengths to unit vectors.</p>

.. data:: apply_normal_normalization_per_vertex

   *MeshLab filter name*: 'Normalize Vertex Normals'

   .. raw:: html

      Normalize Vertex Normal Lengths to unit vectors.</p>

.. data:: apply_normal_point_cloud_smoothing

   *MeshLab filter name*: 'Smooth normals on point sets'

   .. raw:: html

      Smooth the normals of the vertices of a mesh without exploiting the triangle connectivity, useful for dataset with no faces</p>

   **Parameters:**

   ``k : int = 10``

      .. raw:: html

         <i>Number of neighbors</i>: The number of neighbors used to smooth normals.

   ``usedist : bool = False``

      .. raw:: html

         <i>Weight using neighbour distance</i>: If selected, the neighbour normals are waighted according to their distance

.. data:: apply_normal_smoothing_per_face

   *MeshLab filter name*: 'Smooth Face Normals'

   .. raw:: html

      Laplacian smooth of the face normals, without touching the position of the vertices.</p>

.. data:: apply_normal_unsharp_mask_per_vertex

   *MeshLab filter name*: 'UnSharp Mask Normals'

   .. raw:: html

      Unsharp mask filtering of the normals per face, putting in more evidence normal variations.<br><b>A simple normal enhancement technique for interactive non-photorealistic renderings</b> by <i>Cignoni, Scopigno and Tarini</i>, Comput Graph, 29 (1) (2005)<br><a href='https://doi.org/10.1016/j.cag.2004.11.012'>doi:10.1016/j.cag.2004.11.012</a></p>

   **Parameters:**

   ``recalc : bool = False``

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

.. data:: apply_scalar_clamping_per_vertex

   *MeshLab filter name*: 'Clamp Vertex Quality'

   .. raw:: html

      Clamp vertex quality values to a given range according to specific values or to percentiles</p>

   **Parameters:**

   ``minval : float = 0``

      .. raw:: html

         <i>Min</i>: The value that will be mapped with the lower end of the scale (red)

   ``maxval : float = 0``

      .. raw:: html

         <i>Max</i>: The value that will be mapped with the upper end of the scale (blue)

   ``perc : float (bounded) = 0 [min: 0; max: 100]``

      .. raw:: html

         <i>Percentile Crop [0..100]</i>: If not zero this value will be used for a percentile cropping of the quality values.<br> If this parameter is set to a value <i>P</i> then the two values <i>V_min,V_max</i> for which <i>P</i>% of the vertices have a quality <b>lower or greater</b> than <i>V_min,V_max</i> are used as min/max values for clamping.<br><br> The automated percentile cropping is very useful for automatically discarding outliers.

   ``zerosym : bool = False``

      .. raw:: html

         <i>Zero Symmetric</i>: If true the min max range will be enlarged to be symmetric (so that green is always Zero)

.. data:: apply_scalar_saturation_per_vertex

   *MeshLab filter name*: 'Saturate Vertex Quality'

   .. raw:: html

      Saturate vertex quality, so that for each vertex the gradient of the quality is lower than the given threshold value (in absolute value)<br>The saturation is done in a conservative way (quality is always decreased and never increased)</p>

   **Parameters:**

   ``gradientthr : float = 1``

      .. raw:: html

         <i>Gradient Threshold</i>: The maximum value admitted for the quality gradient (in absolute value)

   ``updatecolor : bool = False``

      .. raw:: html

         <i>Update ColorMap</i>: if true the color ramp is computed again

.. data:: apply_scalar_smoothing_per_vertex

   *MeshLab filter name*: 'Smooth Vertex Quality'

   .. raw:: html

      Laplacian smooth of the <a href='https://stackoverflow.com/questions/58610746'>quality per vertex</a> values.</p>

.. data:: apply_scalar_unsharp_mask_per_vertex

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

.. data:: apply_selection_by_same_connected_component

   *MeshLab filter name*: 'Select Connected Faces'

   .. raw:: html

      Expand the current face selection so that it includes all the faces in the connected components where there is at least a selected face.</p>

.. data:: apply_selection_dilatation

   *MeshLab filter name*: 'Dilate Selection'

   .. raw:: html

      Dilate (expand) the current set of selected faces.</p>

.. data:: apply_selection_erosion

   *MeshLab filter name*: 'Erode Selection'

   .. raw:: html

      Erode (reduce) the current set of selected faces.</p>

.. data:: apply_selection_inverse

   *MeshLab filter name*: 'Invert Selection'

   .. raw:: html

      Invert the current set of selected faces/vertices.</p>

   **Parameters:**

   ``invfaces : bool = False``

      .. raw:: html

         <i>Invert Faces</i>: If true the filter will invert the set of selected faces.

   ``invverts : bool = False``

      .. raw:: html

         <i>Invert Vertices</i>: If true the filter will invert the set of selected vertices.

.. data:: apply_texcoord_merge_per_wedge

   *MeshLab filter name*: 'Merge Wedge Texture Coord'

   .. raw:: html

      Merge together per-wedge texture coords that are very close. Used to correct apparent texture seams that can arise from numerical approximations when saving in ascii formats.</p>

   **Parameters:**

   ``mergethr : float = 0.0001``

      .. raw:: html

         <i>Merging Threshold</i>: All the per-wedge texture coords that are on the same vertex and are distant less then the given threshold are merged together. It can be used to remove the fake texture seams that arise from error. Distance is in texture space (the default, 1e-4, corresponds to one texel on a 10kx10x texture) 

.. data:: apply_texmap_defragmentation

   *MeshLab filter name*: 'Texture Map Defragmentation'

   .. raw:: html

      Reduces the texture fragmentation by merging atlas charts. 		               The used algorithm is: <br><b>Texture Defragmentation for Photo-Reconstructed 3D Models</b><br> 		               <i>Andrea Maggiordomo, Paolo Cignoni and Marco Tarini</i> <br>		               Eurographics 2021</p>

   **Parameters:**

   ``matchingthreshold : float = 2``

      .. raw:: html

         <i>Matching Error Threshold</i>: Threshold on the seam alignment error. Using a higher threshold can reduce the fragmentation but increase runtime and distortion.

   ``boundarytolerance : float = 0.2``

      .. raw:: html

         <i>Seam to chart-boundary-length tolerance</i>: Cutoff on the minimum fractional seam length. Seams with lower fractional length (relative to the chart perimeter) are not merged to keep the chart borders compact.

   ``distortiontolerance : float = 0.5``

      .. raw:: html

         <i>Local ARAP distortion tolerance</i>: Local UV-optimization distortion tolerance when merging a seam. If the local energy is higher than this value, the operation is reverted.

   ``globaldistortiontolerance : float = 0.025``

      .. raw:: html

         <i>Global ARAP distortion tolerance</i>: Global ARAP distortion tolerance when merging a seam. If the global atlas energy is higher than this value, the operation is reverted.

   ``uvreductionlimit : float (bounded) = 0 [min: 0; max: 100]``

      .. raw:: html

         <i>UV Length Target (percentage)</i>: Target UV length as percentage of the input length. The algorithm halts if the target UV length has be    en reached, or if no further seams can be merged.

   ``offsetfactor : float = 5``

      .. raw:: html

         <i>Local expansion coefficient</i>: Coefficient used to control the extension of the UV-optimization area. Larger values can increase the efficacy of the defragmentation, but increase the cost of the geometric optimization and the algorithm runtime.

   ``timelimit : float = 0``

      .. raw:: html

         <i>Time limit (seconds)</i>: Time limit for the defragmentation process (zero means unlimited).

.. data:: compute_color_and_texture_from_active_rasters_projection

   *MeshLab filter name*: 'Project active rasters color to current mesh, filling the texture'

   .. raw:: html

      Color information from all the active rasters is perspective-projected on the current mesh, filling the texture, using basic weighting</p>

   **Parameters:**

   ``textname : str = '_color.png'``

      .. raw:: html

         <i>Texture file</i>: The texture file to be created

   ``texsize : int = 1024``

      .. raw:: html

         <i>pixel size of texture image</i>: pixel size of texture image, the image will be a square tsize X tsize, most applications do require that tsize is a power of 2

   ``dorefill : bool = True``

      .. raw:: html

         <i>fill atlas gaps</i>: If true, unfilled areas of the mesh are interpolated, to avoid visible seams while mipmapping

   ``deptheta : float = 0.5``

      .. raw:: html

         <i>depth threshold</i>: threshold value for depth buffer projection (shadow buffer)

   ``onselection : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If true, projection is only done for selected vertices

   ``useangle : bool = True``

      .. raw:: html

         <i>use angle weight</i>: If true, color contribution is weighted by pixel view angle

   ``usedistance : bool = True``

      .. raw:: html

         <i>use distance weight</i>: If true, color contribution is weighted by pixel view distance

   ``useborders : bool = True``

      .. raw:: html

         <i>use image borders weight</i>: If true, color contribution is weighted by pixel distance from image boundaries

   ``usesilhouettes : bool = True``

      .. raw:: html

         <i>use depth discontinuities weight</i>: If true, color contribution is weighted by pixel distance from depth discontinuities (external and internal silhouettes)

   ``usealpha : bool = False``

      .. raw:: html

         <i>use image alpha weight</i>: If true, alpha channel of the image is used as additional weight. In this way it is possible to mask-out parts of the images that should not be projected on the mesh. Please note this is not a transparency effect, but just influences the weigthing between different images

.. data:: compute_color_by_conntected_component_per_face

   *MeshLab filter name*: 'Random Component Color'

   .. raw:: html

      Colorize each connected component randomly.</p>

.. data:: compute_color_by_function_per_face

   *MeshLab filter name*: 'Per Face Color Function'

   .. raw:: html

      Color function using muparser lib to generate new RGBA color for every face<br>Red, Green, Blue and Alpha channels may be defined specifying a function in their respective fields.<br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>vi0, vi1, vi2</b> for vertex indices, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fi</b> for face index, <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

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

   ``onselected : bool = False``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected faces

.. data:: compute_color_by_function_per_vertex

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

   ``onselected : bool = False``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: compute_color_by_point_cloud_voronoi_projection

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

   ``backward : bool = False``

      .. raw:: html

         <i>BackDistance</i>: If true the mesh is colored according the distance from the frontier of the voonoi diagram induced by the VertexMesh seeds.

.. data:: compute_color_from_active_rasters_projection

   *MeshLab filter name*: 'Project active rasters color to current mesh'

   .. raw:: html

      Color information from all the active rasters is perspective-projected on the current mesh using basic weighting</p>

   **Parameters:**

   ``deptheta : float = 0.5``

      .. raw:: html

         <i>depth threshold</i>: threshold value for depth buffer projection (shadow buffer)

   ``onselection : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If true, projection is only done for selected vertices

   ``useangle : bool = True``

      .. raw:: html

         <i>use angle weight</i>: If true, color contribution is weighted by pixel view angle

   ``usedistance : bool = True``

      .. raw:: html

         <i>use distance weight</i>: If true, color contribution is weighted by pixel view distance

   ``useborders : bool = True``

      .. raw:: html

         <i>use image borders weight</i>: If true, color contribution is weighted by pixel distance from image boundaries

   ``usesilhouettes : bool = True``

      .. raw:: html

         <i>use depth discontinuities weight</i>: If true, color contribution is weighted by pixel distance from depth discontinuities (external and internal silhouettes)

   ``usealpha : bool = False``

      .. raw:: html

         <i>use image alpha weight</i>: If true, alpha channel of the image is used as additional weight. In this way it is possible to mask-out parts of the images that should not be projected on the mesh. Please note this is not a transparency effect, but just influences the weigthing between different images

   ``blankcolor : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>Color for unprojected areas</i>: Areas that cannot be projected willb e filled using this color. If R=0 G=0 B=0 A=0 old color is preserved

.. data:: compute_color_from_current_raster_projection

   *MeshLab filter name*: 'Project current raster color to current mesh'

   .. raw:: html

      Color information from the current raster is perspective-projected on the current mesh</p>

   **Parameters:**

   ``usedepth : bool = True``

      .. raw:: html

         <i>Use depth for projection</i>: If true, depth is used to restrict projection on visible faces

   ``deptheta : float = 0.5``

      .. raw:: html

         <i>depth threshold</i>: threshold value for depth buffer projection (shadow buffer)

   ``onselection : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If true, projection is only done for selected vertices

   ``blankcolor : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>Color for unprojected areas</i>: Areas that cannot be projected willb e filled using this color. If R=0 G=0 B=0 A=0 old color is preserved

.. data:: compute_color_from_scalar_per_face

   *MeshLab filter name*: 'Colorize by face Quality'

   .. raw:: html

      Color faces depending on their quality field (manually equalized).</p>

   **Parameters:**

   ``minval : float = 0``

      .. raw:: html

         <i>Min</i>: The value that will be mapped with the lower end of the scale (red)

   ``maxval : float = 0``

      .. raw:: html

         <i>Max</i>: The value that will be mapped with the upper end of the scale (blue)

   ``perc : float (bounded) = 0 [min: 0; max: 100]``

      .. raw:: html

         <i>Percentile Crop [0..100]</i>: If not zero this value will be used for a percentile cropping of the quality values.<br> If this parameter is set to a value <i>P</i> then the two values <i>V_min,V_max</i> for which <i>P</i>% of the faces have a quality <b>lower or greater</b> than <i>V_min,V_max</i> are used as min/max values for clamping.<br><br> The automated percentile cropping is very useful for automatically discarding outliers.

   ``zerosym : bool = False``

      .. raw:: html

         <i>Zero Symmetric</i>: If true the min max range will be enlarged to be symmetric (so that green is always Zero)

.. data:: compute_color_from_scalar_per_vertex

   *MeshLab filter name*: 'Colorize by vertex Quality'

   .. raw:: html

      Color vertices depending on their quality field (manually equalized).</p>

   **Parameters:**

   ``minval : float = 0``

      .. raw:: html

         <i>Min</i>: The value that will be mapped with the lower end of the scale (red)

   ``maxval : float = 0``

      .. raw:: html

         <i>Max</i>: The value that will be mapped with the upper end of the scale (blue)

   ``perc : float (bounded) = 0 [min: 0; max: 100]``

      .. raw:: html

         <i>Percentile Crop [0..100]</i>: If not zero this value will be used for a percentile cropping of the quality values.<br> If this parameter is set to a value <i>P</i> then the two values <i>V_min,V_max</i> for which <i>P</i>% of the vertices have a quality <b>lower or greater</b> than <i>V_min,V_max</i> are used as min/max values for clamping.<br><br> The automated percentile cropping is very useful for automatically discarding outliers.

   ``zerosym : bool = False``

      .. raw:: html

         <i>Zero Symmetric</i>: If true the min max range will be enlarged to be symmetric (so that green is always Zero)

.. data:: compute_color_from_scalar_using_transfer_function_per_vertex

   *MeshLab filter name*: 'Quality Mapper applier'

   .. raw:: html

      The filter maps quality levels into colors using a colorband built from a transfer function (may be loaded from an external file) and colorizes the mesh vertices. The minimum, medium and maximum quality values can be set by user to obtain a custom quality range for mapping</p>

   **Parameters:**

   ``minqualityval : float = 0``

      .. raw:: html

         <i>Minimum mesh quality</i>: The specified quality value is mapped in the <b>lower</b> end of the chosen color scale. Default value: the minimum quality value found on the mesh.

   ``maxqualityval : float = 0``

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

.. data:: compute_color_from_texture_per_vertex

   *MeshLab filter name*: 'Transfer Color: Texture to Vertex'

   .. raw:: html

      Texture to Vertex color transfer</p>

.. data:: compute_color_perlin_noise_per_vertex

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

   ``offset : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Offset</i>: This values is the XYZ frequency offset of the Noise function (offset 1 means 1 period shift).

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: compute_color_random_per_face

   *MeshLab filter name*: 'Random Face Color'

   .. raw:: html

      Colorize Faces randomly. If internal edges are present they are used. Useful for quads.</p>

.. data:: compute_color_scattering_per_mesh

   *MeshLab filter name*: 'PerMesh Color Scattering'

   .. raw:: html

      Assigns a random color to each visible mesh layer in the document. Colors change every time the filter is executed, but are always chosen so that they differ as much as possible.</p>

   **Parameters:**

   ``seed : int = 0``

      .. raw:: html

         <i>Seed</i>: Random seed used to generate scattered colors. Zero means totally random (each time the filter is started it generates a different result)

.. data:: compute_color_transfer_face_to_vertex

   *MeshLab filter name*: 'Transfer Color: Face to Vertex'

   .. raw:: html

      Face to Vertex color transfer</p>

.. data:: compute_color_transfer_mesh_to_face

   *MeshLab filter name*: 'Transfer Color: Mesh to Face'

   .. raw:: html

      Mesh to Face color transfer</p>

   **Parameters:**

   ``allvisiblemesh : bool = False``

      .. raw:: html

         <i>Apply to all Meshes</i>: If true the color mapping is applied to all the meshes.

.. data:: compute_color_transfer_vertex_to_face

   *MeshLab filter name*: 'Transfer Color: Vertex to Face'

   .. raw:: html

      Vertex to Face color transfer</p>

.. data:: compute_coord_by_function

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

   ``onselected : bool = False``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: compute_coord_linear_morphing

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

.. data:: compute_curvature_and_color_apss_per_vertex

   *MeshLab filter name*: 'Colorize curvature (APSS)'

   .. raw:: html

      Colorize the vertices of a mesh or point set using the curvature of the underlying surface.<br><br>This is the <i>algebraic point set surfaces</i> (APSS) variant which is based on the local fitting of algebraic spheres. It requires points equipped with oriented normals. <br>For all the details about APSS see: <br> Guennebaud and Gross, 'Algebraic Point Set Surfaces', Siggraph 2007, and<br>Guennebaud et al., 'Dynamic Sampling and Rendering of APSS', Eurographics 2008</p>

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

   ``selectiononly : bool = False``

      .. raw:: html

         <i>Selection only</i>: If checked, only selected vertices will be projected.

   ``curvaturetype : str = 'Mean' (or int = 0)``

      Possible enum values:

         0. ``'Mean'``
         1. ``'Gauss'``
         2. ``'K1'``
         3. ``'K2'``
         4. ``'ApproxMean'``

      .. raw:: html

         <i>Curvature type</i>: The type of the curvature to plot.<br>ApproxMean uses the radius of the fitted sphere as an approximation of the mean curvature.

.. data:: compute_curvature_and_color_rimls_per_vertex

   *MeshLab filter name*: 'Colorize curvature (RIMLS)'

   .. raw:: html

      Colorize the vertices of a mesh or point set using the curvature of the underlying surface.<br><br>This is the Robust Implicit MLS (RIMLS) variant which is an extension of Implicit MLS preserving sharp features using non linear regression. For more details see: <br>Oztireli, Guennebaud and Gross, 'Feature Preserving Point Set Surfaces based on Non-Linear Kernel Regression' Eurographics 2009.</p>

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

   ``selectiononly : bool = False``

      .. raw:: html

         <i>Selection only</i>: If checked, only selected vertices will be projected.

   ``curvaturetype : str = 'Mean' (or int = 0)``

      Possible enum values:

         0. ``'Mean'``
         1. ``'Gauss'``
         2. ``'K1'``
         3. ``'K2'``

      .. raw:: html

         <i>Curvature type</i>: The type of the curvature to plot.

.. data:: compute_curvature_principal_directions_per_vertex

   *MeshLab filter name*: 'Compute curvature principal directions'

   .. raw:: html

      Compute the principal directions of curvature with different algorithms</p>

   **Parameters:**

   ``method : str = 'Quadric Fitting' (or int = 3)``

      Possible enum values:

         0. ``'Taubin approximation'``
         1. ``'Principal Component Analysis'``
         2. ``'Normal Cycles'``
         3. ``'Quadric Fitting'``
         4. ``'Scale Dependent Quadric Fitting'``

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

   ``scale : Percentage = 10%``

      .. raw:: html

         <i>Curvature Scale</i>: This parameter is used only for scale dependent methods: 'Scale Dependent Quadric Fitting' and 'PCA'. It specifies the scale at which the curvature is computed. e.g. for SDQF it specify how large is the patch where we fit the quadric used to compute curvature dirs.

   ``autoclean : bool = True``

      .. raw:: html

         <i>Remove Unreferenced Vertices</i>: If selected, before starting the filter will remove any unreference vertex (for which curvature values are not defined)

.. data:: compute_custom_radius_scalar_attribute_per_vertex

   *MeshLab filter name*: 'Estimate radius from density'

   .. raw:: html

      Estimate the local point spacing (aka radius) around each vertex using a basic estimate of the local density.</p>

   **Parameters:**

   ``nbneighbors : int = 16``

      .. raw:: html

         <i>Number of neighbors</i>: Number of neighbors used to estimate the local density. Larger values lead to smoother variations.

.. data:: compute_iso_parametrization

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

         <i>Convergence Precision</i>: This parameter controls the convergence speed/precision of the optimization of the texture coordinates. Larger the number slower the processing and, eventually, slightly better results

   ``doublestep : bool = True``

      .. raw:: html

         <i>Double Step</i>: Use this bool to divide the parameterization in 2 steps. Double step makes the overall process faster and robust.<br> Consider to disable this bool in case the object has topologycal noise or small handles.

.. data:: compute_matrix_by_fitting_to_plane

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

   ``toorigin : bool = True``

      .. raw:: html

         <i>Move to Origin</i>: Also apply a translation, such that the centroid of selection rests on the Origin

   ``freeze : bool = True``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: compute_matrix_by_icp_between_meshes

   *MeshLab filter name*: 'ICP Between Meshes'

   .. raw:: html

      Perform the ICP algorithm to minimize the difference between two cloud of points.</p>

   **Parameters:**

   ``referencemesh : int = 0``

      .. raw:: html

         <i>Reference Mesh</i>: The Reference Mesh is the point cloud kept fixed during the ICP process.

   ``sourcemesh : int = 1``

      .. raw:: html

         <i>Source Mesh</i>: The Source Mesh is the point cloud which will be roto-translated to match the Reference Mesh.

   ``samplenum : int = 2000``

      .. raw:: html

         <i>Sample Number</i>: Number of samples that we try to choose at each ICP iteration

   ``mindistabs : float = 10``

      .. raw:: html

         <i>Minimal Starting Distance</i>: For all the chosen sample on one mesh we consider for ICP only the samples nearer than this value.If MSD is too large outliers could be included, if it is too small convergence will be very slow. A good guess is needed here, suggested values are in the range of 10-100 times of the device scanning error.This value is also dynamically changed by the 'Reduce Distance Factor'

   ``trgdistabs : float = 0.005``

      .. raw:: html

         <i>Target Distance</i>: When 50% of the chosen samples are below this distance we consider the two mesh aligned. Usually it should be a value lower than the error of the scanning device.

   ``maxiternum : int = 75``

      .. raw:: html

         <i>Max Iteration Num</i>: The maximum number of iteration that the ICP is allowed to perform.

   ``samplemode : bool = True``

      .. raw:: html

         <i>Normal Equalized Sampling</i>: if true (default) the sample points of icp are chosen with a distribution uniform with respect to the normals of the surface. Otherwise they are distributed in a spatially uniform way.

   ``reducefactorperc : float = 0.8``

      .. raw:: html

         <i>MSD Reduce Factor</i>: At each ICP iteration the Minimal Starting Distance is reduced to be 5 times the <Reduce Factor> percentile of the sample distances (e.g. if RF is 0.9 the new Minimal Starting Distance is 5 times the value <X> such that 90% of the sample lies at a distance lower than <X>.

   ``passhifilter : float = 0.75``

      .. raw:: html

         <i>Sample Cut High</i>: At each ICP iteration all the sample that are farther than the <cuth high> percentile are discarded ( In practice we use only the <cut high> best results ).

   ``matchmode : bool = True``

      .. raw:: html

         <i>Rigid matching</i>: If true the ICP is constrained to perform matching only through roto-translations (no scaling allowed). If false a more relaxed transformation matrix is allowed (scaling and shearing can appear).

   ``savelastiteration : bool = False``

      .. raw:: html

         <i>Save Last Iteration</i>: Toggle this checkbox in order to save the last iteration points in two layers.

.. data:: compute_matrix_by_mesh_global_alignment

   *MeshLab filter name*: 'Global Align Meshes'

   .. raw:: html

      Perform the global alignment process to align a set of visible meshes together. The alignment algorithm is implemented over the idea written by <i>Kari Pulli</i> in his paper: "Multiview Registration for Large Data Sets"</p>

   **Parameters:**

   ``basemesh : int = 0``

      .. raw:: html

         <i>Base Mesh</i>: The base mesh is the one who will stay fixed during the alignment process.

   ``onlyvisiblemeshes : bool = False``

      .. raw:: html

         <i>Only visible meshes</i>: Apply the global alignment only to the visible meshes

   ``ogsize : int = 50000``

      .. raw:: html

         <i>Occupancy Grid Size</i>: To compute the overlap between range maps we discretize them into voxel and count them (both for area and overlap); This parameter affect the resolution of the voxelization process. Using a too fine voxelization can...

   ``arcthreshold : float = 0.3``

      .. raw:: html

         <i>Arc Area Thr.</i>: We run ICP on every pair of mesh with a relative overlap greater than this threshold. The relative overlap is computed as overlapArea / min(area1,area2)

   ``recalcthreshold : float = 0.1``

      .. raw:: html

         <i>Recalc Fraction</i>: Every time we start process we discard the <recalc> fraction of all the arcs in order to recompute them and hopefully improve the final result. It corresponds to iteratively recalc the bad arcs.

   ``samplenum : int = 2000``

      .. raw:: html

         <i>Sample Number</i>: Number of samples that we try to choose at each ICP iteration

   ``mindistabs : float = 10``

      .. raw:: html

         <i>Minimal Starting Distance</i>: For all the chosen sample on one mesh we consider for ICP only the samples nearer than this value.If MSD is too large outliers could be included, if it is too small convergence will be very slow. A good guess is needed here, suggested values are in the range of 10-100 times of the device scanning error.This value is also dynamically changed by the 'Reduce Distance Factor'

   ``trgdistabs : float = 0.005``

      .. raw:: html

         <i>Target Distance</i>: When 50% of the chosen samples are below this distance we consider the two mesh aligned. Usually it should be a value lower than the error of the scanning device.

   ``maxiternum : int = 75``

      .. raw:: html

         <i>Max Iteration Num</i>: The maximum number of iteration that the ICP is allowed to perform.

   ``samplemode : bool = True``

      .. raw:: html

         <i>Normal Equalized Sampling</i>: if true (default) the sample points of icp are chosen with a distribution uniform with respect to the normals of the surface. Otherwise they are distributed in a spatially uniform way.

   ``reducefactorperc : float = 0.8``

      .. raw:: html

         <i>MSD Reduce Factor</i>: At each ICP iteration the Minimal Starting Distance is reduced to be 5 times the <Reduce Factor> percentile of the sample distances (e.g. if RF is 0.9 the new Minimal Starting Distance is 5 times the value <X> such that 90% of the sample lies at a distance lower than <X>.

   ``passhifilter : float = 0.75``

      .. raw:: html

         <i>Sample Cut High</i>: At each ICP iteration all the sample that are farther than the <cuth high> percentile are discarded ( In practice we use only the <cut high> best results ).

   ``matchmode : bool = True``

      .. raw:: html

         <i>Rigid matching</i>: If true the ICP is constrained to perform matching only through roto-translations (no scaling allowed). If false a more relaxed transformation matrix is allowed (scaling and shearing can appear).

.. data:: compute_matrix_by_principal_axis

   *MeshLab filter name*: 'Transform: Align to Principal Axis'

   .. raw:: html

      Generate a matrix transformation that rotates the mesh aligning it to its principal axis of inertia.If the mesh is watertight the Itertia tensor is computed assuming the interior of the mesh has a uniform density.In case of an open mesh or a point clouds the inerta tensor is computed assuming each vertex is a constant puntual mass.</p>

   **Parameters:**

   ``pointsflag : bool = True``

      .. raw:: html

         <i>Use vertex</i>: If selected, only the vertices of the mesh are used to compute the Principal Axis. Mandatory for point clouds or for non water tight meshes

   ``freeze : bool = True``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: compute_matrix_from_rotation

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

   ``customaxis : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom axis</i>: This rotation axis is used only if the 'custom axis' option is chosen.

   ``customcenter : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom center</i>: This rotation center is used only if the 'custom point' option is chosen.

   ``snapflag : bool = False``

      .. raw:: html

         <i>Snap angle</i>: If selected, before starting the filter will remove any unreferenced vertex (for which curvature values are not defined)

   ``snapangle : float = 30``

      .. raw:: html

         <i>Snapping Value</i>: This value is used to snap the rotation angle (i.e. if the snapping value is 30, 227 becomes 210).

   ``freeze : bool = True``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: compute_matrix_from_scaling_or_normalization

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

   ``uniformflag : bool = True``

      .. raw:: html

         <i>Uniform Scaling</i>: If selected an uniform scaling (the same for all the three axis) is applied (the X axis value is used)

   ``scalecenter : str = 'origin' (or int = 0)``

      Possible enum values:

         0. ``'origin'``
         1. ``'barycenter'``
         2. ``'custom point'``

      .. raw:: html

         <i>Center of scaling:</i>: Choose a method

   ``customcenter : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Custom center</i>: This scaling center is used only if the 'custom point' option is chosen.

   ``unitflag : bool = False``

      .. raw:: html

         <i>Scale to Unit bbox</i>: If selected, the object is scaled to a box whose sides are at most 1 unit length

   ``freeze : bool = True``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: compute_matrix_from_translation

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

   ``axisx : float (bounded) = 0 [min: -8.66025; max: 8.66025]``

      .. raw:: html

         <i>X Axis</i>: when using [XYZ translation], amount of translation along the X axis (in model units)

   ``axisy : float (bounded) = 0 [min: -8.66025; max: 8.66025]``

      .. raw:: html

         <i>Y Axis</i>: when using [XYZ translation], amount of translation along the Y axis (in model units)

   ``axisz : float (bounded) = 0 [min: -8.66025; max: 8.66025]``

      .. raw:: html

         <i>Z Axis</i>: when using [XYZ translation], amount of translation along the Z axis (in model units)

   ``neworigin : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>New Origin:</i>: when using [Set new Origin], this is the location of the new Origin.

   ``freeze : bool = True``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: compute_matrix_from_translation_rotation_scale

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

   ``compose : bool = False``

      .. raw:: html

         <i>Compose with current</i>: If selected, the new matrix will be composed with the current one (matrix=new*old)

   ``freeze : bool = True``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: compute_mls_projection_apss

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

   ``selectiononly : bool = False``

      .. raw:: html

         <i>Selection only</i>: If checked, only selected vertices will be projected.

   ``maxsubdivisions : int = 0``

      .. raw:: html

         <i>Refinement - Max subdivisions</i>: Max number of subdivisions.

   ``thangleindegree : float = 2``

      .. raw:: html

         <i>Refinement - Crease angle (degree)</i>: Threshold angle between two faces controlling the refinement.

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

   ``accuratenormal : bool = True``

      .. raw:: html

         <i>Accurate normals</i>: If checked, use the accurate MLS gradient instead of the local approximationto compute the normals.

.. data:: compute_mls_projection_rimls

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

   ``selectiononly : bool = False``

      .. raw:: html

         <i>Selection only</i>: If checked, only selected vertices will be projected.

   ``maxsubdivisions : int = 0``

      .. raw:: html

         <i>Refinement - Max subdivisions</i>: Max number of subdivisions.

   ``thangleindegree : float = 2``

      .. raw:: html

         <i>Refinement - Crease angle (degree)</i>: Threshold angle between two faces controlling the refinement.

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

.. data:: compute_new_custom_point_attribute_per_face

   *MeshLab filter name*: 'Define New Per Face Custom Point Attribute'

   .. raw:: html

      Add a new Per-Face custom point attribute to current mesh.<br>You can specify custom name and a function to generate attribute's values<br>It's possible to use per-face variables in the expression:<br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>vi0, vi1, vi2</b> for vertex indices, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fi</b> for face index, <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br><font color="#FF0000">The attribute name specified below can be used in other filter function</font></p>

   **Parameters:**

   ``name : str = 'Custom Attr Name'``

      .. raw:: html

         <i>Name</i>: the name of new attribute. you can access attribute in other filters through this name

   ``x_expr : str = 'x0'``

      .. raw:: html

         <i>x coord function =</i>: function to calculate custom x coord of the point attribute value for each face

   ``y_expr : str = 'y0'``

      .. raw:: html

         <i>y coord function =</i>: function to calculate custom y coord of the point attribute value for each face

   ``z_expr : str = 'z0'``

      .. raw:: html

         <i>z coord function =</i>: function to calculate custom z coord of the point attribute value for each face

.. data:: compute_new_custom_point_attribute_per_vertex

   *MeshLab filter name*: 'Define New Per Vertex Custom Point Attribute'

   .. raw:: html

      Add a new Per-Vertex custom point attribute to current mesh and fill it with the defined function.<br>The name specified below can be used in other filter functionIt's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``name : str = 'Custom Attr Name'``

      .. raw:: html

         <i>Name</i>: the name of new attribute. you can access attribute in other filters through this name

   ``x_expr : str = 'x'``

      .. raw:: html

         <i>x coord function =</i>: function to calculate custom x coord of the point attribute value for each vertex

   ``y_expr : str = 'y'``

      .. raw:: html

         <i>y coord function =</i>: function to calculate custom y coord of the point attribute value for each vertex

   ``z_expr : str = 'z'``

      .. raw:: html

         <i>z coord function =</i>: function to calculate custom z coord of the point attribute value for each vertex

.. data:: compute_new_custom_scalar_attribute_per_face

   *MeshLab filter name*: 'Define New Per Face Custom Scalar Attribute'

   .. raw:: html

      Add a new Per-Face custom scalar attribute to current mesh.<br>You can specify custom name and a function to generate attribute's values<br>It's possible to use per-face variables in the expression:<br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>vi0, vi1, vi2</b> for vertex indices, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fi</b> for face index, <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br><font color="#FF0000">The attribute name specified below can be used in other filter function</font></p>

   **Parameters:**

   ``name : str = 'Custom Attr Name'``

      .. raw:: html

         <i>Name</i>: the name of new attribute. you can access attribute in other filters through this name

   ``expr : str = 'fi'``

      .. raw:: html

         <i>Scalar function =</i>: function to calculate custom scalar attribute value for each face

.. data:: compute_new_custom_scalar_attribute_per_vertex

   *MeshLab filter name*: 'Define New Per Vertex Custom Scalar Attribute'

   .. raw:: html

      Add a new Per-Vertex custom scalar attribute to current mesh and fill it with the defined function.<br>The name specified below can be used in other filter functionIt's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``name : str = 'Custom Attr Name'``

      .. raw:: html

         <i>Name</i>: the name of new attribute. you can access attribute in other filters through this name

   ``expr : str = 'x'``

      .. raw:: html

         <i>Scalar function =</i>: function to calculate custom scalar attribute value for each vertex

.. data:: compute_normal_by_function_per_vertex

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

   ``onselected : bool = False``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: compute_normal_for_point_clouds

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

   ``flipflag : bool = False``

      .. raw:: html

         <i>Flip normals w.r.t. viewpoint</i>: If the 'viewpoint' (i.e. scanner position) is known, it can be used to disambiguate normals orientation, so that all the normals will be oriented in the same direction.

   ``viewpos : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>Viewpoint Pos.</i>: The viewpoint position can be set by hand (i.e. getting the current viewpoint) or it can be retrieved from mesh camera, if the viewpoint position is stored there.

.. data:: compute_normal_from_cameras_per_vertex

   *MeshLab filter name*: 'Re-Orient vertex normals using cameras'

   .. raw:: html

      Reorient vertex normals using cameras. For this  filter to work the mesh needs to have the attribute 'correspondences' which is only created when loading Bundler files (.out projects)</p>

.. data:: compute_normal_per_face

   *MeshLab filter name*: 'Re-Compute Face Normals'

   .. raw:: html

      Recompute face normals as the normal of the plane of the face.<br>See <a href='https://math.stackexchange.com/questions/305642/'>How to find surface normal of a triangle</a></p>

.. data:: compute_normal_per_vertex

   *MeshLab filter name*: 'Re-Compute Vertex Normals'

   .. raw:: html

      Recompute vertex normals according to four different schemes:<br>1) Simple (no weights) average of normals of the incident faces <br>2) Area weighted average of normals of the incident faces <br>3) Angle weighted sum of normals of the incident faces according to the article <b>[1]</b>. Probably this is the best all-purpose choice. It could slightly bias the result for degenerate, fat triangles.<br>4) Weighted sum of normals of the incident faces, as defined by article <b>[2]</b>. The weight for each wedge is the cross product of the two edges over the product of the square of the two edge lengths.According to the original article it is perfect only for spherical surface, but it should perform well also in practice.<br>[1]: <b>Computing Vertex Normals from Polygonal Facet</b> by <i>G Thurmer and CA Wuthrich</i>, JGT volume3, num 1. 1998<br><a href='https://doi.org/10.1080/10867651.1998.10487487'>doi:10.1080/10867651.1998.10487487</a><br>[2]: <b>Weights for Computing Vertex Normals from Facet Normals</b> by <i>Nelson Max</i>, JGT vol4, num 2. 1999<br><a href='https://doi.org/10.1080/10867651.1999.10487501'>doi:10.1080/10867651.1999.10487501</a></p>

   **Parameters:**

   ``weightmode : str = 'Simple Average' (or int = 0)``

      Possible enum values:

         0. ``'Simple Average'``
         1. ``'By Area'``
         2. ``'By Angle'``
         3. ``'As defined by N. Max'``

      .. raw:: html

         <i>Weighting Mode:</i>: 

.. data:: compute_normal_polygon_mesh_per_face

   *MeshLab filter name*: 'Re-Compute Per-Polygon Face Normals'

   .. raw:: html

      Recompute face normals as the average of the normals of the triangles that builds a polygon. Useful for showing uniformly shaded quad or polygonal meshes represented using <a href='https://stackoverflow.com/questions/59392193'>faux edges</a>.</p>

.. data:: compute_scalar_ambient_occlusion

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

   ``conedir : numpy.ndarray[numpy.float64[3]] = [0, 1, 0]``

      .. raw:: html

         <i>Lighting Direction</i>: Number of different views placed around the mesh. More views means better accuracy at the cost of increased calculation time

   ``coneangle : float = 30``

      .. raw:: html

         <i>Cone amplitude</i>: Number of different views uniformly placed around the mesh. More views means better accuracy at the cost of increased calculation time

   ``usegpu : bool = False``

      .. raw:: html

         <i>Use GPU acceleration</i>: Only works for per-vertex AO. In order to use GPU-Mode, your hardware must support FBOs, FP32 Textures and Shaders. Normally increases the performance by a factor of 4x-5x

   ``depthtexsize : int = 512``

      .. raw:: html

         <i>Depth texture size(should be 2^n)</i>: Defines the depth texture size used to compute occlusion from each point of view. Higher values means better accuracy usually with low impact on performance

.. data:: compute_scalar_by_aspect_ratio_per_face

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

.. data:: compute_scalar_by_border_distance_per_vertex

   *MeshLab filter name*: 'Colorize by border distance'

   .. raw:: html

      Store in the quality field the geodesic distance from borders and color the mesh accordingly.</p>

.. data:: compute_scalar_by_discrete_curvature_per_vertex

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

.. data:: compute_scalar_by_distance_from_another_mesh_per_vertex

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

   ``signeddist : bool = True``

      .. raw:: html

         <i>Compute Signed Distance</i>: If TRUE, the distance is signed; if FALSE, it will compute the distance absolute value.

   ``maxdist : Percentage = 100%``

      .. raw:: html

         <i>Max Distance [abs]</i>: Search is interrupted when nothing is found within this distance range [+maxDistance -maxDistance].

.. data:: compute_scalar_by_distance_from_point_cloud_per_vertex

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

   ``radius : float (bounded) = 0.173205 [min: 0; max: 0.57735]``

      .. raw:: html

         <i>Radius</i>: the radius of the spheres centered in the VertexMesh seeds 

   ``sampleradius : bool = False``

      .. raw:: html

         <i>Use sample radius</i>: Use the radius that is stored in each sample of the vertex mesh. Useful for displaing the variable disk sampling results

   ``approximategeodetic : bool = False``

      .. raw:: html

         <i>Use Approximate Geodetic</i>: Use the Approximate Geodetic Metric instead of the Euclidean distance. Approximate geodetic metric uses the normals between the two points to weight the euclidean distance.

.. data:: compute_scalar_by_function_per_face

   *MeshLab filter name*: 'Per Face Quality Function'

   .. raw:: html

      Quality function using muparser to generate new Quality for every face<br>Insert three function each one for quality of the three vertex of a face<br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>vi0, vi1, vi2</b> for vertex indices, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fi</b> for face index, <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

   **Parameters:**

   ``q : str = 'x0+y0+z0'``

      .. raw:: html

         <i>func q0 = </i>: function to generate new Quality foreach face

   ``normalize : bool = False``

      .. raw:: html

         <i>normalize</i>: if checked normalize all quality values in range [0..1]

   ``map : bool = False``

      .. raw:: html

         <i>map into color</i>: if checked map quality generated values into per-vertex color

   ``onselected : bool = False``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected faces

.. data:: compute_scalar_by_function_per_vertex

   *MeshLab filter name*: 'Per Vertex Quality Function'

   .. raw:: html

      Quality function using muparser to generate new Quality for every vertex<br>It's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``q : str = 'vi'``

      .. raw:: html

         <i>func q = </i>: function to generate new Quality for every vertex

   ``normalize : bool = False``

      .. raw:: html

         <i>normalize</i>: if checked normalize all quality values in range [0..1]

   ``map : bool = False``

      .. raw:: html

         <i>map into color</i>: if checked map quality generated values into per-vertex color

   ``onselected : bool = False``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: compute_scalar_by_geodesic_distance_from_given_point_per_vertex

   *MeshLab filter name*: 'Colorize by geodesic distance from a given point'

   .. raw:: html

      Store in the quality field the geodesic distance from a given point on the mesh surface and color the mesh accordingly.</p>

   **Parameters:**

   ``startpoint : numpy.ndarray[numpy.float64[3]] = [-0.5, -0.5, -0.5]``

      .. raw:: html

         <i>Starting point</i>: The starting point from which geodesic distance has to be computed. If it is not a surface vertex, the closest vertex to the specified point is used as starting seed point.

   ``maxdistance : Percentage = 50%``

      .. raw:: html

         <i>Max Distance</i>: If not zero it indicates a cut off value to be used during geodesic distance computation.

.. data:: compute_scalar_by_geodesic_distance_from_selection_per_vertex

   *MeshLab filter name*: 'Colorize by geodesic distance from the selected points'

   .. raw:: html

      Store in the quality field the geodesic distance from the selected points on the mesh surface and color the mesh accordingly.</p>

   **Parameters:**

   ``maxdistance : Percentage = 50%``

      .. raw:: html

         <i>Max Distance</i>: If not zero it indicates a cut off value to be used during geodesic distance computation.

.. data:: compute_scalar_by_scalar_harmonic_field_per_vertex

   *MeshLab filter name*: 'Generate Scalar Harmonic Field'

   .. raw:: html

      Generates a scalar harmonic field over the mesh. Input scalar values must be assigned to two vertices as Dirichlet boundary conditions. Applying the filter, a discrete Laplace operator generates the harmonic field values for all the mesh vertices, which are stored in the <a href='https://stackoverflow.com/questions/58610746'>quality per vertex attribute</a> of the mesh.<br>For more details see:<b>Dynamic Harmonic Fields for Surface Processing</b> by <i>Kai Xua, Hao Zhang, Daniel Cohen-Or, Yueshan Xionga</i>. Computers & Graphics, 2009 <br><a href='https://doi.org/10.1016/j.cag.2009.03.022'>doi:10.1016/j.cag.2009.03.022</a></p>

   **Parameters:**

   ``point1 : numpy.ndarray[numpy.float64[3]] = [-0.5, -0.5, -0.5]``

      .. raw:: html

         <i>Point 1</i>: A vertex on the mesh that represent one harmonic field boundary condition.

   ``point2 : numpy.ndarray[numpy.float64[3]] = [0.5, 0.5, 0.5]``

      .. raw:: html

         <i>Point 2</i>: A vertex on the mesh that represent one harmonic field boundary condition.

   ``value1 : float (bounded) = 0 [min: 0; max: 1]``

      .. raw:: html

         <i>value for the 1st point</i>: Harmonic field value for the vertex.

   ``value2 : float (bounded) = 1 [min: 0; max: 1]``

      .. raw:: html

         <i>value for the 2nd point</i>: Harmonic field value for the vertex.

   ``colorize : bool = True``

      .. raw:: html

         <i>Colorize</i>: Colorize the mesh to provide an indication of the obtained harmonic field.

.. data:: compute_scalar_by_shape_diameter_function_per_vertex

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

   ``removefalse : bool = True``

      .. raw:: html

         <i>Remove false intersections</i>: For eachray we check the normal at the point of intersection,and ignore intersections where the normal at the intersectionpoints is in the same direction as the point-of-origin(the same direction is defined as an angle difference lessthan 90) 

   ``removeoutliers : bool = False``

      .. raw:: html

         <i>Remove outliers</i>: The outliers removal is made on the fly with a supersampling of the depth buffer. For each ray that we trace, we take multiple depth values near the point of intersection and we output only the median of these values. Some mesh can benefit from this additional calculation. 

.. data:: compute_scalar_by_volumetric_obscurance

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

.. data:: compute_scalar_from_camera_per_vertex

   *MeshLab filter name*: 'Vertex Quality from Camera'

   .. raw:: html

      Compute vertex quality using the camera definition, according to viewing angle or distance</p>

   **Parameters:**

   ``depth : bool = True``

      .. raw:: html

         <i>Depth</i>: Use depth as a factor.

   ``facing : bool = False``

      .. raw:: html

         <i>ViewAngle</i>: Use cosine of viewing angle as a factor.

   ``clip : bool = False``

      .. raw:: html

         <i>Clipping</i>: clip values outside the viewport to zero.

   ``normalize : bool = False``

      .. raw:: html

         <i>normalize</i>: if checked normalize all quality values in range [0..1]

   ``map : bool = False``

      .. raw:: html

         <i>map into color</i>: if checked map quality generated values into per-vertex color

.. data:: compute_scalar_from_raster_coverage_per_face

   *MeshLab filter name*: 'Quality from raster coverage (Face)'

   .. raw:: html

      Compute a quality value representing the number of images into which each face of the active mesh is visible.</p>

   **Parameters:**

   ``normalizequality : bool = False``

      .. raw:: html

         <i>Normalize</i>: Rescale quality values to the range [0,1]

.. data:: compute_scalar_from_raster_coverage_per_vertex

   *MeshLab filter name*: 'Quality from raster coverage (Vertex)'

   .. raw:: html

      Compute a quality value representing the number of images into which each vertex of the active mesh is visible.</p>

   **Parameters:**

   ``normalizequality : bool = False``

      .. raw:: html

         <i>Normalize</i>: Rescale quality values to the range [0,1]

.. data:: compute_scalar_transfer_face_to_vertex

   *MeshLab filter name*: 'Transfer Quality: Face to Vertex'

   .. raw:: html

      Face to Vertex quality transfer</p>

   **Parameters:**

   ``areaweight : bool = True``

      .. raw:: html

         <i>Area Weighted</i>: If true the vertex quality is computed according to the surface of the involved faces.

.. data:: compute_scalar_transfer_vertex_to_face

   *MeshLab filter name*: 'Transfer Quality: Vertex to Face'

   .. raw:: html

      Vertex to Face quality transfer</p>

.. data:: compute_selection_bad_faces

   *MeshLab filter name*: 'Select 'problematic' faces'

   .. raw:: html

      Select faces with 'problems', like normal inverted w.r.t the surrounding areas, extremely elongated or folded.</p>

   **Parameters:**

   ``usear : bool = True``

      .. raw:: html

         <i>Select by Aspect Ratio</i>: if true, faces with aspect ratio below the limit will be selected

   ``aratio : float (bounded) = 0.02 [min: 0; max: 1]``

      .. raw:: html

         <i>Aspect Ratio</i>: Triangle face aspect ratio [1 (equilateral) - 0 (line)]: face will be selected if BELOW this threshold

   ``usenf : bool = False``

      .. raw:: html

         <i>Select by Normal Angle</i>: if true, adjacent faces with normals forming an angle above the limit will be selected

   ``nfratio : float (bounded) = 60 [min: 0; max: 180]``

      .. raw:: html

         <i>Angle flip</i>: angle between the adjacent faces: face will be selected if ABOVE this threshold

   ``select_folded_faces : bool = False``

      .. raw:: html

         <i>Select folded faces</i>: If true, folded faces created by the Quadric Edge Collapse decimation will be selected. The face is selected if the angle between the face normal and the normal of the best fitting plane of the neighbor vertices is above the selected threshold.

   ``folded_faces_angle_threshold : float (bounded) = 160 [min: 90; max: 180]``

      .. raw:: html

         <i>Folded Faces Angle Threshold</i>: Angle between the face and the best fitting plane of the neighbours vertices. If it is above the threshold the face is selected.

.. data:: compute_selection_by_angle_with_direction_per_face

   *MeshLab filter name*: 'Select Faces by view angle'

   .. raw:: html

      Select faces according to the angle between their normal and the view direction. It is used in range map processing to select and delete steep faces parallel to viewdirection.</p>

   **Parameters:**

   ``anglelimit : float (bounded) = 75 [min: 0; max: 180]``

      .. raw:: html

         <i>angle threshold (deg)</i>: faces with normal at higher angle w.r.t. the view direction are selected

   ``usecamera : bool = False``

      .. raw:: html

         <i>Use ViewPoint from Mesh Camera</i>: Uses the ViewPoint from the camera associated to the current mesh<br> if there is no camera, an error occurs

   ``viewpoint : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>ViewPoint</i>: if UseCamera is true, this value is ignored

.. data:: compute_selection_by_color_per_face

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

   ``inclusive : bool = True``

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

.. data:: compute_selection_by_condition_per_face

   *MeshLab filter name*: 'Conditional Face Selection'

   .. raw:: html

      Boolean function using muparser lib to perform faces selection over current mesh.<br><br>It's possible to use parenthesis <b>()</b>, and predefined operators:<br><b>&&</b> (logic and), <b>||</b> (logic or), <b>&lt;</b>, <b>&lt;=</b>, <b>></b>, <b>>=</b>, <b>!=</b> (not equal), <b>==</b> (equal), <b>_?_:_</b> (c/c++ ternary operator)<br><br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>vi0, vi1, vi2</b> for vertex indices, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fi</b> for face index, <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

   **Parameters:**

   ``condselect : str = '(fi == 0)'``

      .. raw:: html

         <i>boolean function</i>: type a boolean function that will be evaluated in order to select a subset of faces<br>

.. data:: compute_selection_by_condition_per_vertex

   *MeshLab filter name*: 'Conditional Vertex Selection'

   .. raw:: html

      Boolean function using muparser lib to perform vertex selection over current mesh.<br><br>It's possible to use parenthesis <b>()</b>, and predefined operators:<br><b>&&</b> (logic and), <b>||</b> (logic or), <b>&lt;</b>, <b>&lt;=</b>, <b>></b>, <b>>=</b>, <b>!=</b> (not equal), <b>==</b> (equal), <b>_?_:_</b> (c/c++ ternary operator)<br><br>It's possible to use the following per-vertex variables in the expression:<br><b>x,y,z</b> (position), <b>nx,ny,nz</b> (normal), <b>r,g,b,a</b> (color), <b>q</b> (quality), <b>rad</b> (radius), <b>vi</b> (vertex index), <b>vtu,vtv,ti</b> (texture coords and texture index), <b>vsel</b> (is the vertex selected? 1 yes, 0 no) and all custom <i>vertex attributes</i> already defined by user.<br></p>

   **Parameters:**

   ``condselect : str = '(q < 0)'``

      .. raw:: html

         <i>boolean function</i>: type a boolean function that will be evaluated in order to select a subset of vertices<br>example: (y > 0) and (ny > 0)

.. data:: compute_selection_by_edge_length

   *MeshLab filter name*: 'Select Faces with edges longer than...'

   .. raw:: html

      Select all triangles having an edge with length greater or equal than a given threshold.</p>

   **Parameters:**

   ``threshold : float (bounded) = 0.00866025 [min: 0; max: 0.866025]``

      .. raw:: html

         <i>Edge Threshold</i>: All the faces with an edge <b>longer</b> than this threshold will be deleted. Useful for removing long skinny faces obtained by bad triangulation of range maps.

.. data:: compute_selection_by_non_manifold_edges_per_face

   *MeshLab filter name*: 'Select non Manifold Edges'

   .. raw:: html

      Select the faces and the vertices incident on non manifold edges (e.g. edges where more than two faces are incident); note that this function select the components that are related to non manifold edges. The case of non manifold vertices is specifically managed by the pertinent filter.</p>

.. data:: compute_selection_by_non_manifold_per_vertex

   *MeshLab filter name*: 'Select non Manifold Vertices'

   .. raw:: html

      Select the non manifold vertices that do not belong to non manifold edges. For example two cones connected by their apex. Vertices incident on non manifold edges are ignored.</p>

.. data:: compute_selection_by_scalar_per_face

   *MeshLab filter name*: 'Select by Face Quality'

   .. raw:: html

      Select all the faces/vertices with within the specified face quality range.</p>

   **Parameters:**

   ``minq : float (bounded) = 0 [min: 0; max: 0]``

      .. raw:: html

         <i>Min Quality</i>: Minimum acceptable quality value

   ``maxq : float (bounded) = 0 [min: 0; max: 0]``

      .. raw:: html

         <i>Max Quality</i>: Maximum acceptable quality value

   ``inclusive : bool = True``

      .. raw:: html

         <i>Inclusive Sel.</i>: If true only the vertices with <b>all</b> the adjacent faces within the specified range are selected. Otherwise any vertex with at least one face within the range is selected.

.. data:: compute_selection_by_scalar_per_vertex

   *MeshLab filter name*: 'Select by Vertex Quality'

   .. raw:: html

      Select all the faces/vertices within the specified vertex quality range.</p>

   **Parameters:**

   ``minq : float (bounded) = 0 [min: 0; max: 0]``

      .. raw:: html

         <i>Min Quality</i>: Minimum acceptable quality value

   ``maxq : float (bounded) = 0 [min: 0; max: 0]``

      .. raw:: html

         <i>Max Quality</i>: Maximum acceptable quality value

   ``inclusive : bool = True``

      .. raw:: html

         <i>Inclusive Sel.</i>: If true only the faces with <b>all</b> the vertices within the specified range are selected. Otherwise any face with at least one vertex within the range is selected.

.. data:: compute_selection_by_self_intersections_per_face

   *MeshLab filter name*: 'Select Self Intersecting Faces'

   .. raw:: html

      Select only self intersecting faces.</p>

.. data:: compute_selection_by_small_disconnected_components_per_face

   *MeshLab filter name*: 'Select small disconnected component'

   .. raw:: html

      Select the small disconnected components of a mesh.</p>

   **Parameters:**

   ``nbfaceratio : float = 0.1``

      .. raw:: html

         <i>Small component ratio</i>: This ratio (between 0 and 1) defines the meaning of <i>small</i> as the threshold ratio between the number of facesof the largest component and the other ones. A larger value will select more components.

   ``nonclosedonly : bool = False``

      .. raw:: html

         <i>Select only non closed components</i>: 

   ``nbneighbors : int = 16``

      .. raw:: html

         <i>Number of neighbors</i>: Number of neighbors used to estimate the local density. Larger values lead to smoother variations.

.. data:: compute_selection_by_texture_seams_per_vertex

   *MeshLab filter name*: 'Select Vertex Texture Seams'

   .. raw:: html

      Colorize only border edges.</p>

.. data:: compute_selection_crease_per_edge

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

.. data:: compute_selection_from_mesh_border

   *MeshLab filter name*: 'Select Border'

   .. raw:: html

      Select vertices and faces on the boundary.</p>

.. data:: compute_selection_of_visible_convex_hull_per_vertex

   *MeshLab filter name*: 'Select Convex Hull Visible Points'

   .. raw:: html

      Select the <b>visible points</b> in the convex hull of a point cloud, as viewed from a given viewpoint.<br>It uses the Qhull library (http://www.qhull.org/ <br><br>The algorithm used (Katz, Tal and Basri 2007) determines visibility without reconstructing a surface or estimating normals.A point is considered visible if its transformed point lies on the convex hull of a transformed points cloud from the original mesh points.</p>

   **Parameters:**

   ``radiusthreshold : float (bounded) = 0 [min: 0; max: 7]``

      .. raw:: html

         <i>radius threshold </i>: Bounds the radius of the sphere used to select visible points.It is used to adjust the radius of the sphere (calculated as distance between the center and the farthest point from it) according to the following equation: <br>radius = radius * pow(10,threshold); <br>As the radius increases more points are marked as visible.Use a big threshold for dense point clouds, a small one for sparse clouds.

   ``usecamera : bool = False``

      .. raw:: html

         <i>Use ViewPoint from Mesh Camera</i>: Uses the ViewPoint from the camera associated to the current mesh<br> if there is no camera, an error occurs

   ``viewpoint : numpy.ndarray[numpy.float64[3]] = [0, 0, 0]``

      .. raw:: html

         <i>ViewPoint</i>: if UseCamera is true, this value is ignored

   ``convex_hullfp : bool = False``

      .. raw:: html

         <i>Show Partial Convex Hull of flipped points</i>: Show Partial Convex Hull of the transformed point cloud

   ``triangvp : bool = False``

      .. raw:: html

         <i>Show a triangulation of the visible points</i>: Show a triangulation of the visible points

.. data:: compute_selection_point_cloud_outliers

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

.. data:: compute_selection_transfer_face_to_vertex

   *MeshLab filter name*: 'Select Vertices from Faces'

   .. raw:: html

      Select vertices from selected faces.</p>

   **Parameters:**

   ``inclusive : bool = True``

      .. raw:: html

         <i>Strict Selection</i>: If true only the vertices with <b>all</b> the incident face selected are selected. Otherwise any vertex with at least one incident selected face will be selected.

.. data:: compute_selection_transfer_vertex_to_face

   *MeshLab filter name*: 'Select Faces from Vertices'

   .. raw:: html

      Select faces from selected vertices.</p>

   **Parameters:**

   ``inclusive : bool = True``

      .. raw:: html

         <i>Strict Selection</i>: If true only the faces with <b>all</b> selected vertices are selected. Otherwise any face with at least one selected vertex will be selected.

.. data:: compute_texcoord_by_function_per_vertex

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

   ``onselected : bool = False``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected vertices

.. data:: compute_texcoord_by_function_per_wedge

   *MeshLab filter name*: 'Per Wedge Texture Function'

   .. raw:: html

      Texture function using muparser to generate new per wedge tex coords for every face<br>Insert six functions each u v for each one of the three vertex of a face<br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>vi0, vi1, vi2</b> for vertex indices, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fi</b> for face index, <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

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

   ``onselected : bool = False``

      .. raw:: html

         <i>only on selection</i>: if checked, only affects selected faces

.. data:: compute_texcoord_parametrization_and_texture_from_registered_rasters

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

   ``colorcorrection : bool = True``

      .. raw:: html

         <i>Color correction</i>: If true, the final texture is corrected so as to ensure seamless transitions

   ``colorcorrectionfiltersize : int = 1``

      .. raw:: html

         <i>Color correction filter</i>: It is the radius (in pixel) of the kernel that is used to compute the difference between corresponding texels in different rasters. Default is 1 that generate a 3x3 kernel. Highest values increase the robustness of the color correction process in the case of strong image-to-geometry misalignments

   ``usedistanceweight : bool = True``

      .. raw:: html

         <i>Use distance weight</i>: Includes a weight accounting for the distance to the camera during the computation of reference images

   ``useimgborderweight : bool = True``

      .. raw:: html

         <i>Use image border weight</i>: Includes a weight accounting for the distance to the image border during the computation of reference images

   ``usealphaweight : bool = False``

      .. raw:: html

         <i>Use image alpha weight</i>: If true, alpha channel of the image is used as additional weight. In this way it is possible to mask-out parts of the images that should not be projected on the mesh. Please note this is not a transparency effect, but just influences the weigthing between different images

   ``cleanisolatedtriangles : bool = True``

      .. raw:: html

         <i>Clean isolated triangles</i>: Remove all patches compound of a single triangle by aggregating them to adjacent patches

   ``stretchingallowed : bool = False``

      .. raw:: html

         <i>UV stretching</i>: If true, texture coordinates are stretched so as to cover the full interval [0,1] for both directions

   ``texturegutter : int = 4``

      .. raw:: html

         <i>Texture gutter</i>: Extra boundary to add to each patch before packing in texture space (in pixels)

.. data:: compute_texcoord_parametrization_flat_plane_per_wedge

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

   ``aspectratio : bool = False``

      .. raw:: html

         <i>Preserve Ratio</i>: If checked the resulting parametrization will preserve the original apsect ratio of the model otherwise it will fill up the whole 0..1 uv space

   ``sidegutter : float = 0``

      .. raw:: html

         <i>Side Gutter</i>: Leave an empty space around the parametrization area of the specified size (in texture space); accepted range [0.0 - 0.5].

.. data:: compute_texcoord_parametrization_from_registered_rasters

   *MeshLab filter name*: 'Parameterization from registered rasters'

   .. raw:: html

      The mesh is parameterized by creating some patches that correspond to projection of portions of surfaces onto the set of registered rasters.</p>

   **Parameters:**

   ``usedistanceweight : bool = True``

      .. raw:: html

         <i>Use distance weight</i>: Includes a weight accounting for the distance to the camera during the computation of reference images

   ``useimgborderweight : bool = True``

      .. raw:: html

         <i>Use image border weight</i>: Includes a weight accounting for the distance to the image border during the computation of reference images

   ``usealphaweight : bool = False``

      .. raw:: html

         <i>Use image alpha weight</i>: If true, alpha channel of the image is used as additional weight. In this way it is possible to mask-out parts of the images that should not be projected on the mesh. Please note this is not a transparency effect, but just influences the weigthing between different images

   ``cleanisolatedtriangles : bool = True``

      .. raw:: html

         <i>Clean isolated triangles</i>: Remove all patches compound of a single triangle by aggregating them to adjacent patches

   ``stretchingallowed : bool = False``

      .. raw:: html

         <i>UV stretching</i>: If true, texture coordinates are stretched so as to cover the full interval [0,1] for both directions

   ``texturegutter : int = 4``

      .. raw:: html

         <i>Texture gutter</i>: Extra boundary to add to each patch before packing in texture space (in pixels)

.. data:: compute_texcoord_parametrization_triangle_trivial_per_wedge

   *MeshLab filter name*: 'Parametrization: Trivial Per-Triangle'

   .. raw:: html

      Builds a trivial triangle-by-triangle parametrization. <br> Two methods are provided, the first maps all triangles into equal sized triangles, while the second one adapt the size of the triangles in texture space to their original size.</p>

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

.. data:: compute_texcoord_transfer_vertex_to_wedge

   *MeshLab filter name*: 'Convert PerVertex UV into PerWedge UV'

   .. raw:: html

      Converts per Vertex Texture Coordinates to per Wedge Texture Coordinates. It does not merge superfluous vertices...</p>

.. data:: compute_texcoord_transfer_wedge_to_vertex

   *MeshLab filter name*: 'Convert PerWedge UV into PerVertex UV'

   .. raw:: html

      Converts per Wedge Texture Coordinates to per Vertex Texture Coordinates splitting vertices with not coherent Wedge coordinates.</p>

.. data:: compute_texmap_from_color

   *MeshLab filter name*: 'Transfer: Vertex Color to Texture'

   .. raw:: html

      Fills the specified texture using per-vertex color data of the mesh.</p>

   **Parameters:**

   ``textname : str = ''``

      .. raw:: html

         <i>Texture name</i>: The name of the texture to be created

   ``textw : int = 1024``

      .. raw:: html

         <i>Texture width (px)</i>: The texture width

   ``texth : int = 1024``

      .. raw:: html

         <i>Texture height (px)</i>: The texture height

   ``overwrite : bool = False``

      .. raw:: html

         <i>Overwrite texture</i>: if current mesh has a texture will be overwritten (with provided texture dimension)

   ``pullpush : bool = True``

      .. raw:: html

         <i>Fill texture</i>: if enabled the unmapped texture space is colored using a pull push filling algorithm, if false is set to black

.. data:: create_annulus

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

.. data:: create_cone

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

.. data:: create_cube

   *MeshLab filter name*: 'Box/Cube'

   .. raw:: html

      Create a Box, Cube, Hexahedron. You can specify the side length.</p>

   **Parameters:**

   ``size : float = 1``

      .. raw:: html

         <i>Scale factor</i>: Scales the new mesh

.. data:: create_dodecahedron

   *MeshLab filter name*: 'Dodecahedron'

   .. raw:: html

      Create an Dodecahedron</p>

.. data:: create_fractal_terrain

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

   ``saveasquality : bool = False``

      .. raw:: html

         <i>Save as vertex quality</i>: Saves the perturbation value as vertex quality.

.. data:: create_grid

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

   ``center : bool = False``

      .. raw:: html

         <i>centered on origin</i>: center grid generated by filter on origin.<br>Grid is first generated and than moved into origin (using muparser lib to perform fast calc on every vertex)

.. data:: create_icosahedron

   *MeshLab filter name*: 'Icosahedron'

   .. raw:: html

      Create an Icosahedron</p>

.. data:: create_implicit_surface

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

.. data:: create_mesh_by_grammar

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

.. data:: create_noisy_isosurface

   *MeshLab filter name*: 'Noisy Isosurface'

   .. raw:: html

      Create a isosurface perturbed by a noisy isosurface.</p>

   **Parameters:**

   ``resolution : int = 64``

      .. raw:: html

         <i>Grid Resolution</i>: Resolution of the side of the cubic grid used for the volume creation

.. data:: create_octahedron

   *MeshLab filter name*: 'Octahedron'

   .. raw:: html

      Create an Octahedron</p>

.. data:: create_sphere

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

.. data:: create_sphere_cap

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

.. data:: create_sphere_points

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

.. data:: create_tetrahedron

   *MeshLab filter name*: 'Tetrahedron'

   .. raw:: html

      Create a Tetrahedron</p>

.. data:: create_torus

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

.. data:: delete_current_mesh

   *MeshLab filter name*: 'Delete Current Mesh'

   .. raw:: html

      The current mesh layer is deleted</p>

.. data:: delete_current_raster

   *MeshLab filter name*: 'Delete Current Raster'

   .. raw:: html

      The current raster layer is deleted</p>

.. data:: delete_non_active_rasters

   *MeshLab filter name*: 'Delete all Non Selected Rasters'

   .. raw:: html

      All non selected raster layers are deleted</p>

.. data:: delete_non_visible_meshes

   *MeshLab filter name*: 'Delete all non visible Mesh Layers'

   .. raw:: html

      All the non visible mesh layers are deleted</p>

.. data:: export_mesh_to_sketchfab

   *MeshLab filter name*: 'Export to Sketchfab'

   .. raw:: html

      Upload the current layer on Sketchfab. It requires that you have an account and that you set your private API token in the preferences of MeshLab.</p>

   **Parameters:**

   ``sketchfabkeycode : str = '00000000'``

      .. raw:: html

         <i>SketchFab Account API token</i>: The API token of the account on which to upload the model.<br>You can find it by going on Settings -> Password and API -> API token.

   ``title : str = 'MeshLabModel'``

      .. raw:: html

         <i>Title</i>: Mandatory.

   ``description : str = 'A model generated with meshlab'``

      .. raw:: html

         <i>Description</i>: Mandatory. A short description of the model that is uploaded.

   ``tags : str = 'meshlab'``

      .. raw:: html

         <i>Tags</i>: Mandatory. Tags must be separated by a space. Typical tags usually used by MeshLab users: scan, photogrammetry.

   ``isprivate : bool = False``

      .. raw:: html

         <i>Private</i>: This parameter can be true only for PRO account.

   ``ispublished : bool = False``

      .. raw:: html

         <i>Publish</i>: If true the model will be published immediately.

   ``autorotate : bool = True``

      .. raw:: html

         <i>Auto Rotate</i>: If true the model rotated by 90 degree on the X axis to maintain similar default orientation.

   ``saveapisetting : bool = False``

      .. raw:: html

         <i>Save SketchFab Code</i>: Saves the API SketchFab code into the MeshLab settings, allowing to load it as default value every time you run this filter.

.. data:: generate_alpha_shape

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

.. data:: generate_boolean_difference

   *MeshLab filter name*: 'Mesh Boolean: Difference'

   .. raw:: html

      This filter extecutes an exact boolean difference between two meshes. <br>The filter uses the original code provided in the <a href="https://libigl.github.io/">libigl library</a>.<br>The implementation refers to the following paper:<br><i>Qingnan Zhou, Eitan Grinspun, Denis Zorin, Alec Jacobson</i>,<br><b>"Mesh Arrangements for Solid Geometry"</b><br></p>

   **Parameters:**

   ``first_mesh : int = 0``

      .. raw:: html

         <i>First Mesh</i>: The first operand of the boolean operation

   ``second_mesh : int = 0``

      .. raw:: html

         <i>Second Mesh</i>: The second operand of the boolean operation

   ``transfer_face_color : bool = False``

      .. raw:: html

         <i>Transfer face color</i>: Save the color of the birth face to the faces of resulting mesh.

   ``transfer_face_quality : bool = False``

      .. raw:: html

         <i>Transfer face quality</i>: Save the quality of the birth face to the faces of resulting mesh.

   ``transfer_vert_color : bool = False``

      .. raw:: html

         <i>Transfer vertex color</i>: Save the color of the birth vertex to the faces of resulting mesh. For newly created vertices, a simple average of the neighbours is computed.

   ``transfer_vert_quality : bool = False``

      .. raw:: html

         <i>Transfer vertex quality</i>: Save the quality of the birth vertex to the faces of resulting mesh.  For newly created vertices, a simple average of the neighbours is computed.

.. data:: generate_boolean_intersection

   *MeshLab filter name*: 'Mesh Boolean: Intersection'

   .. raw:: html

      This filter extecutes an exact boolean intersection between two meshes. <br>The filter uses the original code provided in the <a href="https://libigl.github.io/">libigl library</a>.<br>The implementation refers to the following paper:<br><i>Qingnan Zhou, Eitan Grinspun, Denis Zorin, Alec Jacobson</i>,<br><b>"Mesh Arrangements for Solid Geometry"</b><br></p>

   **Parameters:**

   ``first_mesh : int = 0``

      .. raw:: html

         <i>First Mesh</i>: The first operand of the boolean operation

   ``second_mesh : int = 0``

      .. raw:: html

         <i>Second Mesh</i>: The second operand of the boolean operation

   ``transfer_face_color : bool = False``

      .. raw:: html

         <i>Transfer face color</i>: Save the color of the birth face to the faces of resulting mesh.

   ``transfer_face_quality : bool = False``

      .. raw:: html

         <i>Transfer face quality</i>: Save the quality of the birth face to the faces of resulting mesh.

   ``transfer_vert_color : bool = False``

      .. raw:: html

         <i>Transfer vertex color</i>: Save the color of the birth vertex to the faces of resulting mesh. For newly created vertices, a simple average of the neighbours is computed.

   ``transfer_vert_quality : bool = False``

      .. raw:: html

         <i>Transfer vertex quality</i>: Save the quality of the birth vertex to the faces of resulting mesh.  For newly created vertices, a simple average of the neighbours is computed.

.. data:: generate_boolean_union

   *MeshLab filter name*: 'Mesh Boolean: Union'

   .. raw:: html

      This filter extecutes an exact boolean union between two meshes. <br>The filter uses the original code provided in the <a href="https://libigl.github.io/">libigl library</a>.<br>The implementation refers to the following paper:<br><i>Qingnan Zhou, Eitan Grinspun, Denis Zorin, Alec Jacobson</i>,<br><b>"Mesh Arrangements for Solid Geometry"</b><br></p>

   **Parameters:**

   ``first_mesh : int = 0``

      .. raw:: html

         <i>First Mesh</i>: The first operand of the boolean operation

   ``second_mesh : int = 0``

      .. raw:: html

         <i>Second Mesh</i>: The second operand of the boolean operation

   ``transfer_face_color : bool = False``

      .. raw:: html

         <i>Transfer face color</i>: Save the color of the birth face to the faces of resulting mesh.

   ``transfer_face_quality : bool = False``

      .. raw:: html

         <i>Transfer face quality</i>: Save the quality of the birth face to the faces of resulting mesh.

   ``transfer_vert_color : bool = False``

      .. raw:: html

         <i>Transfer vertex color</i>: Save the color of the birth vertex to the faces of resulting mesh. For newly created vertices, a simple average of the neighbours is computed.

   ``transfer_vert_quality : bool = False``

      .. raw:: html

         <i>Transfer vertex quality</i>: Save the quality of the birth vertex to the faces of resulting mesh.  For newly created vertices, a simple average of the neighbours is computed.

.. data:: generate_boolean_xor

   *MeshLab filter name*: 'Mesh Boolean: Symmetric Difference (XOR)'

   .. raw:: html

      This filter extecutes an exact boolean symmetric difference (XOR) between two meshes. <br>The filter uses the original code provided in the <a href="https://libigl.github.io/">libigl library</a>.<br>The implementation refers to the following paper:<br><i>Qingnan Zhou, Eitan Grinspun, Denis Zorin, Alec Jacobson</i>,<br><b>"Mesh Arrangements for Solid Geometry"</b><br></p>

   **Parameters:**

   ``first_mesh : int = 0``

      .. raw:: html

         <i>First Mesh</i>: The first operand of the boolean operation

   ``second_mesh : int = 0``

      .. raw:: html

         <i>Second Mesh</i>: The second operand of the boolean operation

   ``transfer_face_color : bool = False``

      .. raw:: html

         <i>Transfer face color</i>: Save the color of the birth face to the faces of resulting mesh.

   ``transfer_face_quality : bool = False``

      .. raw:: html

         <i>Transfer face quality</i>: Save the quality of the birth face to the faces of resulting mesh.

   ``transfer_vert_color : bool = False``

      .. raw:: html

         <i>Transfer vertex color</i>: Save the color of the birth vertex to the faces of resulting mesh. For newly created vertices, a simple average of the neighbours is computed.

   ``transfer_vert_quality : bool = False``

      .. raw:: html

         <i>Transfer vertex quality</i>: Save the quality of the birth vertex to the faces of resulting mesh.  For newly created vertices, a simple average of the neighbours is computed.

.. data:: generate_by_merging_visible_meshes

   *MeshLab filter name*: 'Flatten Visible Layers'

   .. raw:: html

      Flatten all or only the visible layers into a single new mesh. <br> Transformations are preserved. Existing layers can be optionally deleted</p>

   **Parameters:**

   ``mergevisible : bool = True``

      .. raw:: html

         <i>Merge Only Visible Layers</i>: If true, flatten only visible layers, otherwise, all layers are used.

   ``deletelayer : bool = True``

      .. raw:: html

         <i>Delete Layers </i>: Delete all the layers used as source in flattening. <br>If all layers are visible only a single layer will remain after the invocation of this filter.

   ``mergevertices : bool = True``

      .. raw:: html

         <i>Merge duplicate vertices</i>: Merge the vertices that are duplicated among different layers. <br><br>Very useful when the layers are spliced portions of a single big mesh.

   ``alsounreferenced : bool = True``

      .. raw:: html

         <i>Keep unreferenced vertices</i>: Do not discard unreferenced vertices from source layers<br><br>Necessary for point-cloud layers.

.. data:: generate_convex_hull

   *MeshLab filter name*: 'Convex Hull'

   .. raw:: html

      Calculate the <b>convex hull</b> with Qhull library (http://www.qhull.org/html/qconvex.htm).<br><br> The convex hull of a set of points is the boundary of the minimal convex set containing the given non-empty finite set of points.</p>

.. data:: generate_copy_of_current_mesh

   *MeshLab filter name*: 'Duplicate Current layer'

   .. raw:: html

      Create a new layer containing the same model as the current one</p>

.. data:: generate_cylindrical_unwrapping

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

.. data:: generate_dust_accumulation_point_cloud

   *MeshLab filter name*: 'Dust Accumulation'

   .. raw:: html

      Simulate dust accumulation over the mesh generating a cloud of points lying on the current mesh</p>

   **Parameters:**

   ``dust_dir : numpy.ndarray[numpy.float64[3]] = [0, 1, 0]``

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

   ``draw_texture : bool = False``

      .. raw:: html

         <i>Draw Dust</i>: create a new texture saved in dirt_texture.png

.. data:: generate_from_selected_faces

   *MeshLab filter name*: 'Move selected faces to another layer'

   .. raw:: html

      Selected faces are moved (or duplicated) in a new layer. Warning! per-vertex and per-face user defined attributes will not be transferred.</p>

   **Parameters:**

   ``deleteoriginal : bool = True``

      .. raw:: html

         <i>Delete original selection</i>: Deletes the original selected faces/vertices, thus splitting the mesh among layers.<br><br>if false, the selected faces/vertices are duplicated in the new layer.

.. data:: generate_from_selected_vertices

   *MeshLab filter name*: 'Move selected vertices to another layer'

   .. raw:: html

      Selected vertices are moved (or duplicated) in a new layer. Warning! per-vertex user defined attributes will not be transferred.</p>

   **Parameters:**

   ``deleteoriginal : bool = True``

      .. raw:: html

         <i>Delete original selection</i>: Deletes the original selected faces/vertices, thus splitting the mesh among layers.<br><br>if false, the selected faces/vertices are duplicated in the new layer.

.. data:: generate_iso_parametrization_atlased_mesh

   *MeshLab filter name*: 'Iso Parametrization Build Atlased Mesh'

   .. raw:: html

      The filter build a new mesh with a standard atlased per wedge texture. The atlas is simply done by exploiting the low distortion, coarse, regular, mesh of the abstract domain<br>For more details see: <br><b>N. Pietroni, M. Tarini and P. Cignoni</b>, <br><a href="http://vcg.isti.cnr.it/Publications/2010/PTC10/">'Almost isometric mesh parameterization through abstract domains'</a> <br>IEEE Transaction of Visualization and Computer Graphics, 2010</p>

   **Parameters:**

   ``bordersize : float (bounded) = 0.1 [min: 0.01; max: 0.5]``

      .. raw:: html

         <i>BorderSize ratio</i>: This parameter controls the amount of space that must be left between each diamond when building the atlas.It directly affects how many triangle are split during this conversion. <br>In abstract parametrization mesh triangles can naturally cross the triangles of the abstract domain, so when converting to a standard parametrization we must cut all the triangles that protrudes outside each diamond more than the specified threshold.The unit of the threshold is in percentage of the size of the diamond,The bigger the threshold the less triangles are split, but the more UV space is used (wasted).

.. data:: generate_iso_parametrization_remeshing

   *MeshLab filter name*: 'Iso Parametrization Remeshing'

   .. raw:: html

      Uniform Remeshing based on Isoparameterization, each triangle of the domain is recursively subdivided. <br>For more details see: <br><b>N. Pietroni, M. Tarini and P. Cignoni</b>, <br><a href="http://vcg.isti.cnr.it/Publications/2010/PTC10/">'Almost isometric mesh parameterization through abstract domains'</a> <br>IEEE Transaction of Visualization and Computer Graphics, 2010</p>

   **Parameters:**

   ``samplingrate : int = 10``

      .. raw:: html

         <i>Sampling Rate</i>: This specify the sampling rate for remeshing. Must be greater than 2

.. data:: generate_marching_cubes_apss

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

   ``accuratenormal : bool = True``

      .. raw:: html

         <i>Accurate normals</i>: If checked, use the accurate MLS gradient instead of the local approximationto compute the normals.

   ``resolution : int = 200``

      .. raw:: html

         <i>Grid Resolution</i>: The resolution of the grid on which we run the marching cubes.This marching cube is memory friendly, so you can safely set large values up to 1000 or even more.

.. data:: generate_marching_cubes_rimls

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

.. data:: generate_plane_fitting_to_selection

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

   ``hasuv : bool = False``

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

.. data:: generate_polyline_from_planar_section

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

   ``customaxis : numpy.ndarray[numpy.float64[3]] = [0, 1, 0]``

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

   ``createsectionsurface : bool = False``

      .. raw:: html

         <i>Create also section surface</i>: If selected, in addition to a layer with the section polyline, it will be created also a layer with a triangulated version of the section polyline. This only works if the section polyline is closed

   ``splitsurfacewithsection : bool = False``

      .. raw:: html

         <i>Create also split surfaces</i>: If selected, it will create two layers with the portion of the mesh under and over the section plane. It requires manifoldness of the mesh.

.. data:: generate_polyline_from_selected_edges

   *MeshLab filter name*: 'Build a Polyline from Selected Edges'

   .. raw:: html

      Create a new Layer with an edge mesh composed only by the selected edges of the current mesh</p>

.. data:: generate_polyline_from_selection_perimeter

   *MeshLab filter name*: 'Create Selection Perimeter Polyline'

   .. raw:: html

      Create a new Layer with the perimeter polyline(s) of the selection borders</p>

.. data:: generate_resampled_uniform_mesh

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

   ``mergeclosevert : bool = False``

      .. raw:: html

         <i>Clean Vertices</i>: If true the mesh generated by MC will be cleaned by unifying vertices that are almost coincident

   ``discretize : bool = False``

      .. raw:: html

         <i>Discretize</i>: If true the position of the intersected edge of the marching cube grid is not computed by linear interpolation, but it is placed in fixed middle position. As a consequence the resampled object will look severely aliased by a stairstep appearance.<br>Useful only for simulating the output of 3D printing devices.

   ``multisample : bool = False``

      .. raw:: html

         <i>Multi-sample</i>: If true the distance field is more accurately compute by multisampling the volume (7 sample for each voxel). Much slower but less artifacts.

   ``absdist : bool = False``

      .. raw:: html

         <i>Absolute Distance</i>: If true a <b> not</b> signed distance field is computed. In this case you have to choose a not zero Offset and a double surface is built around the original surface, inside and outside. Is useful to convert thin floating surfaces into <i> solid, thick meshes.</i>. t

.. data:: generate_sampling_clustered_vertex

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

   ``selected : bool = False``

      .. raw:: html

         <i>Only on Selection</i>: If true only for the filter is applied only on the selected subset of the mesh.

.. data:: generate_sampling_element

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

.. data:: generate_sampling_montecarlo

   *MeshLab filter name*: 'Montecarlo Sampling'

   .. raw:: html

      Create a new layer populated with a point sampling of the current mesh; samples are generated in a randomly uniform way, or with a distribution biased by the per-vertex quality values of the mesh.</p>

   **Parameters:**

   ``samplenum : int = 8``

      .. raw:: html

         <i>Number of samples</i>: The desired number of samples. It can be smaller or larger than the mesh size, and according to the chosen sampling strategy it will try to adapt.

   ``weighted : bool = False``

      .. raw:: html

         <i>Quality Weighted Sampling</i>: Use per vertex quality to drive the vertex sampling. The number of samples falling in each face is proportional to the face area multiplied by the average quality of the face vertices.

   ``perfacenormal : bool = False``

      .. raw:: html

         <i>Per-Face Normal</i>: If true for each sample we take the normal of the sampled face, otherwise the normal interpolated from the vertex normals.

   ``radiusvariance : float = 1``

      .. raw:: html

         <i>Radius Variance</i>: The radius of the disk is allowed to vary between r/var and r*var. If this parameter is 1 the sampling is the same of the Poisson Disk Sampling

   ``exactnum : bool = True``

      .. raw:: html

         <i>Exact Sample Number</i>: If the required total number of samples is not a strict exact requirement we can exploit a different algorithmbased on the choice of the number of samples inside each triangle by a random Poisson-distributed number with mean equal to the expected number of samples times the area of the triangle over the surface of the whole mesh.

   ``edgesampling : bool = False``

      .. raw:: html

         <i>Sample CreaseEdge Only</i>: Restrict the sampling process to the crease edges only. Useful to sample in a more accurate way the feature edges of a mechanical mesh.

.. data:: generate_sampling_poisson_disk

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

   ``savemontecarlo : bool = False``

      .. raw:: html

         <i>Save Montecarlo</i>: If true, it will generate an additional Layer with the montecarlo sampling that was pruned to build the poisson distribution.

   ``approximategeodesicdistance : bool = False``

      .. raw:: html

         <i>Approximate Geodesic Distance</i>: If true Poisson Disc distances are computed using an approximate geodesic distance, e.g. an euclidean distance weighted by a function of the difference between the normals of the two points.

   ``subsample : bool = False``

      .. raw:: html

         <i>Base Mesh Subsampling</i>: If true the original vertices of the base mesh are used as base set of points. In this case the SampleNum should be obviously much smaller than the original vertex number.<br>Note that this option is very useful in the case you want to subsample a dense point cloud.

   ``refineflag : bool = False``

      .. raw:: html

         <i>Refine Existing Samples</i>: If true the vertices of the below mesh are used as starting vertices, and they will utterly refined by adding more and more points until possible. 

   ``refinemesh : int = 0``

      .. raw:: html

         <i>Samples to be refined</i>: Used only if the above option is checked. 

   ``bestsampleflag : bool = True``

      .. raw:: html

         <i>Best Sample Heuristic</i>: If true it will use a simple heuristic for choosing the samples. At a small cost (it can slow a bit the process) it usually improve the maximality of the generated sampling. 

   ``bestsamplepool : int = 10``

      .. raw:: html

         <i>Best Sample Pool Size</i>: Used only if the Best Sample Flag is true. It control the number of attempt that it makes to get the best sample. It is reasonable that it is smaller than the Montecarlo oversampling factor.

   ``exactnumflag : bool = False``

      .. raw:: html

         <i>Exact number of samples</i>: If requested it will try to do a dicotomic search for the best poisson disk radius that will generate the requested number of samples with a tolerance of the 0.5%. Obviously it takes much longer.

   ``radiusvariance : float = 1``

      .. raw:: html

         <i>Radius Variance</i>: The radius of the disk is allowed to vary between r and r*var. If this parameter is 1 the sampling is the same of the Poisson Disk Sampling

.. data:: generate_sampling_regular_recursive

   *MeshLab filter name*: 'Regular Recursive Sampling'

   .. raw:: html

      The bounding box is recursively partitioned in a octree style, center of bbox are considered, when the center is nearer to the surface than a given threshold it is projected on it. It works also for building offsetted samples.</p>

   **Parameters:**

   ``cellsize : Percentage = 2%``

      .. raw:: html

         <i>Precision</i>: Size of the cell, the default is 1/50 of the box diag. Smaller cells give better precision at a higher computational cost. Remember that halving the cell size means that you build a volume 8 times larger.

   ``offset : Percentage = 50%``

      .. raw:: html

         <i>Offset</i>: Offset of the created surface (i.e. distance of the created surface from the original one).<br>If offset is zero, the created surface passes on the original mesh itself. Values greater than zero mean an external surface, and lower than zero mean an internal surface.<br> In practice this value is the threshold passed to the Marching Cube algorithm to extract the isosurface from the distance field representation.

.. data:: generate_sampling_stratified_triangle

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

   ``random : bool = False``

      .. raw:: html

         <i>Random Sampling</i>: if true, for each (virtual) face we draw a random point, otherwise we pick the face midpoint.

.. data:: generate_sampling_texel

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

   ``texturespace : bool = False``

      .. raw:: html

         <i>UV Space Sampling</i>: The generated texel samples have their UV coords as point positions. The resulting point set is has a square domain, the texels/points, even if on a flat domain retain the original vertex normal to help a better perception of the original provenience.

   ``recovercolor : bool = False``

      .. raw:: html

         <i>RecoverColor</i>: The generated point cloud has the current texture color

.. data:: generate_sampling_volumetric

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

   ``poissonfiltering : bool = True``

      .. raw:: html

         <i>Poisson Filtering</i>: If true the base montecarlo sampling of the volume is filtered to get a poisson disk volumetric distribution.

   ``poissonradius : Percentage = 1%``

      .. raw:: html

         <i>Poisson Radius</i>: Number of voxel per side in the volumetric representation.

.. data:: generate_sampling_voronoi

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

   ``preprocessflag : bool = False``

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

.. data:: generate_simplified_point_cloud

   *MeshLab filter name*: 'Point Cloud Simplification'

   .. raw:: html

      Create a new layer populated with a simplified version of the current point cloud. The simplification is performed by subsampling the original point cloud using a Poisson Disk strategy.</p>

   **Parameters:**

   ``samplenum : int = 1000``

      .. raw:: html

         <i>Number of samples</i>: The desired number of samples. The ray of the disk is calculated according to the sampling density.

   ``radius : Percentage = 0%``

      .. raw:: html

         <i>Explicit Radius</i>: If not zero this parameter override the previous parameter to allow exact radius specification

   ``bestsampleflag : bool = True``

      .. raw:: html

         <i>Best Sample Heuristic</i>: If true it will use a simple heuristic for choosing the samples. At a small cost (it can slow a bit the process) it usually improve the maximality of the generated sampling. 

   ``bestsamplepool : int = 10``

      .. raw:: html

         <i>Best Sample Pool Size</i>: Used only if the Best Sample Flag is true. It control the number of attempt that it makes to get the best sample. It is reasonable that it is smaller than the Montecarlo oversampling factor.

   ``exactnumflag : bool = False``

      .. raw:: html

         <i>Exact number of samples</i>: If requested it will try to do a dicotomic search for the best poisson disk radius that will generate the requested number of samples with a tolerance of the 0.5%. Obviously it takes much longer.

.. data:: generate_solid_wireframe

   *MeshLab filter name*: 'Create Solid Wireframe'

   .. raw:: html

      </p>

   **Parameters:**

   ``edgecylflag : bool = True``

      .. raw:: html

         <i>Edge -> Cyl.</i>: If True all the edges are converted into cylinders.

   ``edgecylradius : Percentage = 1%``

      .. raw:: html

         <i>Edge Cylinder Rad.</i>: The radius of the cylinder replacing each edge.

   ``vertcylflag : bool = False``

      .. raw:: html

         <i>Vertex -> Cyl.</i>: If True all the vertices are converted into cylinders.

   ``vertcylradius : Percentage = 1%``

      .. raw:: html

         <i>Vertex Cylinder Rad.</i>: The radius of the cylinder replacing each vertex.

   ``vertsphflag : bool = True``

      .. raw:: html

         <i>Vertex -> Sph.</i>: If True all the vertices are converted into sphere.

   ``vertsphradius : Percentage = 1%``

      .. raw:: html

         <i>Vertex Sphere Rad.</i>: The radius of the sphere replacing each vertex.

   ``faceextflag : bool = True``

      .. raw:: html

         <i>Face -> Prism</i>: If True all the faces are converted into prism.

   ``faceextheight : Percentage = 0.5%``

      .. raw:: html

         <i>Face Prism Height</i>: The Height of the prism that is substituted with each face.

   ``faceextinset : Percentage = 0.5%``

      .. raw:: html

         <i>Face Prism Inset</i>: The inset radius of each prism, e.g. how much it is moved toward the inside each vertex on the border of the prism.

   ``edgefauxflag : bool = True``

      .. raw:: html

         <i>Ignore faux edges</i>: If true only the Non-Faux edges will be considered for conversion.

   ``cylindersidenum : int = 16``

      .. raw:: html

         <i>Cylinder Side</i>: Number of sides of the cylinder (both edge and vertex).

.. data:: generate_splitting_by_connected_components

   *MeshLab filter name*: 'Split in Connected Components'

   .. raw:: html

      Split current Layer into many layers, one for each connected components</p>

   **Parameters:**

   ``delete_source_mesh : bool = False``

      .. raw:: html

         <i>Delete source mesh</i>: Deletes the source mesh after all the connected component meshes are generated.

.. data:: generate_surface_reconstruction_ball_pivoting

   *MeshLab filter name*: 'Surface Reconstruction: Ball Pivoting'

   .. raw:: html

      Given a point cloud with normals it reconstructs a surface using the <b>Ball Pivoting Algorithm</b>.Starting with a seed triangle, the BPA algorithm  pivots a ball of the given radius around the already formed edges until it touches another point, forming another triangle. The process continues until all reachable edges have been tried. This surface reconstruction algorithm uses the existing points without creating new ones. Works better with uniformly sampled point clouds. If needed first perform a poisson disk subsampling of the point cloud. <br>Bernardini F., Mittleman J., Rushmeier H., Silva C., Taubin G.<br><b>The ball-pivoting algorithm for surface reconstruction.</b><br>IEEE TVCG 1999</p>

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

   ``deletefaces : bool = False``

      .. raw:: html

         <i>Delete initial set of faces</i>: if true all the initial faces of the mesh are deleted and the whole surface is rebuilt from scratch. Otherwise the current faces are used as a starting point. Useful if you run the algorithm multiple times with an increasing ball radius.

.. data:: generate_surface_reconstruction_screened_poisson

   *MeshLab filter name*: 'Surface Reconstruction: Screened Poisson'

   .. raw:: html

      This surface reconstruction algorithm creates watertight surfaces from oriented point sets.<br>The filter uses the original code of Michael Kazhdan and Matthew Bolitho implementing the algorithm described in the following paper:<br><i>Michael Kazhdan, Hugues Hoppe</i>,<br><b>"Screened Poisson surface reconstruction"</b><br></p>

   **Parameters:**

   ``visiblelayer : bool = False``

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

   ``confidence : bool = False``

      .. raw:: html

         <i>Confidence Flag</i>: Enabling this flag tells the reconstructor to use the quality as confidence information; this is done by scaling the unit normals with the quality values. When the flag is not enabled, all normals are normalized to have unit-length prior to reconstruction.

   ``preclean : bool = False``

      .. raw:: html

         <i>Pre-Clean</i>: Enabling this flag force a cleaning pre-pass on the data removing all unreferenced vertices or vertices with null normals.

.. data:: generate_surface_reconstruction_vcg

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

   ``openresult : bool = True``

      .. raw:: html

         <i>Show Result</i>: if not checked the result is only saved into the current directory

   ``smoothnum : int = 1``

      .. raw:: html

         <i>Volume Laplacian iter</i>: How many volume smoothing step are performed to clean out the eventually noisy borders

   ``widenum : int = 3``

      .. raw:: html

         <i>Widening</i>:  How many voxel the field is expanded. Larger this value more holes will be filled

   ``mergecolor : bool = False``

      .. raw:: html

         <i>Vertex Splatting</i>: This option use a different way to build up the volume, instead of using rasterization of the triangular face it splat the vertices into the grids. It works under the assumption that you have at least one sample for each voxel of your reconstructed volume.

   ``simplification : bool = False``

      .. raw:: html

         <i>Post Merge simplification</i>: After the merging an automatic simplification step is performed.

   ``normalsmooth : int = 3``

      .. raw:: html

         <i>PreSmooth iter</i>: How many times, before converting meshes into volume, the normal of the surface are smoothed. It is useful only to get more smooth expansion in case of noisy borders.

.. data:: generate_voronoi_atlas_parametrization

   *MeshLab filter name*: 'Parametrization: Voronoi Atlas'

   .. raw:: html

      Build an atlased parametrization based on a geodesic voronoi partitioning of the surface and parametrizing each region using Harmonic Mapping. For the  parametrization of the disk like voronoi regions the used method is: <br><b>Ulrich Pinkall, Konrad Polthier</b><br><i>Computing Discrete Minimal Surfaces and Their Conjugates</i> <br>Experimental Mathematics, Vol 2 (1), 1993.</p>

   **Parameters:**

   ``regionnum : int = 10``

      .. raw:: html

         <i>Approx. Region Num</i>: An estimation of the number of regions that must be generated. Smaller regions could lead to parametrizations with smaller distortion.

   ``overlapflag : bool = False``

      .. raw:: html

         <i>Overlap</i>: If checked the resulting parametrization will be composed by <i>overlapping</i> regions, e.g. the resulting mesh will have duplicated faces: each region will have a ring of ovelapping duplicate faces that will ensure that border regions will be parametrized in the atlas twice. This is quite useful for building mipmap robust atlases

.. data:: generate_voronoi_filtering

   *MeshLab filter name*: 'Voronoi Filtering'

   .. raw:: html

      Compute a <b>Voronoi filtering</b> (Amenta and Bern 1998) with Qhull library (http://www.qhull.org/). <br><br>The algorithm calculates a triangulation of the input point cloud without requiring vertex normals.It uses a subset of the Voronoi vertices to remove triangles from the Delaunay triangulation. <br>After computing the Voronoi diagram, foreach sample point it chooses the two farthest opposite Voronoi vertices.Then computes a Delaunay triangulation of the sample points and the selected Voronoi vertices, and keep only those triangles in witch all three vertices are sample points.</p>

   **Parameters:**

   ``threshold : float (bounded) = 10 [min: 0; max: 2000]``

      .. raw:: html

         <i>Pole Discard Thr</i>: Threshold used to discard the Voronoi vertices too far from the origin.We discard vertices are further than this factor times the bbox diagonal <br>Growing values of this value will add more Voronoi vertices for a better tightier surface reconstruction.On the other hand they will increase processing time and could cause numerical problems to the qhull library.<br>

.. data:: generate_voronoi_scaffolding

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

   ``surfflag : bool = True``

      .. raw:: html

         <i>Add original surface</i>: Number of voxel per side in the volumetric representation.

   ``elemtype : str = 'Edge' (or int = 1)``

      Possible enum values:

         0. ``'Seed'``
         1. ``'Edge'``
         2. ``'Face'``

      .. raw:: html

         <i>Voronoi Element</i>: 

.. data:: get_area_and_perimeter_of_selection

   *MeshLab filter name*: 'Compute Area/Perimeter of selection'

   .. raw:: html

      Compute area and perimeter of the FACE selection. Open the layer dialog to see the results.</p>

.. data:: get_depth_complexity

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

.. data:: get_geometric_measures

   *MeshLab filter name*: 'Compute Geometric Measures'

   .. raw:: html

      Compute a set of geometric measures of a mesh/pointcloud. Bounding box extents and diagonal, principal axis, thin shell barycenter (mesh only), vertex barycenter and quality-weighted barycenter (pointcloud only), surface area (mesh only), volume (closed mesh) and Inertia tensor Matrix (closed mesh). Open the layer dialog to see the results.</p>

.. data:: get_hausdorff_distance

   *MeshLab filter name*: 'Hausdorff Distance'

   .. raw:: html

      Compute the Hausdorff Distance between two layers, sampling one of the two and finding for each sample the closest point over the other mesh. Distance is stored in vertex quality of the sampled mesh.</p>

   **Parameters:**

   ``sampledmesh : int = 0``

      .. raw:: html

         <i>Sampled Mesh</i>: The mesh whose surface is sampled. For each sample we search the closest point on the Target Mesh.

   ``targetmesh : int = 0``

      .. raw:: html

         <i>Target Mesh</i>: The mesh that is sampled for the comparison.

   ``savesample : bool = False``

      .. raw:: html

         <i>Save Samples</i>: Save the position and distance of all the used samples on both the two surfaces, creating two new layers with two point clouds representing the used samples.

   ``samplevert : bool = True``

      .. raw:: html

         <i>Sample Vertices</i>: For the search of maxima it is useful to sample vertices and edges of the mesh with a greater care. It is quite probably the the farthest points falls along edges or on mesh vertices, and with uniform montecarlo sampling approachesthe probability of taking a sample over a vertex or an edge is theoretically null.<br>On the other hand this kind of sampling could make the overall sampling distribution slightly biased and slightly affects the cumulative results.

   ``sampleedge : bool = False``

      .. raw:: html

         <i>Sample Edges</i>: See the above comment.

   ``samplefauxedge : bool = False``

      .. raw:: html

         <i>Sample FauxEdge</i>: See the above comment.

   ``sampleface : bool = False``

      .. raw:: html

         <i>Sample Faces</i>: See the above comment.

   ``samplenum : int = 8``

      .. raw:: html

         <i>Number of samples</i>: The desired number of samples. It can be smaller or larger than the mesh size, and according to the chosen sampling strategy it will try to adapt.

   ``maxdist : Percentage = 50%``

      .. raw:: html

         <i>Max Distance</i>: Sample points for which we do not find anything within this distance are rejected and not considered neither for averaging nor for max.

.. data:: get_overlapping_meshes_graph

   *MeshLab filter name*: 'Overlapping Meshes'

   .. raw:: html

      Use an occupancy grid to see which meshes overlap between themselves.</p>

   **Parameters:**

   ``ogsize : int = 50000``

      .. raw:: html

         <i>Occupancy Grid Size</i>: To compute the overlap between range maps we discretize them into voxel and count them (both for area and overlap); This parameter affect the resolution of the voxelization process. Using a too fine voxelization can...

.. data:: get_scalar_histogram_per_face

   *MeshLab filter name*: 'Per Face Quality Histogram'

   .. raw:: html

      Compute an histogram of the values of the per-face quality.</p>

   **Parameters:**

   ``histmin : float = 0``

      .. raw:: html

         <i>Hist Min</i>: The faces are displaced of a vector whose norm is bounded by this value

   ``histmax : float = 0``

      .. raw:: html

         <i>Hist Max</i>: The faces are displaced of a vector whose norm is bounded by this value

   ``areaweighted : bool = False``

      .. raw:: html

         <i>Area Weighted</i>: If false, the histogram will report the number of faces with quality values falling in each bin of the histogram. If true each bin of the histogram will report the approximate area of the mesh with that range of values.

   ``binnum : int = 20``

      .. raw:: html

         <i>Bin number</i>: The number of bins of the histogram. E.g. the number of intervals in which the min..max range is subdivided into.

.. data:: get_scalar_histogram_per_vertex

   *MeshLab filter name*: 'Per Vertex Quality Histogram'

   .. raw:: html

      Compute an histogram of the values of the per-vertex quality. It can be useful to evaluate the distribution of the quality value over the surface. It can be discrete (e.g. based on vertex count or area weighted).</p>

   **Parameters:**

   ``histmin : float = 0``

      .. raw:: html

         <i>Hist Min</i>: The vertex are displaced of a vector whose norm is bounded by this value

   ``histmax : float = 0``

      .. raw:: html

         <i>Hist Max</i>: The vertex are displaced of a vector whose norm is bounded by this value

   ``areaweighted : bool = False``

      .. raw:: html

         <i>Area Weighted</i>: If false, the histogram will report the number of vertices with quality values falling in each bin of the histogram. If true each bin of the histogram will report the approximate area of the mesh with that range of values. Area is computed by assigning to each vertex one third of the area all the incident triangles.

   ``binnum : int = 20``

      .. raw:: html

         <i>Bin number</i>: The number of bins of the histogram. E.g. the number of intervals in which the min..max range is subdivided into.

.. data:: get_scalar_statistics_per_face

   *MeshLab filter name*: 'Per Face Quality Stat'

   .. raw:: html

      Compute some aggregate statistics over the per vertex quality, like Min, Max, Average, StdDev and Variance.</p>

.. data:: get_scalar_statistics_per_vertex

   *MeshLab filter name*: 'Per Vertex Quality Stat'

   .. raw:: html

      Compute some aggregate statistics over the per vertex quality, like Min, Max, Average, StdDev and Variance.</p>

.. data:: get_topological_measures

   *MeshLab filter name*: 'Compute Topological Measures'

   .. raw:: html

      Compute a set of topological measures over a mesh.</p>

.. data:: get_topological_measures_from_quad_mesh

   *MeshLab filter name*: 'Compute Topological Measures for Quad Meshes'

   .. raw:: html

      Compute a set of topological measures over a quad mesh.</p>

.. data:: load_active_raster_cameras

   *MeshLab filter name*: 'Import cameras for active rasters from file'

   .. raw:: html

      Import cameras for active rasters from .out or Agisoft .xml formats</p>

   **Parameters:**

   ``importfile : str = ''``

      .. raw:: html

         <i>Choose the camera file to be imported</i>: It's possible to import both Bundler .out and Agisoft .xml files. In both cases, distortion parameters won't be imported. In the case of Agisoft, it's necessary to undistort the images before exporting the xml file.

.. data:: meshing_close_holes

   *MeshLab filter name*: 'Close Holes'

   .. raw:: html

      Close holes smaller than a given threshold</p>

   **Parameters:**

   ``maxholesize : int = 30``

      .. raw:: html

         <i>Max size to be closed </i>: The size is expressed as number of edges composing the hole boundary

   ``selected : bool = False``

      .. raw:: html

         <i>Close holes with selected faces</i>: Only the holes with at least one of the boundary faces selected are closed

   ``newfaceselected : bool = True``

      .. raw:: html

         <i>Select the newly created faces</i>: After closing a hole the faces that have been created are left selected. Any previous selection is lost. Useful for example for smoothing the newly created holes.

   ``selfintersection : bool = True``

      .. raw:: html

         <i>Prevent creation of selfIntersecting faces</i>: When closing an holes it tries to prevent the creation of faces that intersect faces adjacent to the boundary of the hole. It is an heuristic, non intersetcting hole filling can be NP-complete.

.. data:: meshing_cut_along_crease_edges

   *MeshLab filter name*: 'Cut mesh along crease edges'

   .. raw:: html

      Cut the mesh along crease edges, duplicating the vertices as necessary. Crease (or sharp) edges are defined according to the variation of normal of the adjacent faces.</p>

   **Parameters:**

   ``angledeg : float = 90``

      .. raw:: html

         <i>Crease Angle (degree)</i>: If the angle between the normals of two adjacent faces is <b>larger</b> that this threshold the edge is considered a creased and the mesh is cut along it.

.. data:: meshing_decimation_clustering

   *MeshLab filter name*: 'Simplification: Clustering Decimation'

   .. raw:: html

      Collapse vertices by creating a three dimensional grid enveloping the mesh and discretizes them based on the cells of this grid</p>

   **Parameters:**

   ``threshold : Percentage = 1%``

      .. raw:: html

         <i>Cell Size</i>: The size of the cell of the clustering grid. Smaller the cell finer the resulting mesh. For obtaining a very coarse mesh use larger values.

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: meshing_decimation_edge_collapse_for_marching_cube_meshes

   *MeshLab filter name*: 'Simplification: Edge Collapse for Marching Cube meshes'

   .. raw:: html

      A simplification/cleaning algorithm that works ONLY on meshes generated by Marching Cubes algorithm.</p>

.. data:: meshing_decimation_quadric_edge_collapse

   *MeshLab filter name*: 'Simplification: Quadric Edge Collapse Decimation'

   .. raw:: html

      Simplify a mesh using a quadric based edge-collapse strategy. A variant of the well known Garland and Heckbert simplification algorithm with different weighting schemes to better cope with aspect ration andd planar/degenerate quadrics areas.<br> See: <br><i>M. Garland and P. Heckbert.</i> <br><b>Surface Simplification Using Quadric Error Metrics</b> (<a href='http://mgarland.org/papers/quadrics.pdf'>pdf</a>)<br>In Proceedings of SIGGRAPH 97.<br/><br/></p>

   **Parameters:**

   ``targetfacenum : int = 6``

      .. raw:: html

         <i>Target number of faces</i>: The desired final number of faces.

   ``targetperc : float = 0``

      .. raw:: html

         <i>Percentage reduction (0..1)</i>: If non zero, this parameter specifies the desired final size of the mesh as a percentage of the initial size.

   ``qualitythr : float = 0.3``

      .. raw:: html

         <i>Quality threshold</i>: Quality threshold for penalizing bad shaped faces.<br>The value is in the range [0..1]<br> 0 accept any kind of face (no penalties),<br> 0.5  penalize faces with quality < 0.5, proportionally to their shape<br>

   ``preserveboundary : bool = False``

      .. raw:: html

         <i>Preserve Boundary of the mesh</i>: The simplification process tries to do not affect mesh boundaries during simplification

   ``boundaryweight : float = 1``

      .. raw:: html

         <i>Boundary Preserving Weight</i>: The importance of the boundary during simplification. Default (1.0) means that the boundary has the same importance of the rest. Values greater than 1.0 raise boundary importance and has the effect of removing less vertices on the border. Admitted range of values (0,+inf). 

   ``preservenormal : bool = False``

      .. raw:: html

         <i>Preserve Normal</i>: Try to avoid face flipping effects and try to preserve the original orientation of the surface

   ``preservetopology : bool = False``

      .. raw:: html

         <i>Preserve Topology</i>: Avoid all the collapses that should cause a topology change in the mesh (like closing holes, squeezing handles, etc). If checked the genus of the mesh should stay unchanged.

   ``optimalplacement : bool = True``

      .. raw:: html

         <i>Optimal position of simplified vertices</i>: Each collapsed vertex is placed in the position minimizing the quadric error.<br> It can fail (creating bad spikes) in case of very flat areas. <br>If disabled edges are collapsed onto one of the two original vertices and the final mesh is composed by a subset of the original vertices. 

   ``planarquadric : bool = False``

      .. raw:: html

         <i>Planar Simplification</i>: Add additional simplification constraints that improves the quality of the simplification of the planar portion of the mesh, as a side effect, more triangles will be preserved in flat areas (allowing better shaped triangles).

   ``planarweight : float = 0.001``

      .. raw:: html

         <i>Planar Simp. Weight</i>: How much we should try to preserve the triangles in the planar regions. If you lower this value planar areas will be simplified more.

   ``qualityweight : bool = False``

      .. raw:: html

         <i>Weighted Simplification</i>: Use the Per-Vertex quality as a weighting factor for the simplification. The weight is used as a error amplification value, so a vertex with a high quality value will not be simplified and a portion of the mesh with low quality values will be aggressively simplified.

   ``autoclean : bool = True``

      .. raw:: html

         <i>Post-simplification cleaning</i>: After the simplification an additional set of steps is performed to clean the mesh (unreferenced vertices, bad faces, etc)

   ``selected : bool = False``

      .. raw:: html

         <i>Simplify only selected faces</i>: The simplification is applied only to the selected set of faces.<br> Take care of the target number of faces!

.. data:: meshing_decimation_quadric_edge_collapse_with_texture

   *MeshLab filter name*: 'Simplification: Quadric Edge Collapse Decimation (with texture)'

   .. raw:: html

      Simplify a textured mesh using a Quadric based Edge Collapse Strategy preserving UV parametrization. Inspired in the QSLIM surface simplification algorithm by Michael Garland, which turned into the industry standar method for mesh simplification.<br> See: <br><i>M. Garland and P. Heckbert.</i> <br><b>Simplifying Surfaces with Color and Texture using Quadric Error Metrics</b> (<a href='http://mgarland.org/papers/quadric2.pdf'>pdf</a>)<br> In Proceedings of IEEE Visualization 98.<br/><br/></p>

   **Parameters:**

   ``targetfacenum : int = 6``

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

   ``preserveboundary : bool = False``

      .. raw:: html

         <i>Preserve Boundary of the mesh</i>: The simplification process tries not to destroy mesh boundaries

   ``boundaryweight : float = 1``

      .. raw:: html

         <i>Boundary Preserving Weight</i>: The importance of the boundary during simplification. Default (1.0) means that the boundary has the same importance of the rest. Values greater than 1.0 raise boundary importance and has the effect of removing less vertices on the border. Admitted range of values (0,+inf). 

   ``optimalplacement : bool = True``

      .. raw:: html

         <i>Optimal position of simplified vertices</i>: Each collapsed vertex is placed in the position minimizing the quadric error.<br> It can fail (creating bad spikes) in case of very flat areas. <br>If disabled edges are collapsed onto one of the two original vertices and the final mesh is composed by a subset of the original vertices. 

   ``preservenormal : bool = False``

      .. raw:: html

         <i>Preserve Normal</i>: Try to avoid face flipping effects and try to preserve the original orientation of the surface

   ``planarquadric : bool = False``

      .. raw:: html

         <i>Planar Simplification</i>: Add additional simplification constraints that improves the quality of the simplification of the planar portion of the mesh.

   ``selected : bool = False``

      .. raw:: html

         <i>Simplify only selected faces</i>: The simplification is applied only to the selected set of faces.<br> Take care of the target number of faces!

.. data:: meshing_edge_flip_by_curvature_optimization

   *MeshLab filter name*: 'Curvature flipping optimization'

   .. raw:: html

      Mesh optimization by edge flipping, to improve local mesh curvature</p>

   **Parameters:**

   ``selection : bool = False``

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

.. data:: meshing_edge_flip_by_planar_optimization

   *MeshLab filter name*: 'Planar flipping optimization'

   .. raw:: html

      Mesh optimization by edge flipping, to improve local triangle quality</p>

   **Parameters:**

   ``selection : bool = False``

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

.. data:: meshing_invert_face_orientation

   *MeshLab filter name*: 'Invert Faces Orientation'

   .. raw:: html

      Invert faces orientation, flipping the normals of the mesh. <br>If requested, it tries to guess the right orientation; mainly it decide to flip all the faces if the minimum/maximum vertices have not outward point normals for a few directions.<br>Works well for single component watertight objects.</p>

   **Parameters:**

   ``forceflip : bool = True``

      .. raw:: html

         <i>Force Flip</i>: If selected, the normals will always be flipped; otherwise, the filter tries to set them outside

   ``onlyselected : bool = False``

      .. raw:: html

         <i>Flip only selected faces</i>: If selected, only selected faces will be affected

.. data:: meshing_isotropic_explicit_remeshing

   *MeshLab filter name*: 'Remeshing: Isotropic Explicit Remeshing'

   .. raw:: html

      Perform a explicit remeshing of a triangular mesh, by repeatedly applying edge flip, collapse, relax and refine operations to regularize size and aspect ration of the triangular meshing. Loosely inspired to:<br>Hugues Hoppe, Tony DeRose, Tom Duchamp, John McDonald, and Werner Stuetzle.<br>Mesh optimization<br>(SIGGRAPH '93). ACM, New York, NY, USA, 19–26. <a href='https://doi.org/10.1145/166117.166119'>DOI</a></p>

   **Parameters:**

   ``iterations : int = 3``

      .. raw:: html

         <i>Iterations</i>: Number of iterations of the remeshing operations to repeat on the mesh.

   ``adaptive : bool = False``

      .. raw:: html

         <i>Adaptive remeshing</i>: Toggles adaptive isotropic remeshing.

   ``selectedonly : bool = False``

      .. raw:: html

         <i>Remesh only selected faces</i>: If checked the remeshing operations will be applied only to the selected faces.

   ``targetlen : Percentage = 1%``

      .. raw:: html

         <i>Target Length</i>: Sets the target length for the remeshed mesh edges.

   ``featuredeg : float = 30``

      .. raw:: html

         <i>Crease Angle</i>: Minimum angle between faces of the original to consider the shared edge as a feature to be preserved.

   ``checksurfdist : bool = True``

      .. raw:: html

         <i>Check Surface Distance</i>: If toggled each local operation must deviate from original mesh by [Max. surface distance]

   ``maxsurfdist : Percentage = 1%``

      .. raw:: html

         <i>Max. Surface Distance</i>: Maximal surface deviation allowed for each local operation

   ``splitflag : bool = True``

      .. raw:: html

         <i>Refine Step</i>: If checked the remeshing operations will include a refine step.

   ``collapseflag : bool = True``

      .. raw:: html

         <i>Collapse Step</i>: If checked the remeshing operations will include a collapse step.

   ``swapflag : bool = True``

      .. raw:: html

         <i>Edge-Swap Step</i>: If checked the remeshing operations will include a edge-swap step, aimed at improving the vertex valence of the resulting mesh.

   ``smoothflag : bool = True``

      .. raw:: html

         <i>Smooth Step</i>: If checked the remeshing operations will include a smoothing step, aimed at relaxing the vertex positions in a Laplacian sense.

   ``reprojectflag : bool = True``

      .. raw:: html

         <i>Reproject Step</i>: If checked the remeshing operations will include a step to reproject the mesh vertices on the original surface.

.. data:: meshing_merge_close_vertices

   *MeshLab filter name*: 'Merge Close Vertices'

   .. raw:: html

      Merge together all the vertices that are nearer than the specified threshold. Like a unify duplicated vertices but with some tolerance.</p>

   **Parameters:**

   ``threshold : Percentage = 1%``

      .. raw:: html

         <i>Merging distance</i>: All the vertices that closer than this threshold are merged together. Use very small values, default values is 1/10000 of bounding box diagonal. 

.. data:: meshing_poly_to_tri

   *MeshLab filter name*: 'Turn into a Pure-Triangular mesh'

   .. raw:: html

      Convert into a tri-mesh by splitting any polygonal face.</p>

.. data:: meshing_re_orient_faces_coherentely

   *MeshLab filter name*: 'Re-Orient all faces coherentely'

   .. raw:: html

      Re-orient in a consistent way all the faces of the mesh. <br>The filter visits a mesh face to face, reorienting any unvisited face so that it is coherent to the already visited faces. If the surface is orientable it will end with a consistent orientation of all the faces. If the surface is not orientable (e.g. it is non manifold or non orientable like a moebius strip) the filter will not build a consistent orientation simply because it is not possible. The filter can end up in a consistent orientation that can be exactly the opposite of the expected one; in that case simply invert the whole mesh orientation.</p>

.. data:: meshing_refine_by_function

   *MeshLab filter name*: 'Refine User-Defined'

   .. raw:: html

      Refine current mesh with user defined parameters.<br>Specify a Boolean Function needed to select which edges will be cut for refinement purpose.<br>Each edge is identified with first and second vertex.<br>Arguments accepted are first and second vertex attributes:<br><br>It's possible to use parenthesis <b>()</b>, and predefined operators:<br><b>&&</b> (logic and), <b>||</b> (logic or), <b>&lt;</b>, <b>&lt;=</b>, <b>></b>, <b>>=</b>, <b>!=</b> (not equal), <b>==</b> (equal), <b>_?_:_</b> (c/c++ ternary operator)<br><br>It's possible to use the following per-face variables, or variables associated to the three vertex of every face:<br><b>x0,y0,z0</b> for the first vertex position, <b>x1,y1,z1</b> for the second vertex position, <b>x2,y2,z2</b> for the third vertex position, <b>nx0,ny0,nz0 nx1,ny1,nz1 nx2,ny2,nz2</b> for vertex normals, <b>r0,g0,b0,a0 r1,g1,b1,a1 r2,g2,b2,a2</b> for vertex colors, <b>vi0, vi1, vi2</b> for vertex indices, <b>q0,q1,q2</b> for vertex quality, <b>wtu0,wtv0 wtu1,wtv1 wtu2,wtv2</b> for per-wedge texture coords, <b>ti</b> for face texture index, <b>vsel0,vsel1,vsel2</b> for vertex selection (1 yes, 0 no) <b>fi</b> for face index, <b>fr,fg,fb,fa</b> for face color, <b>fq</b> for face quality, <b>fnx,fny,fnz</b> for face normal, <b>fsel</b> face selection (1 yes, 0 no).<br></p>

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

.. data:: meshing_remove_all_faces

   *MeshLab filter name*: 'Delete ALL Faces'

   .. raw:: html

      Delete ALL faces, turning the mesh into a pointcloud. May be applied also to all visible layers.</p>

   **Parameters:**

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected, the filter will be applied to all visible mesh Layers.

.. data:: meshing_remove_connected_component_by_diameter

   *MeshLab filter name*: 'Remove Isolated pieces (wrt Diameter)'

   .. raw:: html

      Delete isolated connected components whose diameter is smaller than the specified constant</p>

   **Parameters:**

   ``mincomponentdiag : Percentage = 10%``

      .. raw:: html

         <i>Enter max diameter of isolated pieces</i>: Delete all the connected components (floating pieces) with a diameter smaller than the specified one

   ``removeunref : bool = True``

      .. raw:: html

         <i>Remove unfreferenced vertices</i>: if true, the unreferenced vertices remaining after the face deletion are removed.

.. data:: meshing_remove_connected_component_by_face_number

   *MeshLab filter name*: 'Remove Isolated pieces (wrt Face Num.)'

   .. raw:: html

      Delete isolated connected components composed by a limited number of triangles</p>

   **Parameters:**

   ``mincomponentsize : int = 25``

      .. raw:: html

         <i>Enter minimum conn. comp size:</i>: Delete all the connected components (floating pieces) composed by a number of triangles smaller than the specified one

   ``removeunref : bool = True``

      .. raw:: html

         <i>Remove unfreferenced vertices</i>: if true, the unreferenced vertices remaining after the face deletion are removed.

.. data:: meshing_remove_duplicate_faces

   *MeshLab filter name*: 'Remove Duplicate Faces'

   .. raw:: html

      Delete all the duplicate faces. Two faces are considered equal if they are composed by the same set of vertices, regardless of the order of the vertices.</p>

.. data:: meshing_remove_duplicate_vertices

   *MeshLab filter name*: 'Remove Duplicate Vertices'

   .. raw:: html

      Check for every vertex on the mesh: if there are two vertices with same coordinates they are merged into a single one.</p>

.. data:: meshing_remove_folded_faces

   *MeshLab filter name*: 'Remove Isolated Folded Faces by Edge Flip'

   .. raw:: html

      Delete all the single folded faces. A face is considered folded if its normal is opposite to all the adjacent faces. It is removed by flipping it against the face f adjacent along the edge e such that the vertex opposite to e fall inside f</p>

.. data:: meshing_remove_null_faces

   *MeshLab filter name*: 'Remove Zero Area Faces'

   .. raw:: html

      Remove null faces (the one with area equal to zero)</p>

.. data:: meshing_remove_selected_faces

   *MeshLab filter name*: 'Delete Selected Faces'

   .. raw:: html

      Delete the current set of selected faces, vertices that remains unreferenced are not deleted.</p>

.. data:: meshing_remove_selected_vertices

   *MeshLab filter name*: 'Delete Selected Vertices'

   .. raw:: html

      Delete the current set of selected vertices; faces that share one of the deleted vertices are deleted too.</p>

.. data:: meshing_remove_selected_vertices_and_faces

   *MeshLab filter name*: 'Delete Selected Faces and Vertices'

   .. raw:: html

      Delete the current set of selected faces and all the vertices surrounded by that faces.</p>

.. data:: meshing_remove_t_vertices

   *MeshLab filter name*: 'Remove T-Vertices'

   .. raw:: html

      Delete t-vertices from the mesh by edge collapse (collapsing the shortest of the incident edges) or edge flip (flipping the opposite edge on the degenerate face if the triangulation quality improves).</p>

   **Parameters:**

   ``method : str = 'Edge Collapse' (or int = 0)``

      Possible enum values:

         0. ``'Edge Collapse'``
         1. ``'Edge Flip'``

      .. raw:: html

         <i>Method</i>: Selects wether to remove t-vertices by edge collapse or edge flip.

   ``threshold : float = 40``

      .. raw:: html

         <i>Ratio</i>: Detects faces where the base/height ratio is lower than this value

   ``repeat : bool = True``

      .. raw:: html

         <i>Iterate until convergence</i>: Iterates the algorithm until it reaches convergence

.. data:: meshing_remove_unreferenced_vertices

   *MeshLab filter name*: 'Remove Unreferenced Vertices'

   .. raw:: html

      Check for every vertex on the mesh: if it is NOT referenced by a face, removes it</p>

.. data:: meshing_remove_vertices_by_scalar

   *MeshLab filter name*: 'Remove Vertices wrt Quality'

   .. raw:: html

      Delete all the vertices with a quality lower smaller than the specified constant</p>

   **Parameters:**

   ``maxqualitythr : Percentage = inf%``

      .. raw:: html

         <i>Delete all vertices with quality under:</i>: 

.. data:: meshing_repair_non_manifold_edges

   *MeshLab filter name*: 'Repair non Manifold Edges'

   .. raw:: html

      Remove non-manifold edges by removing faces (for each non Manifold edge it iteratively deletes the smallest area face until it becomes 2-Manifold) or by splitting vertices (each non manifold edges chain will become a border).</p>

   **Parameters:**

   ``method : str = 'Remove Faces' (or int = 0)``

      Possible enum values:

         0. ``'Remove Faces'``
         1. ``'Split Vertices'``

      .. raw:: html

         <i>Method</i>: Selects wether to remove non manifold edges by removing faces or by splitting vertices.

.. data:: meshing_repair_non_manifold_vertices

   *MeshLab filter name*: 'Repair non Manifold Vertices by splitting'

   .. raw:: html

      Split non Manifold vertices until it becomes 2-Manifold.</p>

   **Parameters:**

   ``vertdispratio : float = 0``

      .. raw:: html

         <i>Vertex Displacement Ratio</i>: This parameter denote the ratio ⍺ of displacement of a vertex. When a vertex <i>v</i> is split, it is moved towards the barycenter <i>b</i> of the FF connected faces sharing it of a (<i>v</i>-<i>b</i>)*⍺. When ⍺ is zero vertex is not displaced. When ⍺ is 0.5 the new vertex is half away toward the barycenter of the face. Reasonable values are in the [0 .. 0.1] range.

.. data:: meshing_snap_mismatched_borders

   *MeshLab filter name*: 'Snap Mismatched Borders'

   .. raw:: html

      Try to snap together adjacent borders that are slightly mismatched.<br>This situation can happen on badly triangulated adjacent patches defined by high order surfaces.<br>For each border vertex the filter snap it onto the closest boundary edge only if it is closest of <i>edge_length*threshold</i>. When vertex is snapped the corresponding face is split and a new vertex is created.</p>

   **Parameters:**

   ``edgedistratio : float = 0.01``

      .. raw:: html

         <i>Edge Distance Ratio</i>: Collapse edge when the edge / distance ratio is greater than this value. E.g. for default value 1000 two straight border edges are collapsed if the central vertex dist from the straight line composed by the two edges less than a 1/1000 of the sum of the edges length. Larger values enforce that only vertices very close to the line are removed.

   ``unifyvertices : bool = True``

      .. raw:: html

         <i>UnifyVertices</i>: if true the snap vertices are weld together.

.. data:: meshing_surface_subdivision_butterfly

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

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: meshing_surface_subdivision_catmull_clark

   *MeshLab filter name*: 'Subdivision Surfaces: Catmull-Clark'

   .. raw:: html

      Apply the Catmull-Clark Subdivision Surfaces. Note that position of the new vertices is simply linearly interpolated. If the mesh is triangle based (no <a href='https://stackoverflow.com/questions/59392193'>faux edges</a>) it generates a quad mesh, otherwise it honores it the faux-edge bits</p>

.. data:: meshing_surface_subdivision_loop

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

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: meshing_surface_subdivision_ls3_loop

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

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: meshing_surface_subdivision_midpoint

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

   ``selected : bool = False``

      .. raw:: html

         <i>Affect only selected faces</i>: If selected the filter affect only the selected faces

.. data:: meshing_tri_to_quad_by_4_8_subdivision

   *MeshLab filter name*: 'Tri to Quad by 4-8 Subdivision'

   .. raw:: html

      Convert a tri mesh into a quad mesh by applying a 4-8 subdivision scheme.It introduces less overhead than the plain Catmull-Clark Subdivision Surfaces(it adds only a single vertex for each triangle instead of four).<br> See: <br><b>4-8 Subdivision</b><br> <i>Luiz Velho, Denis Zorin </i><br>CAGD, volume 18, Issue 5, Pages 397-427. </p>

.. data:: meshing_tri_to_quad_by_smart_triangle_pairing

   *MeshLab filter name*: 'Tri to Quad by smart triangle pairing'

   .. raw:: html

      Convert a tri-mesh into a quad mesh by pairing triangles.</p>

.. data:: meshing_tri_to_quad_dominant

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

.. data:: meshing_vertex_attribute_seam

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

.. data:: nxs_build

   *MeshLab filter name*: 'NXS Build'

   .. raw:: html

      <a href="http://vcg.isti.cnr.it/nexus/">Nexus</a> is a collection of tools for streaming visualization of large 3D models in OpenGL.<br>This filter is the equivalent of calling <a href="http://vcg.isti.cnr.it/nexus/#nxsbuild">nxsbuild</a>: it creates a nxs file starting from a obj, ply or stl.</p>

   **Parameters:**

   ``input_file : str = ''``

      .. raw:: html

         <i>Input File</i>: The input file from which create the .nxs file.

   ``output_file : str = ''``

      .. raw:: html

         <i>Output File</i>: The name of the output nxs file.

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

.. data:: nxs_compress

   *MeshLab filter name*: 'NXS Compress'

   .. raw:: html

      <a href="http://vcg.isti.cnr.it/nexus/">Nexus</a> is a collection of tools for streaming visualization of large 3D models in OpenGL.<br>This filter is the equivalent of calling nxscompress, whichcreates a nxz (compressed nexus) file starting from a nxs.</p>

   **Parameters:**

   ``input_file : str = ''``

      .. raw:: html

         <i>Input File</i>: The input nxs file to compress into an nxz file.

   ``output_file : str = ''``

      .. raw:: html

         <i>Output File</i>: The name of the output nxz file.

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

.. data:: raster_alignment_mutual_information

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

   ``estimate_focal : bool = False``

      .. raw:: html

         <i>Estimate focal length</i>: Estimate focal length: if not checked, only extrinsic parameters are estimated

   ``fine : bool = True``

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

.. data:: raster_global_refinement_mutual_information

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

   ``pre_alignment : bool = False``

      .. raw:: html

         <i>Pre-alignment step</i>: Pre-alignment step

   ``estimate_focal : bool = True``

      .. raw:: html

         <i>Estimate focal length</i>: Estimate focal length

   ``fine : bool = True``

      .. raw:: html

         <i>Fine Alignment</i>: Fine alignment

.. data:: save_active_raster_cameras

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

         <i>Export file name (the right extension will be added at the end)</i>: Name of the output file, it will be saved in the same folder as the project file.

.. data:: save_snapshot

   *MeshLab filter name*: 'GPU Filter Example'

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

.. data:: set_camera_per_mesh

   *MeshLab filter name*: 'Set Mesh Camera'

   .. raw:: html

      This filter allows one to set a shot for the current mesh</p>

   **Parameters:**

   ``shot : Shotf [still unsupported] = None``

      .. raw:: html

         <i>New shot</i>: This filter allows one to set a shot for the current mesh.

.. data:: set_camera_per_raster

   *MeshLab filter name*: 'Set Raster Camera'

   .. raw:: html

      This filter allows one to set a shot for the current mesh</p>

   **Parameters:**

   ``shot : Shotf [still unsupported] = None``

      .. raw:: html

         <i>New shot</i>: This filter allows one to set a shot for the current raster.

.. data:: set_color_per_vertex

   *MeshLab filter name*: 'Vertex Color Filling'

   .. raw:: html

      Fills the color of the vertices of the mesh with a color chosen by the user.</p>

   **Parameters:**

   ``color1 : Color = [0; 0; 0; 255]``

      .. raw:: html

         <i>Color:</i>: Sets the color to apply to vertices.

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only affects selected vertices

.. data:: set_matrix

   *MeshLab filter name*: 'Matrix: Set/Copy Transformation'

   .. raw:: html

      Set the current transformation matrix by filling it, or copying from another layer.</p>

   **Parameters:**

   ``transformmatrix : numpy.ndarray[numpy.float64[4, 4]] = [[1, 0, 0, 0],[0, 1, 0, 0],[0, 0, 1, 0],[0, 0, 0, 1]]``

      .. raw:: html

         <i></i>: 

   ``compose : bool = False``

      .. raw:: html

         <i>Compose with current</i>: If selected, the new matrix will be composed with the current one (matrix=new*old)

   ``freeze : bool = True``

      .. raw:: html

         <i>Freeze Matrix</i>: The transformation is explicitly applied, and the vertex coordinates are actually changed

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected, the filter will be applied to all visible mesh layers

.. data:: set_matrix_identity

   *MeshLab filter name*: 'Matrix: Reset Current Matrix'

   .. raw:: html

      Set the current transformation matrix to the Identity. </p>

   **Parameters:**

   ``alllayers : bool = False``

      .. raw:: html

         <i>Apply to all visible Layers</i>: If selected the filter will be applied to all visible mesh layers

.. data:: set_mesh_name

   *MeshLab filter name*: 'Rename Current Mesh'

   .. raw:: html

      Explicitly change the label shown for a given mesh</p>

   **Parameters:**

   ``newname : str = 'cube'``

      .. raw:: html

         <i>New Label</i>: New Label for the mesh.

.. data:: set_raster_name

   *MeshLab filter name*: 'Rename Current Raster'

   .. raw:: html

      Explicitly change the label shown for a given raster</p>

   **Parameters:**

   ``newname : str = ''``

      .. raw:: html

         <i>New Label</i>: New Label for the raster.

.. data:: set_selection_all

   *MeshLab filter name*: 'Select All'

   .. raw:: html

      Select all the faces/vertices of the current mesh.</p>

   **Parameters:**

   ``allfaces : bool = True``

      .. raw:: html

         <i>Select all Faces</i>: If true the filter will select all the faces.

   ``allverts : bool = True``

      .. raw:: html

         <i>Select all Vertices</i>: If true the filter will select all the vertices.

.. data:: set_selection_none

   *MeshLab filter name*: 'Select None'

   .. raw:: html

      Clear the current set of selected faces/vertices.</p>

   **Parameters:**

   ``allfaces : bool = True``

      .. raw:: html

         <i>De-select all Faces</i>: If true the filter will de-select all the faces.

   ``allverts : bool = True``

      .. raw:: html

         <i>De-select all Vertices</i>: If true the filter will de-select all the vertices.

.. data:: set_texture_per_mesh

   *MeshLab filter name*: 'Set Texture'

   .. raw:: html

      Set a texture associated with current mesh parametrization.<br>If the texture provided exists, then it will be simply associated to the current mesh; else the filter will fail with no further actions.</p>

   **Parameters:**

   ``textname : str = ''``

      .. raw:: html

         <i>Texture file</i>: Sets the given input image as unique texture of the mesh.

.. data:: transfer_attributes_per_vertex

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

   ``geomtransfer : bool = False``

      .. raw:: html

         <i>Transfer Geometry</i>: if enabled, the position of each vertex of the target mesh will be snapped onto the corresponding closest point on the source mesh

   ``normaltransfer : bool = False``

      .. raw:: html

         <i>Transfer Normal</i>: if enabled, the normal of each vertex of the target mesh will get the (interpolated) normal of the corresponding closest point on the source mesh

   ``colortransfer : bool = True``

      .. raw:: html

         <i>Transfer Color</i>: if enabled, the color of each vertex of the target mesh will become the color of the corresponding closest point on the source mesh

   ``qualitytransfer : bool = False``

      .. raw:: html

         <i>Transfer quality</i>: if enabled, the quality of each vertex of the target mesh will become the quality of the corresponding closest point on the source mesh

   ``selectiontransfer : bool = False``

      .. raw:: html

         <i>Transfer Selection</i>: if enabled,  each vertex of the target mesh will be selected if the corresponding closest point on the source mesh falls in a selected face

   ``qualitydistance : bool = False``

      .. raw:: html

         <i>Store dist. as quality</i>: if enabled, we store the distance of the transferred value as in the vertex quality

   ``upperbound : Percentage = 2%``

      .. raw:: html

         <i>Max Dist Search</i>: Sample points for which we do not find anything within this distance are rejected and not considered for recovering attributes.

   ``onselected : bool = False``

      .. raw:: html

         <i>Only on selection</i>: If checked, only transfer to selected vertices on TARGET mesh

.. data:: transfer_attributes_to_texture_per_vertex

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

         <i>Color Data Source</i>: Choose what attribute has to be transferred onto the target texture. You can choose between Per vertex attributes (color,normal,quality) or to transfer color information from source mesh texture

   ``upperbound : Percentage = 2%``

      .. raw:: html

         <i>Max Dist Search</i>: Sample points for which we do not find anything within this distance are rejected and not considered for recovering data

   ``textname : str = 'texture.png'``

      .. raw:: html

         <i>Texture file</i>: The texture file to be created

   ``textw : int = 1024``

      .. raw:: html

         <i>Texture width (px)</i>: The texture width

   ``texth : int = 1024``

      .. raw:: html

         <i>Texture height (px)</i>: The texture height

   ``overwrite : bool = False``

      .. raw:: html

         <i>Overwrite Target Mesh Texture</i>: if target mesh has a texture will be overwritten (with provided texture dimension)

   ``pullpush : bool = True``

      .. raw:: html

         <i>Fill texture</i>: if enabled the unmapped texture space is colored using a pull push filling algorithm, if false is set to black

.. data:: transfer_iso_parametrization_between_meshes

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

.. data:: transfer_texture_to_color_per_vertex

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

