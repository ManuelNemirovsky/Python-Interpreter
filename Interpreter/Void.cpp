#include "Void.h"

Void::Void()
{

}

Void::~Void(){

}

const bool Void::isPrintable()
{
	return false;
}

const string Void::toString()
{
	return "The value is Void and he has nothing";
}