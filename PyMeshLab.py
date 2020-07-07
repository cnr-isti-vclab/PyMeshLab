from PyMeshLab import PyMeshLab

m = PyMeshLab.MeshDocument()

m.load_mesh("/home/alessandro/Drive/Research/3DMeshes/bunny.obj")

print(m.number_meshes())

print(m.number_vertices_selected_mesh())
