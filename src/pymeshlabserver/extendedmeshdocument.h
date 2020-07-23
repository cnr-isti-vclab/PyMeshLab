#ifndef PYMESHLAB_EXTENDEDMESHDOCUMENT_H
#define PYMESHLAB_EXTENDEDMESHDOCUMENT_H

#include <meshmodel.h>
#include <pluginmanager.h>

class ExtendedMeshDocument : public MeshDocument
{
public:
	ExtendedMeshDocument();

	void loadPlugin(const QString& absPath);
private:
	std::string basePath;
	RichParameterSet s;
	PluginManager pm;
};

#endif // PYMESHLAB_EXTENDEDMESHDOCUMENT_H