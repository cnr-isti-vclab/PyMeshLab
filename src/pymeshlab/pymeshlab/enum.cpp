#include "enum.h"

pymeshlab::Enum::Enum(const std::string& value) :
	val(value)
{
}

std::string pymeshlab::Enum::value() const
{
	return val;
}
