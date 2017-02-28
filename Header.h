
#include <vector>
#include <iostream> 
#include <Windows.h>
#include <string>
#include <conio.h>
#include <cassert>
#include <stdio.h>
#include <iomanip> // ��� setw
#include <regex> 
#include <cstdlib>
#include <fstream> 
#include <time.h>
#pragma warning (disable:4996)
using namespace std;


class sklad {//����� �� ����� �����������
protected:
	char *naimen;//������������ ������
	int kol;//��� ���-�� ������
	double cost;//���� �� ����
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
	int schitat();////��������� ������ �� �����
	void print();//����� ����������� � ������
	void del();//�������� ������
	void zapis();//���������� ����� � ��������
	int enter();//������ ����� �����
	void poly();//�������� ������ ������
};

class dostavka {//�� ����� �����������
protected:
	char *firma;//�������� �����
	int Kcar;//����� ��������� �����
	double proc;//% �� ��������
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
	void schitat();//������� ����������� �� �����
	void schitat(int);//���������� �����������
	int enter();//������ ������
	void zapis();//������������ ���� � ����
	void del();//�������
};


class manager : virtual public sklad, virtual public dostavka
{
private:
	char* ysave;//��� ������
	char* otpravka;//���� ��������
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
	void read();//��������� ������
	void forma();//�������� �����
	void smenit();//�������� ����
	void zap();//������������ ����
	void print();//���������� ������
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
	void proverka();//�������� �� ����������
	char *decript( char *);//��������
	char *encript(char *);//�����������
	void smena();//������� ������
	int admin();//������� �� �����
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
	int getLength();//������ ������
	void add(const T&);//�������� ������
	T& at(int);//�������� ������ �������
	void izmenit(const T&, int);//�������� ������
	void deleteN(int);//������� �����
	void deleteD(int);//������� ����������
	void delal();//������� ���� �����
	void delal2();//������� ��� ������
	void display();//����������
};

