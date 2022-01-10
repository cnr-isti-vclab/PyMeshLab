from sys import platform
import os
import pathlib

# for windows we need to tell which Qt libraries use
this_path = str(pathlib.Path(__file__).parent.absolute())
if platform == 'win32':
    os.environ['QT_PLUGIN_PATH'] = this_path
    os.environ['PATH'] = this_path + os.pathsep + os.environ['PATH']

from .pmeshlab import *
from .replacer import replace_pymeshlab_filter_names

# load all the default plugins in the current PyMeshLab session
try:
    load_default_plugins()
except PyMeshLabException as e:
    print("Warning:\n" + str(e))


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


# function that binds a name to a method of a class that calls the apply_filter function
def bind_function(name):
    def foo(self, **kwargs):  # Have to add self since this will become a method
        res_dict = self.apply_filter(name, **kwargs)
        if bool(res_dict):  # return the dictionary only if it is not empty
            return res_dict

    foo.__name__ = name  # change the name of the function to the actual filter name
    return foo


# for each filter loaded, create a method in the MeshSet class with that name that calls the apply_filter
for filter_name in filter_list():
    setattr(MeshSet, filter_name, bind_function(filter_name))


def show_polyscope(self):
    import polyscope
    import numpy

    polyscope.init()
    for m in self:
        isEnabled = m.is_visible()
        if m.is_point_cloud():
            psm = polyscope.register_point_cloud(m.label(), m.vertex_matrix(), enabled=isEnabled)
        else:
            psm = polyscope.register_surface_mesh(m.label(), m.vertex_matrix(), m.face_matrix(), enabled=isEnabled)
        if m.has_vertex_color():
            vc = m.vertex_color_matrix()
            vc = numpy.delete(vc, 3, 1)
            psm.add_color_quantity('vertex_color', vc)
        if m.has_vertex_scalar():
            psm.add_scalar_quantity('vertex_scalar', m.vertex_scalar_array())
        if not m.is_point_cloud() and m.has_face_color():
            fc = m.face_color_matrix()
            fc = numpy.delete(fc, 3, 1)
            psm.add_color_quantity('face_color', fc, defined_on='faces')
        if not m.is_point_cloud() and m.has_face_scalar():
            psm.add_scalar_quantity('face_scalar', m.face_scalar_array(), defined_on='faces')
    polyscope.show()


setattr(MeshSet, 'show_polyscope', show_polyscope)
