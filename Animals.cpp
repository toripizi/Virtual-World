#include "animal.h"

class Wilk : public Animal {
public:
	Wilk() {
		do {
			xX = rand() % (world.getWidth() - 1);
			yY = rand() % (world.getHeight() - 1);
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "wilk";
		sign = 'W';
		strength = 9;
		activity = 5;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
};
class Owca : public Animal {
public:
	Owca() {
		do {
			xX = rand() % (world.getWidth() - 1);
			yY = rand() % (world.getHeight() - 1);
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "owca";
		sign = 'O';
		strength = 4;
		activity = 3;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
};
class Lis : public Animal {
public:
	Lis() {
		do {
			xX = rand() % (world.getWidth() - 1);
			yY = rand() % (world.getHeight() - 1);
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "lis";
		sign = 'L';
		strength = 3;
		activity = 7;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
};
class Zolw : public Animal {
public:
	Zolw() {
		do {
			xX = rand() % (world.getWidth() - 1);
			yY = rand() % (world.getHeight() - 1);
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "zolw";
		sign = 'Z';
		strength = 2;
		activity = 1;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
};