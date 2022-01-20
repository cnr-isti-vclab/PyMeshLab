import pymeshlab as ml


def test_number_plugins():
    print('\n')
    n_plugins = ml.number_plugins()

    ml.print_plugin_list()

    assert(n_plugins == 53)
