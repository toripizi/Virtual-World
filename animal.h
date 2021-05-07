#pragma once
#include "organism.h"
#include "world.h"

class Animal :public Organism
{
	int duplicate();
	bool baby = true;

protected:
	void checkFieldToChild(int newX, int newY);

	//World* w = World::wo;
	int numberOfAvailableFields = 0;
	World* World = &world;
 	//Animal();
	void action() override;
	void conflict(Organism* enemy) override;
	void display() override;
	void move() override;
	void checkField(int newX, int newY) override;
	
	const bool getBaby() {
		return baby;
	}
	void setBaby(bool f) {
		baby = f;
	}

public:

	virtual void createChild(int xxx, int yyy) = 0;

	// tab[][12] a nie tab[][8], bo przy rozmna¿aniu mo¿liwa jest wiêksza liczba miejsc 
	int tab[2][8]{};

	~Animal();

};

