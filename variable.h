#include <iostream>
#include <string>
#include <cstdlib>
#include <string>

using namespace std;
class Variable
{
private:
    int intValue;
    string strValue;
    bool isInt;
    int count;

public:
    // Default Constructor
    Variable();

    // Constructor for Number
    Variable(int varValue);

    // Constructor for String
    Variable(string varValue);

    Variable(char varValue);

    // Getter for the Value
    string getStringValue() const;
    int getIntValue() const;
    bool getIsInt() const;
    int getCount() const;
    void setCount();
    bool operator<(const Variable &other);
};
