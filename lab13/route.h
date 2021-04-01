#pragma once
#define COLUMN 0
#define ROW 1

using namespace std;

class Route
{
public:
	string ToString(unsigned int flag = 0);
	void   setRoute();
	int    getTrainNumber();
	int    getTicket();
	tm     getDateDeparture();
	tm     getDateArrival();
	string getPlaceDeparture();
	string getPlaceArrival();
	bool   empty();
	Route();
	~Route() {};

private:
	bool setYear(int&);
	bool setMounth(int&);
	bool setDay(int&);
	bool setHoure(int&);
	bool setMinute(int&);
	bool setTrainNumber();
	bool setTicket();
	bool setPlaceDeparture();
	bool setPlaceArrival();
	void ClearDate(tm&);
	bool setDateDeparture();
	bool setDateArrival();
	

private:
	int train_number;
	tm  data_departure;
	tm	data_arrival;
	int ticket_count;
	string place_departure;
	string place_arrival;
	bool isEmpty;
};