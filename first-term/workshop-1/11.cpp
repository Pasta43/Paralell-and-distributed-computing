/*
* Date: 2022-02-06 - format: YYYY-mm-dd
* Author: Santiago Pérez González
* Course: Paralell and Distributed Computing
* Topic: Eleventh point of the workshop 1. 
* Program that calculates the amount to pay by a vehicle that roads in a highway.
* It considers the following
* - fix amount for bikes of 100 units
* - motorbikes and cars will pay 30 units per kilometer
* - trucks will pay 30 units per kilometer plus 25 units per ton
*
* to compile: g++ -g 11.cpp -o 11out
* to execute: ./11out
*/
#include <iostream>
#include <vector>
using namespace std;
/**
* Function that get the user input for the kilometers 
* @return the input data of the kilometers
*/
double getAmountPerKm(){
    double km=0;
    while(km<=0){
        cout<<"Inserte la cantidad de kilómetros recorridos: ";
        cin>>km;
        if (km<0){
            cout<<"El número de kilómetros ingresado debe ser un número positivo"<<endl;
        }
    }
    return 30*km;
}
/**
* Function that get the user input for the tons 
* @return the input data of the tons
*/
double getAmountPerTon(){
    double ton=0;
    while(ton<=0){
        cout<<"Inserte la cantidad de toneladas que llevó su camión: ";
        cin>>ton;
        if (ton<0){
            cout<<"El número de toneladas ingresado debe ser un número positivo"<<endl;
        }
    }
    return 25*ton;
}
/**
 * Main function
 * 
 * @param argc that is the number of arguments
 * @param argv that is the vector with the arguments
 */
int main(int argc,char **argv){
    cout<<"Bienvenido"<<endl<<
    "Este es un programa que calcula el importe a pagar por ciruclar en una autopista"<<endl;
    while(true){
        int option=0, amount=0;
        cout<<"Menú principal"<<endl<<
        "1- Bicicleta"<<endl<<
        "2- Moto"<<endl<<
        "3- Coche"<<endl<<
        "4- Camión"<<endl<<
        "5- Salir"<<endl<<endl<<
        "Decida: ";
        cin>>option;
        switch(option){
            case 1:
                amount=100;
                break;
            case 2:
            case 3:
                amount = getAmountPerKm();
                break;
            case 4:
                amount = getAmountPerKm()+getAmountPerTon();
                break;
            case 5:
                cout<<"Gracias por utilizar el servicio"<<endl;
                exit(0);
            default:
                cout<<"Opción inválida. Solo puede digitar números entre 1 y 5"<<endl;
        }
        if (amount!=0){
            cout<<"Importe="<<amount<<endl;
        }
    }
}