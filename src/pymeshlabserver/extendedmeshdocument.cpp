#include "extendedmeshdocument.h"

#include "pymeshlabcommon.h"

ExtendedMeshDocument::ExtendedMeshDocument() :
	MeshDocument(), s(), pm()
{
	QDir dir(QString::fromStdString(pymeshlab::getRootAbsolutePath()));
#ifndef __APPLE__
	dir.cd("lib/meshlab/plugins");
#else
	dir.cd("lib/plugins");
#endif

	//pymeshlab::QDebugRedirect qdbr; //redirect qdebug to null
	pm.loadPlugins(s, dir);
}

//still not working
void ExtendedMeshDocument::loadMesh(const std::string& filename)
{
	QFileInfo finfo(QString::fromStdString(filename));
	if (!finfo.exists()){
		std::cerr << "File does not exists!";
		//todo: manage python exception
	}
	else {
		QString extension = finfo.suffix().toLower();

		if (pm.allKnowInputFormats.contains(extension)){
			MeshIOInterface* plugin = pm.allKnowInputFormats[extension];
			int mask = 0; //todo: use this mask
			RichParameterSet rps; //todo: use rps (example: needs this)
			this->addNewMesh(finfo.filePath(), finfo.fileName());
			bool ok = plugin->open(extension, QString::fromStdString(filename), *(this->mm()), mask, rps);
			if (!ok)
				this->delMesh(this->mm());
			//todo: manage python exception
		}
		else {
			std::cerr << "Unknown format: " << extension.toStdString() << "\n";

			for (auto s: pm.inpFilters)
				std::cerr << s.toStdString() << "; ";
			std::cerr << "\n\n";
			//todo: manage python exception
		}

	}
}


