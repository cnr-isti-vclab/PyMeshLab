#include "filterfunctionset.h"

#include "pymeshlabcommon.h"

pymeshlab::FilterFunctionSet::FilterFunctionSet()
{
}

void pymeshlab::FilterFunctionSet::popolate(const PluginManager& pm)
{
	std::string samplesPath = getSamplesPath();

	MeshDocument dummyMeshDocument;
	dummyMeshDocument.addNewMesh(
				QString::fromStdString(getSamplesPath() + "cube.obj"), "cube");
	int mask = 0;
	mask |= vcg::tri::io::Mask::IOM_VERTQUALITY;
	mask |= vcg::tri::io::Mask::IOM_FACEQUALITY;
	dummyMeshDocument.mm()->Enable(mask);

	for (MeshFilterInterface* fp : pm.meshFilterPlug){
		QList<QAction*> acts = fp->actions();
		for (QAction* act : acts) {
			QString originalFilterName = fp->filterName(act);
			QString pythonFilterName = toPythonName(originalFilterName);
			FilterFunction f(pythonFilterName, originalFilterName);

			RichParameterSet rps;
			fp->initParameterSet(act, dummyMeshDocument, rps);

			for (RichParameter* rp : rps.paramList){
				QString originalParameterName = rp->name;
				QString pythonParameterName = toPythonName(originalParameterName);
				FilterFunctionParameter par(pythonParameterName, originalParameterName, rp->val);
				f.addParameter(par);
			}
			functionSet.insert(f);
		}
	}
}

QStringList pymeshlab::FilterFunctionSet::pythonFunctionNames() const
{
	QStringList fnames;
	for (const FilterFunction& f: functionSet){
		fnames.push_back(f.pythonFunctionName());
	}
	return fnames;
}

pymeshlab::FilterFunctionSet::iterator pymeshlab::FilterFunctionSet::find(const QString& pythonFunctionName) const
{
	return functionSet.find(FilterFunction(pythonFunctionName, ""));
}

bool pymeshlab::FilterFunctionSet::contains(const QString& pythonFunctionName) const
{
	return find(pythonFunctionName) != end();
}

QString pymeshlab::FilterFunctionSet::toPythonName(const QString& name)
{
	QString pythonName = name.toLower();
	pythonName.replace(' ', '_');
	pythonName.replace('/', '_');
	pythonName.replace('-', '_');
	pythonName.remove(QRegularExpression("[().,'\":+]+"));
	return pythonName;
}

void pymeshlab::FilterFunctionSet::addFunction(const pymeshlab::FilterFunction& f)
{
	functionSet.insert(f);
}

void pymeshlab::FilterFunctionSet::deleteFunction(const pymeshlab::FilterFunction& f)
{
	functionSet.erase(f);
}
