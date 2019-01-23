#pragma once

#include "MainInventoryFunctions.h"

// структура для вызываемого меню инвентаря
struct inventory_menu
{
	// переменная, запоминающая номер действия
	int action;
	// переменная, запоминающая текст
	const char *text;
};


// функция, показывающая меню
int show_menu(const inventory_menu *m, int max_item);

// функция показа предметов, которые уже есть в инвентаре
void show_items();

// функция псевдосортировки (поиск по слову)
void find_items();

// функция использования предметов
void use_items();

// функия, производящая сюжетные изменения в игре (добавление в инвентарь сюжетных предметов)
void changes();