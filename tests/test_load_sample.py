import sys

sys.path.append("../pymeshlab")

from pymeshlab import *

def load_meshes():
    md = MeshDocument()
    md.load_mesh("sample/bone.obj")

    print(md.number_meshes())

    md.load_mesh("sample/airplane.obj")

    print(md.number_meshes())

    assert md.number_meshes() == 2

    md.set_current_mesh(0)

    print(md.number_vertices_selected_mesh())

    assert md.number_vertices_selected_mesh() == 1872

    md.set_current_mesh(1)

    print(md.number_vertices_selected_mesh())

    assert md.number_vertices_selected_mesh() == 7017