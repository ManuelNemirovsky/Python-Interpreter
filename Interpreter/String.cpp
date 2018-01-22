#include "String.h"

String::String(string str)
{
	if (str.find("\'"))
	{
		str.replace(str.find("\""), 1, "\'");
		str.replace(str.find("\""), 1, "\'");
	}
	_string = str;
}

String::~String(){

}

const bool String::isPrintable()
{
	return true;
}

const string String::toString()
{
	return  _string;
}
