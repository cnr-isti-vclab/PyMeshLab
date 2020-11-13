import pymeshlab as ml
from . import samples_common


def test_load_meshes():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "bone.ply")

    print(ms.number_meshes())

    ms.load_new_mesh(base_path + "airplane.obj")

    print(ms.number_meshes())

    assert ms.number_meshes() == 2

    ms.set_current_mesh(0)

    print(ms.current_mesh().vertex_number())

    assert ms.current_mesh().vertex_number() == 1872

    ms.set_current_mesh(1)

    print(ms.current_mesh().vertex_number())

    assert ms.current_mesh().vertex_number() == 7017
