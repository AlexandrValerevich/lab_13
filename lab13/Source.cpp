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

using namespace std;

typedef unsigned char u_char;
 
char PATH[] = "schedule.bin";


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Route temp;


	temp.setRoute();
	/*��������� ����������*/
	/*
	ofstream fo(PATH, ios_base::out | ios_base::binary);
	if (!fo.is_open()) {
		cout << "�� ������� ������� ����" << endl;
		return 1;
	}
	
	fo.write((char*)&temp, sizeof(temp));
	fo.close();

	ifstream fi(PATH, ios_base::in | ios_base::binary);
	if (!fi.is_open()) {
		cout << "�� ������� ������� ����" << endl;
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