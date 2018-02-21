#include "parser.h"
#include <iostream>

std::unordered_map<string, Type*> Parser::_variables;

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
		
		t = getVariableValue(str);

		if (!t)
		{
			if (makeAssignment(str))
			{
				return new Void();
			}
			Helper::rtrim(str);
			t = getType(str);
			if (!t)
			{
				if (!isLegalVarName(str))
					throw NameErrorException(str);
				else
					throw SyntaxException();
			}
			else
			{
				return t;
			}
		}
		else
		{
			t->setTemp(false);
			return t;
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
	string name = "", parameter = "";
	Type* t = NULL;
	int place = str.find('=');
	if (place > 0 && place < str.length())
	{
		name = str.substr(0, str.find('='));
		parameter = str.substr(name.size()+1, str.size());

		Helper::trim(name);
		Helper::trim(parameter);

		if (copyType(name, parameter))
		{
			std::unordered_map<std::string, Type*>::iterator it = _variables.find(parameter);
			Type* t = it->second;
			_variables.insert(pair<string, Type*>(name, t));
			return true;
		}

		t = getType(parameter);

		if (isLegalVarName(name) && t)
		{
			std::unordered_map<std::string, Type*>::iterator it = _variables.find(name);
			if (it == _variables.end())
			{
				_variables.insert(pair<string, Type*>(name,t));
			}
			else
			{
				it->second = t;
			}
			return true;
		}
		else
		{
			throw SyntaxException();
		}
	}
	else
	{
		return false;
	}
}

bool Parser::copyType(const std::string& src, const std::string& dst)
{
	std::unordered_map<std::string, Type*>::iterator it = _variables.find(dst);
	return it == _variables.end() ? false : true;
}

Type* Parser::getVariableValue(const std::string &str)
{
	std::unordered_map<std::string, Type*>::iterator it = _variables.find(str);
	if (it != _variables.end())
	{
		return it->second;
	}
	return NULL;
}

void Parser::free()
{
	delete &_variables;
}
