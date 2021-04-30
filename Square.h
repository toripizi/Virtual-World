#pragma once
#include "organism.h"

class Square
{
	unsigned char sign = ' ';

public:
	Organism* organism = nullptr;
	const unsigned char getSign() {
		return sign;
	}
	void setSign(unsigned char newSign) {
		sign = newSign;
	}

};

