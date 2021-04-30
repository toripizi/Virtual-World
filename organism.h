#pragma once
//#include "world.h"
//#include "plant.h"
//#include "animal.h"
#include <iostream>

class Organism
{
protected:
	int strength = 0;
	int activity = 0;
	int x = 0;
	int y = 0;
	int xX = 0;
	int yY = 0;
	std::string name = "empty";
	unsigned char sign = ' ';
	
public:
	virtual void action() = 0;
	virtual void conflict() = 0;
	virtual void display() = 0;

	void changeXY(int newX, int newY) {
		x = newX;
		y = newY;
	}

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

	void setName(std::string newName) {
		name = newName;
	}
	void setSign(unsigned char newSign) {
		sign = newSign;
	}
	const std::string getName() {
		return name;
	}
	const unsigned char getSign() {
		return sign;
	}
};