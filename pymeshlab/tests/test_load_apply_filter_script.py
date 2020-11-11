import pymeshlab as ml
from . import samples_common


def test_load_apply_filter_script():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_filter_script(base_path + "sample_filter_script.mlx")

    ms.apply_filter_script()

    ms.save_current_mesh(output_path + "cube_cc.ply")
