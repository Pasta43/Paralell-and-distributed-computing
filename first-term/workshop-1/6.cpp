	/*
	* Date: 2022-01-31
	* Author: Santiago Pérez González
	* Course: Paralell and Distributed Computing
	* Topic: Sixth point of the workshop 1. 
	* Program that calculates the sum of the multiples of five since a number 'a' until another 'b' considering a>=b
	*/


	#include <stdio.h>
	#include "presentation.cpp"
	/**
	Function that calculates the sum of the multiples of five since a number a until another b
	@param a that is the lower bound of the sum
	@param b that is the highest bound of the sum
	@return the sum of the multiples of five since a to b
	*/
	int calculateSum(int a,int b){
		int sum=0;
		while(a<b){
			if(a%5==0)
				sum+=a;
			a++;
		}
		return sum;
	}

	/**
	Main function
	
	This function captures the data input from the user of two integer numbers and, taking into account which one is greater, it sends it 
	to the calculateSum function and finally prints the result in the screen
	*/
	main(){
		presentation();
		int number1=-1,number2=-1,sum=0;
		printf("Calculadora de suma de múltiplos de 5 desde un número 'a' hasta un número 'b'\n");
		while(number1<0){
			printf("Digite un valor entero 1: ");
			scanf("%d", &number1);	
			if(number1<0){
				printf("Recuerde que no puede ingresar valores negativos\n");
			}
		}
		while(number2<0){
			printf("Digite un valor entero 2: ");
			scanf("%d", &number2);	
			if(number2<0){
				printf("Recuerde que no puede ingresar valores negativos\n");
			}
		}
		if(number1<number2){
			sum=calculateSum(number1,number2);
			printf("\nLa suma entre %d y %d es %d",number1,number2,sum);
		}else{
			sum=calculateSum(number2,number1);
			printf("\nLa suma entre %d y %d es %d",number2,number1,sum);
		}
	}
