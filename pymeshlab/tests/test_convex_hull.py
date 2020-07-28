import pytest
import pymeshlab as ml
from . import samples_common

def test_load_meshes():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_mesh(base_path + "airplane.obj")

    ms.apply_filter('convex_hull')

    assert ms.number_meshes() == 2

    ms.save_mesh(output_path + "convex_hull.obj")

    m = ms.current_mesh()

    print(m.vertex_number())

    assert m.vertex_number() == 455