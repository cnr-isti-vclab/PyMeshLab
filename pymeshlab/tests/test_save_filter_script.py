import pymeshlab as ml
from . import samples_common


def test_save_filter_script():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "cube.obj")

    # remeshing isotropic explicit filter
    ms.apply_filter('remeshing_isotropic_explicit_remeshing')
    ms.apply_filter('remeshing_isotropic_explicit_remeshing')

    # compute per face quality
    ms.apply_filter('per_face_quality_according_to_triangle_shape_and_aspect_ratio')

    # colorize faces by face quality
    ms.apply_filter('colorize_by_face_quality')

    # save the mesh with all the default components
    ms.save_current_mesh(output_path + 'col_rem_cube.ply')

    # save the mesh without face color
    ms.save_current_mesh(output_path + 'nocol_rem_cube.ply', save_face_color=False)

    # save the filter script
    ms.save_filter_script(output_path + 'test_saved_script.mlx')
