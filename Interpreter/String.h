#ifndef STRING_H
#define STRING_H
#include "type.h"
#include <algorithm>
#include "Sequence.h"
#include <string>

using namespace std;
class String : public Type
{
public:
	String(string str);
	~String();
	string String::toString();
	bool String::isPrintable();
	int getLen();
private:
	string _string;
};

#endif // STRING_H