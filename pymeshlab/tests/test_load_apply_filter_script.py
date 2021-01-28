import pymeshlab as ml
from . import samples_common


def test_load_apply_filter_script():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = ml.MeshSet()

    # load the filter script and stores it in the MeshSet
    ms.load_filter_script(base_path + "sample_filter_script.mlx")

    # apply the filter script contained in the MeshSet
    # note - the filter script used in this example does not require an input mesh,
    #        therefore it can be applied also in an empty MeshSet
    ms.apply_filter_script()

    ms.save_current_mesh(output_path + "cube_cc.ply")
