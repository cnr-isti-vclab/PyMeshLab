import pymeshlab as ml
from . import samples_common


def test_merge_meshes():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "bone.ply")
    ms.load_new_mesh(base_path + "airplane.obj")

    ms.generate_by_merging_visible_meshes()
    
    ms.save_current_mesh(output_path + "merged.obj")
