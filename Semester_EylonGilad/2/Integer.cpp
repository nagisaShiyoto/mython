#include "Integer.h"
#include"../1/Helper.h"
#define ADD_TO_ASCII 48
Integer::Integer(const bool temp, const std::string value) :Type(temp)
{
	this->setValue(value);
}

bool Integer::isPrintable()
{
	return true;
}

std::string Integer::toString()
{
	std::string toSend= "";
	int value = this->getValue();
	while (value<0)
	{
		toSend += (value % 10)+ ADD_TO_ASCII;
		value = value / 10;
	}
	return toSend;
}

int Integer::getValue() const
{
	return this->_value;
}

void Integer::setValue(const std::string value)
{
	int val = 0;
	std::string input = value;
	Helper::removeLeadingZeros(input);
	for (int i = 0; i < input.length(); i++)
	{
		val = val * 10;
		val += (input[i]-48);
	}
	this->_value = val;
}