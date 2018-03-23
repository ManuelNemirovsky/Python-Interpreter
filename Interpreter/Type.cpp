#include "type.h"

Type::Type()
{
}

Type::Type(bool value) : _isTemp(value)
{

}

Type::~Type(){
}

bool Type::getTemp()
{
	return this->_isTemp;
}
void Type::setTemp(bool value)
{
	this->_isTemp = value;
}

