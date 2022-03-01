/**
*   Date: 2022-03-01
*   Author: Santiago Pérez
*   Course: Parallel and Distributed Computing
*   Topic: Posix implementation
*   Program to multiply 2 matrixes without global variables
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

//It is defined the threads number based on the configuration
#define MAX 4
//It is implemented the main

int main(){
    int mA[MAX][MAX];
    int mB[MAX][MAX];
    //Created to the indexes of the matrixes
    int r1=MAX;
    int c1=MAX;
    int r2=MAX;
    int c2=MAX;
    //Generate random for the matrixes
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            mA[i][j]=rand()%10;
            mB[i][j]=rand()%10;
        }
    } 
    //Print A matrix
    printf("Matriz A");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("%d ",mA[i][j]);
        }
        printf("\n");
    } 
    printf("\n");
    printf("Matriz B");
    //Print B matrix
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("%d ",mB[i][j]);
        }
        printf("\n");
    } 
}