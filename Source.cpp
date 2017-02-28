#include "Header.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include<cassert>
#include <iomanip> // для setw
#pragma warning (disable:4996)
FILE *f;
FILE *d;
FILE *p;
using namespace std;

char *stroka() {  ////ввод строки со **
	char *s=new char[20];
	char c;
	int i = 0,k=0;
	i = 0;
	fflush(stdin);
	while ((c = getch()) !=13 && i<19) {
		if (c == 8 && i > 0) {
			printf("\b \b");
			i--;
		}		
		else {
			cout << "*";
			s[i] = c;
			i++;
		}
	}
	s[i] = '\0';
	return s;
}

char *stroka1() {
	string buff;
	getline(cin, buff);
	if (buff.length() == 0) { getline(cin, buff); }
	char * a = new char[buff.length()];
	strcpy(a, buff.c_str());
	buff.clear();
	return a;
}
char *stroka2() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int Year = ltm->tm_year - 100;
	int Month = 1 + ltm->tm_mon;
	int Day = ltm->tm_mday;
	int i=0 ,j=0,num=0,num1=0,k=0,s=0;
	char *b=new char[3];
	string buff;
	while (s == 0) {		
		getline(cin, buff);
		if (buff.length() == 0) { getline(cin, buff); }
		i = 6; j = 0; k = 0;
		if (buff.size() != 8) k++;
		else {
			for (i; i < 8; i++) {
				b[j] = buff[i]; j++;
			}
			b[j] = '\0';
			num1 = atoi(b);
			if (num1 < Year)
				k++;
			i = 0; j = 0;
			if (buff[i] != '0') {
				for (i; i < 2; i++) {
					b[j] = buff[i]; j++;
				}
			}
			else b[j] = buff[i + 1]; j++;
			b[j] = '\0';
			num = atoi(b);
			if ((num < Day && num1 == Year) || num > 31)
				k++;
			i = 3; j = 0;
			if (buff[i] != '0') {
				for (i; i < 5; i++) {
					b[j] = buff[i]; j++;
				}
			}
			else b[j] = buff[i + 1]; j++;
			b[j] = '\0';
			num = atoi(b);
			if ((num < Month && num1 == Year) || num >= 13)
				k++;
		}
		if (k != 0) { cout << "неверный ввод надо 01.01.17 "<<endl; 
		s = 0;
		buff.clear();
		system("pause");
		system("cls");
		cout << "Дата   ";
		}
		else s = 1;
	}	
	char * a = new char[buff.length()];
		strcpy(a, buff.c_str());
		buff.clear();
		return a;	
}
 
int chislo() {
	string s;
	int n = 0, k = 0;
	regex str("([0-9])+");	
		try {
			getline(cin, s);
			if (s.length() == 0) { getline(cin, s); }
			if (!regex_match(s, str)) throw "неверно,введите целое число ";
	n = atoi(s.c_str());
	s.clear();
	return n;
		}
		catch (char *a) {
			cout << a << endl;
			s.clear();
			return -1;
		}	
	}
		
	
	

double dobl() {
	string s;
	int  k = 0;
	double n = 0;
	regex str("([0-9\.])+" );
	try {
		getline(cin, s);
		if (s.length() == 0) { getline(cin, s); }
		if (!regex_match(s, str)) throw "неверно,пример 3.4";
		n = atoi(s.c_str());
		s.clear();
		return n;
	}
	catch (char *a) {
		cout << a << endl;
		s.clear();
		return 0;
	}	
}
////////////////////////////////////////////////////////////////////
typedef List<sklad> L;
L l;
typedef List<dostavka> D;
D dos;

