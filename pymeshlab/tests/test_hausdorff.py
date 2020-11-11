import pytest
import pymeshlab as ml
from . import samples_common


def test_hausdorff():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "cube.obj")  # id: 0
    ms.load_new_mesh(base_path + "bone.ply")  # id: 1
    ms.load_new_mesh(base_path + "airplane.obj")  # id: 2

    ms.apply_filter('hausdorff_distance', targetmesh=0, sampledmesh=2)
