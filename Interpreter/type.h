#ifndef TYPE_H
#define TYPE_H

#include <string>

using namespace std;
class Type
{
public:
	Type(bool value);
	Type();
	~Type();
	bool getTemp();
	void setTemp(bool ans);
	virtual const string toString() = 0;
	virtual const bool isPrintable() = 0;

private:
	bool _isTemp;
};

#endif //TYPE_H
