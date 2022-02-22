#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <random>
#include <chrono>
/**
*   
*/
double ** createMatrix(int size){
    int i;
    double **matrix=new double *[size];
    for(i=0;i<size;++i)
        matrix[i]= new double[size];
    return matrix;
}

int main(int argc,char **argv){
    int i,j,k;
    int N=atoi(argv[1]);
    double **matA = createMatrix(N);
    double **matB = createMatrix(N);
    double **matR = createMatrix(N);
}