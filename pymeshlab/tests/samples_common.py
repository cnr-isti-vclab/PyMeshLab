def samples_absolute_path():
    import os
    path_sample = os.path.dirname(os.path.abspath(__file__)) + "/sample_meshes/"
    return path_sample


def test_output_path():
    import os
    path_sample = samples_absolute_path()
    output_path = path_sample + 'test_output/'
    if not os.path.exists(output_path):
        os.mkdir(output_path)
    return output_path
