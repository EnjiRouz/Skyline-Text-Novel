#pragma once//используется для избежания бесконечной рекурсии

#include "Menu.h"//подключение директив предпроцессора(библиотек)
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h> 
#include "Definitions.h"
#include <string> 
#include <fstream>
#include "MainInventoryFunctions.h"
#include "Skyline.h"
#include "Menu.h"


fstream fout(SaveGameFileName, ios::in | ios::out | ios::ate);



int a = 9;
int b = 25;

 hero MainHero;
 item shop;

 

using namespace std;
/*
void Read(char **a, int rowsCount, int columnsCount, char *filename)
{
	//char mass[9][56];
	//char str[305];
	//char *print_array = (char*)mass;
	
	ifstream txt(filename); // открытие файла
	for (int y = 0; y < rowsCount; y++) // цикл записывающий массив строки из файла
	{
		txt.getline(str, sizeof(str)); // получение строки из файла
		for (int x = 0; x <= columnsCount; x++) // запись сиволов из ограниченной области файла
			a[y][x] = str[x];
	}
	txt.close(); // закрытие файла
	for (int r = 0; r <rowsCount; r++)//вывод массива типа char(шапки нашего меню) двойным циклом(по одному символу)
	{
		for (int c = 0; c < columnsCount; c++)
		{
			cout <<a[r][c];// вывод текущего символа на экран
		}
		cout << "\n\t";// отступ, табуляция

	}
}*/

void Print( int rowsCount, int columnsCount, char *filename)
{
	system("color 3");

	char mass[9][56];
	char str[305];
	char *print_array = (char*)mass;
	
	ifstream txt(filename); // открытие файла
	for (int y = 0; y < rowsCount; y++) // цикл записывающий массив строки из файла
	{
		txt.getline(str, sizeof(str)); // получение строки из файла
		for (int x = 0; x <= columnsCount; x++) // запись сиволов из ограниченной области файла
			mass[y][x] = str[x];
	}
	txt.close(); // закрытие файла

	for (int r = 0; r <rowsCount; r++)//вывод массива типа char(шапки нашего меню) двойным циклом(по одному символу)
	{
		for (int c = 0; c < columnsCount; c++)
		{
			cout << mass[r][c];// вывод текущего символа на экран
		}
		cout << "\n\t";// отступ, табуляция

	}
	

}
void Print( int rowsCount, int columnsCount, int positionOfShop, char *filename)
{
	system("color 3");

	char mass[9][56];
	char str[305];
	char *print_array = (char*)mass;

	ifstream txt(filename); // открытие файла
	for (int y = 0; y < rowsCount; y++) // цикл записывающий массив строки из файла
	{
		txt.getline(str, sizeof(str)); // получение строки из файла
		for (int x = 0; x <= columnsCount; x++) // запись сиволов из ограниченной области файла
			mass[y][x] = str[x];
	}
	txt.close(); // закрытие файла

	for (int r = 0; r < rowsCount; r++)//вывод массива типа char(шапки нашего меню) двойным циклом(по одному символу)
	{
		for (int c = 0; c < columnsCount; c++)
		{

			cout << mass[r][c];// вывод текущего символа на экран
		}

		cout << "\n        ";// отступ, табуляция
	}
	stand(5, positionOfShop, 7, "-->");
}

void pointToMenuShop()
{// подключение функции вывода шапки
		
		//Print(MainHero.rowsCount, MainHero.columnsCount,"Shop.txt");// подключение функции вывода шапки
		//Print( a, b, MainHero.positionOfMenu,  "Items.txt");
		display_draw(hat_Shop, 6,52);
		display_draw(Point_Shop, 9, 52);
		strelka(MainHero.positionOfMenu);
		printMeasure();		
}

