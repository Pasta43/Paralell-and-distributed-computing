/*
* Date: 2022-02-04 - format: YYYY-mm-dd
* Author: Santiago Pérez González
* Course: Paralell and Distributed Computing
* Topic: Eighth point of the workshop 1. 
* Program that calculates the tarot number
* to compile: g++ -g 8.cpp -o 8out
* to execute: ./8out
*/

#include<iostream>
#include <cmath>
using namespace std;

/**
* Function that gets the number of digits of an integer number
* @param number that is the number 
* @return the number of the digits of the param of this function
*/
int count_digit(int number) {
   return int(log10(number) + 1);
}
/**
* Function that calculates the Tarot number
* @param day that is the day of birth
* @param month that is the month of birth
* @param year that is the year of birth
* @return the Tarot number
*/
int calculateTarotNumber(int day,int month,int year){
	int sum = day+month+year;
	while(count_digit(sum)>1){
		int newSum=sum;
		sum=0;
		while(newSum!=0){
			int val = newSum%10;
			newSum/=10;
			sum+=val;
		}
	}
	return sum;
}



/**
* Main function
* @param argc that is the number of arguments
* @param argv that is a vector with the arguments
*/
int main(int argc,char** argv){
	int day,month,year;
	cout<<"Bienvenido"<<endl<<"Este es un programa que calcula su número del Tarot"<<endl;
	cout<<"Digite de la forma 'día' 'mes' 'año' (sin comillas, solamente números enteros). Por ejemplo: 22 02 2002."<<endl<<"Escriba su fecha de nacimiento: ";
	cin>>day>>month>>year;
	cout<<"Su número de Tarot es: "<<calculateTarotNumber(day,month,year)<<endl;
}
