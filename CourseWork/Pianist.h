#pragma once
#include "Harmonist.h"

class Pianist : public Harmonist
{
public:
	Pianist();
	Pianist(string text);

	void ShowType() override;
	Harmonist* Clone() override;
};

