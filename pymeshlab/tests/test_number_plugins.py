import pymeshlab as ml


def test_number_plugins():
    print('\n')
    n_plugins = ml.number_plugins()

    assert(n_plugins == 51)
