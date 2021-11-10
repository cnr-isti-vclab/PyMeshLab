import pymeshlab as ml
from . import samples_common


def test_select_faces_with_edge_longer_than():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "cube.obj")

    # butterfly subdivision
    ms.meshing_surface_subdivision_butterfly()
    
    # select faces with edge longer than
    ms.compute_selection_by_edge_length(threshold=0.2)
    
    m = ms.current_mesh()
    
    assert m.selected_face_number() == 312
