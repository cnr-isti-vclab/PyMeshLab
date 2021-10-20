import pymeshlab
import numpy


def example_import_poly_mesh_from_arrays():
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

    # create a list of 6 polygonal faces
    # every row represents a face (quads in this case)
    # faces do not need to have all the same number of vertex indices
    faces = [
        [0, 2, 3, 1],
        [0, 4, 6, 2],
        [0, 1, 5, 4],
        [7, 6, 4, 5],
        [7, 3, 2, 6],
        [7, 5, 1, 3]]

    # create a new Mesh with the two arrays
    m = pymeshlab.Mesh(verts, faces)

    assert m.vertex_number() == 8

    # number of faces of the mesh remains 12, since meshes in meshlab are stored as triangle meshes
    # with faux edges
    assert m.face_number() == 12

    # when creating a mesh from a polymesh, a custom per face scalar attribute is added to the newly created mesh
    # storing the birth polygon faces for each triangle
    # get the birth polygon for each face of the mesh
    birth_faces = m.face_custom_scalar_attribute_array('poly_birth_faces')

    print(birth_faces)

    # the birth face of triangle with id 5 is 2
    assert(birth_faces[5] == 2)

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    # add the mesh to the MeshSet (note: ms contains a *copy* of m)
    ms.add_mesh(m, "cube_mesh")

    # save the current mesh
    # obj format in meshlab supports saving polygonal meshes
    ms.save_current_mesh(output_path + "saved_polygonal_cube_from_array.obj")
