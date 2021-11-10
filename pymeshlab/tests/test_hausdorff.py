import pymeshlab as ml
from . import samples_common


def test_hausdorff():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "cow.obj")  # id: 0
    ms.load_new_mesh(base_path + "bone.ply")  # id: 1, just for test id on mesh parameter
    ms.load_new_mesh(base_path + "cow.obj")  # id: 2

    ms.meshing_isotropic_explicit_remeshing(iterations=10)  # remesh mesh id3

    res_dict = ms.get_hausdorff_distance(targetmesh=0, sampledmesh=2)

    print('Mean hausdorff distance: ' + str(res_dict['mean']))
    print('Mean hausdorff distance w.r.t bb diag of first mesh: ' + str(res_dict['mean'] / res_dict['diag_mesh_0']))

    print('Dict result: ')
    print(str(res_dict))
