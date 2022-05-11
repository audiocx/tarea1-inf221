import sys
from copy import deepcopy
from timeit import default_timer as timer
from typing import Tuple, List

# nombre: CDTI (contador de terreno inundado)
# descripcion: cuenta la cantidad de terreno inundado en la coordenada c
# inputs:
#   * m: matriz en forma de lista (de filas) de listas (de columnas), esta entra por referencia
#   por lo que nos aprovechamos de los cambios que realiza la funcion para marcar las coordenadas visitadas
#   * c: tupla con la coordenada (i, j) a visitar, estos parten desde 0
# output:
#   * int: tamaño del terreno inundado
def CDTI(m: List[List[int]], c: Tuple[int]) -> int:
    # Desempaquetamos las coordenadas
    i, j = c

    # Caso base 1: Nos aseguramos de que las coordenadas esten dentro de los bordes de la matriz
    if i < 0 or i >= len(m) or j < 0 or j >= len(m[0]):
        return 0

    # Caso base 2: Si estamos en tierra, el tamano del terreno inundado es 0
    if m[i][j] != 'W':
        return 0

    # Si estamos en agua, el tamaño de donde estamos es 1
    suma = 1

    # Iteramos por cada vecino de la posicion donde estamos
    for x in range(i - 1, i + 2):
        for y in range(j - 1, j + 2):
            # Nos aseguramos de no sumar nuestra propia posicion
            if x != i or y != j:
                # Nos aseguramos de no salirnos del borde de la matriz
                if x >= 0 and x < len(m) and y >= 0 and y < len(m[0]):
                    # Marcamos nuestra posicion como visitada, mediante el cambio de W a L
                    m[i][j] = 'L'
                    # Sumamos el terreno inundado del vecino
                    suma += CDTI(m, (x, y))
    return suma

def main():
    # Extraemos la información de la entrada estandar, que en este caso es en forma de un archivo .bat
    data = sys.stdin.readlines()

    n_casos = int(data[0].strip('\n'))

    # Diccionario de tuplas, en donde en cada tupla se encuentra como (matriz nxm, [lista de tuplas de consultas ])
    tuplas_matriz_consultas = []

    # Recorremos desde la linea 3 el documento de prueba, estableciendo la matriz y las consultas para cada caso
    # hasta que nos encontremos con un salto de linea
    linea = 2
    for i in range(n_casos):
        matriz = []
        consultas = []
        while linea < len(data) and data[linea] != '\n':
            if data[linea][0] == 'W' or data[linea][0] == 'L':
                matriz.append(list(data[linea].strip('\n')))
            else:
                consultas.append(tuple(map(lambda x: int(x) - 1, data[linea].strip('\n').split(' '))))
            linea += 1
        linea += 1
        tuplas_matriz_consultas.append((matriz, consultas))

    # Iteramos por cada matriz y lista de consultas 
    for matriz, consultas in tuplas_matriz_consultas:
        # Iteramos por cada consulta e imprimimos el resultado por pantalla
        for consulta in consultas:
            matriz_auxiliar = deepcopy(matriz)
            ini = timer() # Cronometro al inicio de la ejecucion
            res = CDTI(matriz_auxiliar, consulta)
            fin = timer() # Cronometro al final de la ejecucion
            print(res, 'Tiempo transcurrido: ' + str(fin - ini) + 's')
        print('\n')

if __name__ == "__main__":
    main()