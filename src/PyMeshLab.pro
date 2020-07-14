# disables the lib prefix
CONFIG += no_plugin_name_prefix
# disable symlinks & versioning
CONFIG += plugin

TEMPLATE = lib
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

message("PYTHON VERSION :" $$PYTHON_VERSION)

win32 {
PYTHON_PATH=$$(ProgramW6432)\Python$$PYTHON_VERSION

CONFIG += dll
LIBS += \
	-L$$PYMESHLAB_DISTRIB_DIRECTORY/lib -lmeshlab-common -lopengl32 -lGLU32 \
	-L$$PYTHON_PATH\libs -lpython$$PYTHON_VERSION

INCLUDEPATH += \
	$$PYTHON_PATH\include

TARGET_NAME=cp-$$PYTHON_VERSION-win_amd64
#QMAKE_LFLAGS_PLUGIN -= -dynamiclib
#QMAKE_LFLAGS_PLUGIN += -bundle
QMAKE_EXTENSION_SHLIB = pyd
}

macx {
PYTHON_PATH=$$(HOME)/.pyenv/versions/$${PYTHON_VERSION}.0

TARGET_NAME = $$system($$PYTHON_PATH/bin/python3-config --extension-suffix | cut -f 2 -d '.')

#needs to be a .so also on macos!
QMAKE_LFLAGS_PLUGIN -= -dynamiclib
QMAKE_LFLAGS_PLUGIN += -bundle
QMAKE_EXTENSION_SHLIB = so

#needed in order to do not link pythonlib
QMAKE_LFLAGS += -Wl,-undefined,dynamic_lookup

LIBS += \
    $$PYMESHLAB_DISTRIB_DIRECTORY/lib/libmeshlab-common.dylib

exists($$PYTHON_PATH/lib/python$$PYTHON_VERSION/config-$$PYTHON_VERSION-darwin){
    INCLUDEPATH += $$PYTHON_PATH/include/python$$PYTHON_VERSION
}
!exists($$PYTHON_PATH/lib/python$$PYTHON_VERSION/config-$$PYTHON_VERSION-darwin){
    INCLUDEPATH += $$PYTHON_PATH/include/python$${PYTHON_VERSION}m
}

#QMAKE_LFLAGS += -Wl,-install_name,@rpath/lib/
QMAKE_POST_LINK += "\
	install_name_tool -change libmeshlab-common.1.dylib @loader_path/lib/libmeshlab-common.1.dylib $$PYMESHLAB_DISTRIB_DIRECTORY/pymeshlab.$${TARGET_NAME}.so "
}

linux {
TARGET_NAME = $$system(python$$PYTHON_VERSION-config --extension-suffix | cut -f 2 -d '.')

LIBS += \
	-L$$PYMESHLAB_DISTRIB_DIRECTORY/lib -lmeshlab-common -lGLU

INCLUDEPATH += \
	/usr/include/python$$PYTHON_VERSION/ #python lib

QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/lib
}


TARGET = pymeshlab.$$TARGET_NAME

DEFINES += MESHLAB_SCALAR=float

include(../meshlab/src/find_system_libs.pri)

#Eigen and glew dirs
CONFIG(system_eigen3): EIGENDIR = /usr/include/eigen3
!CONFIG(system_eigen3):EIGENDIR = ../meshlab/vcglib/eigenlib
!CONFIG(system_glew):  GLEWDIR = ../meshlab/src/external/glew-2.1.0

INCLUDEPATH += \
	../pybind11/include/ \                 #pybind11
	$$EIGENDIR \                           #eigen
	$$GLEWDIR/include/ \                   #glew
	../meshlab/vcglib \                    #vcg
	../meshlab/src/common                  #meshlab_common

SOURCES += \
	pymeshlab.cpp

