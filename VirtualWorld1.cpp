#include <iostream>
#include <windows.h>
#include <conio.h>
#include "world.h"

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
void watchQuit() {
	unsigned char znak = _getch();
	switch (znak)
	{
		//ESC
	case 27: //klawisze specjalne
		world.gameOver = true;
		break;
	}
}
int main()
{
	while (!world.gameOver) {
		if (_kbhit())
		{
			watchQuit();
		}
		world.drawWorld();
		goToxy(0, 0);
	}
	return 0;
}
