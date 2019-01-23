#include "Graph.h"

void GRAPH()
{
	Edge *e = new Edge[EDGES];						// выделяем память под массив структур типа Edge 
	Node *n = new Node[VERTEXNUM];					// выделяем память под массив структур типа Node
	Graph G = new graph;							//выделяем память под граф

	for (int fir = DEFAULT; fir < EDGES; fir++)		//перебираем ребра
	{
		e[fir].Choice = new char[LengthChoice];		//в каждой структуре массива структур выделяем память под массив типа char
	}
	for (int sec = DEFAULT; sec < VERTEXNUM; sec++)	//перебираем вершины
	{
		n[sec].Story = new char[LengthStory];		//в каждой структуре массива структур выделяем память под массив типа char длины 14
	}

	G = GRAPHinit(G);								//функция заполнения структуры графа 
	GRAPHfilling(e);								//функция заполнения исходящей и входящей вершин в ребре, посредством считывания из файла
	Changeherofill(n);
	addEdge(e, G);									//функция добавления списка исходящих ребер к каждой вершине 
	AddСhoice(e);									//функция заполнения массива текстом выбора на ребрах, посредством считывания из файла
	AddStory(n);									//функция заполнения массива текстом истории, посредством считывания из файла
	Selection(G, e, n);								//функция механизма выбора и вывода всей игры на экран

	//удаляем память, занятую под массивы 
	delete e;
	delete n;
	delete G;
	system("cls");
}


Graph GRAPHinit(Graph G)			//функция заполнения структуры графа
{
	G->V = VERTEXNUM;							//заносим в поле структуры V поступаемое кол-во вершин
	G->adj = new list<int>[VERTEXNUM];			//выделяем память по массив листов
	return G;
}

int GRAPHfilling(Edge *e)			//функция заполнения исходящей и входящей вершин в ребре, посредством считывания из файла
{
	ifstream Txtgraph;							//обьявляем переменную 
	Txtgraph.open("Txtgraph.txt");				//открываем файл для чтения
	if (Txtgraph.fail()) { return 1; }			//проверяем, открылся ли файл
	while (!Txtgraph.eof())						//считываем из файла, пока он не кончился
	{
		for (int i = 0; i <EDGES; i++)			//проходим цикл
		{
			Txtgraph >> e[i].v >> e[i].w>> e[i].number;		//считываем в поля структуры значения вершин из файла
		}
	}
	Txtgraph.close();							//закрываем используемый файл
	return 0;
}

int Changeherofill(Node *n)
{
	ifstream ChangeHero;							//обьявляем переменную 
	ChangeHero.open("ChangeHero.txt");				//открываем файл для чтения
	if (ChangeHero.fail()) { return 1; }			//проверяем, открылся ли файл
	while (!ChangeHero.eof())						//считываем из файла, пока он не кончился
	{
		for (int i = 0; i < VERTEXNUM; i++)			//проходим цикл
		{
			ChangeHero >> n[i].changeMoney >> n[i].changeLife >> n[i].changeArmor >> n[i].changeAttack;    //считываем в поля структуры значения вершин из файла
		}						
	}
	ChangeHero.close(); //закрываем используемый файл
	return 0;
}

void addEdge(Edge *e, Graph G)		//функция добавления списка исходящих ребер к каждой вершине 
{
	for (int i = 0; i<EDGES; i++)					//перебираем кол-во ребер 
		G->adj[e[i].v].push_back(e[i].number);			//пушим листы массива входящие вершины
}

int AddСhoice(Edge *e)				//функция заполнения массива текстом выбора на ребрах, посредством считывания из файла
{
	ifstream Сhoice;							//обьявляем переменную
	Сhoice.open("Choice.txt");					//открываем файл для чтения
	if (Сhoice.fail()) { return 1; }			//проверяем, открылся ли файл
	do
	{
		for (int i = 0; i < EDGES; i++)			//проходим цикл
		{
			Сhoice.getline(e[i].Choice, LengthChoice);	//записываем в наш массив строку из файла
		}
	} while (!Сhoice.eof());					//выполняем наш цикл, пока файл не кончился
	Сhoice.close();
	return 0;
}

