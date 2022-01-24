/*****************************************************************************
 * PyMeshLab                                                         o o     *
 * A versatile mesh processing toolbox                             o     o   *
 *                                                                _   O  _   *
 * Copyright(C) 2005-2021                                           \/)\/    *
 * Visual Computing Lab                                            /\/|      *
 * ISTI - Italian National Research Council                           |      *
 *                                                                    \      *
 * All rights reserved.                                                      *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
 * for more details.                                                         *
 *                                                                           *
 ****************************************************************************/
#include "module_functions.h"

#include <QDir>

#include <common/GLExtensionsManager.h>
#include <common/globals.h>
#include <common/mlapplication.h>
#include <common/plugins/action_searcher.h>
#include <common/plugins/plugin_manager.h>
#include <common/python/function_set.h>

#include "helpers/common.h"

void pymeshlab::loadDefaultPlugins()
{
	GLExtensionsManager::init();
	PluginManager& pm = meshlab::pluginManagerInstance();
	pm.loadPlugins(QDir(QString::fromStdString(getPluginsPath())));

	// add all the filters to the action searcher
	ActionSearcher& as = meshlab::actionSearcherInstance();
	for (const auto& p : pm.filterPluginIterator()) {
		for (QAction* a : p->actions()) {
			a->setToolTip(p->filterInfo(a));
			as.addAction(a, true);
		}
	}
}

std::string pymeshlab::getVersion()
{
	std::string pymsversion;
#ifdef PYMESHLAB_VERSION
	pymsversion = PYMESHLAB_STRINGIFY(PYMESHLAB_VERSION);
#else
	pymsversion = "DEV";
#endif
	return pymsversion;
}

void pymeshlab::printVersion()
{
	std::string pymsversion = getVersion();
	std::cout << "PyMeshLab " << pymsversion << " based on MeshLab "
			  << MeshLabApplication::appVer().toStdString() << "\n";
}

std::list<std::string> pymeshlab::filterList()
{
	return pymeshlab::functionSetInstance().pythonFilterFunctionNames();
}

int pymeshlab::numberPlugins()
{
	PluginManager& pm = meshlab::pluginManagerInstance();
	return pm.size();
}

void pymeshlab::printPluginList()
{
	PluginManager& pm = meshlab::pluginManagerInstance();
	std::cout << "PyMeshLab - List of loaded plugins (" << pm.size() << "):\n";
	for (const auto& p : pm.pluginIterator()) {
		std::cout << "\t" << p->pluginName().toStdString() << "\n";
	}
}

void pymeshlab::printPluginFilterList(const std::string& pluginName)
{
	PluginManager& pm    = meshlab::pluginManagerInstance();
	bool           found = false;
	FilterPlugin*  fp    = nullptr;
	for (const auto& p : pm.pluginIterator()) {
		if (p->pluginName().toStdString() == pluginName) {
			fp = dynamic_cast<FilterPlugin*>(p);
			if (fp) {
				found = true;
			}
		}
	}
	if (found) {
		std::cout << pluginName + " plugin - list of filter names:\n";
		for (QAction* a : fp->actions()) {
			std::cout << "\t" << fp->pythonFilterName(fp->ID(a)).toStdString() << "\n";
		}
	}
	else {
		throw MLException(
			"Impossible to find a plugin called " + QString::fromStdString(pluginName));
	}
}

void pymeshlab::printFilterList()
{
	FunctionSet&           fs   = pymeshlab::functionSetInstance();
	std::list<std::string> list = fs.pythonFilterFunctionNames();
	std::cout << "MeshSet class - list of filter names:\n";
	for (const std::string& fname : list) {
		std::cout << "\t" << fname << "\n";
	}
}

/**
 * @brief given the function names, lists all its parameters that can be
 * passed to the "apply_filter" function
 */
void pymeshlab::printFilterParameterList(const std::string& filterName)
{
	FunctionSet&    fs = pymeshlab::functionSetInstance();
	const Function& ff = fs.filterFunction(QString::fromStdString(filterName));
	std::cout << "Please note: some parameters depend on the mesh(es) used as input of the \n"
				 "filter. Default values listed here are computed on a 1x1x1 cube \n"
				 "(pymeshlab/tests/sample/cube.obj), and they will be computed on the input mesh\n"
				 "if they are left as default.\n";

	std::cout << filterName << " filter - list of parameter names:\n";
	if (ff.parametersNumber() == 0) {
		std::cout << "\tNone.\n";
	}
	else {
		for (const FunctionParameter& ffp : ff) {
			std::cout << "\t" << ffp.pythonName().toStdString() << " : "
					  << ffp.pythonTypeString().toStdString() << " = ";
			ffp.printDefaultValue(std::cout);
			std::cout << "\n";
		}
	}
}

void pymeshlab::search(const std::string& searchKeyWord)
{
	ActionSearcher&       as  = meshlab::actionSearcherInstance();
	PluginManager&        pm  = meshlab::pluginManagerInstance();
	std::vector<QAction*> res = as.bestMatchingActions(QString::fromStdString(searchKeyWord), 15);

	uint max = 0;
	std::vector<std::string> names;
	names.reserve(res.size());
	for (QAction* a : res) {
		FilterPlugin* fp = pm.getFilterPluginFromAction(a);
		if (fp == nullptr) {
			throw MLException(
				"An internal error has occurred. Please report this error here: "
				"https://github.com/cnr-isti-vclab/PyMeshLab/issues");
		}
		names.push_back(fp->pythonFilterName(a).toStdString());
		if(fp->pythonFilterName(a).size() > max)
			max = fp->pythonFilterName(a).size();
	}
	for (const std::string& s : names) {
		std::cout << s;
		for (unsigned int i = 0; i < max - s.size(); ++i) std::cerr << " ";
		std::cerr << " : "
				  << "https://pymeshlab.readthedocs.io/en/" << getVersion() << "/filter_list.html#"
				  << s << std::endl;
	}
}

void pymeshlab::loadPlugin(const std::string& filename)
{
	MeshLabPluginType type = PluginManager::checkPlugin(QString::fromStdString(filename));
	if (!(type.isIOPlugin() || type.isFilterPlugin())) {
		throw MLException(
			"Error while loading plugin: PyMeshLab only supports IO or Filter plugins.");
	}
	PluginManager&    pm  = meshlab::pluginManagerInstance();
	FunctionSet&      fs  = pymeshlab::functionSetInstance();
	MeshLabPlugin*    ipf = pm.loadPlugin(QString::fromStdString(filename));
	MeshLabPluginType tp(ipf);
	if (tp.isFilterPlugin()) {
		FilterPlugin* fp = dynamic_cast<FilterPlugin*>(ipf);
		fs.loadFilterPlugin(fp);
		// add the newly added filters to the action searcher
		ActionSearcher& as = meshlab::actionSearcherInstance();
		for (QAction* a : fp->actions()) {
			a->setToolTip(fp->filterInfo(a));
			as.addAction(a);
		}
	}
	else if (tp.isIOPlugin()) {
		fs.loadIOPlugin(dynamic_cast<IOPlugin*>(ipf));
	}
	else { // this should never happen
		throw MLException("Error while loading plugin: Unknown plugin type.");
	}
}
