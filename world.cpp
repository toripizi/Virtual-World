#include "world.h"

void World::drawWorld() {
	for (int i = 0; i < height + 1; i++) {
		for (int j = 0; j < width + 1; j++) {
			if (i == 0 || i == height || j == 0 || j == width) {
				std::cout << (char)219;
				std::cout << (char)219;
			}
			else {
				std::cout << tab[i - 1][j - 1].getSign();
				std::cout << tab[i - 1][j - 1].getSign();
			}
		}
		std::cout << std::endl;
	}
}

void World::setGameOver() {
	gameOver = true;
}

void World::nextTurn() {

}