#pragma once
#include "Header.h"
#include "Date.h"

class Person
{
private:
	string _name;
	string _surname;
	Date _date_of_birth;
public:
	Person();
	Person(string name, string surname, Date date);
	Person(string name, string surname, int day, int month, int year);

	string GetName();
	string GetSurname();
	string GetDateOfBirth();

	void SetName(string name);
	void SetSurname(string surname);
	void SetDateOfBirth(Date date);
	void SetDateOfBirth(int day, int month, int year);

	Person& operator=(Person person);
	bool operator < (Person person);
	bool operator > (Person person);
	bool operator == (Person person);
	bool operator != (Person person);
};

