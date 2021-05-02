#include "animal.h"
#include "plant.h"
#include "Human.h"
//00 00 00
//00 00 00
//00 00 00
Animal::~Animal() {
	world.organisms.DELETE_ELEMENT(this);
}
void Animal::move() {
	do {
		int random = rand() % 8;
		switch (random) {
		case 0:
			xX = x - 1;
			yY = y;
			break;
		case 1:
			xX = x - 1;
			yY = y + 1;
			break;
		case 2:
			xX = x;
			yY = y + 1;
			break;
		case 3:
			xX = x + 1;
			yY = y + 1;
			break;
		case 4:
			xX = x + 1;
			yY = y;
			break;
		case 5:
			xX = x + 1;
			yY = y - 1;
			break;
		case 6:
			xX = x;
			yY = y - 1;
			break;
		case 7:
			xX = x - 1;
			yY = y - 1;
			break;
		}
	} while (xX < 0 || xX >= world.getWidth() || yY < 0 || yY >= world.getHeight());
}

void Animal::action() {
	if (x != xX || y != yY) {
		if (world.tab[xX][yY].organism == nullptr) {
			display();
		}
		else {
			conflict();
		}
	}
}
void Animal::conflict() {
	if (Animal* animal = dynamic_cast<Animal*>(world.tab[xX][yY].organism)) {
		if (animal->strength > this->strength) {
			world.tab[x][y].setSign(' ');
			world.tab[x][y].organism = nullptr;
			if (Human* human = dynamic_cast<Human*>(this)) {
				world.setGameOver();
			}
			delete this;
		}
		else{
			if (Human* human = dynamic_cast<Human*>(animal)) {
				world.setGameOver();
			}
			delete animal;
			display();
		}
	}
	else if (Plant* plant = dynamic_cast<Plant*>(world.tab[xX][yY].organism)) {
	}
}
void Animal::display() {
	world.tab[x][y].setSign(' ');
	world.tab[x][y].organism = nullptr;

	changeXY(xX, yY);
	
	world.tab[x][y].organism = this;
	world.tab[x][y].setSign(this->getSign());
}
