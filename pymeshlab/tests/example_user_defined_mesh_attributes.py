import pymeshlab


def example_user_defined_mesh_attributes():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    ms.load_new_mesh(base_path + "cube.obj")

    # save a reference to the current mesh of the MeshSet
    m = ms.current_mesh()

    # create a new per vertex attribute called v_attr
    # each value is the sum of the x, y and z coords of the vertex
    ms.define_new_per_vertex_attribute(name="v_attr", expr="x+y+z")

    # save the values of the attribute v_attr in a numpy array
    v_attr = m.vertex_scalar_attribute_array('v_attr')

    # create a new per face attribute called f_attr
    # each value is the sum of the vertex indices that form the face
    ms.define_new_per_face_attribute(name="f_attr", expr="vi0+vi1+vi2")

    # save the values of the attribute f_attr in a numpy array
    f_attr = m.face_scalar_attribute_array('f_attr')

    print(v_attr)
    print(f_attr)
