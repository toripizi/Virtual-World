#include "Human.h"
#include <conio.h>

Human::Human() {
	do {
		xX = rand() % (world.getWidth() - 1);
		yY = rand() % (world.getHeight() - 1);
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
		case 80: //strza�ka w dol
			xX = x + 1;
			yY = y;
			break;
		case 72: //strza�ka w gore
			xX = x - 1;
			yY = y;
			break;
		case 75: //strza�ka w lewo
			xX = x;
			yY = y - 1;
			break;
		case 77: //strza�ka w prawo
			xX = x;
			yY = y + 1;
			break;
		}
		break;
	//ESC
	case 122:
		world.nextTurn();
		world.drawWorld();
		break;
	case 27: //klawisze specjalne
		world.setGameOver();
		break;
	}
}

