#pragma once
#include "Harmonist.h"

class Violinist : public Harmonist
{
public:
	Violinist();
	Violinist(string text);

	void ShowType() override;
	Harmonist* Clone() override;
};
