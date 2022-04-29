import pymeshlab


def example_load_project():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    # load an ALN project
    ms.load_project(base_path + "sample_project.aln")

    print(ms.mesh_number())  # the project contains two meshes

    assert ms.mesh_number() == 2

    # load another project, but a MLP project
    ms.load_project(base_path + "sample_project.mlp")

    # also the second project contains two meshes, therefore right now the MeshSet
    # contains 4 meshes.
    print(ms.mesh_number())

    assert ms.mesh_number() == 4
