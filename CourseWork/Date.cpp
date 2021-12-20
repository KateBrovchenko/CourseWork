#include "Date.h"

Date::Date()
{
	_day = 1;
	_month = 1;
	_year = 1;
}

Date::Date(int day, int month, int year)
{
	this->SetDay(day);
	this->SetMonth(month);
	this->SetYear(year);
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
	if (day > 0)
	{
		_day = day;
	}
	else
	{
		throw "Day is less oq equal 0!";
		exit(1);
	}
}

void Date::SetMonth(int month)
{
	if (month > 0)
	{
		_month = month;
	}
	else
	{
		throw "Month is less oq equal 0!";
		exit(1);
	}
}

void Date::SetYear(int year)
{
	if (year > 0)
	{
		_year = year;
	}
	else
	{
		throw "Year is less oq equal 0!";
		exit(1);
	}
}

string Date::ToString()
{	
	return to_string(_day) + '.' + to_string(_month) + '.' + to_string(_year);
}

Date& Date::operator=(Date date)
{
	this->SetDay(date._day);
	this->SetMonth(date._month);
	this->SetYear(date._year);
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
