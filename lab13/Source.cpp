/*
* ������������ ������ �� �����, ���������� ��������� 
* �� ����������� ������� �������� ���������� � ���������� �������.
* ����������� ��� �������� ����: ����� ������, 
							     ������� ����������,
								 ����� ��������,
								 ����� � ����,
								 ������� �������.
* �������� ���������, ������� �������� � ����� � ������� �� �����.
*								 - ����� ����������� ������� � ����� X �� ��������� 
								  ��������� �� � �� � ����� (�������� �, �, � �������� � 
								  ����������)
								  - ������� ������� �� ������ XXX (XXX ������ � ����������)
* 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "route.h"
#include <Windows.h>
#include <list>
#include <algorithm>

using namespace std;

typedef unsigned char u_char;
 
char PATH[] = "schedule.bin";

void Menu();
Route* addRoute();
void deleteRoute(list<Route*>& ls);
void deleteEmpty(list<Route*>& ls);
void readFileRoutes(list<Route*>& ls, char* fileName);
void writeFileRoutes(list<Route*>& ls, char* fileName);
void printRoutes(list<Route*> ls);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int query;
	list<Route*>Routes;
	readFileRoutes(Routes, PATH);
	Menu();
	
	do {
		cout << "# ";
		cin >> query;
		switch (query)
		{
		case 1: 
		{
			printRoutes(Routes);
			break;
		}
		case 2: 
		{
			Routes.push_back(addRoute());
			Routes.sort([](Route* first, Route* second) {
				return first->getTrainNumber() > second->getTrainNumber();
				});
			break;
		}
		case 3:
		{
			deleteRoute(Routes);
			break;
		}
		case 4: {
			system("cls");
		}
		default:
			break;
		}

	} while (query);

	if (!Routes.empty())
	{
		deleteEmpty(Routes);
		writeFileRoutes(Routes, PATH);
	}

	return 0;
}


void Menu() {
	cout << "1. ������� ����������" << endl;
	cout << "2. ������� ����� �������" << endl;
	cout << "3. ������� �������" << endl;
	cout << "4. �������� �������" << endl;
	cout << "0. �������� ���������" << endl;
}

Route* addRoute() {
	Route* temp = new Route();
	temp->setRoute();
	return temp;
}

void deleteRoute(list<Route*>& ls)
{
	Route* temp;
	int train_num;
	cout << "\t������� ����� ������: ";
	cin >> train_num;

	for (auto it = ls.begin(); it != ls.end(); it++) 
	{
		if ((*it)->getTrainNumber() == train_num) 
		{
			it = ls.erase(it);	

			cout << "\t������� ������" << endl;
			return;
		}
	}
	cout << "\t������� �� ������" << endl;
	return;
}


/*Tyt oshibka!!!*/
void deleteEmpty(list<Route*>& ls)
{
	Route* temp;
	list<Route*>::iterator it_b = ls.begin();
	list<Route*>::iterator it_e = ls.end();

	while (it_b != it_e) 
	{
		if ((*it_b)->empty()) 
		{
			temp = (*it_b);
			it_b = ls.erase(it_b);
			delete temp;
		}
		else 
		{
			it_b++;
		}
	}
}

void readFileRoutes(list<Route*>& ls, char* fileName) {
	ifstream fo(fileName, ios_base::in | ios_base::binary);
	
	if (!fo.is_open()) {
		cout << "\t������ ��� ������ �����" << endl;
		exit(0);
	}

	while (fo.good()) {
		Route* temp = new Route();
		fo.read((char*)temp, sizeof(Route));
		ls.push_back(temp);
	}
}

void writeFileRoutes(list<Route*>& ls, char* fileName) {
	ofstream fo(fileName, ios_base::out | ios_base::binary | ios_base::trunc);

	if (!fo.is_open()) {
		cout << "\t������ ��� ������ � �����" << endl;
		return;
	}

	for (const auto& it : ls) {
		fo.write((char*)it, sizeof(Route));
	}
}

void printRoutes(list<Route*> ls) {
	cout << "�������\t\t";
	cout << "������\t\t";
	cout << "����� �\t\t";
	cout << "�������\t\t\t";
	cout << "����� �\t\t";
	cout << "��������\n";

	for (const auto& it : ls) {
		cout << it->ToString(ROW) << endl;
	}
}


