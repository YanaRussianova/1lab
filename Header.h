
#include <vector>
#include <iostream> 
#include <Windows.h>
#include <string>
#include <conio.h>
#include <cassert>
#include <stdio.h>
#include <iomanip> // для setw
#include <regex> 
#include <cstdlib>
#include <fstream> 
#include <time.h>
#pragma warning (disable:4996)
using namespace std;


class sklad {//будет из файла считываться
protected:
	char *naimen;//наименование товара
	int kol;//его кол-во ящиков
	double cost;//цена за ящик
	sklad *head, *tail, *next, *prev;
public:
	sklad();
	sklad(const sklad&ob);
	~sklad();
	friend ostream& operator << (ostream &, const sklad& );
	void setnaimen(char*);
	void setkol(int &);
	void setcost(double &);
	char *getnaimen();
	int getkol();
	double getcost();
	int schitat();////считываем список из файла
	void print();//вывод хранящегося в списке
	void del();//удаление товара
	void zapis();//перезапись файла с товарами
	int enter();//ввести новый товар
	void poly();//изменить данные склада
};

class dostavka {//из файла считывается
protected:
	char *firma;//название фирмы
	int Kcar;//число доступных машин
	double proc;//% за доставку
	double x;
	double y;
	dostavka *head, *tail, *next, *prev;
public:
	dostavka();
	dostavka(const dostavka&ob);
	~dostavka();
	friend ostream& operator << (ostream &, const dostavka&);
	void setfirma(char*);
	void setKcar(int &);
	void setcorrd(double &,double &,double &);
	char *getfirma();
	int getKcar();
	double getproc();
	double getx();
	double gety();
	void schitat();//считаем поставщиков из файла
	void schitat(int);//напичатать поставщиков
	int enter();//ввести нового
	void zapis();//перезаписать файл с ними
	void del();//удалить
};


class manager : virtual public sklad, virtual public dostavka
{
private:
	char* ysave;//код товара
	char* otpravka;//дата отгрузки
	manager *head, *tail, *next,*prev;
public:
	manager() :sklad(), dostavka() {
		head = NULL;
		tail = NULL;
		ysave = nullptr;
		otpravka = nullptr;
	}
	manager(const manager&ob);
	~manager();
	void read();//считываем заказы
	void forma();//оформить заказ
	void smenit();//изменить файл
	void zap();//перезаписать файл
	void print();//напичатать заказы
};

class password {
private:
	char * log;
	char * par;
	password *head, *tail, *next;
public:
	password() {
		head = NULL;
		tail = NULL;
		log = nullptr;
		par = nullptr;
	}
	password(const password&ob) {}
	~password();
	void proverka();//проверка на совпадение
	char *decript( char *);//шифровка
	char *encript(char *);//расшифровка
	void smena();//сменить пароль
	int admin();//считать из файла
};


template  <typename T>
class List {
	class Node {
		Node *next;
		Node *prev;
		T data;
		friend class List <T>;
	public:
		Node() : next(nullptr), prev(nullptr) {}
		~Node() {}
		Node(const T& d):data(d),prev(NULL),next(NULL){}
		T* getData() {
			return &data;
		}
	};
	Node *head;
	Node *tail;
	int length;
	List(const List&) { }
public:
	List();
	~List();
	int getLength();//длинна списка
	void add(const T&);//добавить объект
	T& at(int);//получить данные объекта
	void izmenit(const T&, int);//изменить объект
	void deleteN(int);//удалить склад
	void deleteD(int);//удалить поставщика
	void delal();//удалить весь склад
	void delal2();//удалить все заказы
	void display();//отобразить
};

