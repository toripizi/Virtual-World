#include "Square.h"

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

const unsigned char Square::getSign() {
	return sign;
}
void Square::setSign(unsigned char newSign) {
	sign = newSign;
}
void Square::display() {
	if (organism == nullptr) {
		std::cout << "  ";
	}
	else {
		SetConsoleTextAttribute(hOut, organism->getColor());
		std::cout << sign;
		SetConsoleTextAttribute(hOut, 7);
		std::cout << " ";
	}
}
