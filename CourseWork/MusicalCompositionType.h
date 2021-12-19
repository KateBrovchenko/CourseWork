#pragma once
#include "Header.h"

class MusicalCompositionType
{
protected:
	string _name;
	string _text;
public:
	MusicalCompositionType(string name, string text);

	string GetName();
	string GetText();

	void SetName(string name);
	void SetText(string text);

	virtual void ShowType() = 0;
	virtual MusicalCompositionType* Clone() = 0;
};