#pragma once
#include "MusicalCompositionType.h"

class Symphony : public MusicalCompositionType
{
public:
	Symphony();
	Symphony(string name, string text);

	void ShowType() override;
	MusicalCompositionType* Clone() override;
};

