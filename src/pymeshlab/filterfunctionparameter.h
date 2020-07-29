#ifndef PYMESHLAB_FILTERFUNCTIONPARAMETER_H
#define PYMESHLAB_FILTERFUNCTIONPARAMETER_H

#include <QString>
class Value;
class ParameterDecoration;

namespace pymeshlab {

class FilterFunctionParameter
{
public:
	FilterFunctionParameter(
			const QString& pName,
			const QString& mName,
			const Value* defValue,
			const ParameterDecoration* pd);
	FilterFunctionParameter(const FilterFunctionParameter& oth);
	FilterFunctionParameter(FilterFunctionParameter&& oth);
	virtual ~FilterFunctionParameter();
	QString pythonName() const;
	QString meshlabName() const;
	QString pythonTypeString() const;
	const Value* defaultValue() const;
	void printDefaultValue(std::ostream& o) const;

	FilterFunctionParameter& operator=(FilterFunctionParameter oth);
	bool operator< (const FilterFunctionParameter& oth) const;
	bool operator==(const FilterFunctionParameter& oth) const;
	void swap(FilterFunctionParameter& oth);
private:
	static Value* createNewValue(const Value* ov);
	static ParameterDecoration* createNewParameterDecoration(const ParameterDecoration* pd, const Value* v);
	QString pName;
	QString mName;
	Value* defValue;
	ParameterDecoration* pd;
};

}

#endif // PYMESHLAB_FILTERFUNCTIONPARAMETER_H
