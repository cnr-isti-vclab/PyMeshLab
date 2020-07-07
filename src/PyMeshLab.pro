# disables the lib prefix
CONFIG += no_plugin_name_prefix
# disable symlinks & versioning
CONFIG += plugin

TEMPLATE = lib
TARGET_NAME = $$system(python3-config --extension-suffix | cut -f 2 -d '.')
TARGET = PyMeshLab.$$TARGET_NAME
DESTDIR = $$PYMESHLAB_DISTRIB_DIRECTORY

CONFIG += c++11

PYTHON_VERSION=$$(PYTHON_VERSION)
isEmpty( PYTHON_VERSION ) {
	win32:PYTHON_VERSION=38
	unix:PYTHON_VERSION=3.8
	macx:PYTHON_VERSION=3.8
}

INCLUDEPATH += \
	../pybind11/include/ \
	/usr/include/python$$PYTHON_VERSION/

QMAKE_CXXFLAGS += -shared -fPIC

SOURCES += \
	PyMeshLab.cpp

# if distrib folder is not in $$PWD/../distrib (shadow build case),
# we need to copy all the files inside $$PWD/../distrib in the actual
# distrib folder ($$OUT_PWD/distrib or $$MESHLAB_DISTRIB_DIRECTORY)
!equals(PWD, $$OUT_PWD) : !equals(PWD, $$OUT_PWD/src) {
	#copying the "lib" folder inside the $$OUT_PWD/distrib
	win32:copydir.commands = $(COPY_DIR) \"$$shell_path($$PWD/../PyMeshLab)\" \"$$shell_path($$OUT_PWD/PyMeshLab)\"
	!win32:copydir.commands = $(COPY_DIR) \"$$shell_path($$PWD/../PyMeshLab)\" \"$$shell_path($$OUT_PWD)\"
	first.depends += $(first) copydir
	export(first.depends)
	export(copydir.commands)

	QMAKE_EXTRA_TARGETS += first copydir
}
