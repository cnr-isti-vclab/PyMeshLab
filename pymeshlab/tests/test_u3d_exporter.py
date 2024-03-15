import sys
import platform
import pytest

import pymeshlab as ml
from . import samples_common


@pytest.mark.skipif(sys.platform == 'darwin' and platform.machine() == 'arm64', reason="U3D still does not work on Mac ARM")
def test_u3d_exporter():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "bunny.obj")

    ms.save_current_mesh(output_path + "bunny.u3d")
