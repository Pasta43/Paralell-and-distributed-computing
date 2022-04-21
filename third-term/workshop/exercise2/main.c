#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cfib.h"

/**
 * @brief Función principal. Se hace uso de una función de fibonnaci y se calculan varios con el fin de comparar el rendimiento entre python, cython y C
 *
 * @param argc que representa cuántos argumentos se insertaron en la línea de comandos
 * @param argv que representa cuáles arugmentos se insertaron en la línea de comandos
 * @return un entero que representa si la ejecución fue exitosa o no
 */
int main(int argc, char **argv)
{
    int arg = -1, numiter = -1, i;
    clock_t t;
    if (argc != 3)
    {
        printf("Wrong number of arguments, expecting 2 (got %d)\n.", argc - 1);
        return 1;
    }
    arg = atoi(argv[1]);
    numiter = atoi(argv[2]);
    t = clock();
    for (i = 0; i < numiter; ++i)
    {
        cfib(arg);
    }
    t = clock() - t;
    printf("%f\n", ((float)t) / 1000000 /
                       numiter * 1e9);
    return 0;
}