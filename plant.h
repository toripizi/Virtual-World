#pragma once
#include "organism.h"
#include "world.h"

class Plant :public Organism
{
	bool newOne = true;

protected:
	int numberOfAvailableFields = 0;
	World* World = &world;

	void conflict(Organism* enemy) override;
	void display() override {};
	void move() override; 
	void checkField(int newX, int newY) override;
	virtual void action() = 0;

public:
	int tab[2][8]{};

	~Plant();
};
