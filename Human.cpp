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
		case 72: //strza�ka w dol
			
			break;
		case 80: //strza�ka w gore
			
			break;
		case 75: //strza�ka w lewo
			
			break;
		case 77: //strza�ka w prawo
			
			break;
		}
		break;
	}
}