from .pmeshlab import *
from sys import platform
import os
import pathlib

this_path=str(pathlib.Path(__file__).parent.absolute())
if platform == 'win32':
    os.environ['QT_PLUGIN_PATH']=this_path
elif os.name == "linux":
    os.environ['QT_PLUGIN_PATH']=this_path+'/lib'

try:
    load_default_plugins()
except PyMeshLabException as e:
    print("Warning:\n" + str(e))

print_pymeshlab_version()

def use_cpu_opengl():
    if platform == 'win32':
        os.rename(this_path + '\\opengl32sw.dll', this_path + '\\opengl32.dll')
    else:
        print("Nothing to do.")

def do_not_use_cpu_opengl():
    if platform == 'win32':
        os.rename(this_path + '\\opengl32.dll', this_path + '\\opengl32sw.dll')
    else:
        print("Nothing to do.")
