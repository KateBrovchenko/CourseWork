#include "Music.h"

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

Music& Music::operator=(Music music)
{
	_composer = music.GetComposer();
	_name = music.GetName();
	_type = music.GetMusicalCompositionType()->Clone();
	_opus = music.GetOpus();
	_date_of_creation = music.GetDateOfCreation();
	return *this;
}
