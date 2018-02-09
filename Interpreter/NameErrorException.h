#ifndef NAME_ERROR_EXCEPTION_H
#define NAME_ERROR_EXCEPTION_H

#include "InterperterException.h"
#include <iostream>
class NameErrorException : public InterperterException
{
public:
	NameErrorException(std::string str);
	virtual const char* what() const throw();
private:
	std::string _name;
	std::string _msg;
};

#endif // NAME_ERROR_EXCEPTION_H