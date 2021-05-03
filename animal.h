#pragma once
#include "organism.h"
#include "world.h"

class Animal :public Organism
{
protected:
	int numberOfAvailableFields = 0;
	World* World = &world;
	//Animal();
	void action() override;
	void conflict() override;
	void display() override;
	void move() override;
	void checkField(int newX, int newY) override;

public:
	int tab[2][8]{};

	~Animal();

};

