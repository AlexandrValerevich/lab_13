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

using namespace std;

typedef unsigned char u_char;
 
char PATH[] = "schedule.bin";


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Route temp;


	temp.setRoute();
	/*Возникает исключение*/
	/*
	ofstream fo(PATH, ios_base::out | ios_base::binary);
	if (!fo.is_open()) {
		cout << "Не удается открыть файл" << endl;
		return 1;
	}
	
	fo.write((char*)&temp, sizeof(temp));
	fo.close();

	ifstream fi(PATH, ios_base::in | ios_base::binary);
	if (!fi.is_open()) {
		cout << "Не удается открыть файл" << endl;
		return 1;
	}

	Route test;
	fi.read((char*)&test, sizeof(test));
	fi.close();
	*/
	cout << temp.ToString(ROW) << endl;
	//cout << test.ToString(ROW) << endl;

	return 0;
}