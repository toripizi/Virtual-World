#pragma once
#include "world.h"
class Organism
{
protected:
	int strength = 0;
	int activity = 0;
	int x;
	int y;
	World* World = &world;
	
public:
	virtual void action() = 0;
	virtual void conflict() = 0;
	virtual void display() = 0;

	const int getX() {
		return x;
	}
	void setX(int newX) {
		x = newX;
	}
	const int getY() {
		return y;
	}
	void setY(int newY) {
		y = newY;
	}
	const int getStrength() {
		return strength;
	}
	const int getActivity() {
		return activity;
	}

};

