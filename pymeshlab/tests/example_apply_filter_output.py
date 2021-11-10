import pymeshlab


def example_apply_filter_output():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    ms.load_new_mesh(base_path + "bone.ply")

    # compute the geometric measures of the current mesh
    # and save the results in the out_dict dictionary
    out_dict = ms.get_geometric_measures()

    # get the average edge length from the dictionary
    avg_edge_length = out_dict['avg_edge_length']

    # get the total edge length
    total_edge_length = out_dict['total_edge_length']

    # get the mesh volume
    mesh_volume = out_dict['mesh_volume']

    # get the surface area
    surf_area = out_dict['surface_area']

    # checks with bounds (for numerical errors)
    assert (0.023 < avg_edge_length < 0.024)
    assert (105.343 < total_edge_length < 105.344)
    assert (0.025 < mesh_volume < 0.026)
    assert (0.694 < surf_area < 0.695)
