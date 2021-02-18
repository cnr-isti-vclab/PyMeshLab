#include <iostream>

#include "pymeshlab/meshset.h"
#include "pymeshlab/helpers/common.h"
#include "pymeshlab/module_functions.h"

int main(int , char *[])
{
	pymeshlab::loadDefaultPlugins();
	pymeshlab::MeshSet ms;

	std::string doc = ms.filtersRSTDocumentation();

	QString baseDir(PYMESHLAB_STRINGIFY(PYMESHLAB_SRC_BASE_DIR));
		
	QFile f(baseDir + "/../../docs/filter_list.rst");

	if (!f.open(QIODevice::WriteOnly)) {
		std::cerr << "Could not open docs/filter_list.rst file.\n";
		return -1;
	}

	f.write(doc.data());

	f.close();

	return 0;
}
