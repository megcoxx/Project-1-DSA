#include <iostream>
#include <string>
#include <cstdlib>
#include "variable.h"

using namespace std;

Variable::Variable()
{
    count = 0;
}

Variable::Variable(int varValue)
{
    intValue = varValue;
    isInt = true;
    count = 1;
}

Variable::Variable(string varValue)
{
    strValue = varValue;
    isInt = false;
    count = 1;
}

Variable::Variable(char varValue)
{
    strValue = string(1,varValue);
    isInt = false;
    count = 1;
}

// Getter for the value
int Variable::getIntValue() const
{
    if (isInt == true)
        return intValue;
}

string Variable::getStringValue() const
{
    if (isInt == false)
        return strValue;
}

bool Variable::getIsInt() const
{
    return isInt;
}

int Variable::getCount() const
{
    return count;
}

void Variable::setCount()
{
    count += 1;
    return;
}
