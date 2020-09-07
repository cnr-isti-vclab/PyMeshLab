#ifndef PYMESHLAB_FILTERFUNCTIONPARAMETER_H
#define PYMESHLAB_FILTERFUNCTIONPARAMETER_H

#include <QString>
class Value;
class RichParameter;

namespace pymeshlab {

class FilterFunctionParameter
{
public:
	FilterFunctionParameter(
			const QString& pName,
			const RichParameter& parameter);
	FilterFunctionParameter(const FilterFunctionParameter& oth);
	FilterFunctionParameter(FilterFunctionParameter&& oth);
	virtual ~FilterFunctionParameter();
	QString pythonName() const;
	QString meshlabName() const;
	QString pythonTypeString() const;
	QString description() const;
	QString longDescription() const;
	const Value& defaultValue() const;
	void printDefaultValue(std::ostream& o) const;
	QString defaultValueString() const;

	FilterFunctionParameter& operator=(FilterFunctionParameter oth);
	bool operator< (const FilterFunctionParameter& oth) const;
	bool operator==(const FilterFunctionParameter& oth) const;
	void swap(FilterFunctionParameter& oth);
private:
	QString computePythonTypeString(const RichParameter& par);
	QString pName;
	QString pType;
	RichParameter* parameter;
};

}

#endif // PYMESHLAB_FILTERFUNCTIONPARAMETER_H
