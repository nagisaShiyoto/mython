#pragma once
#pragma once
#include <iostream>
#include "../1/InterpreterException.h"
class builtInFanc :public InterpreterException
{
public:
	builtInFanc(std::string fanc);
	const char* what() const noexcept;
	std::string _fanc;
};
