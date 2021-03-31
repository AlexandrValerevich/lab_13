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
#include <ostream>
#include <istream>
#include <fstream>
#include <string>
#include <time.h>
#include <locale>
#include "route.h"
#include <Windows.h>

using namespace std;

char PATH[] = "schedule.txt";


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Route temp;

	temp.setRoute();

	cout << temp.ToString() << endl;

	return 0;
}