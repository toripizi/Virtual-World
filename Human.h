#pragma once
#include "animal.h"

class Human :public Animal
{
public:
	Human();
	~Human();
	void move() override {}
	void control();
	void createChild(int xxx, int yyy) override {}

};

