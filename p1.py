import sys

def CDTI(m, c):
    i, j = c

    if i < 0 or i >= len(m) or j < 0 or j >= len(m[0]):
        return 0
    if m[i][j] == 'L':
        return 0

    suma = 1

    for x in range(i - 1, i + 2):
        for y in range(j - 1, j + 2):
            if x >= 0 and x < len(m) and y >= 0 and y < len(m[0]):
                if x != i or y != j:
                    m[i][j] = 'L'
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


    for matriz, consultas in tuplas_matriz_consultas:
        for consulta in consultas:
            print(CDTI(matriz, consulta))
        print('\n')

if __name__ == "__main__":
    main()