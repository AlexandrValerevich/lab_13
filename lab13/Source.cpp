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



using namespace std;

char PATH[] = "schedule.txt";

struct Route
{
public:
	int train_number;
	tm  data_start;
	tm	data_end;
	int ticket_count;
};

/*Функция принимает на вход строку определенного формата
Разбивает ее на составляющие и записывает в структуру tm*/
void toTm(const string& data_str, tm& date_tm) {

}

bool getYear(int& y) {
	string temp;
	cout << "Введите год: ";
	cin >> temp;
	try {
		y = stoi(temp);
	}
	catch (exception& m) {
		cout << m.what();
		return false;
	}
	return true;
}

string getDate(tm& date) {
	getYear(date.tm_year);
	return "";
}

int main() {
	setlocale(0, "");
	Route temp;

	getDate(temp.data_start);

	return 0;
}