/*
* Date: 2022-02-10
* Author: Santiago Pérez González
* Course: Parallel and Distributed Computing
* Topic: Moduling programming in C
* File: Main
*/

#include "functions.h"
#include <stdio.h>
/**
*
*
*/
int main(int argc, char** argv){
	int a=10,b=2,result=0;
	printf("Programa principal\n");
	printf("Llamada a la función\n");	
	result=sum(a,b);
	printf("Resultado de la función: %d\n",result);
	return 0;
}