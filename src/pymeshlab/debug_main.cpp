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

	//pybind11::kwargs kw;
	//kw["param"] = 0.2;

	//ms.applyFilter("filter", kw);

	std::cout << "Hello, PyMeshLab!\n";
	return 0;
}

