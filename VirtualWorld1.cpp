#include <iostream>
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

	cout << "SILA: " << human->getStrength() << endl;
	world.drawWorld();
	
	while (!world.getGameOver()) {
		if (_kbhit())
		{
			human->control();
			
			for (int i = 0; i < 200; i++) cout << "||||";
			
			goToxy(0, 0);
			
			cout << "SILA: " << human->getStrength() << endl;
			
			world.drawWorld();
		}
		if (world.getGameOver()) {
			cout << "Przegrales :///////////////////";
			cout << endl << "napisz cos aby wyjsc z gry";
			int o;
			cin >> o;
		}
	}


	return 0;
}
