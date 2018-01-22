#include "Integer.h"

Integer::Integer(int num)
{
	_num = num;
}

Integer::~Integer(){

}

const bool Integer::isPrintable()
{
	return true;
}

const string Integer::toString()
{
	return to_string(_num);
}