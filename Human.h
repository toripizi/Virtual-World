#pragma once
#include "animal.h"

class Human :public Animal
{
	bool immortality = true;
	int numberOfTurns = 0;
	void skill1();
	bool baby = false;
public:
	Human();
	~Human();
	void move() override {}
	void action() override {
		if (x != xX || y != yY) {
			if (world.tab[xX][yY].organism == nullptr) {
				display();
			}
			else if (world.tab[xX][yY].organism->getStrength() > strength) {
				xX = x;
				yY = y;
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
	void conflict(Organism* enemy) override {
		if (immortality && enemy->getStrength() > strength) {
			numberOfAvailableFields = 0;
			Animal::checkFieldToChild(x - 1, y);
			Animal::checkFieldToChild(x - 1, y + 1);
			Animal::checkFieldToChild(x, y + 1);
			Animal::checkFieldToChild(x + 1, y + 1);
			Animal::checkFieldToChild(x + 1, y);
			Animal::checkFieldToChild(x + 1, y - 1);
			Animal::checkFieldToChild(x, y - 1);
			Animal::checkFieldToChild(x - 1, y - 1);

			if (numberOfAvailableFields) {
				int random = rand() % numberOfAvailableFields;
				xX = tab[0][random];
				yY = tab[1][random];
				Animal::action();
				enemy->display();

				//komunikat
				cout << this->getName() << " jest niesmiertelny wiec przesuwa sie na inne miejsce, atakujacy: " << enemy->getName() << " ||| ";
			}
			else{
				int str = strength;
				strength = enemy->getStrength() + 1;
				Animal::conflict(enemy);
				strength = str;
			}
		}
		else Animal::conflict(enemy);
	}
	void control();
	void createChild(int xxx, int yyy) override {}
	int getImmortality();
};

