#include <iostream>
#include "funciones_p2.cpp"

typedef vector<vector<string>> substr; // Lista de pares de strings

/*
    Nombre: DEDS (diferencias entre dos strings)
    Descripcion: analiza 2 strings, entregando una lista con todos los pares de substrings diferentes
    Inputs:
        - str1, str2: strings a analizar
        - memo: hashmap para el backtracking de strings analizados
    Outputs:
        - substr: lista de pares de substring diferentes
*/
substr DEDS(string str1, string str2, map<vector<string>, substr> &memo)
{
    // cout << "[" << str1 << "][" << str2 << "]" << endl; // Descomentame para revisar las entradas
    // cout << "----------------------" << endl;

    if (memo.count({str1, str2}) > 0) // Si esta en la memo, lo retornamos
        return memo[{str1, str2}];

    substr dif = {}; // Inicializamos la lista de substrings diferentes

    if (str1 == "" && str2 == "") // Caso base 1: si son strings vacios, retornamos nada
        return dif;

    char p = primeraCoincidencia(str1, str2); // Extraemos la primera coincidencia

    if (p == '\0') // Caso base 2: si uno de los strings es vacio, o no tienen caracteres en comun, se agregan
    {
        dif.push_back({str1, str2});
        memo[{str1, str2}] = dif; // Memoizamos los inputs como clave, y el retorno como valor
        return dif;
    }

    vector<string> subs1 = split(str1, p); // Separamos el primer string por el caracter coincidente
    vector<string> subs2 = split(str2, p); // Separamos el segundo string por el caracter coincidente

    substr izq = DEDS(subs1[0], subs2[0], memo); // Construimos la lista de strings izquierda
    substr der = DEDS(subs1[1], subs2[1], memo); // Construimos la lista de strings derecha

    for (vector<string> si : izq) // Concatenamos todo
        dif.push_back(si);
    for (vector<string> sd : der)
        dif.push_back(sd);

    memo[{str1, str2}] = dif; // Memoizamos los inputs como clave, y el retorno como valor

    return dif; // Entregamos la lista de pares de substrings diferentes
}

int main()
{
    string linea, a, b;

    getline(cin, linea);

    int k_casos = stoi(linea); // Leemos la cantidad de casos

    map<vector<string>, substr> memo;
    for (int i = 0; i < k_casos; i++) // Iteramos por cada caso
    {
        if (!getline(cin, linea)) // Extraemos string 1
            break;
        a = split(linea, ' ')[1];

        if (!getline(cin, linea)) // Extraemos string 2
            break;
        b = split(linea, ' ')[1];

        memo.clear(); // Reseteamos la memo

        substr res = DEDS(a, b, memo); // Extraemos los pares de substrings diferentes

        cout << res.size() << endl;
        for (vector<string> strs : res) // Printeamos los pares de palabras
            cout << "[" << strs[0] << "][" << strs[1] << "]" << endl;
    }

    return 0;
}