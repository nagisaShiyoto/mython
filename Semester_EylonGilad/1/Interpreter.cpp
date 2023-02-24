#include "Type.h"
#include "InterpreterException.h"
#include "IndentationException.h"
#include "../3/NameErrorException.h"
#include "../2/SyntaxException.h"
#include "../3/Parser.h"
#include <iostream>
#include "../2/Boolean.h"
#include "../2/Integer.h"
#include "../2/String.h"

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Eylon Gilad"


int main(int argc,char **argv)
{
	std::vector<Type*> vars;
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;
	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		try
		{
			// parsing command
			Type* var = Parser::parseString(input_string);
			////////////create a var with right type////////////
			if (var->isPrintable())
			{
				std::cout << var->toString() << std::endl;
			}
			if (var->getIsTemp())
			{
				delete var;
			}
			Parser::cleanTypes();
			
		}
		catch (IndentationException what)
		{
			std::cout << what.what()<<std::endl;
		}
		catch (SyntaxException what)
		{
			std::cout << what.what() << std::endl;
		}
		catch (NameErrorException what)
		{
			const char* msg = what.what();
		}


		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	Parser::cleanVar();
	return 0;
}
