import pymeshlab


def example_apply_filter():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    # load mesh
    ms.load_new_mesh(base_path + "airplane.obj")

    # apply convex hull filter to the current selected mesh (last loaded)
    ms.generate_convex_hull()
    # alternatively:
    # ms.apply_filter('generate_convex_hull')

    assert ms.mesh_number() == 2

    # save the current selected mesh
    ms.save_current_mesh(output_path + "convex_hull.obj")

    # get a reference to the current selected mesh
    m = ms.current_mesh()

    print(m.vertex_number())

    assert m.vertex_number() == 455
