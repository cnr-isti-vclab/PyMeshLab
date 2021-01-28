import pymeshlab as ml
from . import samples_common


def test_save_projects():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "bone.ply")

    # save a MLP project containing all the meshes of the MeshSet
    ms.save_project(output_path + "project_saved.mlp")