template<class T>
List<T>::List() {
	head = NULL;
	tail = NULL;
	length = 0;
}
template<class T>
List<T>::~List() {
	while (head != NULL) {
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
}
template<class T>
int List<T>::getLength() {
	return length;
}

template <class T>
void List<T>::add(const T& data)
{
	Node *n = new Node(data);		// создаем отдельный узел
	// Если список пуст, то
	n->next = NULL;
	if (head == NULL) {
		// связываем последний узел с новым;
		head = n;
		n->prev = NULL;
		
	}	
	else{
		Node *dop = tail;
		dop->next = n;		
	n->prev = dop;
	}
 tail = n;
length++;
}

template <class T>
T& List<T>::at(int index) {
	Node *current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->data;
}


template<class T>
void List<T>::display() {
	for (int i = 0; i < getLength(); i++) {
		//cout <<"№ "<< i + 1 << endl;
		cout << at(i)<<endl<<endl;
	}
}
template<class T>
void List<T>::deleteN(int a) {
	Node *cur = head,*pred;
	int len = l.getLength();
	if (a > len ) { cout << "Неверный ввод "; system("pause"); }
	else {
		for (int i = 0; i < a - 1; i++) {
			cur = cur->next;
			
		}
		if (a == len) {    //если эл-т последний
			pred = cur->prev;
			pred->next = NULL;
		}
		else if (a == 1) {      //если эл-т первый
			pred = cur->next;
			pred->prev = NULL;
			head = head->next;
		}
		else {
			pred = cur->prev;
			pred->next = cur->next;
			cur->next->prev = pred;
		}
		delete cur,pred;/////
		
		length--;
	}
}


template<class T>
void List<T>::izmenit(const T& data,int a) {/////////////////////////////
	Node *n = new Node(data);
	Node *cur = head, *pred;
	int b = l.getLength();
	for (int i = 0; i < a; i++) {
		cur = cur->next;
	}
	if (a == 0) {
		head = n;
		head->prev = NULL;
		head->next = cur->next;
		cur->next->prev = head;
	}
	else if (a == b-1) {
		cur->prev->next = n;
		n->next = NULL;
		n->prev = cur->prev;
	}
	else if (a == 1) {
		head->next = n;
		n->prev = head;
		n->next = cur->next;
		cur->next->prev = n;
	}
	else {
		pred = cur->prev;
		pred->next = n;
		n->prev = pred;
		n->next = cur->next;
		cur->next->prev = n;
	}
	delete cur, pred;
}


template<class T>
void List<T>::deleteD(int a) {
	Node *cur = head, *pred;
	int len = dos.getLength();
	if (a > len ) { cout << "Неверный ввод "; system("pause"); }
	else {
		for (int i = 0; i < a - 1; i++) {
			cur = cur->next;
		}
		if (a == len) {    //если эл-т последний
			pred = cur->prev;
			pred->next = NULL;
		}
		else if (a == 1) {      //если эл-т первый
			pred = cur->next;
			pred->prev = NULL;
			head = head->next;
		}
		else {
			pred = cur->prev;
			pred->next = cur->next;
			cur->next->prev = pred;
		}
		delete cur;
		length--;
	}
}
template<class T>
void List<T>::delal() {	
		Node *cur = head;
		int a = l.getLength();
		for (int i = 0; i < a - 1; i++) {
			cur = head;
			head = head->next;
			delete cur;
			length--;
		}
		head = NULL;
		length = 0;	
}

template<class T>
void List<T>::delal2() {
	Node *cu = head;
	int a = us.getLength();
	for (int i = 0; i < a - 1; i++) {
		if (a != 1) {			
			cu = head;
			head = head->next;
			delete cu;
			length--;
		}
	}
	head = NULL;
	length = 0;
}

//////////////////////////////////////////////////////////////////////////////////
sklad s;

sklad::sklad() {
	head = NULL;
	tail = NULL;
	naimen = nullptr;
	kol = 0;
	cost = 0;
}
sklad::sklad(const sklad&ob) {
	naimen = new char[strlen(ob.naimen) + 1];
	strcpy(naimen, ob.naimen);
	kol = ob.kol;
	cost = ob.cost;
}
sklad::~sklad() {
	delete[] naimen;
	kol = 0;
	cost = 0;
	while (head != NULL) {
		sklad *tmp = head->next;
		delete head;
		head = tmp;
		cout << "Work" << endl;
	}
}
void sklad::del() {
	int a;
	cout << "Какой товар удалить?  ";
	cin >> a;
	l.deleteN(a);
}
void sklad::poly() {//изменение товара
	int a = l.getLength(), num = 0, i;
	int  KOL = 0,k=0;
	cout << "Какой товар изменить" << endl;
	char *na = stroka1();	
	for (i = 0; i < a; i++) {
		if (strcmp(l.at(i).getnaimen(), na) == 0) { 
			num = i; k++; break;
		}
	}
	if(k==0 ) cout << "Нет такого товара "<<endl;
	else {
		k = 0; 
		while (k == 0) {
			cout << "Введите новое количество   ";
			a = chislo();
			if (a >= 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			else system("cls");
		}
		KOL = a;		
		s.setnaimen(l.at(num).getnaimen());
		s.setkol(KOL);
		k = 0;
		double d;
		while (k == 0) {
			cout << "Введите новую цену ";
			d = dobl();
			if (d != 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			else { system("pause"); system("cls"); }
		}		 
		s.setcost(d);
		l.izmenit(s, num);
	}
	system("pause");
}

ostream& operator << (ostream& os, const sklad &l) {           //перегрузка оператора вывода
	printf("%10s  |%8d|  %3.2f  \n", l.naimen , l.kol , l.cost );
	return os;
}
void sklad::setnaimen(char *a) {
	naimen = a;
}
void sklad::setkol(int &a) {
	kol = a;
}
void sklad::setcost(double &a) {
	cost = a;
}

int sklad::enter() {
	int  i = 0, k = 0,a;
	a = l.getLength();
	cout << "Введите товар  ";
	char *na = stroka1();
	while (i < a && k == 0) {
		if (strcmp(l.at(i).getnaimen(), na) == 0)
			k++;
		else i++;
	}
	if (k != 0) {cout << "такой товар уже есть " << endl;
	system("pause");
     }
	else {
		s.setnaimen(na);
		k = 0;
		while (k == 0) {
			cout << "Введите количество товара ";
			a = chislo();
			if (a >= 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		}
		s.setkol(a);
		k = 0;
		double b;
		while (k == 0) {
			cout << "Введите новую цену ";
			b = dobl();
			if (b != 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			else { system("pause"); system("cls"); }
		}
		s.setcost(b);
		l.add(s);
	}
	return 0;
}
int sklad::schitat() {
	l.delal();
	fopen_s(&f, "sklad.txt", "r");
	try {                              ////????????????????????????????????????????????????????????????
		if (f == NULL) throw "Создайте список склада";
		while (feof(f) == 0) {
		char *na = new char[50];
		char *k = new char[20];
		char *c = new char[20];
		fscanf(f, "%s\n%s\n%s\n", na, k, c);	
		s.setnaimen(na);
		int a = atoi(k);
		s.setkol(a);
		double b = atof(c);
		s.setcost(b);
		l.add(s);
		s.~sklad();       /////****
	}
	fclose(f);
	return 1;
	}
	catch(char* a){
		cout << a;
		system("pause");
		return 0;
	}                                   ////????????????????????????????????????????????????????????????
	
}
void sklad::print() {
	cout << "   Товар    | Кол-во | Цена за 1 ящик" << endl;
	cout << "_____________________________________" << endl;
	l.display();
}
void sklad::zapis() {
	ofstream f("sklad.txt", ios_base::out);
	int a = l.getLength();
	try {                             ////????????????????????????????????????????????????????????????
		for (int i = 0; i < a; i++) {
			if (i == a - 1) throw 1;
			else {
				f << l.at(i).getnaimen() << endl;
				f << l.at(i).getkol() << endl;
				f << l.at(i).getcost() << endl;
				f << "\n";
			}
		}
	}
	catch(int i){
				f << l.at(i).getnaimen() << endl;
				f << l.at(i).getkol() << endl;
				f << l.at(i).getcost() << endl;
			}
	f.close();
}

char *sklad::getnaimen() {
	return naimen;
}
int sklad::getkol() {
	return kol;
}
double sklad::getcost() {
	return cost;
}
//////////////////////////////////////////////////////////////////////
dostavka::dostavka() {
	head = NULL;
	tail = NULL;
	firma = nullptr;
	Kcar = 0;
	proc = 0.0;
	x = 0.0;
	y = 0.0;
}
dostavka::dostavka(const dostavka&ob) {
	firma = new char[strlen(ob.firma) + 1];
	strcpy(firma, ob.firma);
	Kcar = ob.Kcar;
	proc = ob.proc;
	x = ob.x;
	y = ob.y;
}
dostavka::~dostavka() {
	delete[] firma;
	Kcar = 0;
	proc = 0;
	x = 0;
	y = 0;
	while (head != NULL) {
		dostavka *tmp = head->next;
		delete head;
		head = tmp;
	}
	cout << "dd";
}
ostream& operator << (ostream& os, const dostavka &l) {
	printf("%15s |%13d | %3.2f | %3.1f  %3.1f\n", l.firma, l.Kcar, l.proc, l.x, l.y);
	return os;
}
char *dostavka::getfirma(){
	return firma;
}
int dostavka::getKcar(){
	return Kcar;
}
double dostavka::getproc(){
	return proc;
}
double dostavka::getx(){
	return x;
}
double dostavka::gety(){
	return y;
}

void dostavka::setfirma(char *a) {
	firma = a;
}
void dostavka::setKcar(int &a) {
	Kcar = a;
}
void dostavka::setcorrd(double &a,double &b,double &c) {
	proc = a;
	x = b;
	y = c;
}
dostavka dost;
void dostavka::schitat() {
	ifstream file("dost.txt", ios_base::in);
	while (file.eof() == 0) {		
		char *fi = new char[50];
		char *k = new char[10];
		char *c = new char[10];
		char *x = new char[10];
		char *y = new char[10];
		char *nu = new char[1];
		file.getline(fi, 50);
		file.getline(k, 10);
		file.getline(c, 10);
		file.getline(x, 10);
		file.getline(y, 10);
		file.getline(nu, 1);
		dost.setfirma(fi);
		int m = atoi(k);
		dost.setKcar(m);
		double p = atof(c);
		double x1 = atof(x);
		double y1 = atof(y);
		dost.setcorrd(p,x1,y1);
		dos.add(dost);
		dost.~dostavka();       /////****
	}
	file.close();
}
void dostavka::schitat(int a) {
	cout << "  Организация   | Кол-во машин |  %   | Координаты" << endl;
	cout << "__________________________________________________" << endl;
	dos.display();
}
int dostavka::enter() {
	cout << "Введите поставщика  ";
	char *na = stroka1();
	dost.setfirma(na);
	int k = 0,a=0;
	while (k == 0) {
		cout << "Введите количество машин ";
		a = chislo();
		if (a >= 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	}	
	dost.setKcar(a);
	k = 0;
	double p,x1,y1;
	while (k == 0) {
		cout << "Введите процент ";
		p = dobl();
		if (p != 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		else { system("pause"); system("cls"); }
	}
	k = 0;
	while (k == 0) {
		cout << "Введите координаты х и у";
		x1 = dobl();
		y1= dobl();
		if (x1 != 0 && y1!=0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		else { system("pause"); system("cls"); }
	}
	dost.setcorrd(p,x1,y1);
	dos.add(dost);
	return 0;
}
void dostavka::zapis() {
	//ofstream f("dost.txt", ios_base::trunc);
	std::fstream f;
	f.exceptions(ios::badbit | ios::failbit);
	try                                         ///////////////////????????????????????????????????
	{
		f.open("dost.txt", ios::out);
		int a = dos.getLength();
		for (int i = 0; i < a; i++) {
			if (i == a - 1) {
				f << dos.at(i).getfirma() << endl;
				f << dos.at(i).getKcar() << endl;
				f << dos.at(i).getproc() << endl;
				f << dos.at(i).getx() << endl;
				f << dos.at(i).gety() << endl;
			}
			else {
				f << dos.at(i).getfirma() << endl;
				f << dos.at(i).getKcar() << endl;
				f << dos.at(i).getproc() << endl;
				f << dos.at(i).getx() << endl;
				f << dos.at(i).gety() << endl;
				f << "\n";
			}
		}
		f.close();
	}
	catch (ios::failure &e)
	{
		cout << "File opening error: " << e.what() << endl;
		system("pause");
	}	
}

void dostavka::del() {
	int a;
	cout << "Какого поставщика удалить?  ";
	cin >> a;
	dos.deleteD(a);
}
/////////////////////////////////////////////////////////////////////

manager::manager(const manager&ob) :sklad(ob), dostavka(ob) {
	ysave = new char[strlen(ob.ysave) + 1];
	strcpy(ysave, ob.ysave);
	otpravka = new char[strlen(ob.otpravka) + 1];
	strcpy(otpravka, ob.otpravka);
}
manager::~manager() {
	delete[] ysave;
	delete[] otpravka;
	while (head != NULL) {
		manager *tmp = head->next;
		delete head;
		head = tmp;
	}
	cout << "mm";
}
void manager::forma() {
	
	ifstream file("zakaz.txt", ios_base::in);
	if (!file.is_open()) // если файл не открыт
		cout << "Нет заказов\n";
	else {
		while (file.eof() == 0) {
			char *fi = new char[20];
			char *k = new char[6];
			char *c = new char[6];
			char *d = new char[6];
			char *nu = new char[2];
			fi[0] = '\0';
			k[0] = '\0';
			c[0] = '\0';
			d[0] = '\0';
			file.getline(fi, 20);
			file.getline(k, 6);
			file.getline(c, 6);
			file.getline(d, 6);
			file.getline(nu, 2);
			int a = atoi(k);
			double x = atof(c);
			double y = atof(d);
			double Cost = 0;
			int len = l.getLength(), i = 0, r = 0;
			while (i < len && r == 0) {
				if (strcmp(l.at(i).getnaimen(), fi) == 0) {
					Cost = l.at(i).getcost();
					r++;
				}
				else i++;
			}
			int pos = dos.getLength(), zap = 0;
			i = 0;
			double min = sqrt(pow(dos.at(0).getx() - x, 2) + pow(dos.at(0).gety() - y, 2));
			while (i < pos) {
				if (sqrt(pow(dos.at(i).getx() - x, 2) + pow(dos.at(i).gety() - y, 2)) < min) {
					min = sqrt(pow(dos.at(i).getx() - x, 2) + pow(dos.at(i).gety() - y, 2));
					zap = i;
					i++;
				}
				else i++;
			}
			char *den, *Kod;
			cout << "Введите день отгрузки  ";
			den = stroka2();
			cout << "Введите код товара  ";
			Kod = stroka1();
			char *str = new char[3];
			ifstream fl("forma.txt", ios_base::in);
			fl.getline(str, 3);
			fl.getline(str, 3);
			fl.close();
			ofstream f("forma.txt", ios_base::app); 
			if (strcmp(str, "") == 0) {
				f <<"\n"<< fi << "\n"; f << k << "\n"; f << c << "\n"; f << d << "\n";
				f << Cost << "\n"; f << dos.at(zap).getfirma() << "\n";
				f << den << "\n"; f << Kod;
				f.close();
			}
			else {
				f <<"\n"<<fi << "\n"; f << k << "\n"; f << c << "\n"; f << d << "\n";
				f << Cost << "\n"; f << dos.at(zap).getfirma() << "\n";
				f << den << "\n"; f << Kod ;
				f.close();

			}
		}
		file.close();
		remove("zakaz.txt");
	}
} 

void manager::read() {
	head = NULL;
	ifstream fi("forma.txt", ios_base::in);
	if (!fi.is_open()) cout << "Еще нет оформленных заказов " << endl;
	else {
		char *nu = new char[2];
		fi.getline(nu, 2);
		while (fi.eof() == 0) {
			manager *m = new manager;
			char *a = new char[15];
			char *b = new char[6];
			char *c = new char[6];
			char *d = new char[6];
			char *e = new char[6];
			char *f = new char[15];
			char *k = new char[15];
			char *l = new char[8];			
			fi.getline(a, 15);
			fi.getline(b, 6);
			fi.getline(c, 6);
			fi.getline(d, 6);
			fi.getline(e, 6);
			fi.getline(f, 15);
			fi.getline(k, 15);
			fi.getline(l, 8);
			m->naimen = new char[strlen(a) + 1]; m->naimen = a;
			int g = atoi(b);	m->kol = g;
			double h = atof(c); m->x = h;
			h = atof(d); m->y = h;
			h = atof(e); m->cost = h;
			m->firma = new char[strlen(f) + 1]; m->firma = f;
			m->otpravka = new char[strlen(k) + 1]; m->otpravka = k;
			m->ysave = new char[strlen(l) + 1]; m->ysave = l;
			m->next = NULL;
			if (head == NULL) {
				head = m;
				m->prev = NULL;
			}
			else {
				manager *dop = tail;
				dop->next = m;
				m->prev = dop;
			}
			tail = m;
		}
		/**/
		fi.close();
	}
}
void manager::print() {
	manager *u = head;
	while (u != NULL) {
		cout <<"Товар      | "<< u->naimen <<endl<<"Количество | "<< u->kol<<endl;
		cout <<"Координаты | " << u->x <<  "  " << u->y << endl;
		cout <<"Цена       | " << u->cost << endl;
		cout <<"Поставщик  | " << u->firma << endl << "Дата       | " << u->otpravka << endl;
		cout <<"Код        | " << u->ysave << endl<<endl;
		u = u->next;
	}
	system("pause");
}

void manager::smenit() {
	int num = 0,kol=0;
	ifstream fi("forma.txt", ios_base::in);
	if (!fi.is_open()) int a = 0;
	else {
		ifstream f("otmena.txt", ios_base::in);
		if (!f.is_open()) cout << "Нет заказов на отмену " << endl;
		else {
			while (f.eof() == 0) {
				char *fi = new char[6];
				char *k = new char[6];
				fi[0] = '\0';
				k[0] = '\0';
				f.getline(fi, 6);
				f.getline(k, 6);
				double a = atof(fi);
				double b = atof(k);
				manager *t = head,*pred;
				while (t != NULL&& kol==0) {
					if (t->x == a && t->y == b) {
						if (num == 0) {
							if(t->next==NULL){
								head = NULL;
							}
							else {
								pred = t->next;
								pred->prev = NULL;
								head = head->next;
							}
					}
						else if (t->next==NULL) {
							pred = t->prev;
							pred->next = NULL;
						}
						else {
							pred = t->prev;
							pred->next = t->next;
							t->next->prev = pred;
						}
						kol++;
						delete t;
					}
					else { num++; t = t->next; }
				}
			}
          
		}		
	}
	remove("otmena.txt");
	system("pause");
}
void manager::zap() {
	manager *n = head;
	ofstream f("forma.txt", ios_base::out);
	while (n != NULL) {
		if (n->next == NULL) {
			f <<"\n"<< n->naimen<<"\n"; f << n->kol << "\n";
			f << n->x << "\n"; f << n->y << "\n";
			f << n->cost << "\n"; f << n->firma << "\n";
			f << n->otpravka << "\n"; f << n->ysave;
		}
		else {
			f<<"\n" << n->naimen << "\n"; f << n->kol << "\n";
			f << n->x << "\n"; f << n->y << "\n";
			f << n->cost << "\n"; f << n->firma << "\n";
			f << n->otpravka << "\n"; f << n->ysave;
		}
		n = n->next;
	}
}



///////////////////////////////////////////////////////////////


password::~password() {
	delete[]log;
	delete[] par;
	while (head != NULL) {
		password *tmp = head->next;
		delete head;
		head = tmp;
	}
	cout << "kk";
}

void password::proverka() {
	head = NULL;
	fopen_s(&p, "admin.txt", "r");
	while (feof(p) == 0) {
		password *s = new password;
		char *lo = new char[30];
		char *pa = new char[30];
		fscanf(p, "%s\n%s\n", lo, pa);
		decript(lo);
		s->log = new char[strlen(lo) + 1];
		s->log = lo;
		decript(pa);
		s->par = new char[strlen(pa) + 1];
		s->par = pa;
		s->next = NULL;
		if (head == NULL) {
			head = s;
		}
		else tail->next = s;
		tail = s;
	}
	fclose(p);
}
char  *password :: decript(char *a) {    ////расшифровка
	int i ,j=0,dl;
	char zam;
	int k = strlen(a);
	if(k%2==1) dl= k / 2+1;
	else dl = k / 2;
	for (i = 0; i < k; ) {
		j = i;
		zam = a[j];
		a[j] = a[j + 2];
		a[j + 2] = zam;
		zam = a[j + 1];
		a[j + 1]= a[j + 2];
		a[j + 2] = zam;
		i=i + 3;
	}	
	for (i = 0; i < k/2; i++)
	{
		zam = a[i];
		a[i] = a[i+ dl];
		a[i+ dl] = zam;
	}
	try {
		if (a[strlen(a) - 1] == 'A') throw 1;
		else if (a[strlen(a) - 1] == 'F') a[strlen(a) - 1] = '\0';
	}
	catch (int i) {
		a[strlen(a) - 2] = '\0';
	}
	return a;
}

char *password::encript(char *a) {       ////зашифровка
	int k = strlen(a),i,j,dl;
	char zam;
	if (k % 3 == 1)  strcat(a, "FA"); 
	else if (k % 3 == 2)  strcat(a, "F"); 	
	k = strlen(a);
	if(k%2==1) dl = k / 2 +1;
	else dl = k / 2;	
		for (i = 0; i < k/2; i++)
		{
			zam = a[i];
			a[i] = a[i + dl];
			a[i + dl] = zam;
		}	
		for (i = 0; i < k; ) {
			j = i;
			zam = a[j + 1];
			a[j + 1] = a[j];
			a[j] = zam;
			zam = a[j + 1];
			a[j + 1] = a[j + 2];
			a[j + 2] = zam;
			i = i + 3;
		}
	return a;
}

void password::smena() {	
			cout << "Введите новый логин" << endl;
			char * temp1 = stroka();
			encript(temp1);
			cout << endl;
			cout << "Введите новый пароль" << endl;
			char * temp2 = stroka();
			cout << endl;
			encript(temp2);
			ofstream file("admin.txt", ios_base::out);
			file << temp1 << endl;
			file << temp2;
			file.close();	
}

int password::admin() {
	int a = 1;
	char b;
	string buff;
	do {
		password *p = head;
		cout << "Введите свой логин" << endl;
		char * temp1 = stroka();
		cout << endl;
		cout << "Введите свой пароль" << endl;
		char * temp2 = stroka();
		cout << endl;
		while (p != NULL) {
			if (strcmp(temp1, p->log) == 0 && strcmp(temp2, p->par) == 0) {
				a = 2;
				p->next = NULL;
			}
			p = p->next;
			buff.clear();
		}
		if (a == 1) {
			cout << "Неверно, повторите еще.Если хотите выйти нажмите 0" << endl;
			//cout << "" << endl;
			cin >> b;
			if (b == '0') a = 3;
			else a = 1;
			system("cls");
		}
	} while (a == 1);
	return a;
}

