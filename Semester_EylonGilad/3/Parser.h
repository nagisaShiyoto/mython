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
    static std::unordered_map<std::string, Type*> _users;
    static Type* parseString(std::string str);
    static Type* getType(std::string str);
    static void cleanTypes();
    static void cleanVar();
private:
    static bool copyVar(std::string toCopy, std::string copyFrom);
    static bool isLegalVarName(std::string str);
    static bool makeAssignment(std::string str);
    static Type* getVariableValue(std::string str);
    

};
