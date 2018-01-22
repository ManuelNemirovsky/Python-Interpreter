#include "parser.h"
#include <iostream>

//check if the string that we got starts with tab or whitespace
Type* Parser::parseString(std::string str) throw()
{
	char* tab = "	";
	char* whiteSpace = " ";
	Type* t;
	if (str.length() > 0)
	{
		Helper::rtrim(str);
		if (!strncmp(str.c_str(), tab, 1) || !strncmp(str.c_str(), whiteSpace, 1))
			throw IndentationException();

		t = getType(str);

		if (t != NULL)
			return t;
		else
		{
			throw SyntaxException();
		}
	}

	return NULL;
}

Type* Parser::getType(string &str)
{
	bool b = false;
	if (Helper::isInteger(str))
	{
		Integer *i = new Integer(stoi(str));
		i->setTemp(true);
		return i;
	}

	else if (Helper::isBoolean(str))
	{
		if (str == "True")
			b = true;
		Boolean *bo = new Boolean(b);
		return bo;
	}

	else if (Helper::isString(str))
	{
		String *s = new String(str);
		return s;
	}
	
	else
	{
		return NULL;
	}
}

bool Parser::isLegalVarName(const std::string& str)
{
	bool ans = true;
	
	if (Helper::isDigit(str[0]))
		return false;

	for (int i = 0; i < str.size(); i++)
	{
		if (!Helper::isLetter(str[i]) && !Helper::isUnderscore(str[i]) && !Helper::isDigit(str[i]))
			ans = false;
	}
	return ans;
}

bool Parser::makeAssignment(const std::string& str)
{
	string name = "";
	string placement = "";
	int i = 0;
	int j = 0;
	Type* t;
	if (!str.find("="))
	{
		return false;
	}

	while (str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}

	Helper::rtrim(name);
	
	while (str[i] != 0)
	{
		placement[j] = str[i];
		i++;
		j++;
	}
	Helper::rtrim(placement);

	if (!isLegalVarName(name))
	{
		throw SyntaxException();
	}

	t = getType(placement);

	if (t != NULL)
		return t;
	else
	{
		throw SyntaxException();
	}

	//_varibles.insert(pair<string, Type*>(name, t));
	
}
