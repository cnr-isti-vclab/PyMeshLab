from pymeshlab import pymeshlabserver as pymls

def samples_absolute_path():
    import os
    return os.path.dirname(os.path.abspath(__file__)) + "/sample/"
    

def load_meshes():
    base_path = samples_absolute_path()
    md = pymls.MeshDocument()

    md.load_mesh(base_path + "bone.obj")

    print(md.number_meshes())

    md.load_mesh(base_path + "airplane.obj")

    print(md.number_meshes())

    assert md.number_meshes() == 2

    md.set_current_mesh(0)

    print(md.current_mesh().vertex_number())

    assert md.current_mesh().vertex_number() == 1872

    md.set_current_mesh(1)

    print(md.current_mesh().vertex_number())

    assert md.current_mesh().vertex_number() == 7017

    box = md.current_mesh().bounding_box()

    print(box.dim_x())

    assert abs(box.dim_x() - 1.9649) <= 0.0001
