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
#include <pthread.h>
#include <unistd.h> 
#include <stdlib.h>

/**
*   Function of each thread that calculates a single element over the result matrix
*   @param *arg data vector passed. This will be a part sent for the operation of the element over the result matrix
*   @return 
*/
void *matrixProduct(void *arg){
    int *data=(int *)arg;//"data" integer variable is a pointer of the data vector "arg"
    int i, j, k;
    int x=data[0];
    for(i=1;i<=x;++i)
        k+=data[i]*data[i+x];
    int *p =(int *) malloc(sizeof(int));
    *p = k;
    //It is usted for end the thread and return the value passed as pointer
    pthread_exit(p);
}