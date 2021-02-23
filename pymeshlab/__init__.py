from .pmeshlab import *
import os
import pathlib

os.environ['QT_PLUGIN_PATH']=str(pathlib.Path(__file__).parent.absolute())

try:
    load_default_plugins()
except PyMeshLabException as e:
    print("Warning:\n" + str(e))

print_pymeshlab_version()
