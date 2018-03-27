#ifndef LIST_H
#define LIST_H

#include "Sequence.h"
#include <vector>

class List : public Sequence
{
public:
	List(vector<Type*>& value, bool isTemp);
	bool isPrintable();
	string toString();
	int getLen();

private:

	vector<Type*> _value;
};

#endif // LIST_H