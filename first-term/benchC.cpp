/*
* Date: 2022-02-22
* Author: Santiago Pérez González
* Course: Paralell and Distributed Computing
* Topic: build of another benchmark
* Benchmark: Implement step by step benchmark of Matrix Multiplication
* algorithm clasic (rows*columns) of matrixes of same dimension
* to compile: g++ benchC.cpp -o benchC.out
* to execute: ./bench.out <integer value>
*/

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

/**
*   
*
*/
void initializeMatrixes(int size,double ** &matA, double ** &matB, double ** &matC ){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            matA[i][j]=2.1*(i-j);
            matB[i][j]=1.2*(i-j);
            matC[i][j]=0;
        }
    }
}

/**

*/
void printMatrix(double **&matrix,int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf(" %f ",matrix[i][j]);
        }   
        printf("\n");
    }
}
/**
*
*/
int main(int argc,char **argv){
    int i,j,k;
    int N=atoi(argv[1]);
    double **matA = createMatrix(N);
    double **matB = createMatrix(N);
    double **matR = createMatrix(N);
    initializeMatrixes(N,matA,matB,matR);
    printMatrix(matA,N);
    printMatrix(matB,N);
    printMatrix(matR,N);
}