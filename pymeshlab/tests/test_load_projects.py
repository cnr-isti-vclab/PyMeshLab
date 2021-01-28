import pymeshlab as ml
from . import samples_common


def test_load_projects():
    print('\n')

    base_path = samples_common.samples_absolute_path()

    # create a new MeshSet
    ms = ml.MeshSet()

    # load an ALN project
    ms.load_project(base_path + "sample_project.aln")

    print(ms.number_meshes())  # the project contains two meshes

    assert ms.number_meshes() == 2

    # load another project, but a MLP project
    ms.load_project(base_path + "sample_project.mlp")

    # also the second project contains two meshes, therefore right now the MeshSet
    # contains 4 meshes.
    print(ms.number_meshes())

    assert ms.number_meshes() == 4
