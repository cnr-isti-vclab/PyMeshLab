#include <iostream>
#include "mlapplication.h"

int main(){
	
	std::cout << "MeshLab built with " << MeshLabApplication::compilerVersion().toStdString()
		<< " and " << MeshLabApplication::qtVersion().toStdString() << std::endl;
	return 0;
}
