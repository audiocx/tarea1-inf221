import sys

def main():
    # Extraemos la información de la entrada estandar, que en este caso es en forma de un archivo .bat
    data = sys.stdin.readlines()

    n_casos = int(data[0].strip('\n'))

    # Diccionario de tuplas, en donde en cada tupla se encuentra como (matriz nxm, [lista de tuplas de consultas ])
    tuplas_matriz_consultas = {}

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
        tuplas_matriz_consultas[i + 1] = (matriz, consultas)


    print(tuplas_matriz_consultas)

if __name__ == "__main__":
    main()