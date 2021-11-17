import pymeshlab
import numpy


def example_import_mesh_from_arrays():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    output_path = samples_common.test_output_path()

    # create a numpy 8x3 array of vertices
    # columns are the coordinates (x, y, z)
    # every row represents a vertex
    verts = numpy.array([
        [-0.5, -0.5, -0.5],
        [0.5, -0.5, -0.5],
        [-0.5, 0.5, -0.5],
        [0.5, 0.5, -0.5],
        [-0.5, -0.5, 0.5],
        [0.5, -0.5, 0.5],
        [-0.5, 0.5, 0.5],
        [0.5, 0.5, 0.5]])

    # create a numpy 12x3 array of faces
    # every row represents a face (triangle in this case)
    # for every triangle, the index of the vertex
    # in the vertex array
    faces = numpy.array([
        [2, 1, 0],
        [1, 2, 3],
        [4, 2, 0],
        [2, 4, 6],
        [1, 4, 0],
        [4, 1, 5],
        [6, 5, 7],
        [5, 6, 4],
        [3, 6, 7],
        [6, 3, 2],
        [5, 3, 7],
        [3, 5, 1]])

    # create a new Mesh with the two arrays
    m = pymeshlab.Mesh(verts, faces)

    assert m.vertex_number() == 8
    assert m.face_number() == 12

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    # add the mesh to the MeshSet
    ms.add_mesh(m, "cube_mesh")

    # save the current mesh
    ms.save_current_mesh(output_path + "saved_cube_from_array.ply")

    # create a 1D numpy array of 8 elements to store per vertex quality
    vert_scalar = numpy.array([
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8])

    # create a 1D numpy array of 12 elements to store per face quality
    face_scalar = numpy.array([
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        12])

    # create a new mesh with the selected arrays
    m1 = pymeshlab.Mesh(
        vertex_matrix=verts,
        face_matrix=faces,
        v_scalar_array=vert_scalar,
        f_scalar_array=face_scalar)

    # add the mesh to the MeshSet
    ms.add_mesh(m1, "cube_quality_mesh")

    # colorize the cube according to the per face and per vertex quality
    ms.compute_color_from_scalar_per_vertex()
    ms.compute_color_from_scalar_per_face()

    # save the mesh
    ms.save_current_mesh(output_path + "quality_colored_cube_from_array.ply")

    # create a numpy 8x4 array of vertex colors
    # columns are the floating point color components (r, g, b, a)
    # every row represents the color of the i-th vertex
    vert_colors = numpy.array([
        [1, 0, 0, 1],
        [0, 1, 0, 1],
        [0, 0, 1, 1],
        [0.5, 0, 0, 1],
        [0, 0.5, 0, 1],
        [0, 0, 0.5, 1],
        [0.5, 0, 0.5, 1],
        [0, 0.5, 0.5, 1]])

    # create a new mesh with the selected arrays
    m2 = pymeshlab.Mesh(
        vertex_matrix=verts,
        face_matrix=faces,
        v_color_matrix=vert_colors)

    ms.add_mesh(m2, "cube_vcolor_mesh")

    # save the mesh
    ms.save_current_mesh(output_path + "vert_colored_cube_from_array.ply")

    # create a numpy 12x4 array of face colors
    # columns are the floating point color components (r, g, b, a)
    # every row represents the color of the i-th face
    face_colors = numpy.array([
        [1, 0, 0, 1],
        [0, 1, 0, 1],
        [0, 0, 1, 1],
        [0.5, 0, 0, 1],
        [0, 0.5, 0, 1],
        [0, 0, 0.5, 1],
        [0.5, 0, 0.5, 1],
        [0, 0.5, 0.5, 1],
        [0.5, 0.5, 0, 1],
        [0.5, 0.5, 0.5, 1],
        [0, 0, 0, 1],
        [0.8, 0.2, 0.4, 1]])

    # create a new mesh with the selected arrays
    m3 = pymeshlab.Mesh(
        vertex_matrix=verts,
        face_matrix=faces,
        f_color_matrix=face_colors)

    ms.add_mesh(m3, "cube_fcolor_mesh")

    # save the mesh
    ms.save_current_mesh(output_path + "face_colored_cube_from_array.ply")
