#pragma once

#include <string>

class Square
{
	unsigned char sign = ' ';
	std::string name = "empty";
public:
	unsigned char getSign() {
		return sign;
	}
	std::string getName() {
		return name;
	}
};

