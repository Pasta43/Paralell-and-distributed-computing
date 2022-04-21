#include "cfib.h"
/**
 * @brief Función que calcula un número de fibonacci dado un entero n
 * 
 * @param n que representa el número de fibonacci que se quiere de la sucesión
 * @return el número 'n' de fibonnaci
 */
double cfib(int n)
{
    int i;
    double a = 0.0, b = 1.0, tmp;
    for (i = 0; i < n; ++i)
    {
        tmp = a;
        a = a + b;
        b = tmp;
    }
    return a;
}