import pymeshlab as ml
from . import samples_common


def test_csg():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "cow.obj")  # id: 0
    ms.load_new_mesh(base_path + "bone.ply")  # id: 1, just for test id on mesh parameter
    ms.load_new_mesh(base_path + "airplane.obj")  # id: 2

    ms.csg_operation(firstmesh=0, secondmesh=2, operator='Union')

    ms.save_current_mesh(output_path + 'cow_with_wings.obj')
