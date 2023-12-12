import pymeshlab as ml


def test_delete_mesh():
    print('\n')

    ms = ml.MeshSet()
    ms.create_cube()

    assert (ms.mesh_number() == 1)

    ms.generate_copy_of_current_mesh()

    assert (ms.mesh_number() == 2)
    assert (ms.current_mesh_id() == 1)

    ms.set_current_mesh(0)

    assert (ms.current_mesh_id() == 0)

    ms.delete_current_mesh()

    assert(ms.mesh_number() == 1)
