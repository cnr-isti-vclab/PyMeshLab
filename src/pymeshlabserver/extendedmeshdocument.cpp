#include "extendedmeshdocument.h"

std::string ExtendedMeshDocument::path;

ExtendedMeshDocument::ExtendedMeshDocument() :
	MeshDocument(), s(), pm()
{
	//std::cerr << "Path: " << path << "\n";
	//pm.loadPlugins(s);

	//std::cerr << pm.pluginsDir.absolutePath().toStdString() << "\n";
}
