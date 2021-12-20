#pragma once
#include "Harmonist.h"

class Cellist : public Harmonist
{
public:
	Cellist(string text);

	void ShowType() override;
	Harmonist* Clone() override;
};
