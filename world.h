#pragma once
#include "Square.h"
#include "organism.h"
#include <iostream>
#include "List.h"


class World
{
	int height = 20;
	int width = 20;
	bool gameOver = false;
public:
	Square** tab;
	List organisms;

	World(int H, int W);
	
	//~World();
	int getHeight();
	int getWidth();

	void nextTurn();
	void drawWorld();
	void setGameOver();
	const bool getGameOver();
};
inline World world(40, 100);
