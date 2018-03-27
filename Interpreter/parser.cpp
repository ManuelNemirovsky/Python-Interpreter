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
				if (!Helper::isLegalVarName(str))
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

	else if (Helper::isList(str))
	{
		int firstPart = 0, end = 0;
		string node = "";
		vector<Type*> parameters;
		str = str.substr(1, str.length() - 2); // delete '[' and ']'
		Helper::trim(str);
		do
		{
			firstPart = str.find(',' , end);
			if (firstPart == -1)
			{
				firstPart = str.length();
			}

			node = str.substr(end, firstPart - end);
			Helper::trim(node);
			parameters.push_back(getType(node));
			end = firstPart + 1;
		} while (firstPart != str.length());
		return new List(parameters , true);
	}

	else if (Helper::isString(str))
	{
		String *s = new String(str);
		return s;
	}
	
	else if (Helper::isFunc(str))
	{
		string func = findFunctionType(str);
		string value = str.substr(func.length() + 1, str.length() - (func.length() + 2)); 
		if (!func.compare("type"))
		{
			string returnValue = "<type '";
			returnValue += findValueType(value);
			returnValue += "'>";
			String *s = new String(returnValue);
			s->setTemp(true);
			return s;
		}
		else if (!func.compare("len"))
		{
			Integer *s = new Integer(handleLenFunc(value));
			s->setTemp(true);
			return s;
		}
		else if(!func.compare("del"))
		{
			string varName = str.substr(str.find(' ') + 1);
			if (Helper::isLegalVarName(varName))
			{
				if (getVariableValue(varName))
				{
					_variables.erase(varName);
					Void *s = new Void();
					s->setTemp(true);
					return s;
				}
				else
				{
					throw NameErrorException(varName);
				}
			}
			else
			{
				throw SyntaxException();
			}
		}
	}

	else
	{
		return NULL;
	}
}

int Parser::handleLenFunc(std::string& value)
{
	string type = findValueType(value);
	if (!type.compare("list") || !type.compare("str"))
	{
		Type *v = getType(value);
		if (!v)
		{
			return handleLenFunc(getVariableValue(value)->toString());
			if(!v)
				throw NameErrorException(value);
		}
		return v->getLen();
	}
	else
	{
		throw TypeException(type , "len");
	}
}

string Parser::findValueType(std::string& str)
{
	string ans;
	if (Helper::isBoolean(str))
	{
		ans = "bool";
	}
	else if (Helper::isInteger(str))
	{
		ans = "int";
	}
	else if (Helper::isString(str))
	{
		ans = "str";
	}
	else if (Helper::isList(str))
	{
		ans = "list";
	}
	else if (Helper::isLegalVarName(str))
	{
		Type* t = getVariableValue(str);
		if (t)
		{
			ans = findValueType(t->toString());
		}
		else
		{
			throw NameErrorException(str);
		}
	}
	else
	{
		throw SyntaxException();
	}
	return ans;
}

string Parser::findFunctionType(const std::string& str)
{
	string m = "";
	if (Helper::isFunc(str))
	{
		if (!str.substr(0, 3).compare("del") && str.length() > 4)
		{
			m = "del";
		}
		else
		{
			m = str.substr(0, str.find('('));
		}
	}
	else
	{
		throw SyntaxException();
	}
	return m;
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

		if (Helper::isLegalVarName(name) && t)
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
