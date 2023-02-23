#pragma once
#include "../1/InterpreterException.h"
class SyntaxException:public InterpreterException
{
public:
	virtual const char* what() const noexcept;
};