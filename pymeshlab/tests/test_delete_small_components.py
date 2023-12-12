import pymeshlab as ml
from . import samples_common


def test_delete_small_components():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "rangemaps/face000.ply")

    assert ms.mesh_number() == 1

    assert ms.current_mesh().face_number() == 166259

    # select small disconnected component with a given face ratio
    ms.compute_selection_by_small_disconnected_components_per_face(nbfaceratio=0.01)

    assert ms.current_mesh().selected_face_number() == 485

    # delete selected faces
    ms.meshing_remove_selected_faces()

    assert ms.current_mesh().selected_face_number() == 0

    assert ms.current_mesh().face_number() == 165774

    assert ms.current_mesh().vertex_number() == 85849

    # remove unreferenced vertices
    ms.meshing_remove_unreferenced_vertices()

    assert ms.current_mesh().vertex_number() == 84777

    ms.save_current_mesh(output_path + 'face000_clean.ply')
