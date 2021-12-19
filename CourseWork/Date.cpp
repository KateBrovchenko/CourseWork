#include "Date.h"

Date::Date()
{
	_day = 0;
	_month = 0;
	_year = 0;
}

Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

int Date::GetDay()
{
	return _day;
}

int Date::GetMonth()
{
	return _month;
}

int Date::GetYear()
{
	return _year;
}

void Date::SetDay(int day)
{
	_day = day;
}

void Date::SetMonth(int month)
{
	_month = month;
}

void Date::SetYear(int year)
{
	_year = year;
}

string Date::ToString()
{	
	return to_string(_day) + '.' + to_string(_month) + '.' + to_string(_year);
}

Date& Date::operator=(Date date)
{
	_day = date._day;
	_month = date._month;
	_year = date._year;
	return *this;
}

bool Date::operator<(Date date)
{
	return date.ToString() < ToString();
}

bool Date::operator>(Date date)
{
	return date.ToString() > ToString();
}

bool Date::operator==(Date date)
{
	return date.ToString() == ToString();
}

bool Date::operator!=(Date date)
{
	return date.ToString() != ToString();
}
