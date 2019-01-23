#include "Loading.h"
#include "Skyline.h"



void load_game()
{
	bool IsLoadingSuccessful;
	// открытие файла для чтения
	ifstream in3(SaveGameFileName);
	// проверка на наличие файла
	if (!in3)
	{
		// если файл не существует - переменная принимает значение false
		IsLoadingSuccessful = 0;
	}
	else
	{
		// чтение значений переменных из файла и запись их в массив
		for (int i = 0; i < 11; i++)
		{
			in3 >> MainHero.inventory_items[i];
			IsLoadingSuccessful = 1;
		}
		// закрытие файла
		in3.close();
	}
	
	// перевод значений в строках в числа целого типа
	MainHero.Money = atoi(MainHero.inventory_items[0].c_str());
	MainHero.Life = atoi(MainHero.inventory_items[1].c_str());
	MainHero.location = atoi(MainHero.inventory_items[2].c_str());
	
	system("pause");
}



// функция сохранения количества монет, здоровья, выборов игрока, инвентаря
void save()
{
	bool IsSavingSuccessful;
	// открытие файла для записи
	ofstream out0(SaveGameFileName);
	// проверка на наличие файла
	if (!out0)
	{
		// если файл не существует - переменная принимает значение false
		IsSavingSuccessful = 0;
	}
	else
	{
		// запись значений переменных в файл
		out0 << MainHero.Money << endl;;
		out0 << MainHero.Life << endl;;
		out0 << MainHero.location << endl;;

		// запись значений переменных в файл
		for (int i = 3; i < 11; i++)
		{
			out0 << MainHero.inventory_items[i]<< endl;
			IsSavingSuccessful = 1;
		}
		// закрытие файла
		out0.close();
	}
}


// функция создания новой игры
void new_game()
{
	bool IsLoadingNewGameSuccessful;
	// открытие файла для чтения
	ifstream in0(NewGameFileName);
	// проверка на наличие файла
	if (!in0)
	{
		// если файл не существует - переменная принимает значение false
		IsLoadingNewGameSuccessful = 0;
	}
	else
	{
		// чтение значений переменных из файла
		for (int i = 0; i < 11; i++)
		{
			in0 >> MainHero.inventory_items[i];
			IsLoadingNewGameSuccessful = 1;
		}
		// закрытие файла
		in0.close();
	}
	// перевод значений в строках в числа целого типа
	MainHero.Money = atoi(MainHero.inventory_items[0].c_str());
	MainHero.Life = atoi(MainHero.inventory_items[1].c_str());
	MainHero.location = atoi(MainHero.inventory_items[2].c_str());
	
}
