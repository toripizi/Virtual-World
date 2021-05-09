#include "Human.h"
#include <conio.h> // _getch()

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
	color = 4;

	world.tab[x][y].organism = this;
	world.tab[x][y].setSign(this->getSign());

	world.organisms.PUSH(this);
}
Human::Human(int xx, int yy) {
	xX = xx;
	yY = yy;

	x = xX;
	y = yY;

	name = "human";
	sign = 'C';
	strength = 5;
	activity = 4;
	color = 4;

	world.tab[x][y].organism = this;
	world.tab[x][y].setSign(this->getSign());

	world.organisms.PUSH(this);
}

Human::~Human() {
	std::cout << "asd";
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
			yY = y + distance; 
			//standardowo distance = 1; 
			//jeœli jest w³¹czona specjalna umiejêtnoœæ, distance = 2
			//xX -> potencjalny x;
			//yY -> potencjalny y;
			break;
		case 72: //strza³ka w gore
			xX = x;
			yY = y - distance;
			break;
		case 75: //strza³ka w lewo
			xX = x - distance;
			yY = y;
			break;
		case 77: //strza³ka w prawo
			xX = x + distance;
			yY = y;
			break;
		}
		break;
	//ESC
	case 122:// 'z'
		world.nextTurn();
		if (numberOfTurns) {
			numberOfTurns--;
			if (numberOfTurns <= 5) {
				immortality = false;
				distance = 1;
			}
			if (numberOfTurns <= 7 && numberOfTurns > 5) {
				distance = 1;
				if (rand() % 2 == 1) distance = 2;
			}
		}
		break;
	case 27:
		world.setGameOver();
		break;
	case 48://0 //umiejetnosci czlowieka, niesmiertelnosc 
		this->skill1();
		break;
	case 50://2 //umiejetnosci czlowieka, szybkosc antylopy
		this->skill2();
		break;
	case 120:
		world.writeWorldToFile();
		break;
	}
	
}

void Human::skill1() {
	if (!numberOfTurns) {
		immortality = true;
		numberOfTurns = 10;
	}
}

void Human::skill2() {
	if (!numberOfTurns) {
		distance = 2;
		numberOfTurns = 10;
	}
}

int Human::getImmortality() {
	return immortality;
}

void Human::conflict(Organism* enemy) {
	if (immortality && enemy->getStrength() > strength) {
		numberOfAvailableFields = 0;
		Animal::checkFieldToChild(x - 1, y);
		Animal::checkFieldToChild(x - 1, y + 1);
		Animal::checkFieldToChild(x, y + 1);
		Animal::checkFieldToChild(x + 1, y + 1);
		Animal::checkFieldToChild(x + 1, y);
		Animal::checkFieldToChild(x + 1, y - 1);
		Animal::checkFieldToChild(x, y - 1);
		Animal::checkFieldToChild(x - 1, y - 1);

		if (numberOfAvailableFields) {
			int random = rand() % numberOfAvailableFields;
			xX = tab[0][random];
			yY = tab[1][random];
			Animal::action();
			enemy->display();

			//komunikat
			cout << this->getName() << " jest niesmiertelny wiec przesuwa sie na inne miejsce, atakujacy: " << enemy->getName() << " ||| ";
		}
		else {
			int str = strength;
			strength = enemy->getStrength() + 1;
			Animal::conflict(enemy);
			strength = str;
		}
	}
	else Animal::conflict(enemy);
}

void Human::action() {
	if (x != xX || y != yY) {
		if (world.tab[xX][yY].organism == nullptr) {
			display();
		}
		else if (world.tab[xX][yY].organism->getStrength() > strength) {
			xX = x;
			yY = y;
		}
		else if (world.tab[xX][yY].organism->getName() != "zolw") {
			world.tab[xX][yY].organism->conflict(this);
		}
		else if (strength >= 5) {
			world.tab[xX][yY].organism->conflict(this);
		}
		else {
			xX = x;
			yY = y;
		}
	}
}

const int Human::getDistance() {
	return distance;
}

const int Human::getNumberOfTurns() {
	return numberOfTurns;
}