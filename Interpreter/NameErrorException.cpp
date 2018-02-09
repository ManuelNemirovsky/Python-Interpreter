#include "NameErrorException.h"
#include <string>
NameErrorException::NameErrorException(std::string str) : _name(str)
{
	_msg = "NameError: name '" + _name + "' is not defined";
}
const char* NameErrorException::what() const throw()
{
	return _msg.c_str();
}