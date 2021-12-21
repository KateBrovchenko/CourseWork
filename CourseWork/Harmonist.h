#pragma once
#include "Header.h"

class Harmonist
{
protected:
	string _text;
public:
	Harmonist();
	Harmonist(string text);

	string GetText();

	void SetText(string text);

	virtual void ShowType() = 0;
	virtual Harmonist* Clone() = 0;
};

