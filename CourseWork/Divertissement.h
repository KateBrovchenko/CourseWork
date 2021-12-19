#pragma once
#include "Header.h"
#include "MusicalCompositionType.h"

class Divertissement : public MusicalCompositionType
{
public:
	Divertissement(string name, string text);

	void ShowType() override;
	MusicalCompositionType* Clone() override;
};

