#include <iostream>
#include <conio.h>
#include <time.h>

#include "world.h"
#include "organism.h"
#include "Human.h"
#include "Animals.cpp"
#include "List.h"

using namespace std;

int option;
Human* human;

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

void report() {
	cout << "SILA: " << human->getStrength() << endl;
	cout << "niesmiertelnosc: " << human->getImmortality() << endl;
	cout << "szybkosc antylopy: ";
	if (human->getDistance() == 2) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	cout << endl;
	cout << "liczba tur do mozliwosci wlaczenia spejcjalnej umiejestnosci: " << human->getNumberOfTurns();
	cout << " || 0 - niesmiertelnosc, 2 - szybkosc antylopy " << endl;
	cout << "Jesli chcesz zapisac stan gry wcisnij 'x'"<<endl;
	cout << "liczba organizmow: " << world.organisms.size() << endl;
	cout << "C - czlowiek | W - wilk | O - owca | L - lis | Z - zolw | A - antylopa | ";
	cout << " T - trawa | M - mlecz | G - guarana | J - wilcze jagody | B - barszcz sosnowskiego" << endl;
}

void menu() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 4);
	cout << " MENU" << endl;
	cout << "1.";
	SetConsoleTextAttribute(hOut, 15);
	cout << " Zagraj od nowa" << endl;
	SetConsoleTextAttribute(hOut, 4);
	cout << "2.";
	SetConsoleTextAttribute(hOut, 15);
	cout << " Wczytaj z pliku" << endl;
	cout << "Wybierz: ";
	do {
		cin >> option;
		cout << "Nie poprawny numer" << endl;
		cout << "Wybierz ponownie: ";
	} while (option != 1 && option != 2);
	system("CLS");
	if (option == 1) {
		//NOWA GRA
		world.initTab();
		world.init();
		human = new Human;
		report();
		world.drawWorld();
	}
	else if (option == 2) {
		//WCZYTAJ GRE
		world.loadWorldFromFile();
		human = new Human(world.getHumanX(), world.getHumanY());
		report();
		world.drawWorld();
	}
}



int main()
{
	//World::setWorld();
	menu();
	int d = 0;

	while (!world.getGameOver()) {
		if (_kbhit())
		{
			human->control();
			
			for (int i = 0; i < 200; i++) cout << "||||";
			
			goToxy(0, 0);
			
			report();
			
			world.drawWorld();
		}
		if (world.getGameOver()) {
			cout << "Przegrales :///////////////////";
			cout << endl << "napisz cos aby wyjsc z gry";
			int o;
			cin >> o;
		}
	}

	//delete &world;

	return 0;
}
