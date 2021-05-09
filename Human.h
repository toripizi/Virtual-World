#pragma once
#include "animal.h"

class Human :public Animal
{
	bool immortality = false;
	int numberOfTurns = 0;
	void skill1();
	void skill2();
	bool baby = false;
	int distance = 1;
	
public:
	Human();
	Human(int xx, int yy);
	~Human();
	void move() override {}
	void action() override;
	void conflict(Organism* enemy) override;
	void control();
	void createChild(int xxx, int yyy) override {}
	int getImmortality();
	const int getDistance();
	const int getNumberOfTurns();
	
};

