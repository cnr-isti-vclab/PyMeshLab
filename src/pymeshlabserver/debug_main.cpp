#include <iostream>
#include "extendedmeshdocument.h"

int main(int , char *[])
{
	ExtendedMeshDocument m;

	m.loadMesh("/home/alessandro/Drive/Research/Repos/Projects/PyMeshLab/pymeshlab/tests/sample/bone.obj");
	return 0;
}

