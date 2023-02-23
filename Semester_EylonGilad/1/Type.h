#pragma once
#include <iostream>

class Type
{
public:
	bool _isTemp;
	Type(const bool isTemp);
	virtual bool isPrintable() = 0;
	virtual std::string toString() = 0;
	bool getIsTemp()const;

	void setIsTemp(const bool isTemp);
};
