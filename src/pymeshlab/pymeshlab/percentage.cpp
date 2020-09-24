#include "percentage.h"
#include "exceptions.h"

pymeshlab::Percentage::Percentage(float value)
{
	setValue(value);
}

void pymeshlab::Percentage::setValue(float v)
{
	if (v > 100 || v < 0)
		throw InvalidPercentageException(
				"Invalid percentage -- value must be between 0 and 100. "
				"Value: " + std::to_string(v));
	val = v;
}

float pymeshlab::Percentage::value() const
{
	return val;
}
