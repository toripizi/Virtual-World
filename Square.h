#pragma once
#include "organism.h"

class Square
{
	unsigned char sign = ' ';

public:
	Organism* organism = nullptr;
	const unsigned char getSign();
	void setSign(unsigned char newSign);
};

