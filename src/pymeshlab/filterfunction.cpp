#include "filterfunction.h"
#include <QStringList>
#include <filter_parameter/rich_parameter.h>

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

bool pymeshlab::FilterFunction::contains(const QString& pythonParameter) const
{
	RichInt tmp("", 0);
	iterator it = std::find(parameters.begin(), parameters.end(), FilterFunctionParameter(pythonParameter, tmp));
	return it != parameters.end();
}

const pymeshlab::FilterFunctionParameter& pymeshlab::FilterFunction::getFilterFunctionParameter(const QString& pythonParameter) const
{
	RichInt tmp("", 0);
	iterator it = std::find(parameters.begin(), parameters.end(), FilterFunctionParameter(pythonParameter, tmp));
	return *it;
}

bool pymeshlab::FilterFunction::operator<(const pymeshlab::FilterFunction& oth) const
{
	return pythonFunName < oth.pythonFunName;
}
