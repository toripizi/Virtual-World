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
	void checkField(int newX, int newY){
		if (newX >= 0 &&
			newX < world.getWidth() &&
			newY >= 0 &&
			newY < world.getHeight())
		{
			if (world.tab[newX][newY].organism) {
				if (world.tab[newX][newY].organism->getStrength() <= strength) {
					tab[0][numberOfAvailableFields] = newX;
					tab[1][numberOfAvailableFields] = newY;
					numberOfAvailableFields++;
				}
			}
			else {
				tab[0][numberOfAvailableFields] = newX;
				tab[1][numberOfAvailableFields] = newY;
				numberOfAvailableFields++;
			}
		}
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
	void move() {
		if (rand() % 4 == 0) {
			Animal::move();
		}
	}
};
class Antylopa : public Animal {
	int tab[2][24];
public:
	Antylopa() {
		do {
			xX = rand() % (world.getWidth() - 1);
			yY = rand() % (world.getHeight() - 1);
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "antylopa";
		sign = 'A';
		strength = 4;
		activity = 4;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	void checkField(int newX, int newY) {
		if (newX >= 0 &&
			newX < world.getWidth() &&
			newY >= 0 &&
			newY < world.getHeight())
		{
			tab[0][numberOfAvailableFields] = newX;
			tab[1][numberOfAvailableFields] = newY;
			numberOfAvailableFields++;
		}
	}
	void move() {
		numberOfAvailableFields = 0;
		checkField(x - 2, y - 2);
		checkField(x - 2, y - 1);
		checkField(x - 2, y);
		checkField(x - 2, y + 1);
		checkField(x - 2, y + 2);
		checkField(x - 1, y + 2);
		checkField(x , y + 2);
		checkField(x + 1, y + 2);
		checkField(x + 2, y + 2);
		checkField(x + 2, y + 1);
		checkField(x + 2, y);
		checkField(x + 2, y - 1);
		checkField(x + 2, y - 2);
		checkField(x + 1, y - 2);
		checkField(x, y - 2);
		checkField(x - 1, y - 2);
		checkField(x - 1, y);
		checkField(x - 1, y + 1);
		checkField(x, y + 1);
		checkField(x + 1, y + 1);
		checkField(x + 1, y);
		checkField(x + 1, y - 1);
		checkField(x, y - 1);
		checkField(x - 1, y - 1);

		if (numberOfAvailableFields) {
			int random = rand() % numberOfAvailableFields;
			xX = tab[0][random];
			yY = tab[1][random];
		}
	}
};