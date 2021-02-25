import pymeshlab as ml
from . import samples_common

import pytest
from sys import platform


def test_ambient_occlusion():
    if platform == 'linux':
        pytest.skip("ambient_occlusion filter does not work on pytest on linux; skipping")
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "bunny.obj")

    ms.ambient_occlusion()

    ms.save_current_mesh(output_path + 'bunny_ao.ply')
