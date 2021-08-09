import pymeshlab as ml


def test_load_relative_path():
    print('\n')
    ms = ml.MeshSet()

    ms.load_new_mesh("sample_meshes/bone.ply")
