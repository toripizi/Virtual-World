#include "world.h"
#include "animal.h"
#include "animals.cpp"

World::World(int H, int W) : height(H), width(W) {
	tab = new Square * [H];
	for (int i = 0; i < H; i++) {
		tab[i] = new Square[W];
	}

	Owca* owca = new Owca;
	Owca* owca2 = new Owca;
	Owca* owca3 = new Owca;
	Owca* owca4 = new Owca;
	Owca* owca5 = new Owca;
	Owca* owca6 = new Owca;
	Lis* lis = new Lis;
	Zolw* zolw = new Zolw;
	Wilk* wilk = new Wilk;

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
	//nie moge tak iterowa�
	//musz� tylko po organizmach
	//najlepiej od najmniejszego activity
}