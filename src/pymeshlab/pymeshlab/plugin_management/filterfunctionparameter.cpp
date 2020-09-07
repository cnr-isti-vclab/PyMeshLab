#include "filterfunctionparameter.h"

#include "filter_parameter/rich_parameter_list.h"

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(const QString& pName,
		const RichParameter& parameter) :
	pName(pName),
	pType(computePythonTypeString(parameter)),
	parameter(parameter.clone())
{
}

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(
		const pymeshlab::FilterFunctionParameter& oth):
	pName(oth.pName),
	pType(oth.pType),
	parameter(oth.parameter->clone())
{
}

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(pymeshlab::FilterFunctionParameter&& oth):
	pName(oth.pName),
	pType(oth.pType)
{
	parameter = oth.parameter;
	oth.parameter = nullptr;
}

pymeshlab::FilterFunctionParameter::~FilterFunctionParameter()
{
	delete parameter;
}

QString pymeshlab::FilterFunctionParameter::pythonName() const
{
	return pName;
}

QString pymeshlab::FilterFunctionParameter::meshlabName() const
{
	return parameter->name();
}

QString pymeshlab::FilterFunctionParameter::pythonTypeString() const
{
	return pType;
}

QString pymeshlab::FilterFunctionParameter::description() const
{
	if (parameter){
		return parameter->fieldDescription();
	}
	return QString();
}

QString pymeshlab::FilterFunctionParameter::longDescription() const
{
	if (parameter){
		return parameter->toolTip();
	}
	return QString();
}

const Value& pymeshlab::FilterFunctionParameter::defaultValue() const
{
	return parameter->value();
}

void pymeshlab::FilterFunctionParameter::printDefaultValue(std::ostream& o) const
{
	if (!parameter)
		o << "no_value";
	if (parameter->value().isEnum()) {
		o << parameter->value().getEnum();
		return;
	}
	if (parameter->value().isAbsPerc()) {
		RichAbsPerc* rabs = dynamic_cast<RichAbsPerc*>(parameter);
		float abs = parameter->value().getAbsPerc();
		float perc = (abs - rabs->min) / (rabs->max - rabs->min) * 100;
		o << perc << "% (float = " << abs << ")";
		return;
	}
	if (parameter->value().isDynamicFloat()) {
		o << parameter->value().getDynamicFloat();
		return;
	}
	if (parameter->value().isBool()) {
		o << (parameter->value().getBool() ? "true" : "false");
		return;
	}
	if (parameter->value().isInt()) {
		o << parameter->value().getInt();
		return;
	}
	if (parameter->value().isFloat()){
		o << parameter->value().getFloat();
		return;
	}
	if (parameter->value().isString()){
		o << "'" << parameter->value().getString().toStdString() << "'";
		return;
	}
	if (parameter->value().isMatrix44f()){
		o << "None";
		return;
	}
	if (parameter->value().isPoint3f()) {
		o << "None";
		return;
	}
	if (parameter->value().isShotf()) {
		o << "None";
		return;
	}
	if (parameter->value().isColor()) {
		o << "None";
		return;
	}
	if (parameter->value().isMesh()){
		o << "None";
		return;
	}
	if (parameter->value().isFileName()){
		o << "'" << parameter->value().getFileName().toStdString() << "'";
		return;
	}
	if (parameter->value().isFloatList()){
		o << "None";
		return;
	}

	//to support: floatlist, dynamicfloat, openfile, savefile, mesh
}

QString pymeshlab::FilterFunctionParameter::defaultValueString() const
{
	std::stringstream ss;
	printDefaultValue(ss);
	return QString::fromStdString(ss.str());
}

pymeshlab::FilterFunctionParameter& pymeshlab::FilterFunctionParameter::operator=(pymeshlab::FilterFunctionParameter oth)
{
	this->swap(oth);
	return *this;
}

bool pymeshlab::FilterFunctionParameter::operator<(const pymeshlab::FilterFunctionParameter& oth) const
{
	return pName < oth.pName;
}

bool pymeshlab::FilterFunctionParameter::operator==(const pymeshlab::FilterFunctionParameter& oth) const
{
	return pName == oth.pName;
}

void pymeshlab::FilterFunctionParameter::swap(pymeshlab::FilterFunctionParameter& oth)
{
	std::swap(pName, oth.pName);
	std::swap(pType, oth.pType);
	std::swap(parameter, oth.parameter);
}

QString pymeshlab::FilterFunctionParameter::computePythonTypeString(const RichParameter& par)
{
	const Value& v = par.value();
	if (v.isEnum())
		return "int [" + par.value().typeName() + "]";
	if (v.isAbsPerc())
		return "Percentage";
	if (v.isDynamicFloat())
		return "float [" + par.value().typeName() + "]";
	if (v.isBool())
		return "bool";
	if (v.isInt())
		return "int";
	if (v.isFloat())
		return "float";
	if (v.isString())
		return "str";
	if (v.isMatrix44f())
		return "Matrix44f [still unsupported]";
	if (v.isPoint3f())
		return "Point3f [still unsupported]";
	if (v.isShotf())
		return "Shotf [still unsupported]";
	if (v.isColor())
		return "Color";
	if (v.isMesh())
		return "Mesh [still unsupported]";
	if (v.isFileName())
		return "str";
	if (v.isFloatList())
		return "FloatList [still unsupported]";
	return "still_unsupported";
}
