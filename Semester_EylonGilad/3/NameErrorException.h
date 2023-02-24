
#pragma once
#include <iostream>
#include "../1/InterpreterException.h"
class NameErrorException :public InterpreterException
{
public:
	NameErrorException(std::string name);
	const char* what() const noexcept;
	std::string _name;
};