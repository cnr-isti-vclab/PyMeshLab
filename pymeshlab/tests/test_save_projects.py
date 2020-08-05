import pytest
import pymeshlab as ml
from . import samples_common

def test_save_mesh():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_mesh(base_path + "bone.ply")

    ms.save_project(output_path + "project_saved.mlp")
