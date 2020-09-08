#include <iostream>

#include "pymeshlab/meshset.h"

int main(int , char *[])
{
	pymeshlab::MeshSet ms;

	//pybind11::kwargs kw;
	//kw["param"] = 0.2;

	std::cout << "Hello, PyMeshLab!\n";
	return 0;
}

