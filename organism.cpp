#include "organism.h"
#include "world.h"

void Organism::changeXY(int newX, int newY) {
	x = newX;
	y = newY;
}

const int Organism::getX() {
	return x;
}
void Organism::setX(int newX) {
	x = newX;
}
const int Organism::getY() {
	return y;
}
void Organism::setY(int newY) {
	y = newY;
}
const int Organism::getStrength() {
	return strength;
}
const int Organism::getActivity() {
	return activity;
}

void Organism::setName(std::string newName) {
	name = newName;
}
void Organism::setSign(unsigned char newSign) {
	sign = newSign;
}
const std::string Organism::getName() {
	return name;
}
const unsigned char Organism::getSign() {
	return sign;
}