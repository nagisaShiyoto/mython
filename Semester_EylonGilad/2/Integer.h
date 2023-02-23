#pragma once
#include "../1/Type.h"

class Integer :public Type
{
public:
	Integer(const bool temp, const std::string value);
	virtual bool isPrintable()override;
	virtual std::string toString()override;

	int getValue()const;
	void setValue(const std::string value);
private:
	int _value;
};