#include "animal.h"
#include "plant.h"

void Animal::action() {
	world.tab[x][y].setSign(' ');
	world.tab[x][y].organism = nullptr;

	changeXY(xX, yY);

	if (world.tab[x][y].organism == nullptr) {
		world.tab[x][y].organism = this;
		world.tab[x][y].setSign(this->getSign());
	}
	else if(Animal* animal = dynamic_cast<Animal*>(world.tab[x][y].organism)) {
		std::cout<<this->name;
	}
	else if(Plant* plant = dynamic_cast<Plant*>(world.tab[x][y].organism)){

	}
}
void Animal::conflict() {

}
void Animal::display() {

}
