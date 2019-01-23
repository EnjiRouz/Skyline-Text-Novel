#pragma once//используется для избежания бесконечной рекурсии
//подключение директив предпроцессора(библиотек)
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>
#include "Definitions.h"


using namespace std;


	
	
void Inventory(int positionOfShop);
//инициализация функций (праобразов функций)
void Read(char **a, int rowsCount, int columnsCount, char *filename);
void printMeasure();
//**************
void pointToMenu();
void pointToMenu2();
void pointToMenuShop();
//**************
void Print( int rowsCount, int columnsCount, char *filename);
void Print( int rowsCount, int columnsCount, int positionOfMenu, char *filename);
//**************
void moveToMenuPoint(int a, int b, char ** Massive, int y, char ** Massive2, int y2, int proverka);
//**************
void userSelection(int Cur);
void userSelectionShop(int Cur);
void userSelection2(int Cur);
//**************
void stand(int X_COORD, int Y_COORD, int TEXT_COLOR, char*str);
void stand(int X_COORD, int Y_COORD, int TEXT_COLOR, int Q, char*str);
void stand(int X_COORD, int Y_COORD, int TEXT_COLOR, int Q);
void stand(int X_COORD, int Y_COORD);
//**************
int matreein();
//**************
char** textures(int masy, int masx, const  char* fillname); 
//**************
void display_draw(char ** Massive, int Massive_Y, int Massive_X);

//**************
void file_scan(char **mas, int masx, int masy, const char*filename);
//**************
extern char**  hat_Skyline;
extern char**  hat_Shop ;
extern char**  Point_Shop ;
extern char**  Point_MainMenu;
extern char**  Point_StartGame ;
void strelka(int position);