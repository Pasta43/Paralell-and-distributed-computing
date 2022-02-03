/*
* Date: 2022-02-01
* Author: Santiago Pérez González
* Course: Paralell and Distributed Computing
* Topic: build of first benchmark
* Benchmark: toy app thath allows to meausre performance 
* of a specific aspet of the computer
* 
* to compile: g++ -g MyProgram3.cpp -o MiPrograma3
*/

/* Its required to impolement an app that multiply 2 matrixes
   the algorithm to use will be the clasic (rows * columns)
*/

#include <iostream>
#include <vector>

using namespace std;
/**
 Function that prints in console a matrix
 */

void printMatrix(vector<vector<int>> M){
	for(int i=0;i<M.size();i++){
		for(int j=0;j<M.size();j++){
			cout<<M[i][j]<<"\t";
		}
		cout<<endl;
	}

}
int main (int argc, char** argv){
	int i,j,k;
	int N=atoi(argv[1]);
	/*It is used the vector class to create the matrixes*/
	cout<< "Número ingresado: "<<N<<endl;
	vector<vector<int>> vector1(N,vector<int>(N,0));
	printMatrix(vector1);	
}
