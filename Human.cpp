#include "Human.h"
#include <conio.h>

Human::Human(int X, int Y) {
	xX = X;
	yY = Y;

	name = "human";
	sign = 'H';
	strength = 5;
	activity = 4;

	action();
}
Human::Human() {
	strength = 5;
	activity = 4;
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
			xX = x + 1;
			yY = y;
			break;
		case 72: //strza³ka w gore
			xX = x - 1;
			yY = y;
			break;
		case 75: //strza³ka w lewo
			xX = x;
			yY = y - 1;
			break;
		case 77: //strza³ka w prawo
			xX = x;
			yY = y + 1;
			break;
		}
		break;
	//ESC
	case 122:
		this->action();
		world.drawWorld();
		world.nextTurn();
		break;
	case 27: //klawisze specjalne
		world.gameOver = true;
		break;
	}
}