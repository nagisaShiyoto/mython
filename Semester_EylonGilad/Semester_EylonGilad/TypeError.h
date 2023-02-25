#pragma once
#include <iostream>
#include "../1/InterpreterException.h"
class TypeError :public InterpreterException
{
public:
	TypeError(std::string type);
	const char* what() const noexcept;
	std::string _type;
};
