#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include "world.h"
#include "organism.h"
#include "Human.h"
#include "Animals.cpp"

using namespace std;

//ustawia kursor w konsoli na 0,0
//przez co plansza sie nadpisuje
void goToxy(int x, int y)
{
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

int main()
{
	srand((unsigned)time(NULL));

	Human human(0, 0);
	Wilk wilk;

	world.drawWorld();
	goToxy(0, 0);
	while (!world.gameOver) {
		if (_kbhit())
		{
			human.control();
			goToxy(0, 0);
		}
	}
	return 0;
}
