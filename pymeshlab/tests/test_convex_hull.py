import pymeshlab as ml
from . import samples_common


def test_convex_hull():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    # load mesh
    ms.load_new_mesh(base_path + "airplane.obj")

    # apply convex hull to the current selected mesh (last loaded)
    ms.apply_filter('convex_hull')

    assert ms.number_meshes() == 2

    # save the current selected mesh
    ms.save_current_mesh(output_path + "convex_hull.obj")

    # get a reference to the current selected mesh
    m = ms.current_mesh()

    print(m.vertex_number())

    assert m.vertex_number() == 455