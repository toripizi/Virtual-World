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

	cout << "C - czlowiek | ";
	cout << "W - wilk | ";
	cout << "O - owca | ";
	cout << "L - lis | ";
	cout << "Z - zolw | ";
	cout << "A - antylopa | " << endl;
	world.drawWorld();
	
	while (!world.getGameOver()) {
		if (_kbhit())
		{
			human->control();
			cout << "||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << "||||||||||||||||||||||||||||||||||||||||||||" << endl;
			goToxy(0, 0);
			cout << "C - czlowiek | ";
			cout << "W - wilk | ";
			cout << "O - owca | ";
			cout << "L - lis | ";
			cout << "Z - zolw | ";
			cout << "A - antylopa | " << endl;
			world.drawWorld();
		}
	}


	return 0;
}
