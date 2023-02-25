#include "../3/Parser.h"
#include "IndentationException.h"
#include "../3/NameErrorException.h"
#include "../2/SyntaxException.h"
#include <iostream>
#include "../2/Boolean.h"
#include "../2/Integer.h"
#include "../2/String.h"
#include "../2/Void.h"
#include "../4/List.h"
std::unordered_map<std::string, Type*> Parser::_users;

Type* Parser::parseString(std::string str)
{
	Type* val = nullptr;
	if (str[0] == ' '||str[0]=='	')
	{
		throw IndentationException();
	}
	Helper::rtrim(str);
	if (str.length() > 0)
	{
		Helper::rtrim(str);
		val = Parser::getType(str);
		if ( val!= nullptr)
		{
			return val;
		}
		val = Parser::getVariableValue(str);
		if (val!=nullptr)
		{
			return val;
		}
		if (Parser::makeAssignment(str))
		{
			Void* var = new Void(true);
			return var;
		}
	}

	throw SyntaxException();
}

Type* Parser::getType(std::string str)
{
	if (Helper::isBoolean(str))
	{
		Boolean* var = new Boolean(true, str);
		return var;
	}
	if (Helper::isInteger(str))
	{
		Integer* var = new Integer(true, str);
		return var;
	}
	if (Helper::isString(str))
	{
		String* var = new String(true, str);
		return var;
	}
	if (str[0] == '[' && str[str.length()-1] == ']')
	{
		List* var = new List(str,true);
		return var;
	}
	return nullptr;
}

void Parser::cleanTypes()
{
	for (auto it = Parser::_users.begin(); it != Parser::_users.end(); it++)
	{
		if (it->second->getIsTemp())
		{
			Parser::_users.erase(it);
		}
	}
}

void Parser::cleanVar()
{
	for (auto it = Parser::_users.begin(); it != Parser::_users.end(); it++)
	{
		delete it->second;
	}
	Parser::_users.clear();
}

bool Parser::copyVar(std::string toCopy,std::string copyFrom)
{
	Type* var = Parser::getVariableValue(copyFrom);
	if (var == nullptr)
	{
		throw NameErrorException(copyFrom);
		return false;
	}
	//check if list
	if (var->toString()[0] == '[')
	{
		Parser::_users.insert_or_assign(toCopy, var);
		return true;
	}
	Type* copyVar = Parser::getType(var->toString());
	copyVar->setIsTemp(var->getIsTemp());
	Parser::_users.insert_or_assign(toCopy, copyVar);
	return true;

}

bool Parser::isLegalVarName(std::string str)
{
	if (Helper::isDigit(str[0]))
	{
		return false;
	}
	for (auto it = str.begin(); it != str.end(); it++)
	{
		if (!(Helper::isLetter(*it) || Helper::isUnderscore(*it)))
		{
			return false;
		}
	}
	return true;
}

bool Parser::makeAssignment(std::string str)
{
	std::string name = "";
	std::string value = "";
	int place = str.find('=');
	if (place== std::string::npos)
	{
		throw NameErrorException(str);
		//return false;
	}
	name = str.substr(0, place);
	value = str.substr(place + 1);
	Helper::trim(name);
	if (!Parser::isLegalVarName(name))
	{
		throw NameErrorException(name);
	}
	Helper::trim(value);
	Type* var=Parser::getType(value);
	if (var == nullptr)
	{
		if (Parser::copyVar(name, value))
		{
			return true;
		}
		throw SyntaxException();
	}
	var->setIsTemp(false);
	Parser::_users.insert_or_assign(name, var);
	return true;
}

Type* Parser::getVariableValue(std::string str)
{
	auto var = Parser::_users.find(str);
	if (var != Parser::_users.end())
	{
		return var->second;
	}
	return nullptr;
}


