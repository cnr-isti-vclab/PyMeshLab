#include "bindings/pyboundingbox.h"
#include "bindings/pycolor.h"
#include "bindings/pymesh.h"
#include "bindings/pymeshset.h"
#include "bindings/pypercentage.h"

#include "bindings/pyexceptions.h"
#include "pymeshlab/helpers/common.h"

namespace py = pybind11;

//creation of a python module
PYBIND11_MODULE(PYMESHLAB_MODULE_NAME, m) {
	//bindings of all the classes in the module
	pymeshlab::initBoundingBox(m); //BoundingBox Class
	pymeshlab::initColor(m); //Color Class
	pymeshlab::initMesh(m); //Mesh Class
	pymeshlab::initMeshSet(m); //MeshDocument Class
	pymeshlab::initPercentage(m); //Percentage Class
	
	//binding the exceptions
	pymeshlab::initExceptions(m); //Exceptions
	
	//binding some other functions
	m.def("print_pymeshlab_version", &pymeshlab::printVersion);
	m.def("number_plugins", &pymeshlab::numberPlugins);
	m.def("print_plugin_list", &pymeshlab::printPluginList);
	m.def("set_max_gpu_memory", &pymeshlab::setMaxGPUMem);

#ifdef PYMESHLAB_VERSION
	m.attr("__version__") = PYMESHLAB_STRINGIFY(PYMESHLAB_VERSION);
#else
	m.attr("__version__") = "dev";
#endif

}
