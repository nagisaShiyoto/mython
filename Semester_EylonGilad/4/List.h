#pragma once
#include "../2/Sequence.h"
#include "../1/Type.h"
class List :public Sequence<Type*>
{
public:
	List(std::string vars, bool isTemp);
	virtual bool isPrintable();
	virtual std::string toString();
};
