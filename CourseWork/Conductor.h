#pragma once
#include "Harmonist.h"

class Conductor : public Harmonist
{
public:
	Conductor();
	Conductor(string text);

	void ShowType() override;
	Harmonist* Clone() override;
};

