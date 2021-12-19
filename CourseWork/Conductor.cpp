#include "Conductor.h"

Conductor::Conductor(string text) : Harmonist(text)
{
}

void Conductor::ShowType()
{
	cout << "Conductor" << endl;
}

Harmonist* Conductor::Clone()
{
	Harmonist* result = new Conductor(_text);
	return result;
}
