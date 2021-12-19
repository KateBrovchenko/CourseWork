#pragma once
#include "Header.h"

class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(int day, int month, int year);

	int GetDay();
	int GetMonth();
	int GetYear();

	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);

	string ToString();

	Date& operator=(Date date);
	bool operator < (Date date);
	bool operator > (Date date);
	bool operator == (Date date);
	bool operator != (Date date);
};

