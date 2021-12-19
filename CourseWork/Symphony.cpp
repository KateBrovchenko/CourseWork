#include "Symphony.h"

Symphony::Symphony(string name, string text) : MusicalCompositionType(name, text)
{
}

void Symphony::ShowType()
{
	cout << "Symphony" << endl;
}

MusicalCompositionType* Symphony::Clone()
{
	MusicalCompositionType* result = new Symphony(_name, _text);
	return result;
}
