#pragma once
#include <cstdlib>
#include "MainInventoryFunctions.h"

// функция загрузки количества монет, здоровья, выборов игрока (основана на массиве)
void load_game();

// функция сохранения количества монет, здоровья, выборов игрока
void save();

// функция создания новой игры
void new_game();