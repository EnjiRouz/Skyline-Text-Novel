#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <cstdio> 
#include <string>
#include <Windows.h>
#include "Menu.h"
#include "Definitions.h"
#include "MainInventoryFunctions.h"
#include "Skyline.h"

//void itemSortStructure(item *a, int min, int max, int kind);               //сортировка инвентаря
void printInterBlue();                                    //вывод синей линии интерфейса(количество монет и очков здоровья)
void printInterGreen();                                                    //вывод зелёной линии интерфейса(кнопки магазина и инвентаря)