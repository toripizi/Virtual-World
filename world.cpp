#include "world.h"
#include "animal.h"
#include "animals.cpp"

World::World(int H, int W) : height(H), width(W) {
	const int numberOfOwca = 395;
	const int numberOfLis = 1;
	const int numberOfWilk = 1;
	const int numberOfZolw = 1;
	const int numberOfAntylopa = 1;

	tab = new Square * [W];
	for (int i = 0; i < W; i++) {
		tab[i] = new Square[H];
	}
	
	Owca* owca[numberOfOwca]{};
	for(int i = 0; i < numberOfOwca; i++) {
		owca[i] = new Owca;
	}

	Lis* lis[numberOfLis]{};
	for (int i = 0; i < numberOfLis; i++) {
		lis[i] = new Lis;
	}

	Wilk* wilk[numberOfWilk]{};
	for (int i = 0; i < numberOfWilk; i++) {
		wilk[i] = new Wilk;
	}

	Zolw* zolw[numberOfZolw]{};
	for (int i = 0; i < numberOfZolw; i++) {
		zolw[i] = new Zolw;
	}

	Antylopa* antylopa[numberOfAntylopa]{};
	for (int i = 0; i < numberOfAntylopa; i++) {
		antylopa[i] = new Antylopa;
	}
}

//World::~World();
int World::getHeight() {
	return height;
}

int World::getWidth() {
	return width;
}

void World::drawWorld() {
	cout << "C - czlowiek | ";
	cout << "W - wilk | ";
	cout << "O - owca | ";
	cout << "L - lis | ";
	cout << "Z - zolw | ";
	cout << "A - antylopa | " << endl;

	for (int i = 0; i < height + 2; i++) {
		for (int j = 0; j < width + 2; j++) {
			if (i == 0 || i == height + 1 || j == 0 || j == width + 1) {
				std::cout << (char)219;
				std::cout << (char)219;
			}
			else {
				std::cout << tab[j - 1][i - 1].getSign();
				cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

void World::setGameOver() {
	gameOver = true;
}

const bool World::getGameOver(){
	return gameOver;
}

void World::nextTurn() {
	world.organisms.MAKE_ACTION();
}