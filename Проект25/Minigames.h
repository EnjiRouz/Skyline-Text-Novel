#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Graph.h"

using namespace std;

void skeletonKey(int* res);//мини-игра "Отмычка"


void showMap(char** map, int y, int x);
void moveSK(char** map, int fix_y, int x, int y, int* res);
int ifUseSK(char** map, int y, int x);
void inputResult(int a, int* res);