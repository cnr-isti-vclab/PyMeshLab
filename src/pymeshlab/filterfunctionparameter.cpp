#include "filterfunctionparameter.h"

#include "filterparameter.h"

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(
		const QString& pythonName,
		const QString& meshlabName,
		const Value* defaultValue,
		const ParameterDecoration* pd) :
	pName(pythonName),
	mName(meshlabName),
	defValue(createNewValue(defaultValue)),
	pd(createNewParameterDecoration(pd, defValue))
{
}

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(
		const pymeshlab::FilterFunctionParameter& oth):
	pName(oth.pName),
	mName(oth.mName),
	defValue(createNewValue(oth.defValue)),
	pd(createNewParameterDecoration(oth.pd, defValue))
{
}

pymeshlab::FilterFunctionParameter::FilterFunctionParameter(pymeshlab::FilterFunctionParameter&& oth):
	pName(oth.pName),
	mName(oth.mName)
{
	defValue = oth.defValue;
	pd = oth.pd;
	oth.defValue = nullptr;
	oth.pd = nullptr;
}

pymeshlab::FilterFunctionParameter::~FilterFunctionParameter()
{
	delete defValue;
	delete pd;
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
	if (!defValue)
		return "no_value";
	if (defValue->isEnum())
		return "int [Enum]";
	if (defValue->isAbsPerc())
		return "float [AbsPerc]";
	if (defValue->isDynamicFloat())
		return "float [Dynamic]";
	if (defValue->isBool())
		return "bool";
	if (defValue->isInt())
		return "int";
	if (defValue->isFloat())
		return "float";
	if (defValue->isString())
		return "str";
	if (defValue->isMatrix44f())
		return "Matrix44f [still unsupported]";
	if (defValue->isPoint3f())
		return "Point3f [still unsupported]";
	if (defValue->isShotf())
		return "Shotf [still unsupported]";
	if (defValue->isColor())
		return "Color [still unsupported]";
	if (defValue->isMesh())
		return "Mesh [still unsupported]";
	if (defValue->isFileName())
		return "FileName [still unsupported]";
	if (defValue->isFloatList())
		return "FloatList [still unsupported]";
	return "still_unsupported";
}

QString pymeshlab::FilterFunctionParameter::description() const
{
	if (pd){
		return pd->fieldDesc;
	}
	return QString();
}

QString pymeshlab::FilterFunctionParameter::longDescription() const
{
	if (pd){
		return pd->tooltip;
	}
	return QString();
}

const Value* pymeshlab::FilterFunctionParameter::defaultValue() const
{
	return defValue;
}

