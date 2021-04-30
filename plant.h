#pragma once
#include "organism.h"

class Plant :public Organism
{
	void action() override;
	void conflict() override;
	void display() override;
};
