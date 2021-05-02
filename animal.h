#pragma once
#include "organism.h"
#include "world.h"

class Animal :public Organism
{
protected:
	~Animal();
	World* World = &world;
	//Animal();
	void action() override;
	void conflict() override;
	void display() override;
public:
	void move() override;
	
};

