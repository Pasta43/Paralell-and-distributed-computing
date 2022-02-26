/*
* Date: 2022-02-01
* Author: Santiago Pérez González
* Course: Parallel and Distributed Computing
* Topic: first application to measure the performance
*/

/*Defining the interfaces*/
#include<stdio.h>
/*Const that defines the matrix size*/
#define size 32768
int matrix[size][size];

/*Main function

This executes the course name, the author's name and what will do the program
*/
int main(void) {
	printf("Computación paralela y distribuida\n");
	printf("Santiago Pérez González\n");
	printf("\nPrograma que llena una matriz de tamaño %d",size);
	for(int i = 0; i<size; i++) {
		for(int j = 0; j<size; j++) {
			matrix[i][j] = 47;
		}
	}
	return 0;
}
