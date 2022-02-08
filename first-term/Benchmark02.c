/*
* Date: 2022-02-08
* Author: Santiago Pérez González
* Course: Paralell and Distributed Computing
* Topic: build of second benchmark
* Benchmark: Implement step by step benchmark of Matrix Multiplication
* algorithm clasic (rows*columns) of matrixes of same dimension
* to compile: gcc Benchmark02.c -o benchmark02
* to execute: ./benchmark02 <integer value>
*/
#include <stdio.h>
#include <stdlib.h>

//Variable with high value to reserve memory
#define DATA_SZ (1024*1024*64*3)

//Its reserved the memory space taking into account DATA_SZ
static double MEM_CHUNK[DATA_SZ];

//Its created the function to initialize matrix
void initializeMatrix(int SZ,double *Ma,double *Mb, double *Mr){
    int i,j,k;
    for(i=0;i<SZ;++i){
        for(j=0;j<SZ;++j){
            Ma[j+i*SZ]=3.0*(i-j);
            Mb[j+i*SZ]=2.8*(i+j);
            Mr[j+i*SZ]=0.0;
        }
    }
}

//Its implemented the print to validate data
void printMatrix(int SZ,double *Ma){
    int i,j,k;
    for(i=0;i<SZ;++i){
        for(j=0;j<SZ;++j){
            printf("%f  ",Ma[j+i*SZ]);
        }
        printf("\n");
    }
}

/**
* Main function
* @param argc that is the number of arguments
* @param argv that is a vector with the arguments
*/
int main (int argc, char ** argv){
    /*Its captured the dimesion of the matrix*/
    int N = (int) atof(argv[1]);
    printf("Valor ingresado %d\n",N);
    //create the pointers to the reserved memory with dimension NxN
    double *Ma, *Mb, *Mr;
    Ma=MEM_CHUNK;
    Mb=Ma+N*N;
    Mr=Mb+N*N;
    initializeMatrix(N,Ma,Mb,Mr);
    printf("\nMatriz A\n");
    printMatrix(N,Ma);
    printf("\nMatriz B\n");    
    printMatrix(N,Mb);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //Auxiliar pointers
            double *pA, *pB;
            double auxiliarSum=0;
            pA=Ma+(i*N);
            pB=Mb+j;        
            for(int k=0;k<N;k++,pA++,pB+=N){
                auxiliarSum+=(*pA * *pB);
            }
            Mr[i*N+j]=auxiliarSum;
        }
    }
    printf("\nMatriz resultante\n");
    printMatrix(N,Mr);
    return 0;
}
