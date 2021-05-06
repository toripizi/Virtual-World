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
	Wilk(int newX, int newY) {
		xX = newX;
		yY = newY;
		x = xX;
		y = yY;

		name = "wilk";
		sign = 'W';
		strength = 9;
		activity = 5;

		World->tab[x][y].organism = this;
		World->tab[x][y].setSign(this->getSign());

		World->organisms.PUSH(this);
	}
	void createChild(int newX, int newY) override {
		Wilk* childW = new Wilk(newX, newY);
	}

};
class Owca : public Animal {
public:
	Owca() {
		do {
			xX = rand() % world.getWidth();
			yY = rand() % world.getHeight();
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
	Owca(int newX, int newY) {

		xX = newX;
		yY = newY;
		x = xX;
		y = yY;

		name = "owca";
		sign = 'O';
		strength = 4;
		activity = 3;

		World->tab[x][y].organism = this;
		World->tab[x][y].setSign(this->getSign());

		World->organisms.PUSH(this);
	}
	void createChild(int newX, int newY) override {
		Owca* childO = new Owca(newX, newY);
	}

};
class Lis : public Animal {
public:
	Lis() {
		do {
			xX = rand() % world.getWidth();
			yY = rand() % world.getHeight();
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
	Lis(int newX, int newY) {

		xX = newX;
		yY = newY;
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
	void createChild(int newX, int newY) override {
		Lis* childL = new Lis(newX, newY);
	}
};
class Zolw : public Animal {
public:
	Zolw() {
		do {
			xX = rand() % world.getWidth();
			yY = rand() % world.getHeight();
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
	Zolw(int newX, int newY) {

		xX = newX;
		yY = newY;
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
	void createChild(int newX, int newY) override {
		Zolw* childZ = new Zolw(newX, newY);
	}
};
class Antylopa : public Animal {
	int tab[2][24];
public:
	Antylopa() {
		do {
			xX = rand() % world.getWidth();
			yY = rand() % world.getHeight();
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
	Antylopa(int newX, int newY) {

		xX = newX;
		yY = newY;
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
	void checkField2(int newX, int newY) {
		if (newX >= 0 &&
			newX < world.getWidth() &&
			newY >= 0 &&
			newY < world.getHeight() &&
			world.tab[newX][newY].organism == nullptr)
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
	void conflict(Organism* enemy) {
		if (rand() % 2 == 0 && enemy->getName() != "antylopa") {
			//antylopa ucieka na s¹siednie niezajête pole
			//sprawdzam czy taki pole istnieje
			numberOfAvailableFields = 0;
			checkField2(x - 1, y);
			checkField2(x - 1, y + 1);
			checkField2(x, y + 1);
			checkField2(x + 1, y + 1);
			checkField2(x + 1, y);
			checkField2(x + 1, y - 1);
			checkField2(x, y - 1);
			checkField2(x - 1, y - 1);

			if (numberOfAvailableFields) {
				//jesli istnieje
				int random = rand() % numberOfAvailableFields;
				xX = tab[0][random];
				yY = tab[1][random];
				display();
				enemy->display();
			}
			else {
				//jesli nie istnieje
				Animal::conflict(enemy);
			}
			
		}
		else {
			Animal::conflict(enemy);
		}
	}
	void createChild(int newX, int newY) override{
		Antylopa* childA = new Antylopa(newX, newY);
	}
};