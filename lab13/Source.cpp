/*
* Сформировать массив на диске, содержащий свединеия 
* об отправлении поездов дальнего следования с Казанского вокзала.
* Структурный тип содержит поля: Номер поезда, 
							     станция назначения,
								 время отправки,
								 Время в пути,
								 наличие билетов.
* Написать программу, которая выбирает с диска и выводит на экран.
*								 - Время отправоения поездов в город X во временном 
								  интервале от А до В часов (значения А, В, Х Вводятся с 
								  клавиатуры)
								  - наличие билетов на поезде XXX (XXX ввести с кламиатуры)
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
	cout << "1. Вывести расписание" << endl;
	cout << "2. Создать новый маршрут" << endl;
	cout << "3. Удалить маршрут" << endl;
	cout << "4. Очистить консоль" << endl;
	cout << "0. Покинуть программу" << endl;
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
	cout << "\tВведите номер поезда: ";
	cin >> train_num;

	for (auto it = ls.begin(); it != ls.end(); it++) 
	{
		if ((*it)->getTrainNumber() == train_num) 
		{
			it = ls.erase(it);	

			cout << "\tМаршрут удален" << endl;
			return;
		}
	}
	cout << "\tМаршрут не найден" << endl;
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
		cout << "\tОшибка при чтении файла" << endl;
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
		cout << "\tОшибка при записи в файла" << endl;
		return;
	}

	for (const auto& it : ls) {
		fo.write((char*)it, sizeof(Route));
	}
}

void printRoutes(list<Route*> ls) {
	cout << "№Поезад\t\t";
	cout << "Билеты\t\t";
	cout << "Пункт А\t\t";
	cout << "Отбытие\t\t\t";
	cout << "Пункт Б\t\t";
	cout << "Прибытие\n";

	for (const auto& it : ls) {
		cout << it->ToString(ROW) << endl;
	}
}


