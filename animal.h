#pragma once
#include "organism.h"
#include "world.h"

class Animal :public Organism
{
protected:
	World* World = &world;
	//Animal();
	void action() override;
	void conflict() override;
	void display() override;
	
};

