#include "filterfunctionset.h"

#include "pymeshlabcommon.h"

pymeshlab::FilterFunctionSet::FilterFunctionSet()
{
}

void pymeshlab::FilterFunctionSet::popolate(const PluginManager& pm)
{
	std::string samplesPath = getSamplesPath();

	MeshDocument dummyMeshDocument;
	QString dummyMesh(QString::fromStdString(getSamplesPath() + "cube.obj"));
	dummyMeshDocument.addNewMesh(dummyMesh, "cube");
	int mask = 0;
	mask |= vcg::tri::io::Mask::IOM_VERTQUALITY;
	mask |= vcg::tri::io::Mask::IOM_FACEQUALITY;
	dummyMeshDocument.mm()->Enable(mask);

	for (auto inputFormat : pm.allKnowInputFormats.keys()){
		QString originalFilterName = inputFormat;
		QString pythonFilterName = "load_" + inputFormat.toLower();
		FilterFunction f(pythonFilterName, originalFilterName);
		MeshIOInterface* plugin = pm.allKnowInputFormats[inputFormat];
		RichParameterSet rps;
		plugin->initGlobalParameterSet(nullptr, rps);
		plugin->initPreOpenParameter(inputFormat, dummyMesh, rps);
		plugin->initOpenParameter(inputFormat, *dummyMeshDocument.mm(), rps);

		//filename parameter
		QString originalParameterName = "file_name";
		QString pythonParameterName = toPythonName(originalParameterName);
		StringValue sv = "file." + inputFormat;
		StringDecoration sd(new StringValue(sv));
		FilterFunctionParameter par(pythonParameterName, originalParameterName, &sv, &sd);
		f.addParameter(par);

		for (RichParameter* rp : rps.paramList){
			QString originalParameterName = rp->name;
			QString pythonParameterName = toPythonName(originalParameterName);
			FilterFunctionParameter par(pythonParameterName, originalParameterName, rp->val, rp->pd);
			f.addParameter(par);
		}
		functionSet.insert(f);
	}

	for (auto outputFormat : pm.allKnowOutputFormats.keys()){
		QString originalFilterName = outputFormat;
		QString pythonFilterName = "save_" + outputFormat.toLower();
		FilterFunction f(pythonFilterName, originalFilterName);
		MeshIOInterface* plugin = pm.allKnowOutputFormats[outputFormat];
		RichParameterSet rps;
		plugin->initGlobalParameterSet(nullptr, rps);
		plugin->initPreOpenParameter(outputFormat, dummyMesh, rps);
		plugin->initOpenParameter(outputFormat, *dummyMeshDocument.mm(), rps);

		//filename parameter
		QString originalParameterName = "file_name";
		QString pythonParameterName = toPythonName(originalParameterName);
		StringValue sv = "file." + outputFormat;
		StringDecoration sd(new StringValue(sv));
		FilterFunctionParameter par(pythonParameterName, originalParameterName, &sv, &sd);
		f.addParameter(par);

		for (RichParameter* rp : rps.paramList){
			QString originalParameterName = rp->name;
			QString pythonParameterName = toPythonName(originalParameterName);
			FilterFunctionParameter par(pythonParameterName, originalParameterName, rp->val, rp->pd);
			f.addParameter(par);
		}
		functionSet.insert(f);
	}

	for (MeshFilterInterface* fp : pm.meshFilterPlug){
		QList<QAction*> acts = fp->actions();
		for (QAction* act : acts) {
			QString originalFilterName = fp->filterName(act);
			QString pythonFilterName = toPythonName(originalFilterName);
			FilterFunction f(pythonFilterName, originalFilterName);

			RichParameterSet rps;
			fp->initGlobalParameterSet(act, rps);
			fp->initParameterSet(act, dummyMeshDocument, rps);

			for (RichParameter* rp : rps.paramList){
				QString originalParameterName = rp->name;
				QString pythonParameterName = toPythonName(originalParameterName);
				FilterFunctionParameter par(pythonParameterName, originalParameterName, rp->val, rp->pd);
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