void moveToMenuPoint(int a, int b,  char ** Massive, int y, char ** Massive2, int y2,int proverka)
{
	bool f = true; //логическая переменная, отвечающая за своевременный выход из цикла

	while (f == true){//цикл по логич переменной
		int code = _getch();//оствлеживание нажатой клавиши
		switch (code)//ее индефикация
		{
		case DOWN_ARROW:
			if (MainHero.positionOfMenu<b)//избежания выхода за границы
				MainHero.positionOfMenu++;//переменная для отслеживания перемещения(подсчет номер пункта меню) увеличение на 1 при единожды выполненном условии
			stand(0, 0);
			//system("cls");
			display_draw(Massive2, y2, 52);
			display_draw(Massive,y,52);	
			
			strelka(MainHero.positionOfMenu);

			break;

		case UP_ARROW:
			if (MainHero.positionOfMenu>a)//избежания выхода за границы
				MainHero.positionOfMenu--;//переменная для отслеживания перемещения(подсчет номер пункта меню) уменьшение на 1 при единожды выполненном условии
			stand(0, 0);
			//system("cls");
			
			display_draw(Massive2, y2, 52);
			display_draw(Massive, y,52);
			strelka(MainHero.positionOfMenu);
		
			break;

		case ENTER://выбор пункта, наведенного курсора
			if (proverka == 1){ userSelection(MainHero.positionOfMenu); }
			// передача параметра позиции в функцию выбора действия, заранее отведенного для пункта меню
			if (proverka == 2){ userSelection2(MainHero.positionOfMenu); }
			if (proverka == 3){ userSelectionShop(MainHero.positionOfMenu); }
			f = false;//прерывание цикла, выход из него
			break;

		case 8:
			system("cls");
			fout.close();
			inventory();
			
			f = false;
			break;

		case 32:
			system("cls");
			fout.close();
			matreein();			
			f = false;
			break;
		}
	}
}

void userSelectionShop(int Cur)
{
	stand(0, 0);
	int p = Cur;
	switch (Cur)
	{
	case 7:
		if (MainHero.Money - Shop[0].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[0].position;
			MainHero.Life = MainHero.Life + Shop[0].of;
			Inventory(p);
		}		
		pointToMenuShop();
		moveToMenuPoint(7, 14,Point_Shop, 9, hat_Shop,6,3);
		break;
	case 8:
		if (MainHero.Money - Shop[1].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[1].position;
			MainHero.Armor = MainHero.Armor + Shop[1].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 9:
		if (MainHero.Money - Shop[2].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[2].position;
			MainHero.Armor = MainHero.Armor + Shop[2].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 10:
		if (MainHero.Money - Shop[3].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[3].position;
			MainHero.Armor = MainHero.Armor + Shop[3].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 11:
		if (MainHero.Money - Shop[4].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[4].position;
			MainHero.Armor = MainHero.Armor + Shop[4].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 12:
		if (MainHero.Money - Shop[5].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[5].position;
			MainHero.Armor = MainHero.Armor + Shop[5].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 13:
		if (MainHero.Money - Shop[6].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[6].position;
			MainHero.Attack = MainHero.Attack + Shop[6].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 14:
		system("cls");
		if (MainHero.game == false)
		{
			pointToMenu();//в случае нажатия клавиши назад, новая перерисовка
			moveToMenuPoint(7, 9, Point_MainMenu, 4, hat_Skyline, 6, 1);
			fout.close();
		}
		break;
	}
}

void printMeasure()

{
	stand(58, 0, 7, "                        ");
	stand(58, 0, 7, MainHero.Life, " ОЖ");
	stand(64, 0, 7, MainHero.Armor, " ОЗ");
	stand(68, 0, 7, MainHero.Attack," ОА");
	stand(73, 0, 7, MainHero.Money," $");

}

void Inventory(int p)
{	
	switch (p)
	{
	case 7:	
		MainHero.inventory_items[5] = "зелье_лечения";
		break;
	case 8:		
		MainHero.inventory_items[7] = "шлем";
		break;
	case 9:		
		MainHero.inventory_items[4] = "броня";
		break;
	case 10:	
		MainHero.inventory_items[8] = "сапоги";
		break;
	case 11:
		MainHero.inventory_items[9] = "наручи";
		break;
	case 12:
		MainHero.inventory_items[10] = "щит";
		break;
	case 13:
		MainHero.inventory_items[3] = "меч";
		break;
	}		
}