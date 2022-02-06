/*
* Date: 2022-02-04 - format: YYYY-mm-dd
* Author: Santiago P�rez Gonz�lez
* Course: Paralell and Distributed Computing
* Topic: Eighth point of the workshop 1. 
* Program that calculates the tarot number
* to compile: g++ -g 8.cpp -o 8out
* to execute: ./8out
*/

#include <iostream>
#include <cmath>
using namespace std;

/**
* Function that gets the number of digits of an integer number
* @param number that is the number to calculate its digits
* @return the number of the digits of the param of this function
*/
int count_digit(int number) {
   return int(log10(number) + 1);
}
/**
* Function that calculates the Tarot number. It tooks first the sum of the day, month and year and
* then the sum of the digits of the sum reducing it to one digit
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
	while(true){
		cout<<"Digite de la forma 'día' 'mes' 'año' (sin comillas, solamente números enteros). Por ejemplo: 22 02 2002."<<endl<<"Escriba su fecha de nacimiento: ";
		cin>>day>>month>>year;
		if(day<1 || day>31 || month<1 || month>12 || year<1900 || year>2022){
			cout<<"La fecha introducida no es válida"<<endl;
		}else{
			break;
		}
	}
	cout<<"Su número de Tarot es: "<<calculateTarotNumber(day,month,year)<<endl;
}
