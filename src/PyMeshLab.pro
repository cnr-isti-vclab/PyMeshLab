# disables the lib prefix
CONFIG += no_plugin_name_prefix
# disable symlinks & versioning
CONFIG += plugin

TEMPLATE = lib
TARGET_NAME = $$system(python3-config --extension-suffix | cut -f 2 -d '.')
TARGET = PyMeshLab.$$TARGET_NAME
DESTDIR = $$PYMESHLAB_DISTRIB_DIRECTORY

CONFIG += c++11
CONFIG += qt
QT += core opengl xml

PYTHON_VERSION=$$(PYTHON_VERSION)
isEmpty( PYTHON_VERSION ) {
	win32:PYTHON_VERSION=38
	unix:PYTHON_VERSION=3.8
	macx:PYTHON_VERSION=3.8
}

DEFINES += MESHLAB_SCALAR=float

include(../meshlab/src/find_system_libs.pri)

#Eigen and glew dirs
CONFIG(system_eigen3): EIGENDIR = /usr/include/eigen3
!CONFIG(system_eigen3):EIGENDIR = ../meshlab/vcglib/eigenlib
!CONFIG(system_glew):  GLEWDIR = ../meshlab/src/external/glew-2.1.0

INCLUDEPATH += \
	/usr/include/python$$PYTHON_VERSION/ \ #python lib
	../pybind11/include/ \                 #pybind11
	$$EIGENDIR \                           #eigen
	$$GLEWDIR \                            #glew
	../meshlab/vcglib \                    #vcg
	../meshlab/src/common                  #meshlab_common

win32-msvc:LIBS += \
	-L$$PYMESHLAB_DISTRIB_DIRECTORY/lib -lmeshlab-common -lopengl32 -lGLU32

macx:LIBS += \
	$$PYMESHLAB_DISTRIB_DIRECTORY/lib/libmeshlab-common.dylib

linux:LIBS += \
	-L$$PYMESHLAB_DISTRIB_DIRECTORY/lib -lmeshlab-common -lGLU

QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/lib

SOURCES += \
	PyMeshLab.cpp

