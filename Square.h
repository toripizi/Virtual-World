#pragma once
#include "organism.h"

# ifndef WIN32_LEAN_AND_MEAN
#   define WIN32_LEAN_AND_MEAN
# endif
# ifndef VC_EXTRALEAN
#   define VC_EXTRALEAN
# endif
# ifndef NOMINMAX
#   define NOMINMAX
# endif
#include <windows.h>

class Square
{
	unsigned char sign = ' ';

public:
	Organism* organism = nullptr;
	const unsigned char getSign();
	void setSign(unsigned char newSign);
	void display();
};

