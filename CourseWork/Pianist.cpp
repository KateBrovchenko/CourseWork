#include "Pianist.h"

Pianist::Pianist() : Harmonist()
{
}

Pianist::Pianist(string text) : Harmonist(text)
{
}

void Pianist::ShowType()
{
	cout << "Pianist" << endl;
}

Harmonist* Pianist::Clone()
{
	Harmonist* result = new Pianist(_text);
	return result;
}