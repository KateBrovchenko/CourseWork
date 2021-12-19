#pragma once
#include "Header.h"
#include "MusicalCompositionType.h"

class Sonata : public MusicalCompositionType
{
public:
	Sonata(string name, string text);

	void ShowType() override;
	MusicalCompositionType* Clone() override;
};

