import pymeshlab


def example_get_mesh_values():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    ms.load_new_mesh(base_path + 'chameleon.pts')

    # applying some filters...
    ms.generate_simplified_point_cloud()
    ms.generate_surface_reconstruction_ball_pivoting()
    ms.compute_texcoord_parametrization_triangle_trivial_per_wedge(textdim=1024)
    ms.save_current_mesh(output_path + 'chameleon_simplified.obj')
    ms.compute_texmap_from_color(textname='chameleon_simplified.png')

    # get a reference to the current mesh
    m = ms.current_mesh()

    # get numpy arrays of vertices and faces of the current mesh
    v_matrix = m.vertex_matrix()
    f_matrix = m.face_matrix()

    # clear the MeshSet
    ms.clear()

    # create a mesh cube into the MeshSet
    ms.create_cube()

    # compute an edge mesh composed of a planar section of the mesh
    # default values will use a plane with +X normal and passing into the origin
    # a new mesh will be added into the MeshSet and will be the current one
    ms.generate_polyline_from_planar_section()

    # get a reference to the current edge mesh
    m = ms.current_mesh()

    # get numpy arrays of vertices, edges and faces of the current mesh
    v_matrix = m.vertex_matrix()
    e_matrix = m.edge_matrix()
    f_matrix = m.face_matrix()
