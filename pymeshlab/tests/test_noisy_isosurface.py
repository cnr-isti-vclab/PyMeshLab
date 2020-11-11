import pymeshlab as ml
from . import samples_common


def test_noisy_isosurface():
    print('\n')
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.apply_filter('noisy_isosurface', resolution=128)

    ms.save_current_mesh(output_path + 'noisy_isosurface' + str(128) + '.ply')

