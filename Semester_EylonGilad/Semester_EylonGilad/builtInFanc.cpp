#include "builtInFanc.h"

builtInFanc::builtInFanc(std::string fanc)
{
	this->_fanc = fanc;
}

const char* builtInFanc::what() const noexcept
{
	std::string msg = "<built-in function " + this->_fanc + ">";
	std::cout << msg << std::endl;
	return msg.c_str();
}
