#pragma once
#include "Square.h"
#include "organism.h"
#include <iostream>
#include "List.h"
#include <fstream>


class World
{
	struct File
	{
		int x = 0;
		int y = 0;
		string name = "human";
	};
	int height = 20;
	int width = 20;
	bool gameOver = false;
	int humanX = 0;
	int humanY = 0;
public:
	//static World* wo;
	
	Square** tab{};
	List organisms;

	World(int H, int W);
	
	/*static void setWorld() {
		wo = new World(20, 20);
	}*/
	~World();
	const int getHeight();
	const int getWidth();

	const int getHumanX();
	const int getHumanY();

	void nextTurn();
	void drawWorld();
	void setGameOver();
	const bool getGameOver();
	void loadWorldFromFile();
	void writeWorldToFile();
	void init();
	void initTab();
};
inline World world(10, 10);
