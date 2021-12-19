#include "Cellist.h"

Cellist::Cellist(string text) : Harmonist(text)
{
}

void Cellist::ShowType()
{
	cout << "Cellist" << endl;
}

Harmonist* Cellist::Clone()
{
	Harmonist* result = new Cellist(_text);
	return result;
}
