#include <iostream>
#include "funciones_p1.cpp"
using namespace std;

/*
    * Nombre: CDTI (contador de terreno inundadoo)
    * Descripcion: cuenta el terreno inundado en una grilla, en una coordenada.
    * Inputs:
        - m: matriz donde se hara la busqueda (entra por referencia)
        - M, N: tamano vertical (filas) y horizontal de la grilla (columnas) respectivamente
        - i , j: coordenada donde se hara la busqueda
    * Outputs:
        - int: tamano del terreno inundado
*/
int CDTI(matriz &m, int M, int N, int i, int j)
{
    if (i < 0 or j < 0 or i >= M or j >= N) // Caso base 1: ¿estamos dentro de la grilla?
        return 0;                           // Retornamos 0 si estamos fuera

    if (m[i][j] != 'W') // Caso base 2: ¿estamos en terreno inundado?
        return 0;       // Retornamos 0 si no estamos

    int suma = 1; // Si estamos en terreno inundado, lo sumamos

    m[i][j] = 'L'; // Cambiamos el terreno inundado por tierra

    // Sumamos recursivamente el terreno inundado de los vecinos
    for (int x = i - 1; x < i + 2; x++)
    {
        for (int y = j - 1; y < j + 2; y++)
        {
            if (x != i or y != j) // Evitamos la misma coordenada
                suma += CDTI(m, M, N, x, y);
        }
    }

    return suma; // Retornamos la suma total
}

int main()
{
    string linea; // Creamos un buffer de texto

    getline(cin, linea);       // Leemos la primera linea (cantidad de casos)
    int n_casos = stoi(linea); // Guardamos la cantidad de casos

    getline(cin, linea); // Saltamos el salto de linea

    int filas, columnas;
    for (int i = 0; i < n_casos; i++)
    {
        matriz m;    // Instanciamos la grilla
        matriz *aux; // Instanciamos una copia de la grilla m
        cons c;      // Instanciamos la consulta
        filas = 0;
        while (getline(cin, linea) && linea.length() > 0)
        {
            if (linea[0] == 'W' or linea[0] == 'L') // Leemos la matriz
            {
                filas++;
                columnas = linea.length();
                m.push_back(linea);
            }
            else
            {
                c = splitInt(linea, ' ');                                // Separamos los int de la coordenada por un espacio
                aux = deepcopy(m);                                       // Con la matriz original, nos consume el agua
                cout << CDTI(*aux, filas, columnas, c[0], c[1]) << endl; // Printeamos
                delete aux;
            }
        }

        cout << endl;
    }

    return 0;
}