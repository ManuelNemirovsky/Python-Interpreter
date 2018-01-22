#ifndef VOID_H
#define VOID_H

#include "type.h"
#include <string>

using namespace std;
class Void : public Type
{
public:
	Void();
	~Void();
	const string toString();
	const bool isPrintable();
private:

};

#endif // VOID_H