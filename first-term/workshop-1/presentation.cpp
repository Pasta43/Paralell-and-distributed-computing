#include <stdio.h>  
#include <windows.h>  
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void presentation(){
	int x,y;
 	//Vertical bar
 	for(y=1;y<=7;y++)
 	{
  		gotoxy(1,y);
  		printf("║");
 		gotoxy(59,y);
  		printf("║");
 	}
 	//Horizontal bar
 	for(x=1;x<=59;x++){
  		gotoxy(x,1);printf("═");
		gotoxy(x,7);printf("═");
 	}
 	gotoxy(1,1); printf("╔");
 	gotoxy(1,7); printf("╚");
 	gotoxy(59,1); printf("╗");
 	gotoxy(59,7); printf("╝");
 	gotoxy(17,2);
 	printf(CYAN "Santiago Pérez González");
	gotoxy(19,3);
	printf("Computación Paralela");
 	gotoxy(10,4);
 	printf("Ingeniería de Sistemas y Telecomunicaciones");
	gotoxy(18,5);
	printf("Profesor John Corredor");
 	gotoxy(17,6);
 	printf("Universidad Sergio Arboleda\n\n\n" WHITE "");
}