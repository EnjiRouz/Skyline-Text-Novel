#include "Skyline.h"
#include "RunFunctions.h"
#include "Menu.h"
#include "Minigames.h"
#include "MainInventoryFunctions.h"

// главный алгоритм работы игры
int main()
{
	// включение русского языка
	setlocale(LC_ALL, "Russian");
	// вызов главного меню
	menu();
	// условие смерти игрока
	if (MainHero.Life <= 0)
	{
		// отчистка экрана
		system("cls");
		// оповещение о смерти игрока
		cout << "ВЫ УМЕРЛИ!!!" << endl;
	}
}

// функция выхода из игры
void exit()
{
	// отчистка экрана
	system("cls");
	// вопрос об уверенности игрока в желании  выйти из игры
	cout << "Вы действительно хотите выйти (+/-)?" << endl;
	// объявление и чтение переменной для выхода
	char a;
	cin >> a;
	// условие выхода
	if (a == '+')
	{
		// сохранение
		save();
		// прекращение работы программы
		exit(0);
	}
}
