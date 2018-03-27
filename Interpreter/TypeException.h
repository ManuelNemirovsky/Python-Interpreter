#ifndef TYPE_ERROR_EXCEPTION_H
#define TYPE_ERROR_EXCEPTION_H

#include "InterperterException.h"
#include <iostream>

#define MAX_VARIABLE_LEN 100
class TypeException : public InterperterException
{
public:
	TypeException(std::string type , std::string func);
	virtual const char* what() const throw();
private:
	std::string _type;
	std::string _func;
	std::string _msg;
};

#endif // TYPE_ERROR_EXCEPTION_H