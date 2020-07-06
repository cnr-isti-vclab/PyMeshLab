from ctypes import *
from sys import platform

shared_lib_path = "./meshlab/lib/libmeshlab-common.so"
if platform.startswith('win32'):
    shared_lib_path = "./meshlab/lib/meshlab-common.dll"

try:
    meshlab_common_lib = CDLL(shared_lib_path)
    print("Successfully loaded ", meshlab_common_lib)
except Exception as e:
    print(e)

