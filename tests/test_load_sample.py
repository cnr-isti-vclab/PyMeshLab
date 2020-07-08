# before running: LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libGLEW.so.2.1

import sys

sys.path.append("../PyMeshLab")

from PyMeshLab import PyMeshLab


def load_meshes():
    m = PyMeshLab.MeshDocument()
    m.load_mesh("sample/bone.obj")

    print(m.number_meshes())

    m.load_mesh("sample/airplane.obj")

    print(m.number_meshes())

    assert m.number_meshes() == 2

    m.set_current_mesh(0)

    print(m.number_vertices_selected_mesh())

    assert m.number_vertices_selected_mesh() == 1872

    m.set_current_mesh(1)

    print(m.number_vertices_selected_mesh())

    assert m.number_vertices_selected_mesh() == 7017
