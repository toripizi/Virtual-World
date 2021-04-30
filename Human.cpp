#include "Human.h"
#include <conio.h>

Human::Human(int X, int Y) {
	changeXY(X, Y);

	strength = 5;
	activity = 4;

	getIn();
}
Human::Human() {
	strength = 5;
	activity = 4;
}

void Human::getOut() {
	world.tab[x][y].setName("empty");
	world.tab[x][y].setSign(' ');
}
void Human::changeXY(int newX, int newY) {
	x = newX;
	y = newY;
}
void Human::getIn() {
	world.tab[x][y].setName(name);
	world.tab[x][y].setSign(sign);
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
		getOut();
		changeXY(xX, yY);
		getIn();
		world.drawWorld();
		world.nextTurn();
		break;
	case 27: //klawisze specjalne
		world.gameOver = true;
		break;
	}
}