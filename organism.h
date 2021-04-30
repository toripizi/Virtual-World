#pragma once
#include "world.h"
class Organism
{
protected:
	int strength = 0;
	int activity = 0;
	int x;
	int y;
	World world;
public:
	Organism(World& theWorld, int X, int Y) : world(theWorld), x(X), y(Y) {};
	//~Organism();
	virtual void action() = 0;
	virtual void conflict() = 0;
	virtual void display() = 0;

};

