#include "type.h"
#include "InterperterException.h"
#include "IndentationException.h"
#include "NameErrorException.h"
#include "SyntaxException.h"

#include "parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define MY_NAME "Manuel Nemirovsky"

using namespace std;

int main(int argc,char **argv)
{
	system("color A");
	std::cout << WELCOME << MY_NAME << std::endl;
	Type* t;
	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		try
		{
			// prasing command
			t = Parser::parseString(input_string);
			//if someone enters empty message
			if (t)
			{
				if (t->isPrintable())
					cout << t->toString() << endl;
				if (t->getTemp())
				{
					free(t);
				}
			}
		}
		catch (IndentationException e)
		{
			cout << e.what() << endl;
		}
		catch (SyntaxException e)
		{
			cout << e.what() << endl;
		}
		catch (NameErrorException e)
		{
			cout << e.what() << endl;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	Parser::free();
	return 0;
}


