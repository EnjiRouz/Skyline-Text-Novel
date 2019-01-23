#pragma once

#include <iostream>
#include <fstream>
#include <cstdio> 
#include <cstdlib>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "Menu.h"
#include "Definitions.h"
#include "Inventory.h"
#include "Loading.h"
#include "GRAPH.h"


using namespace std;

//Путь к файлу сохранения/загрузки
#define SaveGameFileName "Save1.txt"

//Путь к файлу создания новой игры
#define NewGameFileName "New.txt"

// главный алгоритм инвентаря
int inventory();
// главный алгоритм магазина
void menu();