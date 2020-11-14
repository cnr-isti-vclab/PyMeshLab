#include "meshlab_singletons.h"

#include <common/pluginmanager.h>
#include "common.h"

RichParameterList& pymeshlab::MeshLabSingletons::globalRPLInstance()
{
	static RichParameterList globalRPS;
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

pymeshlab::MeshLabSingletons::MeshLabSingletons()
{
}
