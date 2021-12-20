#include "Person.h"

Person::Person()
{
	_name = string();
	_surname = string();
	_date_of_birth = Date();
}

Person::Person(string name, string surname, Date date)
{
	_name = name;
	_surname = surname;
	_date_of_birth = date;
}

Person::Person(string name, string surname, int day, int month, int year)
{
	_name = name;
	_surname = surname;
	_date_of_birth.SetDay(day);
	_date_of_birth.SetMonth(month);
	_date_of_birth.SetYear(year);
}

string Person::GetName()
{
	return _name;
}

string Person::GetSurname()
{
	return _surname;
}

string Person::GetDateOfBirth()
{
	return _date_of_birth.ToString();
}

void Person::SetName(string name)
{
	_name = name;
}

void Person::SetSurname(string surname)
{
	_surname = surname;
}

void Person::SetDateOfBirth(Date date)
{
	_date_of_birth = date;
}

void Person::SetDateOfBirth(int day, int month, int year)
{
	_date_of_birth.SetDay(day);
	_date_of_birth.SetMonth(month);
	_date_of_birth.SetYear(year);
}

Person& Person::operator=(Person person)
{
	_name = person._name;
	_surname = person._surname;
	_date_of_birth = person._date_of_birth;
	return *this;
}

bool Person::operator<(Person person)
{
	return _date_of_birth < person._date_of_birth;
}

bool Person::operator>(Person person)
{
	return _date_of_birth > person._date_of_birth;
}

bool Person::operator==(Person person)
{
	return _date_of_birth == person._date_of_birth;
}

bool Person::operator!=(Person person)
{
	return _date_of_birth != person._date_of_birth;
}
