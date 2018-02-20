#ifndef PARSER_H
#define PARSER_H

#include "InterperterException.h"
#include "type.h"
#include "Helper.h"
#include "Integer.h"
#include "Boolean.h"
#include "Void.h"
#include "String.h"
#include "IndentationException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>

class Parser
{
public:
	static Type* parseString(std::string str) throw();
	static Type* getType(std::string &str);
	static unordered_map<string, Type*> _variables;
	static void free();
private:

	static bool isLegalVarName(const std::string& str);
	static bool makeAssignment(const std::string& str);
	static bool copyType(const std::string& dst, const std::string& src);
	static Type* getVariableValue(const std::string &str);
	
};

#endif //PARSER_H
