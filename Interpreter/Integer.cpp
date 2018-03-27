#include "Integer.h"

Integer::Integer(int num)
{
	_num = num;
}

Integer::~Integer(){

}

bool Integer::isPrintable()
{
	return true;
}

string Integer::toString()
{
	return to_string(_num);
}