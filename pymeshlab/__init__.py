from .pmeshlab import *
try:
    pmeshlab.load_default_plugins()
except PyMeshLabException as e:
    print("Warning: " + e)

pmeshlab.print_pymeshlab_version()
