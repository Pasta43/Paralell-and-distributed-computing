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
#include <random>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <unistd.h>
#include <math.h>
#include <cstring>
using namespace std;

struct timespec start,endCount;

/*Inicio: medida de tiempo*/
void sampleStart(){
	clock_gettime(CLOCK_MONOTONIC,&start);
}

/*Fin: medida de tiempo*/
void sampleEnd(){
	clock_gettime(CLOCK_MONOTONIC,&endCount);
	/*Se imprime el tiempo*/
	double totalTime;
	totalTime=(endCount.tv_sec-start.tv_sec)*1e9;
	totalTime=(totalTime+endCount.tv_nsec-start.tv_nsec)*1e-9;
	printf("%f\n",totalTime);
}

/*More randomly*/
float randMM(){
	float min=0.001,max=9.999;
	static int first=-1;
	if((first=(first<0)))
		srand(time(NULL)+getpid());
	if(min>max)
		return errno=EDOM,NAN;
	return min +(float)rand()/((float)RAND_MAX/(max-min)); 
}
/**
* Function that multiplies two matrixes
* @param Ma that is the A matrix
* @param Mb that is the B matrix
* @return The matrix product between Ma and Mb
*/
void multiMatrix(vector<vector<double>> Ma, vector<vector<double>> Mb){
	sampleStart();
	vector<vector<double>> MResult(Ma.size(),vector<double>(Ma.size(),0));
	for(int i=0;i<Ma.size();i++){
		for(int j=0;j<Ma.size();j++){
			for(int k=0;k<Ma.size();k++){
				MResult[i][j]+=Ma[i][k]*Mb[k][j];
			}
		}
	}
	sampleEnd();
}
/**
 * @brief Function that generates a random value 
 * 
 * @param fMin that is the lower limit of the random value
 * @param fMax that is the higher limit of the random value
 * @return a double value between fMin and fMax 
 */
double randomNumber(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
/**
 * Function that generates a matrix with truly random values
 * @param N that is the size of the matrix
 * @return a matrix with random values
 */
vector<vector<double>> generateMatrix(int N){
	vector<vector<double>> M(N,vector<double>(N,0));

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			M[i][j]=randMM();
		}
	}
    return M;
}

/**
 * Function that prints in console a matrix
 * @param M that its the matrix will be printed
 */

void printMatrix(vector<vector<double>> M){
	for(int i=0;i<M.size();i++){
		for(int j=0;j<M.size();j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}

}

/**
* Main function
* @param argc that is the number of arguments
* @param argv that is a vector with the arguments
*/
int main (int argc, char** argv){
	srand(time(NULL));
	int i,j,k;
	int N=atoi(argv[1]);
	/*It is used the vector class to create the matrixes*/
	//cout<< "Número ingresado: "<<N<<endl;
	vector<vector<double>> M1(N,vector<double>(N,0));
	vector<vector<double>> M2(N,vector<double>(N,0));
	vector<vector<double>> MR(N,vector<double>(N,0));
	M1=generateMatrix(N);
	M2=generateMatrix(N);
	multiMatrix(M1,M2);
	
		
}

