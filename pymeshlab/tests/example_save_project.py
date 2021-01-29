import pymeshlab


def example_save_project():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    ms.load_new_mesh(base_path + "bone.ply")

    # save a MLP project containing all the meshes of the MeshSet
    ms.save_project(output_path + "project_saved.mlp")
