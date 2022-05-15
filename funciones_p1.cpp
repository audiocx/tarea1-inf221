#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> matriz;

typedef vector<int> cons;

cons splitInt(string str, char spl)
{
    string str1, str2;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == spl)
        {
            i++;
            for (int j = 0; i + j < str.length(); j++)
            {
                str2[j] = str[i + j];
            }
            break;
        }
        str1[i] = str[i];
    }
    return {stoi(str1) - 1, stoi(str2) - 1};
}

matriz *deepcopy(matriz m)
{
    matriz *copy = new matriz;
    for (string s : m)
        copy->push_back(s);
    return copy;
}