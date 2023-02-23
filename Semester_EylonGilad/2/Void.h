#pragma once
#include "../1/Type.h"

class Void:public Type
{
public:
	Void(const bool temp);
	virtual bool isPrintable();
	virtual std::string toString();
};
