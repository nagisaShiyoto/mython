#pragma once
#include <iostream>

class Type
{
protected:
	bool _isTemp;
	Type(const bool isTemp);
	virtual bool isPrintable() = 0;
	virtual std::string toString() = 0;
public:
	bool getIsTemp()const;

	void setIsTemp(const bool isTemp);
};
