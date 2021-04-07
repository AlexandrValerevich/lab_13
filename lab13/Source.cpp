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
#include <memory>


using namespace std;

typedef unsigned char u_char;
 
char PATH[] = "schedule.out";


void Menu();
void addRoute(list<shared_ptr<Route>>& ls);
void deleteEmpty(list<shared_ptr<Route>>& ls);
void printRoutes(list<shared_ptr<Route>>& ls, list<shared_ptr<Route>>& del_ls);
void deleteRoute(list<shared_ptr<Route>>& ls, list<shared_ptr<Route>>& del_ls);
void readFileRoutes(list<shared_ptr<Route>>& ls, char* fileName);
void writeFileRoutes(list<shared_ptr<Route>>& ls, list<shared_ptr<Route>>& del_ls, char* fileName);



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int query;
	list<shared_ptr<Route>> Routes;
	list<shared_ptr<Route>> deleteRoutes;
	deleteRoutes.push_back(shared_ptr<Route>(new Route()));
	readFileRoutes(Routes, PATH);
	Menu();
	
	do {
		cout << "# ";
		cin >> query;
		switch (query)
		{
		case 1: 
		{
			printRoutes(Routes, deleteRoutes);
			break;
		}
		case 2: 
		{
			addRoute(Routes);
			if (Routes.size() > 1) {
				Routes.sort([](shared_ptr<Route> first, shared_ptr<Route> second) {
					return first->getTrainNumber() > second->getTrainNumber();
					});
			}
			break;
		}
		case 3:
		{
			deleteRoute(Routes, deleteRoutes);
			break;
		}
		case 4: {
			system("cls");
			break;
		}
		default:
			break;
		}

	} while (query);

	//deleteEmpty(Routes);
	writeFileRoutes(Routes,deleteRoutes, PATH);
	
	exit(0);
}


void Menu() {
	cout << "1. Вывести расписание"    << endl;
	cout << "2. Создать новый маршрут" << endl;
	cout << "3. Удалить маршрут"       << endl;
	cout << "4. Очистить консоль"      << endl;
	cout << "0. Покинуть программу"    << endl;
}

void addRoute(list<shared_ptr<Route>>& ls) {
	shared_ptr<Route> temp = shared_ptr<Route>(new Route());
	temp->setRoute();
	if (temp->empty()) 
		return;
	ls.push_back(temp);
	return;
}

void deleteRoute(list<shared_ptr<Route>>& ls, list<shared_ptr<Route>>& del_ls)
{
	int train_num;
	cout << "\tВведите номер поезда: ";
	cin >> train_num;

	for (auto& it : ls)
		if (it->getTrainNumber() == train_num)
			del_ls.push_back(it);
			
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
		cout << "\tОшибка при чтении файла" << endl;
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

void writeFileRoutes(list<shared_ptr<Route>>& ls, list<shared_ptr<Route>>& del_ls, char* fileName) {
	ofstream fo(fileName, ios_base::out | ios_base::binary | ios_base::trunc);

	if (!fo.is_open()) {
		cout << "\tОшибка при записи в файла" << endl;
		return;
	}

	for (const auto& it : ls) {
		auto find_it = find_if(del_ls.begin(), del_ls.end(), [it](shared_ptr<Route>& compeare) {
			return compeare.get() == it.get();
			});

		if (find_it == del_ls.end()) {
			fo.write((char*)it.get(), sizeof(Route));
		}
	}
	fo.close();
}

void printRoutes(list<shared_ptr<Route>>& ls, list<shared_ptr<Route>>& del_ls) {
	int i = 1;

	cout << "№\t";
	cout << "№Поезад\t\t";
	cout << "Билеты\t\t";
	cout << "Пункт А\t\t";
	cout << "Отбытие\t\t\t";
	cout << "Пункт Б\t\t";
	cout << "Прибытие\n";


	for (auto& it : ls) 
	{
		auto find_it = find_if(del_ls.begin(), del_ls.end(), [it](shared_ptr<Route>& compeare) {
			return compeare.get() == it.get();
			});

		if(find_it == del_ls.end()) {
			cout << i++ << "\t";
			cout << it->ToString(ROW) << endl;
		}
	}
	return;
}


