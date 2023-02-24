#include "Type.h"

Type::Type(const bool isTemp)
{
    this->_isTemp = isTemp;
}


bool Type::getIsTemp() const
{
    return this->_isTemp;
}

void Type::setIsTemp(const bool isTemp)
{
    this->_isTemp = isTemp;
}
