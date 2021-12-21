#include "Music.h"

Music::Music()
{
	_composer = Person();
	_name = string();
	_type = nullptr;
	_opus = string();
	_date_of_creation = Date();
}

Music::Music(Person composer, string name, MusicalCompositionType* type, string opus, Date date)
{
	_composer = composer;
	_name = name;
	_type = type->Clone();
	_opus = opus;
	_date_of_creation = date;
}

Person Music::GetComposer()
{
	return _composer;
}

string Music::GetName()
{
	return _name;
}

MusicalCompositionType* Music::GetMusicalCompositionType()
{
	return _type;
}

string Music::GetOpus()
{
	return _opus;
}

Date Music::GetDateOfCreation()
{
	return _date_of_creation;
}

void Music::SetComposer(Person composer)
{
	_composer = composer;
}

void Music::SetName(string name)
{
	_name = name;
}

void Music::SetMusicalCompositionType(MusicalCompositionType* type)
{
	_type = type->Clone();
}

void Music::SetOpus(string opus)
{
	_opus = opus;
}

void Music::SetDateOfCreation(Date date)
{
	_date_of_creation = date;
}

void Music::SetDateOfCreation(int day, int month, int year)
{
	_date_of_creation.SetDay(day);
	_date_of_creation.SetMonth(month);
	_date_of_creation.SetYear(year);
}


Music& Music::operator=(const Music& music)
{
	_composer = music._composer;
	_name = music._name;
	_type = music._type;
	_opus = music._opus;
	_date_of_creation = music._date_of_creation;
	return *this;
}
