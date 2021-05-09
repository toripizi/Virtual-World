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
	if (!this->getBaby()) {
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
	else {
		this->setBaby(false);
	}
}

void Animal::action() {
	if (x != xX || y != yY) {
		if (world.tab[xX][yY].organism == nullptr) {
			display();
		}
		else if (world.tab[xX][yY].organism->getName() != "zolw" ) {
			world.tab[xX][yY].organism->conflict(this);
		}
		else if (this->getName() == "zolw") {
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

void Animal::checkFieldToChild(int newX, int newY) {
	if (newX >= 0 &&
		newX < world.getWidth() &&
		newY >= 0 &&
		newY < world.getHeight() &&
		World->tab[newX][newY].organism == nullptr)
	{
		tab[0][numberOfAvailableFields] = newX;
		tab[1][numberOfAvailableFields] = newY;
		numberOfAvailableFields++;
	}
}

int Animal::duplicate() {
	numberOfAvailableFields = 0;
	checkFieldToChild(x - 1, y);
	checkFieldToChild(x - 1, y + 1);
	checkFieldToChild(x, y + 1);
	checkFieldToChild(x + 1, y + 1);
	checkFieldToChild(x + 1, y);
	checkFieldToChild(x + 1, y - 1);
	checkFieldToChild(x, y - 1);
	checkFieldToChild(x - 1, y - 1);

	return numberOfAvailableFields;
}

void Animal::conflict(Organism* enemy) {
	if (Animal* animal = dynamic_cast<Animal*>(enemy)) {
		if (enemy->getName() == this->getName()) {
			//rozmna¿anie 
			//duplicate() sprawdza czy s¹ gdzies wolne miejsca
			int numberOfAvailableFieldsThis = this->duplicate();
			int numberOfAvailableFieldsAnimal = animal->duplicate();
			int razem = numberOfAvailableFieldsThis + numberOfAvailableFieldsAnimal;
			//sumuje wszytskie wolne miejsca
			if (razem) {
				//jeœli istniej¹
				//losuje jedno z nich
				int random = rand() % razem;
				//sprawdzam czy wylosowana liczba miesci sie w zakresie dostepnych pól dla this
				if (random < numberOfAvailableFieldsThis) {
					this->createChild(this->tab[0][random], this->tab[1][random]);
				}
				else {
					// jesli nie 
					//to dziecko rodzi sie na polu dostepnemu dla animal
					animal->createChild(
						animal->tab[0][random-numberOfAvailableFieldsThis],
						animal->tab[1][random-numberOfAvailableFieldsThis]);
					//createChild(int x, int y)
					//tworzy nowe zwierze
					//metoda ta jest zadeklarowna w ka¿dym zwierzêciu osobno
				}
			}
		}
		else if (enemy->getStrength() >= this->strength) {
			//atakuj¹cy wygrywa
			//wyœwietlam atakuj¹cego na nowym polu
			enemy->display();

			//komunikat
			//cout << this->getName() << " zostal zjedzony przez: " << enemy->getName() << " ||| ";

			//jeœli this jest cz³owiek, koñczymy gre
			if (Human* human = dynamic_cast<Human*>(this)) {
				world.setGameOver();
			}

			//usuwam this
			delete this;
		}
		else {
			//atakuj¹cy przegrywa
			//wiêc ustawiam jego polna na puste
			world.tab[enemy->getX()][enemy->getY()].setSign(' ');
			world.tab[enemy->getX()][enemy->getY()].organism = nullptr;

			//komunikat
			//cout << enemy->getName() << " zostal zjedzony przez: " << this->getName() << " ||| ";

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
