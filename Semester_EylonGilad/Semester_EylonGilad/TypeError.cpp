#include "TypeError.h"

TypeError::TypeError(std::string name)
{
	this->_type = name;
}

const char* TypeError::what() const noexcept
{
	std::string msg = "TypeError: object of type '" + this->_type + "' has no len()";
	std::cout << msg << std::endl;
	return msg.c_str();
}
