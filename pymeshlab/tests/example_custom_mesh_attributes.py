import pymeshlab


def example_custom_mesh_attributes():
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

    # create a new per vertex custom scalar attribute called v_attr
    # each value is the sum of the x, y and z coords of the vertex
    ms.define_new_per_vertex_custom_scalar_attribute(name="v_attr", expr="x+y+z")

    # save the values of the custom attribute v_attr in a numpy array
    v_attr = m.vertex_custom_scalar_attribute_array('v_attr')

    # create a new per face custom scalar attribute called f_attr
    # each value is the sum of the vertex indices that form the face
    ms.define_new_per_face_custom_scalar_attribute(name="f_attr", expr="vi0+vi1+vi2")

    # save the values of the custom attribute f_attr in a numpy array
    f_attr = m.face_custom_scalar_attribute_array('f_attr')

    print(v_attr)
    print(f_attr)

    # create a new per vertex custom point (3 scalars) attribute called vp_attr
    # values are the x, y and z coords of the vertex (useful to save coordinates
    # before some geometry processing)
    ms.define_new_per_vertex_custom_point_attribute(name="vp_attr", x_expr="x", y_expr="y", z_expr="z")

    # save the values of the custom attribute vp_attr in a numpy array
    vp_attr = m.vertex_custom_point_attribute_matrix('vp_attr')

    print(vp_attr)
