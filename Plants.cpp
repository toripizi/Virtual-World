#include "plant.h"
#include "animal.h"
#include "Human.h"

class Trawa :public Plant {
public:
	Trawa() {
		do {
			xX = rand() % world.getWidth();
			yY = rand() % world.getHeight();
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "trawa";
		sign = 'T';
		strength = 0;
		activity = 0;
		color = 10;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	Trawa(int X, int Y) {
		this->setX(X);
		this->setY(Y);

		name = "trawa";
		sign = 'T';
		strength = 0;
		activity = 0;
		color = 10;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	void action() {
		if (numberOfAvailableFields && rand() % 12 == 0) {
			Trawa* tra = new Trawa(xX, yY);
		}
	}
};
class Mlecz :public Plant {
public:
	Mlecz() {
		do {
			xX = rand() % world.getWidth();
			yY = rand() % world.getHeight();
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "mlecz";
		sign = 'M';
		strength = 0;
		activity = 0;
		color = 6;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	Mlecz(int X, int Y) {
		this->setX(X);
		this->setY(Y);

		name = "mlecz";
		sign = 'M';
		strength = 0;
		activity = 0;
		color = 6;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	void action() {
		if (numberOfAvailableFields && rand() % 4 == 0) {
			Mlecz* mle = new Mlecz(xX, yY);
		}
	}
};
class Guarana :public Plant {
public:
	Guarana() {
		do {
			xX = rand() % world.getWidth();
			yY = rand() % world.getHeight();
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "guarana";
		sign = 'G';
		strength = 0;
		activity = 0;
		color = 5;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	Guarana(int X, int Y) {
		this->setX(X);
		this->setY(Y);

		name = "guarana";
		sign = 'G';
		strength = 0;
		activity = 0;
		color = 5;
		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	void action() {
		if (numberOfAvailableFields && rand() % 12 == 0) {
			Guarana* gua = new Guarana(xX, yY);
		}
	}
	void conflict(Organism* enemy) {
		enemy->setStrength(enemy->getStrength() + 3);
		Plant::conflict(enemy);
	}
};
class WilczeJagody :public Plant {
public:
	WilczeJagody() {
		do {
			xX = rand() % world.getWidth();
			yY = rand() % world.getHeight();
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "wilcze jagody";
		sign = 'J';
		strength = 999;
		activity = 0;
		color = 1;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	WilczeJagody(int X, int Y) {
		this->setX(X);
		this->setY(Y);

		name = "wilcze jagody";
		sign = 'J';
		strength = 999;
		activity = 0;
		color = 1;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	void action() {
		if (numberOfAvailableFields && rand() % 12 == 0) {
			WilczeJagody* jagody = new WilczeJagody(xX, yY);
		}
	}
};
class BarszczSosnowskiego :public Plant {
public:
	BarszczSosnowskiego() {
		do {
			xX = rand() % world.getWidth();
			yY = rand() % world.getHeight();
		} while (world.tab[xX][yY].organism != nullptr);

		x = xX;
		y = yY;

		name = "barszcz sosnowskiego";
		sign = 'B';
		strength = 10;
		activity = 0;
		color = 7;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	BarszczSosnowskiego(int X, int Y) {
		this->setX(X);
		this->setY(Y);

		name = "barszcz sosnowskiego";
		sign = 'B';
		strength = 10;
		activity = 0;
		color = 7;

		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());

		world.organisms.PUSH(this);
	}
	void checkField2(int newX, int newY) {
		if (newX >= 0 &&
			newX < world.getWidth() &&
			newY >= 0 &&
			newY < world.getHeight()){
			//jesli te wspolrzedne sa prawidlowe, to dopiero sprawdzam czy istnieje tam jakis organizm
			if (world.tab[newX][newY].organism != nullptr) {
				//jeœli jest organizm to sprawdzam czy jest to zwierze
				if (Animal* animal = dynamic_cast<Animal*>(world.tab[newX][newY].organism)) {
					//jeœli tak, to umiera
					if (Human* human = dynamic_cast<Human*>(animal)) {
						if (!human->getImmortality()) {
							world.setGameOver();
							world.tab[animal->getX()][animal->getY()].organism = nullptr;
							world.tab[animal->getX()][animal->getY()].setSign(' ');
							//cout << "Barszcz Sosnowskiego zostal zjedzony przez: ";
							//cout << animal->getName() << ", co skutkuje natychmiastowa smiercia :O" << " ||| ";
							delete human;
						}
						else {
							human->conflict(this);
						}
					}
					else {
						world.tab[animal->getX()][animal->getY()].organism = nullptr;
						world.tab[animal->getX()][animal->getY()].setSign(' ');
						//cout << "Barszcz Sosnowskiego zostal zjedzony przez: ";
						//cout << animal->getName() << ", co skutkuje natychmiastowa smiercia :O" << " ||| ";
						delete animal;
					}
				}
			}
		}
	}
	void action() {
		// sprawdzam czy na polach obok s¹ jakieœ zwierzêta
		checkField2(x - 1, y);
		checkField2(x - 1, y + 1);
		checkField2(x, y + 1);
		checkField2(x + 1, y + 1);
		checkField2(x + 1, y);
		checkField2(x + 1, y - 1);
		checkField2(x, y - 1);
		checkField2(x - 1, y - 1);
		if (numberOfAvailableFields && rand() % 12 == 0) {
			BarszczSosnowskiego* barszcz = new BarszczSosnowskiego(xX, yY);
		}
	}
};