#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h> 
#include "GRAPH.h"

using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE); // номер потока для буфера консоли в системе

void stand(int X_COORD, int Y_COORD, int TEXT_COLOR, int Q, char*str)
{
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = 0;
	ci.dwSize = 100;
	SetConsoleCursorInfo(H, &ci); // убрать мигающий курсор

	COORD c;
	c.X = X_COORD; c.Y = Y_COORD;
	SetConsoleCursorPosition(H, c); //установка курсора
	SetConsoleTextAttribute(H, TEXT_COLOR); //установка цвета текста
	cout << Q <<str<< "\n";
	
}

void stand(int X_COORD, int Y_COORD, int TEXT_COLOR,  char*str)
{
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = 0;
	ci.dwSize = 100;
	SetConsoleCursorInfo(H, &ci); // убрать мигающий курсор

	COORD c;
	c.X = X_COORD; c.Y = Y_COORD;
	SetConsoleCursorPosition(H, c); //установка курсора
	SetConsoleTextAttribute(H, TEXT_COLOR); //установка цвета текста
	cout << str << "\n";
	
}


void stand(int X_COORD, int Y_COORD)//вместо system cls, устанавливаем курсор в начало

{
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible =0;
	ci.dwSize =100;
	SetConsoleCursorInfo(H, &ci); // убрать мигающий курсор
	COORD c;
	c.X = X_COORD; c.Y = Y_COORD;
	SetConsoleCursorPosition(H, c); //установка курсора

}