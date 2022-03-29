/*Fecha: 2022-03-16
* Autor: Santiago Pérez.
* Subject: Parallel and Distributed Computing.
* Topic: Posix implemetation (Library)
* Description: Application for matrix multiplication
  with the classical algorithm (rows x columns) using
  global variables. Also, using the following functions:
    1. Creation of double pointer variables for matrices
    2. Memory reserve for double pointer matrices
    3. Init matrix
    4. Function for the matrix's product:
        4.1.1 The matrix A is divide and those portions 
        will be sent to an individual thread
        4.1.2 The matrix's size will be sent in the 
        execution.
    5. Matrix's size always squared (NxN)
    6.  Print matrix with double pointer.

* 
*/


/*Interfaces*/
#include "module.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

/**
 * @brief Main function
 * 
 * @param argc That is the arguments count
 * @param argv That is the arguments values
 * @return 0 if everything is ok or another number in error case
 */
int main(int argc, char* argv[]){
    double **Ma,**Mb,**Mc;
    if (argc!=3){
        printf("./MMPosix <matrix size> <# of threads>\n");
        return -1;
    }
    
    
    /*Init of global variables*/
    int N           = atof(argv[1]);    /* Matrix's size.*/
    int Nthreads    = atof(argv[2]);    /* Number of threads.*/
    

    pthread_t *threads=(pthread_t*)malloc(N*sizeof(pthread_t));//Thread reservation
    /*Memory creation and reserce for each matrix*/
    Ma = memReserve(N); 
    Mb = memReserve(N);
    Mc = memReserve(N);
    initMatrix_DoublePointers (Ma, Mb, Mc, N);
    if (N<4){
        printf("Matriz A\n");
        printMatrix_DoublePointers (Ma, N);
        printf("Matriz B\n");
        printMatrix_DoublePointers (Mb, N);
    }
    
    sampleStart();
    for (int i = 0; i < Nthreads; ++i){
        int *idThread;
        idThread=(int *)malloc(sizeof(int));
        *idThread=i;
        struct dataThread *dataThread_=(struct dataThread *)malloc(sizeof(struct dataThread));//Thread data reservation
        dataThread_->NThreads=Nthreads;
        dataThread_->N=N;
        dataThread_->Ma=Ma;
        dataThread_->Mb=Mb;
        dataThread_->Mr=Mc;
        dataThread_->idThread=*idThread;
        pthread_create(&threads[i],NULL,multMM,(void *)dataThread_);
    }
    for (int i = 0; i < Nthreads; ++i){
        
        pthread_join(threads[i],NULL);
    }
    sampleEnd();
    free(threads);
    if (N<4){
        printf("Matriz C\n");
        printMatrix_DoublePointers (Mc, N);
    }
    
    return 0;
}

