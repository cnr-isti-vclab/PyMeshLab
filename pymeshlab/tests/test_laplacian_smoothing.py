import pymeshlab as ml
from . import samples_common


def test_laplacian_smoothing():
    print('\n')
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.noisy_isosurface()

    ms.laplacian_smooth()

    ms.save_current_mesh(output_path + 'smoothed_noisy_isosurface.ply')