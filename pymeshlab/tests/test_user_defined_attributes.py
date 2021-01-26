import pymeshlab as ml
from . import samples_common


def test_user_defined_attributes():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "cube.obj")

    m = ms.current_mesh()

    ms.apply_filter("define_new_per_vertex_attribute", name="v_attr", expr="x+y+z")

    v_attr = m.vertex_scalar_attribute_array('v_attr')

    ms.apply_filter("define_new_per_face_attribute", name="f_attr", expr="vi0+vi1+vi2")

    f_attr = m.face_scalar_attribute_array('f_attr')

    print(v_attr)
    print(f_attr)