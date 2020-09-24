#ifndef PYMESHLAB_EXCEPTIONS_H
#define PYMESHLAB_EXCEPTIONS_H

#include <exception>
#include <string>

namespace pymeshlab {

class InvalidPercentageException : public std::exception
{
public:
	InvalidPercentageException(const std::string& text) :
		std::exception(), text(text){}

	inline const char* what() const throw() {return text.data();}

protected:
	std::string text;
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

#endif // PYMESHLAB_EXCEPTIONS_H
