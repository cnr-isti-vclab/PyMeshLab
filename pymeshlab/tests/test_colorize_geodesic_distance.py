import pymeshlab as ml
from . import samples_common


def test_colorize_geodesic_distance():
    print('\n')
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()
    ms = ml.MeshSet()

    ms.load_new_mesh(base_path + "airplane.obj")

    # create point (back of the airplane)
    import numpy
    point = numpy.array([0.1784, 0.6335, -0.7529])
    ms.apply_filter('colorize_by_geodesic_distance_from_a_given_point', startpoint=point)

    ms.save_current_mesh(output_path + 'colored_airplane.ply')
