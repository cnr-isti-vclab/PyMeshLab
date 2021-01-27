/****************************************************************************
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
#include "meshlab_singletons.h"

#include <common/plugin_manager.h>
#include "common.h"

RichParameterList& pymeshlab::MeshLabSingletons::globalRPLInstance()
{
	static bool initialized = false;
	static RichParameterList globalRPS;
	if (!initialized){
		initialized = true;
		globalRPS.addParam(RichInt(
			PYMESHLAB_GLOBAL_SETTING_MAXGPUMEM, 
			350, 
			"Maximum GPU Memory Dedicated to PyMeshLab (Mb)",
			"Maximum GPU Memory Dedicated to PyMeshLab (megabyte) for the storing "
				"of the geometry attributes. The dedicated memory must NOT be all "
				"the GPU memory presents on the videocard."));
	}
	return globalRPS;
}

PluginManager& pymeshlab::MeshLabSingletons::pluginManagerInstance(bool verbose)
{
	static bool initialized = false;
	static PluginManager pm;
	if (!initialized){
		initialized = true;
		QDir dir(QString::fromStdString(getPluginsPath()));
		pymeshlab::QDebugRedirect* qdbr = nullptr;
		if (!verbose)
			qdbr = new pymeshlab::QDebugRedirect(); //redirect qdebug to null, just for this scope
		pm.loadPlugins(dir);
		delete qdbr;
	}
	return pm;
}

vcg::QtThreadSafeMemoryInfo& pymeshlab::MeshLabSingletons::threadSafeMemoryInfoInstance()
{
	static int gpumemmb = globalRPLInstance().getInt(PYMESHLAB_GLOBAL_SETTING_MAXGPUMEM);
	static std::ptrdiff_t maxgpumem = (std::ptrdiff_t) gpumemmb * (float)(1024 * 1024);
	static vcg::QtThreadSafeMemoryInfo gpumeminfo(maxgpumem);
	return gpumeminfo;
}

pymeshlab::MeshLabSingletons::MeshLabSingletons()
{
}
