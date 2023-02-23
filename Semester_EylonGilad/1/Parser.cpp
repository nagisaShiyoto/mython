#include "Parser.h"
#include "IndentationException.h"
#include "../2/SyntaxException.h"
#include <iostream>
#include "../2/Boolean.h"
#include "../2/Integer.h"
#include "../2/String.h"
Type* Parser::parseString(std::string str)
{
	if (str[0] == ' '||str[0]=='	')
	{
		throw IndentationException();
	}
	Helper::rtrim(str);
	if (str.length() > 0)
	{
		if (Helper::isBoolean(str))
		{
			Boolean* var=new Boolean(false, str);
			return var;
		}
		if (Helper::isInteger(str))
		{
			Integer* var=new Integer(false, str);
			return var;
		}
		if (Helper::isString(str))
		{
			String* var=new String(false, str);
			return var;
		}
	}

	throw SyntaxException();
}


