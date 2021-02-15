from .pmeshlab import *

try:
    load_default_plugins()
except PyMeshLabException as e:
    print("Warning:\n" + e)

print_pymeshlab_version()
