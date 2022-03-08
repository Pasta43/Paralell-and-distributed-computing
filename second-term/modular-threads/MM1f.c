#include "module.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <errno.h>
// Variable with high value to reserve memory

#define DATA_SZ (1024 * 1024 * 64 * 3)

// Its reserved the memory space taking into account DATA_SZ
static double MEM_CHUNK[DATA_SZ];


int main(int argc,char **argv){
    /*Its captured the dimesion of the matrix*/
    int N = (int) atof(argv[1]);
    // printf("Valor ingresado %d\n",N);
    //create the pointers to the reserved memory with dimension NxN
    double *Ma, *Mb, *Mr;
    Ma=MEM_CHUNK;
    Mb=Ma+N*N;
    Mr=Mb+N*N;
    sampleStart();
    initializeMatrix(N,Ma,Mb,Mr);
    matrixMM1f(N,Ma,Mb,Mr);
    sampleEnd();
    printMatrix(N,Ma);
    printMatrix(N,Mb);
    printMatrix(N,Mr);
}