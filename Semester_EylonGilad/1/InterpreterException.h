#pragma once
#include <exception>


class InterpreterException : public std::exception
{
	virtual const char* what() const noexcept=0;
};
