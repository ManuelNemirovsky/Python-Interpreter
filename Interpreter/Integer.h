#ifndef INTEGER_H
#define INTEGER_H
#include "type.h"
#include <string>

using namespace std;
class Integer : public Type
{
public:
	Integer(int num);
	~Integer();
	const string toString();
	const bool isPrintable();
private:
	int _num;
};

#endif // INTEGER_H