#include "Boolean.h"

Boolean::Boolean(bool something)
{
	_something = something;
}

Boolean::~Boolean(){

}

bool Boolean::isPrintable()
{
	return true;
}

string Boolean::toString()
{
	if (_something)
	{
		return "true";
	}
	return "false";
}