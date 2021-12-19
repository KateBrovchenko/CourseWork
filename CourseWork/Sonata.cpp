#include "Sonata.h"

Sonata::Sonata(string name, string text) : MusicalCompositionType(name, text)
{
}

void Sonata::ShowType()
{
	cout << "Sonata" << endl;
}

MusicalCompositionType* Sonata::Clone()
{
	MusicalCompositionType* result = new Sonata(_name, _text);
	return result;
}

