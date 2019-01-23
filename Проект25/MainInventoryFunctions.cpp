#include "MainInventoryFunctions.h"


// главный алгоритм
int inventory()
{
	system("color 3");
	// внешний вид меню в инвентаре
	inventory_menu menu[] =
	{
		{ 1, "просмотреть содержимое" },
		{ 2, "поиск предметов" },
		{ 3, "использовать предмет"},
	};
	// установка русского языка для ввода-вывода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// чтение варианта
	int variant;
	do
	{
		// вызов меню
		variant = show_menu(menu, 3);
		switch (variant)
		{
			// показывает содержимое инвентаря
		case 1:
			cout << "\n" << "Содержимое:" << "\n" << endl;
			show_items();
			break;
			// производит поиск по инвентарю
		case 2:
			cout << endl;
			find_items();
			break;
			// позволяет использовать зелье здоровья
		case 3:
			cout << endl;
			use_items();
			break;
			// сообщает об ошибке
		default:
			cerr << "Вы выбрали неверный вариант" << endl;
		}
		// при выборе 0 происходит выход
	} while (variant != 0);
	system("cls");
	// выход в меню
	if (MainHero.game == false)
	{
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
	}
	// возврат значения
	return 0;
}

