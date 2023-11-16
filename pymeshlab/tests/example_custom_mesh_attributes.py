import pymeshlab
import numpy


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
    ms.compute_new_custom_scalar_attribute_per_vertex(name="v_attr", expr="x+y+z")

    # save the values of the custom attribute v_attr in a numpy array
    v_attr = m.vertex_custom_scalar_attribute_array('v_attr')

    # create a new per face custom scalar attribute called f_attr
    # each value is the sum of the vertex indices that form the face
    ms.compute_new_custom_scalar_attribute_per_face(name="f_attr", expr="vi0+vi1+vi2")

    # save the values of the custom attribute f_attr in a numpy array
    f_attr = m.face_custom_scalar_attribute_array('f_attr')

    print(v_attr)
    print(f_attr)

    # create a new per vertex custom point (3 scalars) attribute called vp_attr
    # values are the x, y and z coords of the vertex (useful to save coordinates
    # before some geometry processing)
    ms.compute_new_custom_point_attribute_per_vertex(name="vp_attr", x_expr="x", y_expr="y", z_expr="z")

    # save the values of the custom attribute vp_attr in a numpy array
    vp_attr = m.vertex_custom_point_attribute_matrix('vp_attr')

    print(vp_attr)

    # save the cube in ply format, including also the 'v_attr' custom attribute
    # custom attribute can be saved through boolean parameters named with lowercase names and with the prefix
    # that depends on the type of custom attribute:
    # - __ca_vs__: Custom Attribute Vertex Scalar;
    # - __ca_vp__: Custom Attribute Vertex Point;
    # - __ca_fs__: Custom Attribute Face Scalar;
    # - __ca_fp__: Custom Attribute Face Point;
    ms.save_current_mesh(output_path + 'cube_custom_attr.ply', binary=False, __ca_vs__v_attr=True)

    # add a point attribute manually using numpy array

    # generate numpy array
    attrs = numpy.array([
        [-0.5, -0.5, -0.5],
        [0.5, -0.5, -0.5],
        [-0.5, 0.5, -0.5],
        [0.5, 0.5, -0.5],
        [-0.5, -0.5, 0.5],
        [0.5, -0.5, 0.5],
        [-0.5, 0.5, 0.5],
        [0.5, 0.5, 0.5]])
    
    # add a new custom point attribute
    m.add_vertex_custom_point_attribute(attrs, 'numpy_attr')

    # get the attribute and print it
    ret_attr = m.vertex_custom_point_attribute_matrix('numpy_attr')

    print(ret_attr)