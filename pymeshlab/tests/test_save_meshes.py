import pymeshlab as ml
from . import samples_common


def test_save_meshes():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = ml.MeshSet()

    # load a new mesh
    ms.load_new_mesh(base_path + "bone.ply")

    # save the current mesh with default parameters
    ms.save_current_mesh(output_path + "bone_saved.obj")

    # save the current mesh without face color
    ms.save_current_mesh(output_path + 'bone_without_color.ply', save_face_color=False)
