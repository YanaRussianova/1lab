//Шилт 443
#include <iostream> 
#include <Windows.h>
#include <string>
#include <conio.h>
#include "Header.h"
#pragma warning (disable:4996)
using namespace std;
#include <time.h>
#include <ctime>

void gotoxy(int xpos, int ypos);
int pozicionirovanie(int n);
int menuad(sklad &, dostavka &, password &);

void gotoxy(int xpos, int ypos) { //помещает курсор текстового экрана в точку с координатами х,у
	COORD koord_simv; //структура, которая содержит координаты символьной клетки в консили
	HANDLE diskriptor = GetStdHandle(STD_OUTPUT_HANDLE); //получаем хендел консоли. Извлекает дескриптор устройства стандартного вывода
	koord_simv.X = xpos; koord_simv.Y = ypos; //задаются считанные координаты 
	SetConsoleCursorPosition(diskriptor, koord_simv); // устанавливает позицию курсора в заданном экранном буфере консоли
}

int pozicionirovanie(int n) { //функция позволяет шагать по консоли с помощью стрелок вверх и вниз
	char c = ' ';
	int state = 0;
	gotoxy(40, 5); //устанавливаем курсор на против первого пункта меню
	printf(">");
	while (c != 13) { //пока не нажмем Enter
		gotoxy(50, 20); //устанавливаем курсор за меню
		c = getch(); //считывает, какая клавиша нажата
		gotoxy(40, 5 + state);
		printf(" "); // чтоб закрыть значек >

		if (c == 72) state--; //если мы нажали стрелку вверх на клав-е
		if (c == 80) state++; //если мы нажали стрелку вниз на клав-е

		if (state < 0) state = n; // чтоб переходить по кругу в меню
		if (state > n) state = 0;

		gotoxy(40, 5 + state);
		printf(">");
		gotoxy(50, 20);
	}
	system("cls");
	return state;
}
sklad a;
dostavka b;
password ob;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	gotoxy(0, 0);
	int ad = 0;
	ob.proverka();	
	int trigger;
	trigger = a.schitat();
	if (trigger == 0) { a.enter();	a.zapis(); }
	b.schitat();
	while (true) {		
		system("cls");
		gotoxy(50, 4); printf("Меню:");
		gotoxy(42, 5); printf("Вход.");
		gotoxy(42, 6); printf("Выход.\n");
		switch (pozicionirovanie(1)) {		
		case 0:ob.proverka(); if (ob.admin() == 2) menuad(a,b,ob); break;
		case 1:ob.~password();b.~dostavka();a.~sklad();system("pause");  return 0;
		}
	}
	return 0;
}
int in = 0;
int menuad(sklad &a,dostavka &b,password &ob) {
	manager m,m1;
	
	while (true) {
		system("cls");
		gotoxy(42, 5); printf("Просмотр товаров");
		gotoxy(42, 6); printf("Удалить товар");
		gotoxy(42, 7); printf("Добавить товар");
		gotoxy(42, 8); printf("Просмотр поставщиков");
		gotoxy(42, 9); printf("Удалить поставщика");
		gotoxy(42, 10); printf("Добавить поставщика");
		gotoxy(42, 11); printf("Сменить логин и пароль");
		gotoxy(42, 12); printf("Изменить список склада");
		gotoxy(42, 13); printf("Выход.\n");
		switch (pozicionirovanie(8)) {
		case 0: a.print(); system("pause"); break;
		case 1: a.del(); a.zapis();break;
		case 2: a.enter(); a.zapis(); break;
		case 3: b.schitat(1); system("pause"); break;
		case 4: b.del(); b.zapis(); break;
		case 5: b.enter(); b.zapis(); break;
		case 6: ob.smena(); break;
		case 7: a.poly(); a.zapis(); break;
		case 8:m.~manager();m1.~manager(); return 0;
		}
	}
}

