/*
* Date: 2022-02-06 - format: YYYY-mm-dd
* Author: Santiago Pérez González
* Course: Paralell and Distributed Computing
* Topic: Ninth point of the workshop 1. 
* Program that makes in the screen a digit sequence like a pyramid. The rows are between 11 and 20
* to compile: g++ -g 9.cpp -o 9out
* to execute: ./9out
*/
#include<iostream>
#include "presentation.cpp"
using namespace std;
/**
 * Main function
 * 
 * @param argc that is the number of arguments
 * @param argv that is the vector with the arguments
 */
int main(int argc, char** argv) {
    presentation();
    int n=0;
    cout<<"Bienvenido"<<endl<<"Este es un programa que hace una secuencia de números en forma de pirámide"<<endl<<"Tenga en cuenta que debe digitar valores entre 11 y 20"<<endl;
    while(n<11 ||n>20){
        cout<<"Digite el número de filas de la pirámide: ";
        cin>>n;
        if(n<11 || n>20){
            cout<<"El número de filas debe estar entre 11 y 20"<<endl;
        }
    }
    //Starts the algorithm printing the numbers
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";//You will print spaces to center the pyramid
        }
        int excess=2;
        for(int j=0;j<2*i+1;j++){
            if(j>i){ //it means that i+j+1 is greater than 2*i+1 and simplifying you get j>i
                cout<<(i+j+1-excess)%10;//You will print the numbers in the pyramid when j>i
                excess+=2;
            }else{
                cout<<(i+j+1)%10; //You will print the numbers in the pyramid when j<=i
            }
        }
        cout<<endl;
    }
}
