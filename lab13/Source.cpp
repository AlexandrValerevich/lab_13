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
#include <memory>

using namespace std;

typedef unsigned char u_char;
 
char PATH[] = "schedule.bin";

void Menu();
shared_ptr<Route> addRoute();
void deleteRoute(list<shared_ptr<Route>>& ls);
void deleteEmpty(list<shared_ptr<Route>>& ls);
void printRoutes(list<shared_ptr<Route>> ls);
void readFileRoutes(list<shared_ptr<Route>>& ls, char* fileName);
void writeFileRoutes(list<shared_ptr<Route>>& ls, char* fileName);


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int query;
	list<shared_ptr<Route>> Routes;
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
			deleteEmpty(Routes);
			if (Routes.size() > 1) {
				Routes.sort([](shared_ptr<Route> first, shared_ptr<Route> second) {
					return first->getTrainNumber() > second->getTrainNumber();
					});
			}
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

	deleteEmpty(Routes);
	writeFileRoutes(Routes, PATH);
	
	exit(0);
}


void Menu() {
	cout << "1. ������� ����������" << endl;
	cout << "2. ������� ����� �������" << endl;
	cout << "3. ������� �������" << endl;
	cout << "4. �������� �������" << endl;
	cout << "0. �������� ���������" << endl;
}

shared_ptr<Route> addRoute() {
	shared_ptr<Route> temp = shared_ptr<Route>(new Route());
	temp->setRoute();
	if (temp->empty()) {
		return nullptr;
	}
	return temp;
}

void deleteRoute(list<shared_ptr<Route>>& ls)
{
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
void deleteEmpty(list<shared_ptr<Route>>& ls)
{
	auto it_b = ls.begin();
	auto it_e = ls.end();

	while (it_b != it_e ) 
	{
		if (*it_b == nullptr) {
			it_b = ls.erase(it_b);
		} else if ((*it_b)->empty())
		{
			it_b = ls.erase(it_b);
		} else 
		{
			it_b++;
		}
	}
}

void readFileRoutes(list<shared_ptr<Route>>& ls, char* fileName) {
	ifstream fo(fileName, ios_base::in | ios_base::binary);
	
	if (!fo.is_open()) {
		cout << "\t������ ��� ������ �����" << endl;
		exit(0);
	}

	while (fo.good()) {
		shared_ptr<Route> temp = shared_ptr<Route>(new Route());
		fo.read((char*)temp.get(), sizeof(Route));
		if(!temp->empty())
			ls.push_back(temp);
	}
	fo.close();
}

void writeFileRoutes(list<shared_ptr<Route>>& ls, char* fileName) {
	ofstream fo(fileName, ios_base::out | ios_base::binary | ios_base::trunc);

	if (!fo.is_open()) {
		cout << "\t������ ��� ������ � �����" << endl;
		return;
	}

	for (const auto& it : ls) {
		fo.write((char*)it.get(), sizeof(Route));
	}
	fo.close();
}

void printRoutes(list<shared_ptr<Route>> ls) {
	int i = 1;

	cout << "�\t";
	cout << "�������\t\t";
	cout << "������\t\t";
	cout << "����� �\t\t";
	cout << "�������\t\t\t";
	cout << "����� �\t\t";
	cout << "��������\n";

	for (const auto& it : ls) {
		cout << i++ << "\t";
		cout << it->ToString(ROW) << endl;
	}
	return;
}


