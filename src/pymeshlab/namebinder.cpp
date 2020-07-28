#include "namebinder.h"

#include "pymeshlabcommon.h"

pymeshlab::NameBinder::NameBinder()
{

}

void pymeshlab::NameBinder::popolate(const PluginManager pm)
{
	std::string samplesPath = getSamplesPath();

	MeshDocument dummyMeshDocument;
	dummyMeshDocument.addNewMesh(QString::fromStdString(getSamplesPath() + "cube.obj"), "cube");

	for (auto fp : pm.meshFilterPlug){
		auto acts = fp->actions();
		for (auto act : acts){
			QString originalFilterName = fp->filterName(act);
			QString pythonFilterName = toPythonName(originalFilterName);
			std::cerr << pythonFilterName.toStdString() << "\n";

			RichParameterSet rps;
			fp->initParameterSet(act, *dummyMeshDocument.mm(), rps);
			for (auto rp : rps.paramList){
				QString originalParameterName = rp->name;
				QString pythonParameterName = toPythonName(originalParameterName);
				std::cerr << "\t" << pythonParameterName.toStdString() << "\n";
			}
		}
	}

}

QString pymeshlab::NameBinder::toPythonName(const QString& name) const
{
	QString pythonName = name.toLower();
	pythonName.replace(' ', '_');
	pythonName.replace('/', '_');
	pythonName.replace('-', '_');
	pythonName.remove(QRegularExpression("[().,'\":+]+"));
	return pythonName;
}
