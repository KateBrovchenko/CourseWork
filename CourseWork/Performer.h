#pragma once
#include "Person.h"
#include "Harmonist.h"

class Performer
{
private:
	Person _person;
	Harmonist* _harmonist;
public:
	Performer();
	Performer(Person person, Harmonist* harmonist);

	Person GetPerson();
	Harmonist* GetHarmonist();

	void SetPerson(Person person);
	void SetHarmonist(Harmonist* harmonist);

	Performer& operator=(Performer performer);
};

