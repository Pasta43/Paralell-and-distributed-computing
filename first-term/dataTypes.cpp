/*
* Date: 2022-02-01
* Author: Santiago Pérez González
* Course: Paralell and Distributed Computing
* Topic: application that shows the datatypes and its size
*/

/*Interfaces are declared*/
#include <iostream>

/*Definition of a lambda function SIZEBITES that returns the number of bits  by a given variable*/
#define SIZEBITES(x) sizeof(x)*8


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"========================================================================================="<<endl;
	cout<<"	Type            | 	Meaning       		|	Bytes	|	bits	|"<<endl;
	cout<<"========================================================================================="<<endl;
	cout<<"	bool		|	Boolean			|	 "<<sizeof(bool)<<"	|	  "<<SIZEBITES(bool)<<"	"<<endl;
	cout<<"	wchar_t		|	Wide Character		|	 "<<sizeof(wchar_t)<<"	|	 "<<SIZEBITES(wchar_t)<<"	"<<endl;
	cout<<"	char16_t	|	Unicode Character	|	 "<<sizeof(char16_t)<<"	|	 "<<SIZEBITES(char16_t)<<"	"<<endl;
	cout<<"	char32_t	|	Unicode Character	|	 "<<sizeof(char32_t)<<"	|	 "<<SIZEBITES(char32_t)<<"	"<<endl;
	cout<<"	short		|	Short Integer		|	 "<<sizeof(short)<<"	|	 "<<SIZEBITES(short)<<"	"<<endl;
	cout<<"	int		|	Integer			|	 "<<sizeof(int)<<"	|	 "<<SIZEBITES(int)<<"	"<<endl;
	cout<<"	long		|	Long Integer		|	 "<<sizeof(long)<<"	|	 "<<SIZEBITES(long)<<"	"<<endl;
	cout<<"	long long	|	Long Long Integer	|	 "<<sizeof(long long)<<"	|	 "<<SIZEBITES(long long)<<"	"<<endl;
	cout<<"	float		|Single Precision Floating Point|	 "<<sizeof(float)<<"	|	 "<<SIZEBITES(float)<<"	"<<endl;
	cout<<"	double		|Double Precision Floating Point|	 "<<sizeof(double)<<"	|	 "<<SIZEBITES(double)<<"	"<<endl;
	cout<<"	long double	|Extend Precision Floating Point|	"<<sizeof(long double)<<"	|	"<<SIZEBITES(long double)<<"	"<<endl;
	return 0;
}
