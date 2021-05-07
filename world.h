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
	//static World* wo;
	
	Square** tab;
	List organisms;

	World(int H, int W);
	
	/*static void setWorld() {
		wo = new World(20, 20);
	}*/
	//~World();
	int getHeight();
	int getWidth();

	void nextTurn();
	void drawWorld();
	void setGameOver();
	const bool getGameOver();
};
inline World world(40, 100);
