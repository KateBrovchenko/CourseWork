#pragma once
#include "MusicalCompositionType.h"

class Divertissement : public MusicalCompositionType
{
public:
	Divertissement();
	Divertissement(string name, string text);

	void ShowType() override;
	MusicalCompositionType* Clone() override;
};

