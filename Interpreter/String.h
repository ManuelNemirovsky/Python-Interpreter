#ifndef STRING_H
#define STRING_H
#include "type.h"
#include "Sequence.h"
#include <string>

using namespace std;
class String : public Type
{
public:
	String(string str);
	~String();
	const string String::toString();
	const bool String::isPrintable();

private:
	string _string;
};

#endif // STRING_H