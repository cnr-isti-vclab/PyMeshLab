import pymeshlab


def example_apply_filter_parameters_point():
    # lines needed to run this specific example
    print('\n')
    from . import samples_common
    base_path = samples_common.samples_absolute_path()
    output_path = samples_common.test_output_path()

    # create a new MeshSet
    ms = pymeshlab.MeshSet()

    ms.load_new_mesh(base_path + "airplane.obj")

    # Points are numpy arrays -- need to import numpy
    import numpy

    # create the point (back of the airplane)
    point = numpy.array([0.1784, 0.6335, -0.7529])

    # apply a filter, passing the point as parameter
    ms.compute_scalar_by_geodesic_distance_from_given_point_per_vertex(startpoint=point)

    # save the result of the filter
    ms.save_current_mesh(output_path + 'colored_airplane.ply')
