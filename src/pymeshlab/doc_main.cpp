#include <iostream>

#include "pymeshlab/meshset.h"

int main(int , char *[])
{
	pymeshlab::MeshSet ms;

	std::string doc = ms.filtersRSTDocumentation();

	QFile f("../docs/filter_list.rst");

	if (!f.open(QIODevice::WriteOnly)) {
		std::cerr << "Could not open docs/filter_list.rst file.\n";
		return -1;
	}

	f.write(doc.data());

	f.close();

	return 0;
}
