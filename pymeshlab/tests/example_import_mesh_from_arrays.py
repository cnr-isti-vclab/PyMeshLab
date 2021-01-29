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
