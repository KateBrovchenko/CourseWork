#include "MusicalCompositionType.h"

MusicalCompositionType::MusicalCompositionType(string name, string text)
{
	_name = name;
	_text = text;
}

string MusicalCompositionType::GetName()
{
	return _name;
}

string MusicalCompositionType::GetText()
{
	return _text;
}

void MusicalCompositionType::SetName(string name)
{
	_name = name;
}

void MusicalCompositionType::SetText(string text)
{
	_text = text;
}
