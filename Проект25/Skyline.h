#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdio> 
#include <string>
#include <Windows.h>
#include "Menu.h"
#include "Definitions.h"
#include "MainInventoryFunctions.h"


using namespace std;

void read();
void printInterBlue();                                    //вывод синей линии интерфейса(количество монет и очков здоровь€)
void printInterGreen();                                                    //вывод зелЄной линии интерфейса(кнопки магазина и инвентар€)
void exit(); // функци€ выхода

const enum Direction { left = 1, top, right, low };                       //направление входа в €чейку микросхемы
struct cell                                                                 //стуктура €чеек с пол€ми:
{                                                                           //
	Direction in;                                                           //точка входа в €чейку
	Direction out;                                                          //точка выхода из €чейки
	char map[4][4];                                                         //массив символов - изображение €чейки
};                                                                          //

struct hero
{
	int Money;
	int Life;
	int Armor = 0;
	int Attack = 1;
	int positionOfShop = 7;
	int positionOfMenu = 7;
	int rowsCount = 6;
	int columnsCount = 55;
	int location;
	bool game = false; 
	int x;
	string inventory_items[11];
};
extern hero MainHero;

const enum nameItem { LifePosion, helmet, armor, boots, shield, sword, manacles };

struct item
{

	nameItem is;
	unsigned short position;
	byte of;

};

extern item Shop[7];