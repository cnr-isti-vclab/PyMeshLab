#ifndef PYMESHLAB_ENUM_H
#define PYMESHLAB_ENUM_H

#include <string>

namespace pymeshlab {

class Enum
{
public:
	Enum(const std::string& value);
	std::string value() const;
private:
	std::string val;
};

class InvalidEnumException : public std::exception
{
public:
	InvalidEnumException(const std::string& text) :
		std::exception(), text(text){}

	inline const char* what() const throw() {return text.data();}

protected:
	std::string text;
};

}

#endif // PYMESHLAB_ENUM_H
