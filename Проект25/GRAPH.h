#pragma once

#include <fstream> 
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <list>
#include "MainInventoryFunctions.h"
#include "RunFunctions.h"
#include "Skyline.h"
#include "Minigames.h"


using namespace std;

struct graph { int V; list<int> *adj; };
typedef graph *Graph;
typedef struct { int v; int w; int number; char *Choice; } Edge;

struct Node 
{ 
	char *Story; 
	int changeMoney;
	int changeLife;
	int changeArmor;
	int changeAttack;
};

void GRAPH();
Graph GRAPHinit(Graph G);
int GRAPHfilling(Edge *e);
void addEdge(Edge *e, Graph G);
int Add—hoice(Edge *e);
int AddStory(Node *n);
void Selection(Graph G, Edge *e, Node *n);
void endofgame();
void Showstory(Node *n, int *z);
void Showchoices(Graph G, Edge *e, int *listmass);
void CheckingInput(int *z);
int Changeherofill(Node *n);
void ChangeHero(Node *n);