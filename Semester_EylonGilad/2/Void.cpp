#include "Void.h"

Void::Void(const bool temp):Type(temp)
{
}

bool Void::isPrintable()
{
    return false;
}

std::string Void::toString()
{
    return "Void";
}
