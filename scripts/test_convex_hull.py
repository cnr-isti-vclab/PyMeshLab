import pymeshlab as ml

def test_convex_hull():
    print('\n')
    base_path = 'pymeshlab/tests/sample/'
    output_path = base_path + 'test_output/'
    ms = ml.MeshSet()

    # load mesh
    ms.load_mesh(base_path + "airplane.obj")

    # apply convex hull to the current selected mesh (last loaded)
    ms.apply_filter('convex_hull')

    assert ms.number_meshes() == 2

    # save the current selected mesh
    ms.save_mesh(output_path + "convex_hull.obj")

    # get a reference to the current selected mesh
    m = ms.current_mesh()

    print('Vertex number: ' +  str(m.vertex_number()))

    assert m.vertex_number() == 455

test_convex_hull()
