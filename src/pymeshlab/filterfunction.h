#ifndef PYMESHLAB_FILTERFUNCTIONLIST_H
#define PYMESHLAB_FILTERFUNCTIONLIST_H

#include <QString>
#include <list>
#include <set>

namespace pymeshlab {

class FilterFunctionParameter
{
public:
	enum Type {
		UNDEFINED,
		BOOL,
		INT,
		FLOAT,
		STRING,
		MATRIX,
		POINT,
		SHOT,
		COLOR,
		ABS_PERC,
		ENUM,
		FLOAT_LIST,
		DYNAMIC_FLOAT,
		OPEN_FILE,
		SAVE_FILE,
		MESH
	};
	FilterFunctionParameter(const QString& pName, const QString& mName, const Type& type);
	QString pythonName() const;
	QString meshlabName() const;
	QString pythonTypeString() const;

	bool operator< (const FilterFunctionParameter& oth) const;
private:
	QString pName;
	QString mName;
	Type type;
};

class FilterFunction
{
public:
	FilterFunction(const QString pythonFunName, const QString meshlabFunName);
	void addParameter(const FilterFunctionParameter& p);
	QString pythonFunctionName() const;
	QString meshlabFunctionName() const;
	unsigned int parametersNumber() const;
	QStringList pythonFunctionParameters() const;
	bool operator< (const FilterFunction& oth) const;

	using iterator = std::list<FilterFunctionParameter>::const_iterator;

	iterator begin() const {return parameters.begin();}
	iterator end() const {return parameters.end();}

private:
	QString pythonFunName;
	QString meshlabFunName;
	std::list<FilterFunctionParameter> parameters;
};

}

#endif // PYMESHLAB_FILTERFUNCTIONLIST_H
