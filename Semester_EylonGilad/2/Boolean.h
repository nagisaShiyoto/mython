#pragma once
#include "../1/Type.h"

class Boolean :public Type
{
public:
	Boolean(const bool temp, const std::string value);
	virtual bool isPrintable()override;
	virtual std::string toString()override;

	void setValue(const std::string value);
	bool getVlue()const;
private:
	bool _value;
};