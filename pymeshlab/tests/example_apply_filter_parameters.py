import pymeshlab


def example_apply_filter_parameters():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    # apply the filter 'create_noisy_isosurface', with a resolution parameter of 128
    # the parameter for this filter is an integer. Check the type of each parameter
    # in the Filter List page.
    ms.create_noisy_isosurface(resolution=128)

    # save the new current mesh created by the filter
    ms.save_current_mesh(output_path + 'create_noisy_isosurface' + str(128) + '.ply')
