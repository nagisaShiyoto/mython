#include "String.h"
String::String(const bool temp, const std::string str):Sequence<char>(temp)
{
    const char* theString = str.c_str();
    ///add the string
    for (int i = 0; i < str.length(); i++)
    {
        this->_values.push_back(theString[i]);
    }
    ///add the string
}


bool String::isPrintable()
{
    return true;
}

std::string String::toString()
{
    std::string toSend = "";
    for (auto it = this->_values.begin(); it != this->_values.end(); it++)
    {
        toSend += *it;
    }
    return toSend;
}
