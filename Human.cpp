#include "Human.h"
#include <conio.h>

Human::Human() {
	do {
		xX = rand() % world.getWidth();
		yY = rand() % world.getHeight();
	} while (world.tab[xX][yY].organism != nullptr);
	
	x = xX;
	y = yY;

	name = "human";
	sign = 'C';
	strength = 5;
	activity = 4;
	
	world.tab[x][y].organism = this;
	world.tab[x][y].setSign(this->getSign());

	world.organisms.PUSH(this);
}

Human::~Human() {
	std::cout << "asd";
}

void Human::move() {
}

void Human::control() {
	unsigned char znak = _getch();
	switch (znak)
	{
	case 224: //klawisze specjalne
		znak = _getch();
		switch (znak)
		{
		case 80: //strza³ka w dol
			xX = x;
			yY = y + 1;
			break;
		case 72: //strza³ka w gore
			xX = x;
			yY = y - 1;
			break;
		case 75: //strza³ka w lewo
			xX = x - 1;
			yY = y;
			break;
		case 77: //strza³ka w prawo
			xX = x + 1;
			yY = y;
			break;
		}
		break;
	//ESC
	case 122:
		world.nextTurn();
		break;
	case 27: //klawisze specjalne
		world.setGameOver();
		break;
	}
}

