#include "extendedmeshdocument.h"

#include "pymeshlabcommon.h"

ExtendedMeshDocument::ExtendedMeshDocument() :
	MeshDocument(), s(), pm()
{
	QDir dir(QString::fromStdString(pymeshlab::getRootAbsolutePath()));
	dir.cd("lib/meshlab/plugins");

	pymeshlab::QDebugRedirect qdbr; //redirect qdebug to null
	pm.loadPlugins(s, dir);
}

//still not working
void ExtendedMeshDocument::loadMesh(const std::string& filename)
{
	QFileInfo finfo(QString::fromStdString(filename));
	if (!finfo.exists()){
		std::cerr << "File does not exists!";
	}
	QString extension = finfo.suffix().toLower();

	if (pm.allKnowInputFormats.contains(extension)){
		MeshIOInterface* plugin = pm.allKnowInputFormats[extension];
		int mask = 0;
		RichParameterSet rps;
		plugin->open(extension, QString::fromStdString(filename), *this->mm(), mask, rps);
	}
	else {
		std::cerr << "Unknown format: " << extension.toStdString() << "\n";
	}
}


