#include "plant.h"
#include "Human.h"

Plant::~Plant() {
	world.organisms.DELETE_ELEMENT(this);
}
void Plant::conflict(Organism* enemy) {
	if (Animal* animal = dynamic_cast<Animal*>(enemy)) {
		if (enemy->getStrength() >= this->strength) {
			//wy�wietlam atakuj�cego na nowym polu
			enemy->display();

			//komunikat
			cout << this->getName() << " zostal zjedzony przez: " << enemy->getName() << " ||| ";

			//usuwam this
			delete this;
		}
		else {
			//zwierze zosta�o otrute
			//wi�c ustawiam jego polna na puste
			world.tab[enemy->getX()][enemy->getY()].setSign(' ');
			world.tab[enemy->getX()][enemy->getY()].organism = nullptr;

			//komunikat
			cout << enemy->getName() << " zostal otruty przez: " << this->getName() << " ||| ";

			//je�li atakuj�cym jest cz�owiek, ko�czymy gre
			if (Human* human = dynamic_cast<Human*>(enemy)) {
				world.setGameOver();
			}

			//usuwam atakuj�cego
			delete animal;
		}
	}
}
void Plant::display() {

}
void Plant::move() {
	if (!newOne) {
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
		newOne = false;
	}
}
void Plant::checkField(int newX, int newY) {
	if (newX >= 0 &&
		newX < world.getWidth() &&
		newY >= 0 &&
		newY < world.getHeight())
	{
		if (world.tab[newX][newY].organism == nullptr) {
			tab[0][numberOfAvailableFields] = newX;
			tab[1][numberOfAvailableFields] = newY;
			numberOfAvailableFields++;
		}
	}
}
