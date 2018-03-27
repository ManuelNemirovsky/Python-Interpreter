#include "List.h"

List::List(vector<Type*>& value, bool isTemp) : Sequence(isTemp), _value(value)
{

}

bool List::isPrintable()
{
	return true;
}

string List::toString()
{
	string m = "[";
	for (vector<Type*>::const_iterator i = _value.begin(); i != _value.end(); i++)
	{
		m += (*i)->toString();
		if (i != _value.rbegin().base() - 1)
		{
			m += ", ";
		}
	}
	m += ']';
	return m;
}

int List::getLen()
{
	return _value.size();
}
