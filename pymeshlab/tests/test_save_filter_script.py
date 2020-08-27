import pytest
import pymeshlab as ml
from . import samples_common

def test_save_filter_script():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_mesh(base_path + "cube.obj")

    ms.apply_filter('remeshing_isotropic_explicit_remeshing')
    ms.apply_filter('remeshing_isotropic_explicit_remeshing')
    ms.apply_filter('per_face_quality_according_to_triangle_shape_and_aspect_ratio')
    ms.apply_filter('colorize_by_face_quality')

    ms.save_mesh(output_path + 'col_rem_cube.ply')
    ms.save_filter_script(output_path + 'test_saved_script.mlx')