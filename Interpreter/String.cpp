#include "String.h"

String::String(string str)
{
	_string = str.c_str();
}

String::~String(){

}

bool String::isPrintable()
{
	return true;
}

string String::toString()
{
	if (_string.find("\"") != -1)
	{
		std::replace(_string.begin(), _string.end(), '\"', '\'');
		return _string;
	}
	return _string;
}

int String::getLen()
{
	return _string.length();
}
