#pragma once
#include "../1/Type.h"
#include <Vector>
template<class T>
class Sequence :public Type
{
public:
	std::vector<T> _values;
	Sequence<T>(const bool temp):Type(temp)
	{
	}
	virtual bool isPrintable()=0;
	virtual std::string toString() = 0;
	virtual std::vector<T> getValus()
	{
		return _values;
	};
	virtual void addValue(const T value)
	{
		_values.push_back(value);
	};

	
};