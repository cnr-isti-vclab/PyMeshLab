import pytest
from pymeshlab import pymeshlabserver as pymls
from . import samples_common

def test_save_meshe():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    md = pymls.MeshDocument()

    md.load_mesh(base_path + "bone.ply")

    md.save_mesh(base_path + "bone_saved.obj")