/*Fecha: 2022-03-16
* Autor: Santiago Pérez
* Subject: Parallel and Distributed Computing.
* Topic: Construction of the first Benchmark
* Description: Application that allows evaluating the performance
*  of a specific aspect of the computer using matrix multiplication
*  with the calssical algorithm (rows x columns)
* Code taken from: https://github.com/ACLXRD/Computacion_Paralela_Distribuida/tree/master
*/

/*Interfaces*/

#include "module.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>


// typedef struct dataThread
// {
// 	int idThread;
// 	int portionSize;
// 	int initRow;
// 	int endRow;
// } implicit_data;


/*CONSTANTS*/
struct timespec inicio, fin;


/* -------------------------------------Funciones ------------------------------------*/


/**
 * 	@brief: Get the init time*/
void sampleStart(){
	clock_gettime(CLOCK_MONOTONIC, &inicio);	
}

/**
 * 	@brief: Get the end time */
void sampleEnd(){
	clock_gettime(CLOCK_MONOTONIC, &fin);	
	double totalTime;
	totalTime = (fin.tv_sec - inicio.tv_sec)*1e9;
	totalTime = (totalTime + (fin.tv_nsec - inicio.tv_nsec))*1e-9;
	printf ("\nTotal time: %f seg \n", totalTime);
}
/*	@brief: Function that generates a random number 
	@return: Random number between 0.001 and 9.999 with double precision
    ---
    getpid(): Gets an ID of a rand porcess of the system
*/
double randNumber(){
    float min = 0.001, max = 9.999;
    static int first = -1;
    if(first == (first < 0)){
       srand(time(NULL) + getpid());
    }
    if(min >= max){
        return errno = EDOM, NAN;
    }
    return min + (float)rand()/((float)RAND_MAX/(max-min));
}

/*	@brief: Gives values for each space of a matrix
	@param SZ: Size of the matrix

*/
void initMatrix(int SZ, double *Ma, double *Mb, double *Mr){
	int i, j;
	for(i=0; i<SZ; ++i){
		for(j=0;j<SZ;++j){
			Ma[j+i*SZ] = 3.0*(i-j);
			Mb[j+i*SZ] = 2.8*(j+i);
			Mr[j+i*SZ] = 0.0;
		}
	}
		
}

/*	@brief: Print a matrix
	@param SZ: Size of the matrix
	@return *M: Matrix to print	
*/
void printMatrix(int SZ, double *M){
	int i,j;
	for (i=0;i<SZ; ++i){
		for (j=0;j<SZ; ++j){
			printf("  %f  ",M[j+i*SZ]);
		}
		printf("\n");
	}
		printf("----------------------------");
		printf("\n");
		
		
}

/*	@brief: Multiply matrices
	@param size: Size of matrix
	@param a: Matriz A to multiply
	@param b: Matriz B to multiply
	@param c: Total matrix of multiplication
    ---
*/
void matrixMultiplyMM1c(int size, double *Ma, double *Mb, double *Mr){
	int i, j;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
		/*Necesita puteros auxiliares*/
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = Ma + (i*size);
		pB = Mb + j;
			for(int k = 0; k < size; ++k, pA ++, pB+=size){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[i*size+j] = sumaAuxiliar;
		}
	}
}

void matrixMultiplyMM1f(int size, double *Ma, double *Mb, double *Mr){
  int i, j;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
		/*Necesita puteros auxiliares*/
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = Ma + (i*size);
		pB = Mb + (j*size);
			for(int k = 0; k < size; ++k, pA++, pB++){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[i*size+j] = sumaAuxiliar;
		}
	}
}

/*	Se imlementa paso a paso benchmark Multiaplicacion de matrices
	Algoritmo clasico (filas x columnas) de matrices
	de igual diemnsion
*/


/****************** Functions for posix (program using threads)**************************/

/*
	@breif: Memory reserve for double pointer matrices
	@param size: Matrix size
	@return ptr: Doble pointer Vector with portions of the matrix allocated in threads
*/
double ** memReserve (int size){
	/* Memory reserve of dimenion NxN double*/
	double *val = (double *) malloc(size*size*sizeof(double));

	/* Doble pointer Vector reserve of dimenion size*/
	double ** ptr = (double **) malloc(size*size*sizeof(double *));
	/* Iteration with the purpose that each pointer position itself in the memory reserve*/
	for (int i = 0; i < size; ++i)	{
		ptr[i] = &val[i*size];
	}
	return ptr;
}

/*	@brief: Gives values for each space of a matrix
	@param **Ma: Matrix A
	@param **Mb: Matrix B
	@param **Mc: Matrix C
	@param size: Size of the matrix
*/
void initMatrix_DoublePointers (double **MA, double **MB, double **MC, int size){
	int i, j; /*Indices*/
	for (i = 0; i < size; ++i)	{
		for (j = 0; j < size; ++j)	{
			MA[i][j] = 3.9*(i-j);
            MB[i][j] = 2.0*(j+i);
            MC[i][j] = 0.0;
		}
	}
}

void printMatrix_DoublePointers (double **M, int size){
	int i, j; /*Indices*/
	for (i = 0; i < size; ++i)	{
		for (j = 0; j < size; ++j)	{
			printf("	%lf", M[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");

}