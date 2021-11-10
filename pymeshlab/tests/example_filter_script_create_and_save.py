import pymeshlab


def example_filter_script_create_and_save():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    # load a new mesh
    ms.load_new_mesh(base_path + "cube.obj")

    # applying some filter to the mesh...
    # every apply_filter saves in the filter script stored in the MeshSet
    # the applied filter with their parameters
    ms.meshing_isotropic_explicit_remeshing()
    ms.meshing_isotropic_explicit_remeshing()
    ms.compute_scalar_by_aspect_ratio_per_face()
    ms.compute_color_from_scalar_per_face()

    # save the mesh
    ms.save_current_mesh(output_path + 'col_rem_cube.ply')

    # save the current filter script, containing all the filters with their parameters
    # that have been applied in the MeshSet ms.
    ms.save_filter_script(output_path + 'test_saved_script.mlx')
