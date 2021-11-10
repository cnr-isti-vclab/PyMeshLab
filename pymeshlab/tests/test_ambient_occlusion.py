import pymeshlab as ml
from . import samples_common

import pytest
from sys import platform


@pytest.mark.glcontext
def test_ambient_occlusion():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "bunny.obj")

    ms.compute_scalar_ambient_occlusion()

    ms.save_current_mesh(output_path + 'bunny_ao.ply')
