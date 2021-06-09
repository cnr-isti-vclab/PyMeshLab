#include <iostream>

#include "pymeshlab/meshset.h"
#include "pymeshlab/module_functions.h"
#include <pybind11/embed.h>
#include <pymeshlab/mesh.h>
#include <pymeshlab/percentage.h>

int main(int , char *[])
{
	pybind11::scoped_interpreter guard{};
	pymeshlab::loadDefaultPlugins();
	pymeshlab::MeshSet ms;
	ms.loadNewMesh("/home/alessandro/Repositories/Projects/PyMeshLab/src/meshlab/sample/bunny10k_textured.obj");

	//pybind11::kwargs kw;
	//kw["param"] = 0.2;

	//ms.applyFilter("filter", kw);

	std::cout << "Hello, PyMeshLab!\n";
	return 0;
}

