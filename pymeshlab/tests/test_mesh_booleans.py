import sys
import platform
import pytest

import pymeshlab as ml
from . import samples_common


@pytest.mark.skipif(sys.platform == 'darwin' and platform.machine() == 'arm64', reason="LibIGL booleans bug on Mac ARM")
def test_mesh_booleans():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "cow.obj")  # id: 0
    ms.load_new_mesh(base_path + "bone.ply")  # id: 1, just for test id on mesh parameter
    ms.load_new_mesh(base_path + "airplane.obj")  # id: 2

    ms.generate_boolean_union(first_mesh=0, second_mesh=2)

    ms.save_current_mesh(output_path + 'cow_with_wings.obj')
