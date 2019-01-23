#pragma once//используется для избежания бесконечной рекурсии

#include "Menu.h"//подключение директив предпроцессора(библиотек)
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h> 
#include <string> 
#include <fstream>
#include "Definitions.h"
#include "MainInventoryFunctions.h"
#include "Skyline.h"
#include "Minigames.h"
#include "GRAPH.h"

using namespace std;
char**  hat_Skyline = textures(6, 52, "Skyline.txt");
char**  hat_Shop = textures(6, 52, "Shop.txt");
char**  Point_Shop = textures(9, 52, "Items.txt");
char**  Point_MainMenu = textures(4, 52, "MainMenu.txt");
char**  Point_StartGame = textures(5, 52, "StartGame.txt");

item Shop[SEVEN] = { { LifePosion, 50, 1 }, { helmet, 100, 10 }, { armor, 200, 10 }, { boots, 300,10 }, 
{ shield,1000, 10 },{ sword, 10, 10 }, { manacles, 99, 10 } };


void pointToMenu()
{
	MainHero.positionOfMenu =SEVEN;

	display_draw(hat_Skyline, 6,52);
	display_draw(Point_MainMenu, 4,52);
	strelka(MainHero.positionOfMenu);
}
void pointToMenu2()
{
	MainHero.positionOfMenu = SEVEN;
	
	display_draw(hat_Skyline, 6, 52);
	display_draw(Point_StartGame, 5, 52);
	strelka(MainHero.positionOfMenu);
	
}

// присоединять свои функции только в функциях userSelection2 и userSelection3, вместо соответствующих текстовых сообщений
void userSelection(int Cur)
{
	system("cls");//очистка экрана
	switch (Cur)
	{	
	case 7:pointToMenu2();//вывод пунктов (Начать игру)
		moveToMenuPoint(SEVEN, FOURTEEN,Point_StartGame, 5,hat_Skyline,6,2);//запуск цикла перемешения по меню, а так же его перерисовки
		break;
	case 8:pointToMenuShop();//вывод пунктов 
		moveToMenuPoint(SEVEN, FOURTEEN, Point_Shop, 9, hat_Shop,6,3);//запуск цикла перемешения по меню, а так же его перерисовки
		break;	
	}
}                                                                               
void userSelection2(int Cur)
{
	system("cls");//очистка экрана
	switch (Cur)
	{

	case 7: cout << "Инструкция"<<endl;// возврат в меню после вывода тексов рекорда
		cout << "Для возврата в меню нажмите любую клавишу";
		_getch();// ожидание нажатия клавиши
		system("cls");// очитска экрана
		pointToMenu2();// перерисовка пунктов
		moveToMenuPoint(SEVEN, FOURTEEN,Point_StartGame, 5, hat_Skyline, 6,2); // новый вызов цикла перемещения
		break;
	case 8: cout <<"Начать игру сначала"<<endl;
		new_game();
		system("cls");// очистка экрана
		GRAPH();
		pointToMenu2();// перерисовка пунктов
		moveToMenuPoint(SEVEN, FOURTEEN, Point_StartGame, 5, hat_Skyline, 6, 2);
		break;
	case 9: cout << "Продолжить игру"<<endl;
		load_game();
		system("cls");// очитска экрана
		GRAPH();
		pointToMenu2();// перерисовка пунктов
		moveToMenuPoint(SEVEN, FOURTEEN, Point_StartGame, 5, hat_Skyline, 6, 2);
		break;
	case 10:
		pointToMenu();//в случае нажатия клавиши назад, новая перерисовка
		moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);
		break;
	}
}

void menu()
{

	system("color 3");
	setlocale(LC_ALL, "RUS");//поддержка кодировки русского языка
	pointToMenu();
	moveToMenuPoint(SEVEN, NINE,Point_MainMenu, 4, hat_Skyline, 6,1);
	


}


char** textures(int masy, int masx, const  char* fillname) // Функция инициализирует динамический массив под текстуры
{
	
	char **mass = new char*[masy]; // Выделение динамической памяти под двумерный массив
	for (int i = 0; i < masy; i++)
		mass[i] = new char[masx];

	file_scan(mass, masx, masy, fillname); // Вызываем функцию, которая заполнит массив символами из файла

	char** mas = mass;
	return mas; // Возввращает указатель натпервый элемент
}
	
void strelka(int position)
{
	stand(4, MainHero.positionOfMenu,7, "-->");
}

void display_draw(char ** Massive,int Massive_Y, int Massive_X) // Функция - вырисовка массивов в консоль
{
	system("color 3");
	for (int r = 0; r < Massive_Y; r++)//вывод массива типа char(шапки нашего меню) двойным циклом(по одному символу)
	{
		for (int c = 0; c < Massive_X; c++)
		{

			cout << Massive[r][c];// вывод текущего символа на экран
		}

		cout << "\n        ";// отступ, табуляция
	}

}

void file_scan(char **mas, int masx, int masy, const char*filename ) // Заполнение массива символами из файла
{
	system("color 3");
	char* str = new char[masx + 1];
	ifstream txt(filename); // открытие файла
	for (int y = 0; y < masy; y++) // цикл записывающий массив строки из файла
	{
		txt.getline(str, sizeof(char)*(masx + 1)); // получение строки из файла
		for (int x = 0; x <= masx; x++) // запись сиволов из ограниченной области файла
			mas[y][x] = str[x];
	}
	txt.close(); // закрытие файла
	
	
	
}
