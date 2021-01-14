import pymeshlab as ml
from . import samples_common


def test_compute_geometric_measures():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "bone.ply")
    out_dict = ms.apply_filter('compute_geometric_measures')
    avg_edge_length = out_dict['avg_edge_length']
    total_edge_length = out_dict['total_edge_length']
    mesh_volume = out_dict['mesh_volume']
    surf_area = out_dict['surface_area']

    assert (0.023 < avg_edge_length < 0.024)
    assert (105.343 < total_edge_length < 105.344)
    assert (0.025 < mesh_volume < 0.026)
    assert (0.694 < surf_area < 0.695)

