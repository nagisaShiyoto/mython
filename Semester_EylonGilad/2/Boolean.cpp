#include "Boolean.h"

Boolean::Boolean(const bool temp, const std::string value):Type(temp)
{
    this->setValue(value);
}

bool Boolean::isPrintable()
{
    return true;
}

std::string Boolean::toString()
{
    if (this->_value)
    {
        return "True";
    }
    return "False";
}

void Boolean::setValue(const std::string value)
{
    if (value == "False")
    {
        this->_value = false;
    }
    else
    {
        this->_value = true;
    }
}

bool Boolean::getVlue() const
{
    return this->_value;
}
