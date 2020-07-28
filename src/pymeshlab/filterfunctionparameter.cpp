#include "filterfunctionparameter.h"

#include "filterparameter.h"

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(
		const QString& pythonName,
		const QString& meshlabName,
		const Value* defaultValue) :
	pName(pythonName),
	mName(meshlabName),
	defValue(createNewValue(defaultValue))
{
}

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(
		const pymeshlab::FilterFunctionParameter& oth):
	pName(oth.pName),
	mName(oth.mName),
	defValue(createNewValue(oth.defValue))
{
}

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(pymeshlab::FilterFunctionParameter&& oth):
	pName(oth.pName),
	mName(oth.mName)
{
	defValue = oth.defValue;
	oth.defValue = nullptr;
}

pymeshlab::FilterFunctionParameter::~FilterFunctionParameter()
{
	delete defValue;
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
	if (defValue->isEnum()) {
		return "still_unsupported";
	}
	if (defValue->isAbsPerc()) {
		return "still_unsupported";
	}
	if (defValue->isDynamicFloat()) {
		return "still_unsupported";
	}
	if (defValue->isBool())
		return "bool";
	if (defValue->isInt())
		return "int";
	if (defValue->isFloat())
		return "float";
	if (defValue->isString())
		return "str";
	return "still_unsupported";
}

const Value* pymeshlab::FilterFunctionParameter::defaultValue() const
{
	return defValue;
}

void pymeshlab::FilterFunctionParameter::printDefaultValue(std::ostream& o) const
{
	if (defValue->isEnum()) {
		o << "None";
		return;
	}
	if (defValue->isAbsPerc()) {
		o << "None";
		return;
	}
	if (defValue->isDynamicFloat()) {
		o << "None";
		return;
	}
	if (defValue->isBool()) {
		o << (defValue->getBool() ? "true" : "false");
		return;
	}
	if (defValue->isInt()) {
		o << defValue->getInt();
		return;
	}
	if (defValue->isFloat()){
		o << defValue->getFloat();
		return;
	}
	if (defValue->isString()){
		o << defValue->getString().toStdString();
		return;
	}
	if (defValue->isMatrix44f()){
		o << "None";
		return;
	}
	if (defValue->isPoint3f()) {
		o << "None";
		return;
	}
	if (defValue->isShotf()) {
		o << "None";
		return;
	}
	if (defValue->isColor()) {
		o << "None";
		return;
	}
	if (defValue->isMesh()){
		o << "None";
		return;
	}
	if (defValue->isFileName()){
		o << "None";
		return;
	}
	if (defValue->isFloatList()){
		o << "None";
		return;
	}

	//to support: floatlist, dynamicfloat, openfile, savefile, mesh
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

void pymeshlab::FilterFunctionParameter::swap(pymeshlab::FilterFunctionParameter& oth)
{
	std::swap(pName, oth.pName);
	std::swap(mName, oth.mName);
	std::swap(defValue, oth.defValue);
}

Value* pymeshlab::FilterFunctionParameter::createNewValue(const Value* ov)
{
	if (ov->isEnum())
		return new EnumValue(ov->getEnum());
	if (ov->isAbsPerc())
		return new AbsPercValue(ov->getAbsPerc());
	if (ov->isDynamicFloat())
		return new DynamicFloatValue(ov->getDynamicFloat());
	if (ov->isBool())
		return new BoolValue(ov->getBool());
	if (ov->isInt())
		return new IntValue(ov->getInt());
	if (ov->isFloat())
		return new FloatValue(ov->getFloat());
	if (ov->isString())
		return new StringValue(ov->getString());
	if (ov->isMatrix44f())
		return new Matrix44fValue(ov->getMatrix44f());
	if (ov->isPoint3f())
		return new Point3fValue(ov->getPoint3f());
	if (ov->isShotf())
		return new ShotfValue(ov->getShotf());
	if (ov->isColor())
		return new ColorValue(ov->getColor());
	if (ov->isMesh())
		return new MeshValue(ov->getMesh());
	if (ov->isFileName())
		return new FileValue(ov->getFileName());
	if (ov->isFloatList())
		return new FloatListValue(ov->getFloatList());

	assert(0);
	return nullptr;
}


