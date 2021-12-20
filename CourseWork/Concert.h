#pragma once
#include "MusicalCompositionType.h"

class Concert : public MusicalCompositionType
{
public:
	Concert(string name, string text);

	void ShowType() override;
	MusicalCompositionType* Clone() override;
};