void pymeshlab::FilterFunctionParameter::printDefaultValue(std::ostream& o) const
{
	if (!defValue)
		o << "no_value";
	if (defValue->isEnum()) {
		o << defValue->getEnum();
		return;
	}
	if (defValue->isAbsPerc()) {
		o << defValue->getAbsPerc();
		return;
	}
	if (defValue->isDynamicFloat()) {
		o << defValue->getDynamicFloat();
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

bool pymeshlab::FilterFunctionParameter::operator==(const pymeshlab::FilterFunctionParameter& oth) const
{
	return pName == oth.pName;
}

void pymeshlab::FilterFunctionParameter::swap(pymeshlab::FilterFunctionParameter& oth)
{
	std::swap(pName, oth.pName);
	std::swap(mName, oth.mName);
	std::swap(defValue, oth.defValue);
	std::swap(pd, oth.pd);
}

Value* pymeshlab::FilterFunctionParameter::createNewValue(const Value* ov)
{
	if (!ov)
		return nullptr;
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

ParameterDecoration* pymeshlab::FilterFunctionParameter::createNewParameterDecoration(
		const ParameterDecoration* pd,
		const Value* v)
{
	if (!v || !pd) {
		return nullptr;
	}
	if (v->isEnum()){
		EnumValue* ev = (EnumValue*)v;
		const EnumDecoration *ed = (const EnumDecoration*)pd;
		return new EnumDecoration(
					new EnumValue(*ev),
					ed->enumvalues,
					ed->fieldDesc,
					ed->tooltip);
	}
	if (v->isAbsPerc()){
		AbsPercValue* apv = (AbsPercValue*)v;
		const AbsPercDecoration *apd = (const AbsPercDecoration*)pd;
		return new AbsPercDecoration(
					new AbsPercValue(*apv),
					apd->min,
					apd->max,
					apd->fieldDesc,
					apd->tooltip);
	}
	if (v->isDynamicFloat()){
		DynamicFloatValue* dfv = (DynamicFloatValue*)v;
		const DynamicFloatDecoration *dfd = (const DynamicFloatDecoration*)pd;
		return new DynamicFloatDecoration(
					new DynamicFloatValue(*dfv),
					dfd->min,
					dfd->max,
					dfd->fieldDesc,
					dfd->tooltip);
	}
	if (v->isBool()){
		BoolValue * bv = (BoolValue*)v;
		const BoolDecoration * bd = (const BoolDecoration*)pd;
		return new BoolDecoration(
					new BoolValue(*bv),
					bd->fieldDesc,
					bd->tooltip);
	}
	if (v->isInt()){
		IntValue * iv = (IntValue*)v;
		const IntDecoration * id = (const IntDecoration*)pd;
		return new IntDecoration(
					new IntValue(*iv),
					id->fieldDesc,
					id->tooltip);
	}
	if (v->isFloat()){
		FloatValue * fv = (FloatValue*)v;
		const FloatDecoration * fd = (const FloatDecoration*)pd;
		return new FloatDecoration(
					new FloatValue(*fv),
					fd->fieldDesc,
					fd->tooltip);
	}
	if (v->isString()){
		StringValue * sv = (StringValue*)v;
		const StringDecoration * sd = (const StringDecoration*)pd;
		return new StringDecoration(
					new StringValue(*sv),
					sd->fieldDesc,
					sd->tooltip);
	}
	if (v->isMatrix44f()){
		Matrix44fValue * mv = (Matrix44fValue*)v;
		const Matrix44fDecoration * md = (const Matrix44fDecoration*)pd;
		return new Matrix44fDecoration(
					new Matrix44fValue(*mv),
					md->fieldDesc,
					md->tooltip);
	}
	if (v->isPoint3f()){
		Point3fValue * pv = (Point3fValue*)v;
		const Point3fDecoration * pfd = (const Point3fDecoration*)pd;
		return new Point3fDecoration(
					new Point3fValue(*pv),
					pfd->fieldDesc,
					pfd->tooltip);
	}
	if (v->isShotf()) {
		ShotfValue * sv = (ShotfValue*)v;
		const ShotfDecoration * sd = (const ShotfDecoration*)pd;
		return new ShotfDecoration(
					new ShotfValue(*sv),
					sd->fieldDesc,
					sd->tooltip);
	}
	if (v->isColor()) {
		ColorValue * cv = (ColorValue*)v;
		const ColorDecoration * cd = (const ColorDecoration*)pd;
		return new ColorDecoration(
					new ColorValue(*cv),
					cd->fieldDesc,
					cd->tooltip);
	}
	if (v->isMesh()) {
		MeshValue * mv = (MeshValue*)v;
		const MeshDecoration * md = (const MeshDecoration*)pd;
		return new MeshDecoration(
					new MeshValue(*mv),
					nullptr,
					md->fieldDesc,
					md->tooltip);
	}
	if (v->isFileName()) {
		FileValue * fv = (FileValue*)v;
		const OpenFileDecoration* ofd = dynamic_cast<const OpenFileDecoration*>(pd);
		const SaveFileDecoration* sfd = dynamic_cast<const SaveFileDecoration*>(pd);
		if (ofd){
			return new OpenFileDecoration(
						new FileValue(*fv),
						ofd->exts,
						ofd->fieldDesc,
						ofd->tooltip);
		}
		else if (sfd){
			return new SaveFileDecoration(
						new FileValue(*fv),
						sfd->ext,
						sfd->fieldDesc,
						sfd->tooltip);
		}
		else {
			assert(0);
			return nullptr;
		}
	}
	if (v->isFloatList()) {
		FloatListValue * fv = (FloatListValue*)v;
		const FloatListDecoration * fd = (const FloatListDecoration*)pd;
		return new FloatListDecoration(
					new FloatListValue(*fv),
					fd->fieldDesc,
					fd->tooltip);
	}
	assert(0);
	return nullptr;
}


