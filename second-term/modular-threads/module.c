/**
*   Date: 2022-03-01
*   Author: Santiago Pérez
*   Course: Parallel and Distributed Computing
*   Topic: Posix implementation
*   Main's module to multiply 2 matrixes without global variables
*   
*   It is required that the design will be modular
*   
*   The module will implement the threads that will do the
*   calculus of the matrix product
*/
#include "module.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <errno.h>


struct timespec start,endCount;
/*Inicio: medida de tiempo*/
void sampleStart(){
    clock_gettime(CLOCK_MONOTONIC,&start);
}

/*Fin: medida de tiempo*/
void sampleEnd(){
    clock_gettime(CLOCK_MONOTONIC,&endCount);
    /*Se imprime el tiempo*/
    double totalTime;
    totalTime=(endCount.tv_sec-start.tv_sec)*1e9;
    totalTime=(totalTime+endCount.tv_nsec-start.tv_nsec)*1e-9;
    printf("%f\n",totalTime);
}

/**
*   Function of each thread that calculates a single element over the result matrix
*   @param *arg data vector passed. This will be a part sent for the operation of the element over the result matrix
*   @return 
*/
void *matrixProduct(void *arg){
    int *data=(int *)arg;//"data" integer variable is a pointer of the data vector "arg"
    int i, k;
    int x=data[0];
    for(i=1;i<=x;++i)
        k+=data[i]*data[i+x];
    int *p =(int *) malloc(sizeof(int));
    *p = k;
    //It is usted for end the thread and return the value passed as pointer
    pthread_exit(p);
}

float randMM()
{
    float min = 0.001, max = 9.999;
    static int first = -1;
    if ((first = (first < 0)))
        srand(time(NULL) + getpid());
    if (min > max)
        return errno = EDOM, NAN;
    return min + (float)rand() / ((float)RAND_MAX / (max - min));
}

// Its created the function to initialize matrix
void initializeMatrix(int SZ, double *Ma, double *Mb, double *Mr)
{
    int i, j;
    for (i = 0; i < SZ; ++i)
    {
        for (j = 0; j < SZ; ++j)
        {
            Ma[j + i * SZ] = randMM();
            Mb[j + i * SZ] = randMM();
            Mr[j + i * SZ] = 0.0;
        }
    }
}

// Its implemented the print to validate data
void printMatrix(int SZ, double *Ma)
{
    int i, j;
    for (i = 0; i < SZ; ++i)
    {
        for (j = 0; j < SZ; ++j)
        {
            printf("%f  ", Ma[j + i * SZ]);
        }
        printf("\n");
    }
}

void matrixMM(int size, double *Ma, double *Mb, double *Mr){
    int i, j, k;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            // Auxiliar pointers
            double *pA, *pB;
            double auxiliarSum = 0;
            pA = Ma + (i * size);
            pB = Mb + j;
            for (k = 0; k < size; k++, pA += size, pB++)
            {
                auxiliarSum += (*pA * *pB);
            }
            Mr[i * size + j] = auxiliarSum;
        }
    }
}
void *matrixMM1c(int size, double *Ma, double *Mb, double *Mr){
    int i, j, k;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            // Auxiliar pointers
            double *pA, *pB;
            double auxiliarSum = 0;
            pA = Ma + (i * size);
            pB = Mb + j;
            for (k = 0; k < size; k++, pA ++, pB+= size)
            {
                auxiliarSum += (*pA * *pB);
            }
            Mr[i * size + j] = auxiliarSum;
        }
    }
}
void *matrixMM1f(int size, double *Ma, double *Mb, double *Mr){
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            // Auxiliar pointers
            double *pA, *pB;
            double auxiliarSum = 0;
            pA = Ma + (i * size);
            pB = Mb + (j*size);
            for (int k = 0; k < size; k++, pA ++, pB++)
            {
                auxiliarSum += (*pA * *pB);
            }
            Mr[i * size + j] = auxiliarSum;
        }
    }
}