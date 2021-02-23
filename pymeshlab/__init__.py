from .pmeshlab import *
import os
import pathlib

this_path=str(pathlib.Path(__file__).parent.absolute())
os.environ['QT_PLUGIN_PATH']=this_path

try:
    load_default_plugins()
except PyMeshLabException as e:
    print("Warning:\n" + str(e))

print_pymeshlab_version()

def use_cpu_opengl():
    if os.name == 'nt':
        os.rename(this_path + '\\opengl32sw.dll', this_path + '\\opengl32.dll')
    else:
        print("Nothing to do.")

def do_not_use_cpu_opengl():
    if os.name == 'nt':
        os.rename(this_path + '\\opengl32.dll', this_path + '\\opengl32sw.dll')
    else:
        print("Nothing to do.")
