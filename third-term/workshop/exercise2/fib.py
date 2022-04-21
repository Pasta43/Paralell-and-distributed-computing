def fib(n):
    """
    Función que calcula un número de fibonacci dado un entero n

    Parámetros:

    n - que representa el número de fibonacci que se quiere de la sucesión

    Retorna

    el número 'n' de fibonnaci
    """
    a, b = 0.0, 1.0
    for i in range(n):
        a, b = a + b, a
    return a

if __name__ == '__main__': #Si se ejecuta la función principal
    import sys
    arg, numiter = map(int, sys.argv[1:]) #Se verifican los argumentos en línea de comandos
    for i in range(numiter):
        fib(arg)