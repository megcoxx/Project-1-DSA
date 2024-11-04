
#include "variable.h"
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
    vector<Variable> variableArray;

    vector<Variable> digitArray;

    vector<Variable> charArray;

    string input = "";
    string pieceOfInput = "";
    while (getline(cin, pieceOfInput))
    {
        input.append(pieceOfInput);
        input.push_back('\n');
    }

    int i = 0;

    int n = input.size();
    // go through the beginning until you hit a letter or number
    // go through that particular if statement until it is not true

    while (i < n)
    {
        if (isdigit(input[i]))
        {
            // make string but also make char array
            bool isFoundDigit = false;
            string integerInput = "";
            integerInput.push_back(input[i]);
            int j = i + 1;
            while (j < n && isdigit(input[j]))
            {
                integerInput.push_back(input[j]);
                j++;
            }
            i = j;
            char numStringToArray[integerInput.length() + 1];
            strcpy(numStringToArray, integerInput.c_str());

            int varValue = stoi(integerInput);

            for (int w = 0; w < (int)integerInput.length(); w++)
            {
                bool isFoundChar = false;
                for (int l = 0; l < (int)charArray.size(); l++)
                {
                    if (charArray[l].getStringValue().at(0) == numStringToArray[w])
                    {
                        charArray[l].setCount();
                        isFoundChar = true;
                        break;
                    }
                }

                if (isFoundChar == false)
                {
                    charArray.push_back(Variable(numStringToArray[w]));
                }
            }
            for (int l = 0; l < (int)digitArray.size(); l++)
            {
                if (digitArray[l].getIsInt() == true)
                {
                    if (digitArray[l].getIntValue() == varValue)
                    {
                        digitArray[l].setCount();
                        isFoundDigit = true;
                        break;
                    }
                }
            }

            if (isFoundDigit == false)
            {
                digitArray.push_back(Variable(varValue));
            }
        }
        else if (isalpha(input[i]) && !(input[i] == 'n' && input[i - 1] == '\\'))
        {
            bool isFoundString = false;
            string stringInput = "";
            stringInput.push_back(input[i]);
            int j = i + 1;
            while (j < n && isalpha(input[j]))
            {
                stringInput.push_back(input[j]);
                j++;
            }
            i = j;
            char StringToArray[stringInput.length() + 1];
            strcpy(StringToArray, stringInput.c_str());

            for (int w = 0; w < (int)stringInput.length(); w++)
            {
                bool isFoundChar = false;
                for (int l = 0; l < (int)charArray.size(); l++)
                {
                    if (charArray[l].getStringValue().at(0) == StringToArray[w])
                    {
                        charArray[l].setCount();
                        isFoundChar = true;
                        break;
                    }
                }

                if (isFoundChar == false)
                {
                    charArray.push_back(Variable(StringToArray[w]));
                }
            }

            for (int l = 0; l < (int)variableArray.size(); l++)
            {
                if (variableArray[l].getIsInt() == false)
                {
                    if (variableArray[l].getStringValue() == stringInput)
                    {
                        variableArray[l].setCount();
                        isFoundString = true;
                        break;
                    }
                }
            }

            if (isFoundString == false)
            {
                variableArray.push_back(Variable(stringInput)); 
            }
        }

        else
        {
            bool isFoundChar = false;
            bool newLine = false;
            string stringInput = "";
            if (input[i] == '\n')
            {
                newLine = true;
            }
            if (!newLine)
            {
                stringInput.push_back(input[i]);
                int j = i + 1;
                while (j < n && isspace(input[j]))
                {
                    stringInput.push_back(input[j]);
                    j++;
                }
                i = j;
                char StringToArray[stringInput.length() + 1];
                strcpy(StringToArray, stringInput.c_str());

                for (int w = 0; w < (int)stringInput.length(); w++)
                {
                    for (int l = 0; l < (int)charArray.size(); l++)
                    {
                        if (charArray[l].getStringValue().at(0) == StringToArray[w])
                        {
                            charArray[l].setCount();
                            isFoundChar = true;
                            break;
                        }
                    }

                    if (isFoundChar == false)
                    {
                        charArray.push_back(Variable(StringToArray[w]));
                    }
                }
            }
            else
            {
                char newLineChar = '\n';
                for (int l = 0; l < (int)charArray.size(); l++)
                {
                    if (charArray[l].getStringValue().at(0) == newLineChar)
                    {
                        charArray[l].setCount();
                        isFoundChar = true;
                        break;
                    }
                }

                if (isFoundChar == false)
                {
                    charArray.push_back(Variable(newLineChar));
                }
                i++;
            }
        }
    }

    sort(variableArray.begin(), variableArray.end(), [](const Variable &a, const Variable &b)
         { return a.getCount() > b.getCount(); });
    sort(charArray.begin(), charArray.end(), [](const Variable &a, const Variable &b)
         { if (a.getCount() != b.getCount()){
            return a.getCount() > b.getCount();
         }
         return a.getStringValue() < b.getStringValue(); });
    sort(digitArray.begin(), digitArray.end(), [](const Variable &a, const Variable &b)
         { return a.getCount() > b.getCount(); });

    if ((int)charArray.size() < 10)
    {
        cout << "Total " << (int)charArray.size() << " different characters, " << (int)charArray.size() << " most used characters: " << endl;
        for (int k = 0; k < (int)charArray.size(); k++)
        {
            cout << "No. " << k << ": ";
            if (charArray[k].getStringValue().at(0) == '\n')
            {
                cout << "\\n\t" << charArray[k].getCount() << endl;
            }
            else
            {
                cout << charArray[k].getStringValue() << "\t\t" << charArray[k].getCount()
                     << endl;
            }
        }
    }
    else
    {
        cout << "Total " << (int)charArray.size() << " different characters, 10 most used characters: " << endl;
        for (int k = 0; k < 10; k++)
        {
            cout << "No. " << k << ": ";
            if (charArray[k].getStringValue().at(0) == '\n')
            {
                cout << "\\n\t\t" << charArray[k].getCount() << endl;
            }
            else
            {
                cout << charArray[k].getStringValue() << "\t\t" << charArray[k].getCount()
                     << endl;
            }
        }
    }

    if ((int)variableArray.size() < 10)
    {
        cout << "\nTotal " << (int)variableArray.size() << " different words, " << (int)variableArray.size() << " most used words: " << endl;
        for (int k = 0; k < (int)variableArray.size(); k++)
        {
            cout << "No. " << k << ": ";
            cout << variableArray[k].getStringValue() << "\t\t" << variableArray[k].getCount()
                 << endl;
        }
    }
    else
    {
        cout << "\nTotal " << (int)variableArray.size() << " different words, 10 most used words: " << endl;
        for (int k = 0; k < 10; k++)
        {
            cout << "No. " << k << ": ";
            cout << variableArray[k].getStringValue() << "\t\t" << variableArray[k].getCount()
                 << endl;
        }
    }
    if ((int)digitArray.size() < 10)
    {
        cout << "\nTotal " << (int)digitArray.size() << " different numbers, " << (int)digitArray.size() << " most used numbers: " << endl;
        for (int k = 0; k < (int)digitArray.size(); k++)
        {
            cout << "No. " << k << ": ";
            cout << digitArray[k].getIntValue() << "\t\t" << digitArray[k].getCount()
                 << endl;
        }
    }
    else
    {
        cout << "\nTotal " << (int)digitArray.size() << " different numbers, 10 most used numbers: " << endl;
        for (int k = 0; k < 10; k++)
        {
            cout << "No. " << k << ": ";
            cout << digitArray[k].getIntValue() << "\t\t" << digitArray[k].getCount()
                 << endl;
        }
    }
    return 0;
}