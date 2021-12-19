#pragma once
#include "Header.h"
#include "Harmonist.h"

class Violinist : public Harmonist
{
public:
	Violinist(string text);

	void ShowType() override;
	Harmonist* Clone() override;
};