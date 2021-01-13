#include "meshlab_singletons.h"

#include <common/pluginmanager.h>
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
		RichParameterList& globalRPS = globalRPLInstance();
		if (!verbose)
			qdbr = new pymeshlab::QDebugRedirect(); //redirect qdebug to null, just for this scope
		pm.loadPlugins(globalRPS, dir);
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
