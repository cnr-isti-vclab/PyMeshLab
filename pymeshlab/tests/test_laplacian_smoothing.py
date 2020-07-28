import pytest
import pymeshlab as ml
from . import samples_common

def test_laplacian_smoothing():
    print('\n')
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.apply_filter('noisy_isosurface')