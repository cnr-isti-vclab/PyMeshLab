import pymeshlab as ml
from . import samples_common


def test_load_projects():
    print('\n')

    base_path = samples_common.samples_absolute_path()
    ms = ml.MeshSet()

    ms.load_project(base_path + "sample_project.aln")

    print(ms.number_meshes())

    assert ms.number_meshes() == 2

    ms.load_project(base_path + "sample_project.mlp")

    print(ms.number_meshes())

    assert ms.number_meshes() == 4
