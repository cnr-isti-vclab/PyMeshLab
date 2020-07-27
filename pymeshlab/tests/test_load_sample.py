import pytest
import pymeshlab as ml
from . import samples_common

def test_load_meshes():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    md = ml.MeshSet()

    md.load_mesh(base_path + "bone.ply")

    print(md.number_meshes())

    md.load_mesh(base_path + "airplane.obj")

    print(md.number_meshes())

    assert md.number_meshes() == 2

    md.set_current_mesh(0)

    print(md.current_mesh().vertex_number())

    assert md.current_mesh().vertex_number() == 1872

    md.set_current_mesh(1)

    print(md.current_mesh().vertex_number())

    assert md.current_mesh().vertex_number() == 7017
