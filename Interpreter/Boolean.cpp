#include "Boolean.h"

Boolean::Boolean(bool something)
{
	_something = something;
}

Boolean::~Boolean(){

}

const bool Boolean::isPrintable()
{
	return true;
}

const string Boolean::toString()
{
	if (_something)
	{
		return "true";
	}
	return "false";
}