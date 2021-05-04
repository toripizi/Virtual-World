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
void Animal::conflict(Organism* enemy) {
	if (Animal* animal = dynamic_cast<Animal*>(enemy)) {
		if (enemy->getStrength() >= this->strength) {
			//wyœwietlam atakuj¹cego na nowym polu
			enemy->display();

			//komunikat
			cout << this->getName() << " zostal zjedzony przez: " << enemy->getName() << endl;

			//usuwam this
			delete this;
		}
		else {
			//atakuj¹cy przegrywa
			//wiêc ustawiam jego polna na puste
			world.tab[enemy->getX()][enemy->getY()].setSign(' ');
			world.tab[enemy->getX()][enemy->getY()].organism = nullptr;

			//komunikat
			cout << enemy->getName() << " zostal zjedzony przez: " << this->getName() << endl;

			//jeœli atakuj¹cym jest cz³owiek, koñczymy gre
			if (Human* human = dynamic_cast<Human*>(enemy)) {
				world.setGameOver();
			}

			//usuwam atakuj¹cego
			delete animal;
		}
	}
	else if (Plant* plant = dynamic_cast<Plant*>(world.tab[xX][yY].organism)) {
	}
}
void Animal::display() {
	//this wygrywa
	//wiec ustawiam jego pola na puste
	world.tab[x][y].setSign(' ');
	world.tab[x][y].organism = nullptr;
	
	//zmieniam x i y na xX i yY
	changeXY(xX, yY);
	
	//ustawiam nowe pole na this
	world.tab[x][y].organism = this;
	world.tab[x][y].setSign(this->getSign());
}
