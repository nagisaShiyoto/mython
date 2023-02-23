#pragma once
#include "Sequence.h"
class String:public Sequence<char>
{
public:
	String(const bool temp, const std::string str);
	virtual bool isPrintable()override;
	virtual std::string toString()override;
};