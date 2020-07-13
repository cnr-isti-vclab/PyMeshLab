def get_PyMeshLab():
	import sysconfig
	qt_path = sysconfig.get_paths()["purelib"] + "/PySide2/Qt/lib"
	#print(qt_path)
	import os
	os.environ['LD_LIBRARY_PATH'] = qt_path
	import sys
	sys.path.append("./PyMeshLab")
	import pymeshlab
	return pymeshlab.MeshDocument()