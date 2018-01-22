#ifndef NAME_ERROR_EXCEPTION_H
#define NAME_ERROR_EXCEPTION_H

#include "InterperterException.h"

class NameErrorException : public InterperterException
{
public:
	virtual const char* what(char* str) const throw();

};

#endif // NAME_ERROR_EXCEPTION_H