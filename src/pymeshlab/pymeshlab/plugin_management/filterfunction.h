#ifndef PYMESHLAB_FILTERFUNCTIONLIST_H
#define PYMESHLAB_FILTERFUNCTIONLIST_H

#include "filterfunctionparameter.h"

#include <QString>
#include <list>
#include <set>

namespace pymeshlab {

class FilterFunction
{
public:
	FilterFunction();
	FilterFunction(const QString pythonFunName, const QString meshlabFunName, const QString description);
	void addParameter(const FilterFunctionParameter& p);
	QString pythonFunctionName() const;
	QString meshlabFunctionName() const;
	QString description() const;
	unsigned int parametersNumber() const;
	QStringList pythonFunctionParameters() const;
	bool contains(const QString& pythonParameter) const;
	const FilterFunctionParameter& getFilterFunctionParameter(const QString& pythonParameter) const;

	bool operator< (const FilterFunction& oth) const;

	using iterator = std::list<FilterFunctionParameter>::const_iterator;

	iterator begin() const {return parameters.begin();}
	iterator end() const {return parameters.end();}

private:
	QString pythonFunName;
	QString meshlabFunName;
	QString funDescription;
	std::list<FilterFunctionParameter> parameters;
};

}

#endif // PYMESHLAB_FILTERFUNCTIONLIST_H
