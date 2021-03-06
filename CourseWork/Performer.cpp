#include "Performer.h"

Performer::Performer()
{
	_person = Person();
	_harmonist = nullptr;
}

Performer::Performer(Person person, Harmonist* harmonist)
{
	_person = person;
	_harmonist = harmonist->Clone();
}

Person Performer::GetPerson()
{
	return _person;
}

Harmonist* Performer::GetHarmonist()
{
	return _harmonist;
}

void Performer::SetPerson(Person person)
{
	_person = person;
}

void Performer::SetHarmonist(Harmonist* harmonist)
{
	_harmonist = harmonist->Clone();
}

Performer& Performer::operator=(const Performer& performer)
{
	_person = performer._person;
	_harmonist = performer._harmonist;
	return *this;
}
