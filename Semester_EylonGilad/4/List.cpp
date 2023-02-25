#include "List.h"
#include "../1/Helper.h"
#include "../3/Parser.h"
List::List(std::string vars, bool isTemp):Sequence(isTemp)
{
    std::string value = "";
    int placeNow = 0;
    vars = vars.substr(1);
    vars = vars.substr(0, vars.length() - 1);
    while (placeNow != -1)
    {
        placeNow = vars.find(",");
        value = vars.substr(0, placeNow);
        vars = vars.substr(placeNow+1);
        Helper::trim(value);
        this->_values.push_back(Parser::getType(value));
    }
}

bool List::isPrintable()
{
    return true;
}

std::string List::toString()
{
    std::string toSend = "[";
    for (auto it = this->_values.begin(); it != this->_values.end(); it++)
    {
        toSend=toSend+(*it)->toString()+" ,";
    }
    toSend = toSend.substr(0, toSend.size() - 2);
    toSend += "]";
    return toSend;
}
