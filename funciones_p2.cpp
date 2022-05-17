#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*
    Nombre: split
    Descripcion: separa un string por el caracter especificado
    Inputs:
        - str: string a separar
        - spl: caracter con el que se separara el string
    Outputs:
        - vector<string>: lista con 2 substrings izquierdo y derecho
*/
vector<string> split(string str, char spl)
{
    string str1 = "";
    string str2 = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == spl)
        {
            i++;
            for (int j = 0; i + j < str.length(); j++)
            {
                str2.push_back(str[i + j]);
            }
            break;
        }
        str1.push_back(str[i]);
    }

    return {str1, str2};
}

/*
    Nombre: primeraCoincidencia
    Descripcion: encuentra el primer caracter en el que 2 strings coinciden
    Inputs:
        - str1, str2: string a analizar
    Outputs:
        - char: primer caracter donde coinciden los strings
*/
char primeraCoincidencia(string str1, string str2)
{
    char c = '\0';
    set<char> m;
    for (int i = 0; i < str1.length(); i++)
        m.insert(str1[i]);

    for (int j = 0; j < str2.length(); j++)
    {
        if (m.count(str2[j]))
        {
            c = str2[j];
            return c;
        }
    }

    return c;
}