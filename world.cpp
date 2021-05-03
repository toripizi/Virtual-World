#include "world.h"
#include "animal.h"
#include "animals.cpp"

World::World(int H, int W) : height(H), width(W) {
	tab = new Square * [H];
	for (int i = 0; i < H; i++) {
		tab[i] = new Square[W];
	}
	
	Owca* owca[50]{};
	for(int i = 0; i < 50; i++) {
		owca[i] = new Owca;
	}

	Lis* lis[20]{};
	for (int i = 0; i < 20; i++) {
		lis[i] = new Lis;
	}

	Wilk* wilk[1]{};
	for (int i = 0; i < 1; i++) {
		wilk[i] = new Wilk;
	}

	Zolw* zolw[5]{};
	for (int i = 0; i < 5; i++) {
		zolw[i] = new Zolw;
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
	for (int i = 0; i < height + 2; i++) {
		for (int j = 0; j < width + 2; j++) {
			if (i == 0 || i == height + 1 || j == 0 || j == width + 1) {
				std::cout << (char)219;
				std::cout << (char)219;
			}
			else {
				std::cout << tab[i - 1][j - 1].getSign();
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
	//nie moge tak iterowaæ
	//muszê tylko po organizmach
	//najlepiej od najmniejszego activity
}