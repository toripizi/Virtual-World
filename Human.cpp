#include "Human.h"
#include <conio.h>

void Human::control() {
	unsigned char znak = _getch();
	switch (znak)
	{
	case 224: //klawisze specjalne
		znak = _getch();
		switch (znak)
		{
		case 72: //strza³ka w dol
			
			break;
		case 80: //strza³ka w gore
			
			break;
		case 75: //strza³ka w lewo
			
			break;
		case 77: //strza³ka w prawo
			
			break;
		}
		break;
	}
}