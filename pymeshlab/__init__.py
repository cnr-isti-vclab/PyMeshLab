from .pmeshlab import *
from sys import platform
import os
import pathlib

print_pymeshlab_version()

# for windows we need to tell which Qt libraries use
this_path=str(pathlib.Path(__file__).parent.absolute())
if platform == 'win32':
    os.environ['QT_PLUGIN_PATH']=this_path

# load all the default plugins in the current PyMeshLab session
try:
    load_default_plugins()
except PyMeshLabException as e:
    print("Warning:\n" + str(e))

# function that binds a name to a method of a class that calls the apply_filter function
def bind_function(name):
    def foo(self, **kwargs): # Have to add self since this will become a method
        dict = self.apply_filter(name, **kwargs)
        if (bool(dict)): # return the dictionary only if it is not empty
            return dict
    foo.__name__ = name # change the name of the function to the actual filter name
    return foo

# for each filter loaded, create a method in the MeshSet class with that name that calls the apply_filter
for filter_name in filter_list():
    setattr(MeshSet, filter_name, bind_function(filter_name))

# utility function for windows to use cpu opengl dll if opengl is not provided in the system
def use_cpu_opengl():
    if platform == 'win32':
        os.rename(this_path + '\\opengl32sw.dll', this_path + '\\opengl32.dll')
    else:
        print("Nothing to do.")

# utility function to undo the change made by the use_cpu_opengl function
def do_not_use_cpu_opengl():
    if platform == 'win32':
        os.rename(this_path + '\\opengl32.dll', this_path + '\\opengl32sw.dll')
    else:
        print("Nothing to do.")
