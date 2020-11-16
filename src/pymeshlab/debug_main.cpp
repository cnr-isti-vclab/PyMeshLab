#include <iostream>

#include "pymeshlab/meshset.h"
#include <pybind11/embed.h>

int main(int , char *[])
{
	pymeshlab::MeshSet ms;

	pybind11::scoped_interpreter guard{};
	//pybind11::kwargs kw;
	//kw["param"] = 0.2;
	
	//ms.applyFilter("filter", kw);

	std::cout << "Hello, PyMeshLab!\n";
	return 0;
}

