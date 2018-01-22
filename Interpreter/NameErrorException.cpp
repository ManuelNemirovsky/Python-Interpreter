#include "NameErrorException.h"
#include <string>
const char* NameErrorException::what(char* _name) const throw()
{
	char* ans = " NameError : name ";
	strcat_s(ans, strlen(_name) ,_name);
	strcat_s(ans, 15 ," is not defined");
	return ans;
}