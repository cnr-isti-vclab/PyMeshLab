import pymeshlab


def example_apply_filter_parameters_percentage():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    ms.load_new_mesh(base_path + "rangemaps/face000.ply")

    assert ms.mesh_number() == 1

    assert ms.current_mesh().face_number() == 166259

    # create a new object of type PercentageValue, with value 50%
    p = pymeshlab.PercentageValue(50)

    # apply the filter that will remove connected components having diameter less than 50%
    # of the diameter of the entire mesh
    ms.meshing_remove_connected_component_by_diameter(mincomponentdiag=p)

    # There is the possibility to use an PureValue instead of a Percentage:
    #   av = pymeshlab.PureValue(0.5)
    #   ms.meshing_remove_connected_component_by_diameter(mincomponentdiag=av)

    assert ms.current_mesh().face_number() == 161606

    ms.save_current_mesh(output_path + 'face000_clean_by_diameter.ply')
