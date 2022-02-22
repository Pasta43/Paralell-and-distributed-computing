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
*   @brief Function that initializes a three matrixes before do a multiplication
*   @param matA is a pointer that represents a matrix (matrix 1)
*   @param matB is a pointer that represents a matrix (matrix 2)
*   @param matC is a pointer that represents a matrix (result matrix when matA*matB)
*   @param size that is the matrix size of matA,matB,matC
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
*   @brief Function that destroyes a matrix. This deletes all the rows of a matrix and later puts the matrix pointer as a null pointer 
*   @param size that is the matrix size N*N
*   @param matrix is a pointer that represents the matrix 
* 
*/
void destroyMatrix(int size, double** &matrix){
    if(matrix){
        int i; 
        for(i=0;i<size;i++){
            delete [] matrix[i];
        }
        delete [] matrix;
        matrix=nullptr;

    }
}
/**
*   @brief Function 
*   @param
*   @param
*/
double ** matrixProduct(int size, double ** &matrix1,double ** &matrix2){
    int i,j,k;
    double **matrix = createMatrix(size);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            for(k=0;k<size;k++){
                matrix[i][j]+=matrix1[i][k]+matrix2[k][j];
            }   
        }     
    }
    return matrix;
}

/**
* @brief Function that prints a matrix
* @param matrix that is the matrix
* @param size that is the matrix size
*/
void printMatrix(double **&matrix,int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf(" %f ",matrix[i][j]);
        }   
        printf("\n");
        
    }
    printf("\n\n")
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
    matR=matrixProduct(N,matA,matB);
    printMatrix(matR,N);
    destroyMatrix(N,matA);
    destroyMatrix(N,matB);
    destroyMatrix(N,matR);
}