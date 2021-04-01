#include <iostream>
#include "route.h"
#include <string>
#include <locale>
#include <time.h>

using namespace std;

typedef unsigned char u_char;


/*принимает на вход указатель на переменную в которую будет записан
год отправления(прибытия) и возращает значеине true если запись прошла успешно*/
bool Route::setYear(int& y) {
	string temp_str;
	int    temp_dig;
	cout << "\tВведите год: ";
	cin >> temp_str;
	try {
		/*Проверка на коректность введенной строки*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("Неправильный ввод!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 1980 || temp_dig > 2050)
			throw  exception("Неверно указан год!!!\n");

		y = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*принимает на вход указатель на переменную в которую будет записан
месяц отправления(прибытия) и возращает значеине true если запись прошла успешно*/
bool Route::setMounth(int& m) {
	string temp_str;
	int    temp_dig;
	cout << "\tВведите месяц: ";
	cin >> temp_str;
	try {
		/*Проверка на коректность введенной строки*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw exception("Неправильный ввод!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 11)
			throw  exception("Неверно указан месяц!!!\n");

		m = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*принимает на вход указатель на переменную в которую будет записан
день отправления(прибытия) и возращает значеине true если запись прошла успешно*/
bool Route::setDay(int& d) {
	string temp_str;
	int    temp_dig;
	cout << "\tВведите день: ";
	cin >> temp_str;
	try {
		/*Проверка на коректность введенной строки*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("Неправильный ввод!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 1 || temp_dig > 31)
			throw  exception("Неверно указан день!!!\n");

		d = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*принимает на вход указатель на переменную в которую будет записан
час отправления(прибытия) и возращает значеине true если запись прошла успешно*/
bool Route::setHoure(int& h) {
	string temp_str;
	int    temp_dig;
	cout << "\tВведите час: ";
	cin >> temp_str;
	try {
		/*Проверка на коректность введенной строки*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("Неправильный ввод!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 23)
			throw  exception("Неверно указан час!!!\n");

		h = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*принимает на вход указатель на переменную в которую будет записан
минутa отправления(прибытия) и возращает значеине true если запись прошла успешно*/
bool Route::setMinute(int& m) {
	string temp_str;
	int    temp_dig;
	cout << "\tВведите минуту: ";
	cin >> temp_str;
	try {
		/*Проверка на коректность введенной строки*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("Неправильный ввод!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 59)
			throw  exception("Неверно указаны минуты!!!\n");

		m = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*Очищает структуру tm*/
void Route::ClearDate(tm& data) {
	u_char* it = (u_char*)&data;
	for (int i = 0; i < sizeof(data); i++) {
		*it = 0;
		it++;
	}
}

/*устанавлинвает время отправления*/
bool Route::setDateDeparture() {
	int attempt = 3;
	cout << "Отправление:" << endl;

	while (!setYear(data_departure.tm_year))
		if (!--attempt){
			ClearDate(data_departure);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}
			
	attempt = 3;

	while (!setMounth(data_departure.tm_mon))
		if (!--attempt) {
			ClearDate(data_departure);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}

	attempt = 3;

	while (!setDay(data_departure.tm_mday))
		if (!--attempt) {
			ClearDate(data_departure);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}

	attempt = 3;

	while (!setHoure(data_departure.tm_hour))
		if (!--attempt) {
			ClearDate(data_departure);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}

	attempt = 3;

	while (!setMinute(data_departure.tm_min))
		if (!--attempt) {
			ClearDate(data_departure);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}
	return true;
}

/*устанавлинвает время прибытия*/
bool Route::setDateArrival() {
	int attempt = 3;
	cout << "Прибытие:" << endl;

	while (!setYear(data_arrival.tm_year))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}

	attempt = 3;

	while (!setMounth(data_arrival.tm_mon))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}

	attempt = 3;

	while (!setDay(data_arrival.tm_mday))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}

	attempt = 3;

	while (!setHoure(data_arrival.tm_hour))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}

	attempt = 3;

	while (!setMinute(data_arrival.tm_min))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "Привышено количество попыток ввода" << endl;
			return false;
		}
	return true;
}

/*Устанавливает номер поезда*/
bool Route::setTrainNumber() {
	string temp_str;
	int    temp_dig;
	cout << "Введите номер поезда: ";
	cin >> temp_str;
	try {
		/*Проверка на коректность введенной строки*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("Неправильный ввод!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 10000)
			throw  exception("Невозможный номер поезда!!!\n");

		train_number = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*Устанавливает число купленных мест*/
bool Route::setTicket() {
	string temp_str;
	int    temp_dig;
	cout << "Введите количество билетов: ";
	cin >> temp_str;
	try {
		/*Проверка на коректность введенной строки*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("Неправильный ввод!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 500)
			throw  exception("Невозможное количество билетов (0 < Ticet < 500)!!!\n");

		ticket_count = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*Устанавливает место отправления*/
bool Route::setPlaceDeparture()
{
	string temp;
	cout << "Место отправления: ";
	do {
		cin >> temp;
	}while (temp.empty());

	place_departure = temp;

	return true;
}

/*устанавливает место прибытия*/
bool Route::setPlaceArrival()
{
	string temp;
	cout << "Место прибытия: ";
	do {
		cin >> temp;
	} while (temp.empty());

	place_arrival = temp;

	return true;
}

/*Транзакция по заполнению информации о рейсе*/
void Route::setRoute() {
	int attempt = 3;

	while (!setTrainNumber())
		if (!--attempt) {
			cout << "Привышен лимит попыток ввода" << endl;
			cout << "Транзакция отменена" << endl;
			return;
		}

	attempt = 3;

	while (!setTicket()) 
	{
		if (!--attempt) 
		{
			cout << "Привышен лимит попыток ввода" << endl;
			cout << "Транзакция отменена" << endl;
			return;
		}
	}

	if(!setPlaceDeparture()) 
	{
		cout << "Транзакция отменена" << endl;
		return;
	}

	if (!setDateDeparture()) 
	{
		cout << "Транзакция отменена" << endl;
		return;
	}
	if (!setPlaceArrival())
	{
		cout << "Транзакция отменена" << endl;
		return;
	}
		
	if (!setDateArrival())
	{
		cout << "Транзакция отменена" << endl;
		return;
	}

	cout << "Транзакция завершена успешно" << endl;
	isEmpty = false;
	return;
}

/*возвращает номер поезда*/
int Route::getTrainNumber() {
	return train_number;
}

/*возвращает количество купленных билетов поезда*/
int Route::getTicket()
{
	return ticket_count;
}

/*Возвращает копию структуры tm содаржащей
информацию от отправлении*/
tm Route::getDateDeparture()
{
	return data_departure;
}

/*Возвращает копию структуры tm содержашей 
информацию о прибытии*/
tm Route::getDateArrival()
{
	return data_arrival;
}

/*Возвращает место отправления*/
string Route::getPlaceDeparture()
{
	return place_departure;
}

/*Возвращает место прибытия*/
string Route::getPlaceArrival()
{
	return place_arrival;
}

/*Возвращает true если структура пустая*/
bool Route::empty()
{
	return isEmpty;
}

Route::Route()
{
	train_number = 0;
	ticket_count = 0;
	ClearDate(data_arrival);
	ClearDate(data_departure);
	isEmpty = true;
}

string Route::ToString(unsigned int flag ) {

	
	if (this->empty())
		return "";

	string temp;
	string separate;
	switch (flag)
	{
	case 0: {
		separate = '\n';
		break;
	}
	case 1: {
		separate = "\t\t";
		break;
	}
	default:
		separate = '\n';
		break;
	}
	temp += "#" + to_string(train_number)    + separate;
	temp += to_string(ticket_count) + " шт." + separate;
	temp += place_departure                  + separate;
	temp += to_string(data_departure.tm_mday) + '.' +
		to_string(data_departure.tm_mon)      + '.' +
		to_string(data_departure.tm_year)     + ' ' +
		to_string(data_departure.tm_hour)     + ':' +
		to_string(data_departure.tm_min)     + separate;
	temp += place_arrival                    + separate;
	temp += to_string(data_arrival.tm_mday) + '.' +
		to_string(data_arrival.tm_mon)      + '.' +
		to_string(data_arrival.tm_year)     + ' ' +
		to_string(data_arrival.tm_hour)     + ':' +
		to_string(data_arrival.tm_min)       + separate;

	return temp;
}
