#include "animal.h"

class Wilk : public Animal {
public:
	Wilk() {
		xX = rand() % (world.getWidth() - 1);
		yY = rand() % (world.getHeight() - 1);
		
		x = xX;
		y = yY;
		name = "wilk";
		sign = 'W';
		strength = 9;
		activity = 5;

		action();
	}
};
class Owca : public Animal {
public:
	Owca() {
		xX = rand() % (world.getWidth() - 1);
		yY = rand() % (world.getHeight() - 1);

		name = "owca";
		sign = 'O';
		strength = 4;
		activity = 3;

		action();
	}
};