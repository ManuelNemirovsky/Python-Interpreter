#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "type.h"
#include <string>

using namespace std;
class Boolean : public Type
{
public:
	Boolean(bool something);
	~Boolean();
	string toString();
	bool isPrintable();
private:
	bool _something;
};

#endif // BOOLEAN_H