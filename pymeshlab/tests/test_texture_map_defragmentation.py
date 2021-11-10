import pymeshlab as ml
from . import samples_common

import pytest
from sys import platform


@pytest.mark.glcontext
def test_texture_map_defragmentation():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "bunny10k_textured.obj")

    ms.apply_texmap_defragmentation()

    ms.save_current_mesh(output_path + "bunny_text_defrag.obj")
