#pragma once
#include "animal.h"

class Human :public Animal
{
	const std::string name = "human";
	const unsigned char sign = 'C';
	void getOut();
	void changeXY(int newX, int newY);
	void getIn();
	int xX = 0;
	int yY = 0;

public:
	Human(int X, int Y);
	Human();
	const std::string getName() {
		return name;
	}
	const unsigned char getSign() {
		return sign;
	}

	void control();

};

