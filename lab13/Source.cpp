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