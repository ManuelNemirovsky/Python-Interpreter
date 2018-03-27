#include "Helper.h"

bool Helper::isInteger(const std::string& s)
{
	int start = (s[0] == '-') ? 1 : 0;
	for (int i = start; i < s.size(); i++)
	{
		if (!isDigit(s[i]))
		{
			return false;
		}
	}

	return true;
}

bool Helper::isBoolean(const std::string& s)
{
	return (s == "True" || s == "False");
}


bool Helper::isString(const std::string& s)
{
	size_t end = s.size() - 1;

	if (s[0] == '\"' && end == s.find('\"', 1))
	{
		return true;
	}
	if (s[0] == '\'' && end == s.find('\'', 1))
	{
		return true;
	}

	return false;

}

bool Helper::isList(const std::string& s)
{
	size_t end = s.size() - 1;
	return ((s[0] == '[') && (end == s.find(']', 1)));
}

bool Helper::isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

void Helper::trim(std::string &str)
{
	rtrim(str);
	ltrim(str);

}

void Helper::rtrim(std::string &str)
{
	size_t endpos = str.find_last_not_of(" \t");
	if (std::string::npos != endpos)
	{
		str = str.substr(0, endpos + 1);
	}
}

void Helper::ltrim(std::string &str)
{
	size_t startpos = str.find_first_not_of(" \t");
	if (std::string::npos != startpos)
	{
		str = str.substr(startpos);
	}
}

void Helper::removeLeadingZeros(std::string &str)
{
	size_t startpos = str.find_first_not_of("0");
	if (std::string::npos != startpos)
	{
		str = str.substr(startpos);
	}
}

bool Helper::isFunc(const std::string& str)
{
	int fBracket = str.find('(');
	if (fBracket != -1)
	{
		if (isLegalVarName(str.substr(0, fBracket)) && str.find_last_of(')') == str.length() - 1)
		{
			return true;
		}
	}
	else
	{
		if (!str.substr(0, 3).compare("del") && str.length() > 4)
		{
			return true;
		}
	}
	return false;
}

bool Helper::isLegalVarName(const std::string& str)
{
	bool ans = true;
	if (!isDigit(str[0]))
	{
		for (auto i = 0; i < str.length(); i++)
		{
			if (!(isLetter(str[i]) || isDigit(str[i]) || isUnderscore(str[i])))
			{
				ans = false;
			}
		}
	}
	else
	{
		ans = false;
	}
	return ans;
}

bool Helper::isLowerLetter(char c)
{
	return (c >= 'a' && c <= 'z');
}

bool Helper::isUpperLetter(char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool Helper::isLetter(char c)
{
	return (isLowerLetter(c) || isUpperLetter(c));
}

bool Helper::isUnderscore(char c)
{
	return ('_' == c);
}

