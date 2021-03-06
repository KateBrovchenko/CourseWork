#pragma once
#include "Person.h"
#include "MusicalCompositionType.h"
#include "Date.h"

class Music
{
private:
	Person _composer;
	string _name;
	MusicalCompositionType* _type;
	string _opus;
	Date _date_of_creation;
public: 
	Music();
	Music(Person composer, string name, MusicalCompositionType* type, string opus, Date date);

	Person GetComposer();
	string GetName();
	MusicalCompositionType* GetMusicalCompositionType();
	string GetOpus();
	Date GetDateOfCreation();

	void SetComposer(Person composer);
	void SetName(string name);
	void SetMusicalCompositionType(MusicalCompositionType* type);
	void SetOpus(string opus);
	void SetDateOfCreation(Date date);
	void SetDateOfCreation(int day, int month, int year);

	Music& operator=(const Music& music);
};

