#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include "world.h"
#include "organism.h"
#include "Human.h"
#include "Animals.cpp"
#include "List.h"

using namespace std;

//ustawia kursor w konsoli na 0,0
//przez co plansza sie nadpisuje
void goToxy(int x, int y)
{
	HANDLE hCon;
	COORD dwPos{};

	dwPos.X = x;
	dwPos.Y = y;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

int main()
{
	srand((unsigned)time(NULL));

	Human* human = new Human;

	world.drawWorld();
	cout << endl << "C - czlowiek" << endl;
	cout << "W - wilk" << endl;
	cout << "O - owca" << endl;
	cout << "L - lis" << endl;
	cout << "Z - zolw" << endl;
	cout << "A - antylopa" << endl;
	goToxy(0, 0);
	while (!world.getGameOver()) {
		if (_kbhit())
		{
			human->control();
			goToxy(0, 0);
		}
	}


	return 0;
}
