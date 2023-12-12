import pymeshlab


def example_load_mesh():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    # load a new mesh in the MeshSet, and sets it as current mesh
    # the path of the mesh can be absolute or relative
    ms.load_new_mesh(base_path + "bone.ply")

    print(len(ms))  # now ms contains 1 mesh
    # instead of len(ms) you can also use:
    print(ms.mesh_number())

    # load a new mesh, and sets it as current mesh
    ms.load_new_mesh(base_path + "airplane.obj")

    print(ms.mesh_number())  # now ms contains 2 meshes

    assert len(ms) == 2

    # set the first mesh (id 0) as current mesh
    ms.set_current_mesh(0)

    # print the number of vertices of the current mesh
    print(ms.current_mesh().vertex_number())

    assert ms.current_mesh().vertex_number() == 1872

    # set the second mesh (id 1) as current mesh
    ms.set_current_mesh(1)

    # print the number of vertices of the current mesh
    print(ms.current_mesh().vertex_number())

    assert ms.current_mesh().vertex_number() == 7017
