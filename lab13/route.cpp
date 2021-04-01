#include <iostream>
#include "route.h"
#include <string>
#include <locale>
#include <time.h>

using namespace std;

typedef unsigned char u_char;


/*��������� �� ���� ��������� �� ���������� � ������� ����� �������
��� �����������(��������) � ��������� �������� true ���� ������ ������ �������*/
bool Route::setYear(int& y) {
	string temp_str;
	int    temp_dig;
	cout << "\t������� ���: ";
	cin >> temp_str;
	try {
		/*�������� �� ����������� ��������� ������*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("������������ ����!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 1980 || temp_dig > 2050)
			throw  exception("������� ������ ���!!!\n");

		y = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*��������� �� ���� ��������� �� ���������� � ������� ����� �������
����� �����������(��������) � ��������� �������� true ���� ������ ������ �������*/
bool Route::setMounth(int& m) {
	string temp_str;
	int    temp_dig;
	cout << "\t������� �����: ";
	cin >> temp_str;
	try {
		/*�������� �� ����������� ��������� ������*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw exception("������������ ����!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 11)
			throw  exception("������� ������ �����!!!\n");

		m = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*��������� �� ���� ��������� �� ���������� � ������� ����� �������
���� �����������(��������) � ��������� �������� true ���� ������ ������ �������*/
bool Route::setDay(int& d) {
	string temp_str;
	int    temp_dig;
	cout << "\t������� ����: ";
	cin >> temp_str;
	try {
		/*�������� �� ����������� ��������� ������*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("������������ ����!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 1 || temp_dig > 31)
			throw  exception("������� ������ ����!!!\n");

		d = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*��������� �� ���� ��������� �� ���������� � ������� ����� �������
��� �����������(��������) � ��������� �������� true ���� ������ ������ �������*/
bool Route::setHoure(int& h) {
	string temp_str;
	int    temp_dig;
	cout << "\t������� ���: ";
	cin >> temp_str;
	try {
		/*�������� �� ����������� ��������� ������*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("������������ ����!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 23)
			throw  exception("������� ������ ���!!!\n");

		h = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*��������� �� ���� ��������� �� ���������� � ������� ����� �������
�����a �����������(��������) � ��������� �������� true ���� ������ ������ �������*/
bool Route::setMinute(int& m) {
	string temp_str;
	int    temp_dig;
	cout << "\t������� ������: ";
	cin >> temp_str;
	try {
		/*�������� �� ����������� ��������� ������*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("������������ ����!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 59)
			throw  exception("������� ������� ������!!!\n");

		m = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*������� ��������� tm*/
void Route::ClearDate(tm& data) {
	u_char* it = (u_char*)&data;
	for (int i = 0; i < sizeof(data); i++) {
		*it = 0;
		it++;
	}
}

/*�������������� ����� �����������*/
bool Route::setDateDeparture() {
	int attempt = 3;
	cout << "�����������:" << endl;

	while (!setYear(data_departure.tm_year))
		if (!--attempt){
			ClearDate(data_departure);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}
			
	attempt = 3;

	while (!setMounth(data_departure.tm_mon))
		if (!--attempt) {
			ClearDate(data_departure);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}

	attempt = 3;

	while (!setDay(data_departure.tm_mday))
		if (!--attempt) {
			ClearDate(data_departure);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}

	attempt = 3;

	while (!setHoure(data_departure.tm_hour))
		if (!--attempt) {
			ClearDate(data_departure);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}

	attempt = 3;

	while (!setMinute(data_departure.tm_min))
		if (!--attempt) {
			ClearDate(data_departure);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}
	return true;
}

/*�������������� ����� ��������*/
bool Route::setDateArrival() {
	int attempt = 3;
	cout << "��������:" << endl;

	while (!setYear(data_arrival.tm_year))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}

	attempt = 3;

	while (!setMounth(data_arrival.tm_mon))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}

	attempt = 3;

	while (!setDay(data_arrival.tm_mday))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}

	attempt = 3;

	while (!setHoure(data_arrival.tm_hour))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}

	attempt = 3;

	while (!setMinute(data_arrival.tm_min))
		if (!--attempt) {
			ClearDate(data_arrival);
			cout << "��������� ���������� ������� �����" << endl;
			return false;
		}
	return true;
}

/*������������� ����� ������*/
bool Route::setTrainNumber() {
	string temp_str;
	int    temp_dig;
	cout << "������� ����� ������: ";
	cin >> temp_str;
	try {
		/*�������� �� ����������� ��������� ������*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("������������ ����!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 10000)
			throw  exception("����������� ����� ������!!!\n");

		train_number = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*������������� ����� ��������� ����*/
bool Route::setTicket() {
	string temp_str;
	int    temp_dig;
	cout << "������� ���������� �������: ";
	cin >> temp_str;
	try {
		/*�������� �� ����������� ��������� ������*/
		for (const auto& ch : temp_str)
			if (!isdigit(ch))
				throw  exception("������������ ����!!!\n");

		temp_dig = stoi(temp_str);

		if (temp_dig < 0 || temp_dig > 500)
			throw  exception("����������� ���������� ������� (0 < Ticet < 500)!!!\n");

		ticket_count = temp_dig;
	}
	catch (exception& ex) {
		cout << ex.what();
		return false;
	}
	return true;
}

/*������������� ����� �����������*/
bool Route::setPlaceDeparture()
{
	string temp;
	cout << "����� �����������: ";
	do {
		cin >> temp;
	}while (temp.empty());

	place_departure = temp;

	return true;
}

/*������������� ����� ��������*/
bool Route::setPlaceArrival()
{
	string temp;
	cout << "����� ��������: ";
	do {
		cin >> temp;
	} while (temp.empty());

	place_arrival = temp;

	return true;
}

/*���������� �� ���������� ���������� � �����*/
void Route::setRoute() {
	int attempt = 3;

	while (!setTrainNumber())
		if (!--attempt) {
			cout << "�������� ����� ������� �����" << endl;
			cout << "���������� ��������" << endl;
			return;
		}

	attempt = 3;

	while (!setTicket()) 
	{
		if (!--attempt) 
		{
			cout << "�������� ����� ������� �����" << endl;
			cout << "���������� ��������" << endl;
			return;
		}
	}

	if(!setPlaceDeparture()) 
	{
		cout << "���������� ��������" << endl;
		return;
	}

	if (!setDateDeparture()) 
	{
		cout << "���������� ��������" << endl;
		return;
	}
	if (!setPlaceArrival())
	{
		cout << "���������� ��������" << endl;
		return;
	}
		
	if (!setDateArrival())
	{
		cout << "���������� ��������" << endl;
		return;
	}

	cout << "���������� ��������� �������" << endl;
	isEmpty = false;
	return;
}

/*���������� ����� ������*/
int Route::getTrainNumber() {
	return train_number;
}

/*���������� ���������� ��������� ������� ������*/
int Route::getTicket()
{
	return ticket_count;
}

/*���������� ����� ��������� tm ����������
���������� �� �����������*/
tm Route::getDateDeparture()
{
	return data_departure;
}

/*���������� ����� ��������� tm ���������� 
���������� � ��������*/
tm Route::getDateArrival()
{
	return data_arrival;
}

/*���������� ����� �����������*/
string Route::getPlaceDeparture()
{
	return place_departure;
}

/*���������� ����� ��������*/
string Route::getPlaceArrival()
{
	return place_arrival;
}

/*���������� true ���� ��������� ������*/
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
	temp += to_string(ticket_count) + " ��." + separate;
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