int AddStory(Node *n) //функция заполнения массива текстом истории, посредством считывания из файла
{
	ifstream Story;								//обьявляем переменную
	Story.open("Story.txt");					//открываем файл для записи
	if (Story.fail()) { return 1; }				//проверяем, открылся ли файл

	for (int i = 0; i < VERTEXNUM; i++)			//проходим цикл
	{
		Story.getline(n[i].Story, LengthStory, ';');	//записываем в наш массив строку из файла
	}

	Story.close();								//закрытие файла 
	return 0;
}

void endofgame()
{
	cout << "\n\n\n\n\t\t\t" << "Конец игры\n";
	cout << "Авторы:\n";
	cout << "Студенты группы ФО-160001\n";
	cout << "Сивирухин Владислав\nБабичева Татьяна\nГлухих Олег\nЖуков Виктор\nГизатуллин Антон\n\n\n";
}
//убери брик
void Selection(Graph G, Edge *e, Node *n)
{
	int z = DEFAULT;
	int listmass[3] = { 0,0,0 };
	MainHero.game = true;
	while (MainHero.game)
	{
		system("cls");
		ChangeHero(n);
		printInterBlue();
		Showstory(n, &z);

		if ((G->adj[MainHero.location].size() == DEFAULT) || (MainHero.Life < DEFAULT))
		{
			MainHero.game = false;
			system("cls");
			endofgame();
			system("pause");
			break;//
		}

		Showchoices(G, e, listmass);
		printInterGreen();
		CheckingInput(&z);

		switch (z)
		{
		case 1: {MainHero.location = listmass[0]; break; }
		case 2: {if (listmass[1] != DEFAULT) MainHero.location = listmass[1]; break; }
		case 3: {if (listmass[2] != DEFAULT) MainHero.location = listmass[2]; break; }
		case 4: {system("cls"); pointToMenuShop(); moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3); break; }
		case 5: {inventory(); break; }
		case 6: {exit(); break; }
		default:{}
		}

		for (int j = 0; j < 3; j++)
		{
			listmass[j] = DEFAULT;
		}
		z = DEFAULT;
	}
}

void Showstory(Node *n, int *z) //функция, которая выводит текст вершины на экран
{
	if (n[MainHero.location].Story[1] != ' ') //если первый символ массива не пустой, тогда выводим текст вершины
	{
		cout << n[MainHero.location].Story; //выводим на экран текст
		cout << endl;
		_getch();
	}
	else skeletonKey(z); //если условие не выполняется, запускается игра

}

void Showchoices(Graph G, Edge *e, int *listmass) //функция, которая выводит выборы на экран 
{
	int j = 0;//переменная, для перебора элементов массива по индексам
	//цикл для перебора значений, хранящихся в листе вершины
	for (list<int>::iterator i = G->adj[MainHero.location].begin(); i != G->adj[MainHero.location].end(); i++, j++)
	{
		cout << "\t" << e[*i].Choice; //выводим один выбор на экран
		listmass[j] = e[*i].w; //записываем в ячейку массива значение из листа вершины 
	}
}

void CheckingInput(int *z) //функция для проверки корректности ввода
{
	if (*z == DEFAULT) //если z имеет дефолтное значение (0)
	{
		//цикл для отсеивания букв и чисел, не входящих в диапазон
		while (!(cin >> *z) || (cin.peek() != '\n') || (*z < 1) || (*z > 6))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Неправильный ввод, попробуйте снова" << endl;
		}
	}
}

void ChangeHero(Node *n)
{
	MainHero.Money = MainHero.Money + n[MainHero.location].changeMoney;
	MainHero.Life = MainHero.Life + n[MainHero.location].changeLife;
	MainHero.Armor = MainHero.Armor + n[MainHero.location].changeArmor;
	MainHero.Attack = MainHero.Attack + n[MainHero.location].changeAttack;

//	changes();
}