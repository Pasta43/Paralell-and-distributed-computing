/*
* Date: 2022-02-06 - format: YYYY-mm-dd
* Author: Santiago Pérez González
* Course: Paralell and Distributed Computing
* Topic: Tenth point of the workshop 1. 
* Program that finds the numeric centers since 1 to n 
* to compile: g++ -g 10.cpp -o 10out
* to execute: ./10out
*/

#include<iostream>
#include <vector>
using namespace std;
/**
* Function that prints the numbers of a vector
* @param numbers that is a vector with the numbers to print. In this case, will be numeric centers.
* @param n that is a number digited by the user
*
*/
void printNumbers(vector<int> numbers, int n){
    cout<<"Los centros numéricos desde 1 hasta "<<n<< " son: ";
    for(int i =0;i<numbers.size();i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
}
/**
 * Main function
 * 
 * @param argc that is the number of arguments
 * @param argv that is the vector with the arguments
 */
int main(int argc,char **argv){
    int n=0; //Number to know until where it is needed to calculate the numberic centers
    int counter=0; //counter of numeric centers
    cout<<"Bienvenido"<<endl<<"Este es un programa que encuentra centros numéricos"<<endl<<"Digite un valor para calcular todos los centros numéricos desde 1 hasta ese número";
    cin>>n;
    vector<int> list=vector<int> M(N,0);
    
    for(int i=1;i<=n;i++){
        //Preview sum
        long previewSum=0;
        int j=0;
        for(j=1;j<i;j++){
            previewSum+=j;
        }
        //After sum
        long afterSum=0;
        j++;
        while(true){
            afterSum+=j;
            if(afterSum==previewSum){ //If the sums are equals, it means that is a numeric center
                list[counter]=i;
                break;
            }else if(afterSum>previewSum){ //If the after sum is greater than preview, it means that this number is not a numeric center (or could be lower, but it could )
                break;
            }
            j++;
        }
    }
    printNumbers(list);
}