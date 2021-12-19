#include "Violinist.h"


Violinist::Violinist(string text) : Harmonist(text)
{
}

void Violinist::ShowType()
{
	cout << "Violinist" << endl;
}

Harmonist* Violinist::Clone()
{
	Harmonist* result = new Violinist(_text);
	return result;
}
