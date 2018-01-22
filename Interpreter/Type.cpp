#include "type.h"

Type::Type()
{
}

Type::~Type(){
}

bool Type::getTemp()
{
	return _isTemp;
}

void Type::setTemp(bool ans)
{
	_isTemp = ans;
}