#pragma once
#include "animal.h"

class Human :public Animal
{
public:
	Human(int X, int Y);
	Human();

	void control();

};

