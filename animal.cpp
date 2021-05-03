#include "animal.h"
#include "plant.h"
#include "Human.h"
//00 00 00
//00 00 00
//00 00 00
Animal::~Animal() {
	world.organisms.DELETE_ELEMENT(this);
}

void Animal::checkField(int newX, int newY) {
	if(newX >= 0 && 
		newX < world.getWidth() && 
		newY >= 0 && 
		newY < world.getHeight()) 
	{
		tab[0][numberOfAvailableFields] = newX;
		tab[1][numberOfAvailableFields] = newY;
		numberOfAvailableFields++;
	}
}

void Animal::move() {
	numberOfAvailableFields = 0;
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

void Animal::action() {
	if (x != xX || y != yY) {
		if (world.tab[xX][yY].organism == nullptr) {
			display();
		}
		else if(world.tab[xX][yY].organism->getName() != "zolw") {
			conflict();
		}
		else if(strength >= 5) {
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
