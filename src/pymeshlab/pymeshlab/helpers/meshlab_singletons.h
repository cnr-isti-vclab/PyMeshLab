#ifndef PYMESHLAB_MESHLABSINGLETONS_H
#define PYMESHLAB_MESHLABSINGLETONS_H

#include <string>

class RichParameterList;
class PluginManager;

namespace pymeshlab {

class MeshLabSingletons
{
public:
	/** Singleton Instances **/
	static RichParameterList& globalRPLInstance();
	static PluginManager& pluginManagerInstance(bool verbose = false);

	MeshLabSingletons(MeshLabSingletons const&) = delete;
	void operator=(MeshLabSingletons const&) = delete;
private:
	MeshLabSingletons();
};

}

#endif // PYMESHLAB_MESHLABSINGLETONS_H
