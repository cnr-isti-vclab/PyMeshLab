#include <iostream>

#include "pymeshlab/meshset.h"
#include "pymeshlab/module_functions.h"
#include <pybind11/embed.h>
#include <pymeshlab/mesh.h>
#include <pymeshlab/percentage.h>

#include <common/python/python_utils.h>

#include <fstream>

int main(int , char *[])
{
	std::ofstream file;
	file.open("keys.txt");

	PluginManager& pm = meshlab::pluginManagerInstance();

	for (auto* p : pm.filterPluginIterator()) {
		auto list = p->actions();
		for (auto f : list) {
			QString s1 = pymeshlab::computePythonName(p->filterName(f));
			QString s2 = p->pythonFilterName(f);
			file << s1.toStdString() << " " << s2.toStdString() << "\n";
		}
	}
	file.close();

	return 0;
}

