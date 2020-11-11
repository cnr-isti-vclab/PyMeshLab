import pymeshlab as ml
from . import samples_common
import numpy


def test_import_mesh_from_array():
    print('\n')
    output_path = samples_common.test_output_path()

    verts = numpy.array([
        [-0.5, -0.5, -0.5],
        [0.5, -0.5, -0.5],
        [-0.5, 0.5, -0.5],
        [0.5, 0.5, -0.5],
        [-0.5, -0.5, 0.5],
        [0.5, -0.5, 0.5],
        [-0.5, 0.5, 0.5],
        [0.5, 0.5, 0.5]])

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

    m = ml.Mesh(verts, faces)

    assert m.vertex_number() == 8
    assert m.face_number() == 12

    ms = ml.MeshSet()
    ms.add_mesh(m, "cube_mesh")
    ms.save_current_mesh(output_path + "saved_cube_from_array.ply")
