#include "NameErrorException.h"



NameErrorException::NameErrorException(std::string name)
{
	this->_name=name;
}

const char* NameErrorException::what() const noexcept
{
	std::string msg = "NameError : name '" + this->_name + "' is not defined";
	std::cout << msg << std::endl;
	return msg.c_str();
}