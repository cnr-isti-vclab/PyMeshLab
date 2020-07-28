#include "filterfunction.h"
#include <QStringList>

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(
		const QString& pythonName,
		const QString& meshlabName,
		const pymeshlab::FilterFunctionParameter::Type& type) :
	pName(pythonName),
	mName(meshlabName),
	type(type)
{

}

QString pymeshlab::FilterFunctionParameter::pythonName() const
{
	return pName;
}

QString pymeshlab::FilterFunctionParameter::meshlabName() const
{
	return mName;
}

QString pymeshlab::FilterFunctionParameter::pythonTypeString() const
{
	switch (type) {
	case INT: return "int";
	case FLOAT: return "float";
	case STRING: return "str";
	case BOOL: return "bool";
	case UNDEFINED: return "None";
	default: return "Still unsupported";
	}
}

bool pymeshlab::FilterFunctionParameter::operator<(const pymeshlab::FilterFunctionParameter& oth) const
{
	return pName < oth.pName;
}


pymeshlab::FilterFunction::FilterFunction(const QString pythonFunctionName, const QString meshlabFilterName) :
	pythonFunName(pythonFunctionName), meshlabFunName(meshlabFilterName)
{

}

void pymeshlab::FilterFunction::addParameter(const pymeshlab::FilterFunctionParameter& p)
{
	parameters.push_back(p);
}

QString pymeshlab::FilterFunction::pythonFunctionName() const
{
	return pythonFunName;
}

QString pymeshlab::FilterFunction::meshlabFunctionName() const
{
	return meshlabFunName;
}

unsigned int pymeshlab::FilterFunction::parametersNumber() const
{
	return parameters.size();
}

QStringList pymeshlab::FilterFunction::pythonFunctionParameters() const
{
	QStringList list;
	for (const FilterFunctionParameter& p : parameters)
		list.push_back(p.pythonName());
	return list;
}

bool pymeshlab::FilterFunction::operator<(const pymeshlab::FilterFunction& oth) const
{
	return pythonFunName < oth.pythonFunName;
}
