#pragma once
#include "organism.h"

class Animal :public Organism
{
	void action() override;
	void conflict() override;
	void display() override;
	
};

