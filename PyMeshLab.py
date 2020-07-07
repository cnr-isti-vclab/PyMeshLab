from PyMeshLab import PyMeshLab

m = PyMeshLab.MeshDocument()

m.load_mesh()

print(m.size())

print(m.number_vertices_selected_mesh())
