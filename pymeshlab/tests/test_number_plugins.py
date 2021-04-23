import pymeshlab as ml

# temp
from sys import platform
#


def test_number_plugins():
    print('\n')
    n_plugins = ml.number_plugins()

    ml.print_plugin_list()

    # tmp on windows: missing FilterSketchFab
    if platform == "win32":
        assert(n_plugins == 48)
    else:
        assert(n_plugins == 49)
