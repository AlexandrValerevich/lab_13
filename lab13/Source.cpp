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

/*������� ��������� �� ���� ������ ������������� �������
��������� �� �� ������������ � ���������� � ��������� tm*/
void toTm(const string& data_str, tm& date_tm) {

}

bool getYear(int& y) {
	string temp;
	cout << "������� ���: ";
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