#include "Concert.h"

Concert::Concert(string name, string text) : MusicalCompositionType(name, text)
{
}

void Concert::ShowType()
{
	cout << "Concert" << endl;
}

MusicalCompositionType* Concert::Clone()
{
	MusicalCompositionType* result = new Concert(_name, _text);
	return result;
}
