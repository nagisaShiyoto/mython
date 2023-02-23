#pragma once
#include "../1/InterpreterException.h"
#include "../1/Type.h"
#include "../1/Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>


class Parser
{
public:
    static Type* parseString(std::string str);
    static Type* getType(std::string &str);

private:

};