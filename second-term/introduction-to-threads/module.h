/**
*   Date: 2022-03-01
*   Author: Santiago Pérez
*   Course: Parallel and Distributed Computing
*   Topic: Posix implementation
*   Main's interface to multiply 2 matrixes without global variables
*   
*   It is required that the design will be modular
*   
*   The module will implement the threads that will do the
*   calculus of the matrix product
*/

#ifndef MODULE_H_INCLUDED
#define MODULE_H_INCLUDED

#include "module.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <stdlib.h>

/**
*   Prototype of the functions to present as interface of module.h
* 
*/
void *matrixProduct(void *arg);


#endif