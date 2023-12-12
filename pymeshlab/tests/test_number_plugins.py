import pymeshlab as ml


def test_number_plugins():
    print('\n')
    n_plugins = ml.plugin_number()

    ml.print_plugin_list()

    assert(n_plugins == 57)
