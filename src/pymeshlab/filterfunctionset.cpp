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
				FilterFunctionParameter par(pythonParameterName, originalParameterName, typeOfParameter(rp));
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

pymeshlab::FilterFunctionParameter::Type pymeshlab::FilterFunctionSet::typeOfParameter(
		const RichParameter* rp)
{
	if (rp->val->isBool())
		return FilterFunctionParameter::BOOL;
	if (rp->val->isInt())
		return FilterFunctionParameter::INT;
	if (rp->val->isFloat())
		return FilterFunctionParameter::FLOAT;
	if (rp->val->isString())
		return FilterFunctionParameter::STRING;
	if (rp->val->isMatrix44f())
		return FilterFunctionParameter::MATRIX;
	if (rp->val->isPoint3f())
		return FilterFunctionParameter::POINT;
	if (rp->val->isShotf())
		return FilterFunctionParameter::SHOT;
	if (rp->val->isColor())
		return FilterFunctionParameter::COLOR;
	if (rp->val->isAbsPerc())
		return FilterFunctionParameter::ABS_PERC;
	if (rp->val->isEnum())
		return FilterFunctionParameter::ENUM;
	//to support: floatlist, dynamicfloat, openfile, savefile, mesh

	return FilterFunctionParameter::UNDEFINED;
}

void pymeshlab::FilterFunctionSet::addFunction(const pymeshlab::FilterFunction& f)
{
	functionSet.insert(f);
}

void pymeshlab::FilterFunctionSet::deleteFunction(const pymeshlab::FilterFunction& f)
{
	functionSet.erase(f);
}
