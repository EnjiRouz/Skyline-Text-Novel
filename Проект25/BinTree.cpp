
#include <iostream>
#include "Menu.h"
#include "Definitions.h"
#include <stack>
#include "Skyline.h"
using namespace std;

/*Узел двоичного дерева имеет данные, левый дочерний и правый дочерний */
struct node
{
	int data;
	struct node* left, *right;
};

/*Вспомогательная функция, которая выделяет новый узел для данных и
NULL для указателей слева и справа. */
struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

// Итеративный процесс для поиска элемента x в заданном двоичном дереве
bool iterativeSearch(node *root, int x)
{
	cout << "1. Зелье лечения. "<<endl;
	cout << "2. Шлем "<<endl;
	cout << "3. Броня "<<endl;
	cout << "4. Сапоги "<<endl;
	cout << "5. Наручи "<<endl;
	cout << "6. Щит "<<endl;
	cout << "7. Мечь "<<endl;
	cout << "Выберите необохдимый вам элемент: "<<endl;
	cin >> MainHero.x;
	// Base Case
	if (root == NULL)
		return false;

	// Создаем пустой стек и нажимаем добавляем в него  root
	stack<node *> nodeStack;
	nodeStack.push(root);

	// Итеративный обход предзаказа для поиска x
	while (nodeStack.empty() == false)
	{
		// См. Верхний элемент из стека и проверьте, совпадает ли он с x
		struct node *node = nodeStack.top();
		if (node->data == MainHero.x)
			return true;
		nodeStack.pop();

		// Направляем правый и левый дочерние элементы выталкиваемого узла в стек
		if (node->right)
			nodeStack.push(node->right);
		if (node->left)
			nodeStack.push(node->left);
	}

	return false;
}


int matreein()
{
	setlocale(LC_ALL, "Russian");
	int height = 0;
	struct node*NewRoot = NULL;
	struct node *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(7);
	root->right->left = newNode(5);
	if (!iterativeSearch(root, MainHero.x))
	{
		cout << "Not Found\n";
	}
	do
	{
		switch (MainHero.x)

		{
			char c;
			case 1:
			cout <<"Зелье лечения"<<endl;
			cout <<"Если хотите купить нажмите *"<<endl ;
			cin>> c;
			if ((c=='*')&&(MainHero.Money - Shop[0].position >= 0))
				{
				MainHero.Money = MainHero.Money - Shop[0].position;
					MainHero.Life = MainHero.Life + Shop[0].of;
					Inventory(MainHero.positionOfShop);
		        }
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, FOURTEEN, Point_Shop, 9, hat_Shop, 6, 3);
				break;
		case 2:
			cout << "Шлем" << endl;
			cout << "Если хотите купить нажмите *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[1].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[1].position;
				MainHero.Armor = MainHero.Armor + Shop[1].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6,1);

			break;
		case 3:
			cout << "Броня" << endl;
			cout << "Если хотите купить нажмите *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[2].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[2].position;
				MainHero.Armor = MainHero.Armor + Shop[2].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
		case 4:
			cout << "Сапоги" << endl;
			cout << "Если хотите купить нажмите *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[3].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[3].position;
				MainHero.Armor = MainHero.Armor + Shop[3].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
		case 5:
			cout << "Наручи" << endl;
			cout << "Если хотите купить нажмите *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[4].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[4].position;
				MainHero.Armor = MainHero.Armor + Shop[4].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
		case 6:
			cout << "Щит"<<endl;
			cout << "Если хотите купить нажмите *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[5].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[5].position;
				MainHero.Armor = MainHero.Armor + Shop[5].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
		case 7:
			cout << "Меч" << endl;
			cout << "Если хотите купить нажмите *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[6].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[6].position;
				MainHero.Attack = MainHero.Attack + Shop[6].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
			// сообщает об ошибке
		default:
			cerr << "Вы выбрали неверный вариант" << endl;
		}
		// при выборе 0 происходит выход
	} while ((MainHero.x != 0) & (MainHero.x>7)& (MainHero.x<0));
	return 0;
}
	
 

/*Функция возвращает значение true, если корень сбалансирован else false
Второй параметр - это высота дерева.
Вначале нам нужно передать указатель на ячейку со значением
Как 0. Мы можем также написать обертку над этой функцией */
bool isBalanced(struct node *root, int* height)
{
	/*Lh->Высота левого поддерева
		Rh->Высота правого поддерева */
	int lh = 0, rh = 0;

	/*L будет истинно, если левое поддерево сбалансировано
		И r будет истинно, если правое поддерево сбалансировано */
	int l = 0, r = 0;

	if (root == NULL)
	{
		*height = 0;
		return 1;
	}

	/*Получить высоты левого и правого поддеревьев в lh и rh
		И сохраните возвращаемые значения в l и r */
	l = isBalanced(root->left, &lh);
	r = isBalanced(root->right, &rh);

	/*Высота текущего узла - это максимальная высота левого и
		Правые поддеревья плюс 1 */
	*height = (lh > rh ? lh : rh) + 1;

	/*Если разница между высотами слева и справа
		Поддеревьев больше 2, тогда этот узел не сбалансирован
		Поэтому возвращаем 0 */
	if ((lh - rh >= 2) || (rh - lh >= 2))
		return 0;

	/*Если этот узел сбалансирован, а левое и правое поддеревья
		Уравновешиваются, а затем возвращают true */
	else return l&&r;
}