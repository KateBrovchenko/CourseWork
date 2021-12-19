#include "Divertissement.h"

Divertissement::Divertissement(string name, string text) : MusicalCompositionType(name, text)
{
}

void Divertissement::ShowType()
{
	cout << "Divertissement" << endl;
}

MusicalCompositionType* Divertissement::Clone()
{
	MusicalCompositionType* result = new Divertissement(_name, _text);
	return result;
}

