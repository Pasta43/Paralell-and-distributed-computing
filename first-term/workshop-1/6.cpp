	/*
	* Date: 2022-01-31
	* Author: Santiago Pérez González
	* Course: Paralell and Distributed Computing
	* Topic: Sixth point of the workshop 1. 
	* Program that calculates the sum of the multiples of five since a number 'a' until another 'b' considering a>=b
	* to compile: to compile: g++ -g 6.cpp -o 6out
	* to execute: ./6out
	*/


	#include <iostream>
	#include "presentation.cpp"
	using namespace std;
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
	* @param argc that is the number of arguments
	* @param argv that is a vector with the arguments
	
	*/
	int main(int argc, char **argv){
		presentation();
		int number1=-1,number2=-1,sum=0;
		cout<<"Calculadora de suma de múltiplos de 5 desde un número 'a' hasta un número 'b'\n";
		while(number1<0){
			cout<<"Digite un valor entero 1: ";
			cin>>number1;	
			if(number1<0){
				cout<<"Recuerde que no puede ingresar valores negativos\n";
			}
		}
		while(number2<0){
			cout<<"Digite un valor entero 2: ";
			cin>>number2;	
			if(number2<0){
				cout<<"Recuerde que no puede ingresar valores negativos\n";
			}
		}
		if(number1<number2){
			sum=calculateSum(number1,number2);
			cout<<"\nLa suma de múltiplos de 5 entre "<<number1<<" y "<<number2<<" es "<<sum;
		}else{
			sum=calculateSum(number2,number1);
			cout<<"\nLa suma de múltiplos de 5 entre "<<number2<<" y "<<number1<<" es "<<sum;
		}
	}
