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
    # every row represents a face (trianlge in this case)
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
    vert_quality = numpy.array([
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8])

    # create a 1D numpy array of 12 elements to store per face quality
    face_quality = numpy.array([
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
        v_quality_array=vert_quality,
        f_quality_array=face_quality)

    # add the mesh to the MeshSet
    ms.add_mesh(m1, "cube_quality_mesh")

    # colorize the cube according to the per face and per vertex quality
    ms.colorize_by_vertex_quality()
    ms.colorize_by_face_quality()

    # save the mesh
    ms.save_current_mesh(output_path + "colored_cube_from_array.ply")
