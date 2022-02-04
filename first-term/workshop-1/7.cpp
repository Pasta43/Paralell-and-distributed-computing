/*
* Date: 2022-02-03 - format: YYYY-mm-dd
* Author: Santiago Pérez González
* Course: Paralell and Distributed Computing
* Topic: Seventh point of the workshop 1. 
* Program that calculates the sum of \sum_{a=0}^{b}{\frac{1}{x+ay}}
* to compile: g++ -g 7.cpp -o 7out
* to execute: ./7out
*/

#include<iostream>
using namespace std;
/**
* Function that calculates the sum of \sum_{a=0}^{b}{\frac{1}{x+ay}}
* @param b that is the higher limit of the sum. It must be integer
* @param x that is a component of the sum
* @param y that is a component of the sum
* @return the sum of \sum_{a=0}^{b}{\frac{1}{x+ay}}
*/
double calculateSum(int b,double x,double y){
	double sum=0;
	for(int a=0;a<b;a++){
		sum+=1/(x+a*y);
	}
	return sum;
}

int main(int argv,char** argc){
	int b;
	double x=0,y,sum=0;
	cout<<"Bienvenido"<<endl<<"Este es un programa que calcula la sumatoria sum_{a=0}^{b}{frac{1}{x+ay}}"<<endl;
	cout<<"Digite el valor del límite de la sumatoria (b): ";
	cin>>b;
	while(x==0){
		cout<<"Digite el valor del parámetro x: ";
		cin>>x;
		if(x==0){
			cout<<"El valor del parámetro x no puede ser cero"<<endl;
		}
	}
	cout<<"Digite el valor del parámetro y: ";
	cin>>y;
	sum=calculateSum(b,x,y);
	cout<<"El valor de la suma es: "<<sum<<" "<<endl;

}
