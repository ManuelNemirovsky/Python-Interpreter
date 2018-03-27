#include "TypeException.h"


TypeException::TypeException(std::string type, std::string funcName) : _type(type), _func(funcName)
{
	_msg = "TypeError: object of type '" + _type + "' has no " + _func + "().";
}
const char* TypeException::what() const throw()
{
	return _msg.c_str();
}