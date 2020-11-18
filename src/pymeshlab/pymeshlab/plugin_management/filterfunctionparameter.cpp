#include "filterfunctionparameter.h"

#include "pymeshlab/helpers/common.h"
#include <common/filter_parameter/rich_parameter_list.h>

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

QString pymeshlab::FilterFunctionParameter::meshlabTypeString() const
{
	return parameter->stringType();
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

const RichParameter& pymeshlab::FilterFunctionParameter::richParameter() const
{
	return *parameter;
}

void pymeshlab::FilterFunctionParameter::printDefaultValue(std::ostream& o) const
{
	if (!parameter)
		o << "no_value";
	if (parameter->value().isEnum()) {
		RichEnum* ren = dynamic_cast<RichEnum*>(parameter);
		o << "'" << ren->enumvalues.at(ren->value().getEnum()).toStdString() << "'";
		return;
	}
	if (parameter->value().isAbsPerc()) {
		RichAbsPerc* rabs = dynamic_cast<RichAbsPerc*>(parameter);
		float abs = parameter->value().getAbsPerc();
		float perc = (abs - rabs->min) / (rabs->max - rabs->min) * 100;
		o << perc << "%";
		return;
	}
	if (parameter->value().isDynamicFloat()) {
		RichDynamicFloat* rdyn = dynamic_cast<RichDynamicFloat*>(parameter);
		o << parameter->value().getDynamicFloat() <<
			 " [min: " << rdyn->min << "; max: " << rdyn->max << "]";
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
		const MESHLAB_SCALAR* v = parameter->value().getMatrix44f().V();
		o << "[[" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << "],"
			<< "[" << v[4] << ", " << v[5] << ", " << v[6] << ", " << v[7] << "],"
			<< "[" << v[8] << ", " << v[9] << ", " << v[10] << ", " << v[11] << "],"
			<< "[" << v[12] << ", " << v[13] << ", " << v[14] << ", " << v[15] << "]]";
		return;
	}
	if (parameter->value().isPoint3f()) {
		o << "[" << parameter->value().getPoint3f().X() << ", "
			<< parameter->value().getPoint3f().Y() << ", "
			<< parameter->value().getPoint3f().Z() << "]";
		return;
	}
	if (parameter->value().isShotf()) {
		o << "None";
		return;
	}
	if (parameter->value().isColor()) {
		QColor c = parameter->value().getColor();
		o <<
			"[" + std::to_string(c.red()) + "; " +
			std::to_string(c.green()) + "; " +
			std::to_string(c.blue()) + "; " +
			std::to_string(c.alpha()) + "]";
		return;
	}
	if (parameter->value().isMesh()){
		const RichMesh* rm = dynamic_cast<const RichMesh*>(parameter);
		o << rm->meshindex;
		return;
	}
	if (parameter->value().isFileName()){
		o << "'" << parameter->value().getFileName().toStdString() << "'";
		return;
	}

	//to support: dynamicfloat, filename, mesh
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
		return PYTHON_TYPE_ENUM;
	if (v.isAbsPerc())
		return PYTHON_TYPE_ABSPERC;
	if (v.isDynamicFloat())
		return PYTHON_TYPE_DYNAMIC_FLOAT;
	if (v.isBool())
		return PYTHON_TYPE_BOOL;
	if (v.isInt())
		return PYTHON_TYPE_INT;
	if (v.isFloat())
		return PYTHON_TYPE_FLOAT;
	if (v.isString())
		return PYTHON_TYPE_STRING;
	if (v.isMatrix44f())
		return PYTHON_TYPE_MATRIX44F;
	if (v.isPoint3f())
		return PYTHON_TYPE_POINT3F;
	if (v.isShotf())
		return PYTHON_TYPE_SHOTF;
	if (v.isColor())
		return PYTHON_TYPE_COLOR;
	if (v.isMesh())
		return PYTHON_TYPE_MESH;
	if (v.isFileName())
		return PYTHON_TYPE_FILENAME;
	return "still_unsupported";
}
