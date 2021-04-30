#pragma once
#include "Square.h"
#include <iostream>

class World
{
	int height = 20;
	int width = 20;

public:
	Square** tab;

	bool gameOver = false;
	World(int H, int W) : height(H), width(W) {
		tab = new Square *[H];
		for (int i = 0; i < H; i++) {
			tab[i] = new Square[W];
		}
	}

	//~World();

	void nextTurn();
	void drawWorld();
	void setGameOver();
};
inline World world(20, 20);

