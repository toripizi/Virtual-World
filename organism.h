#pragma once
#include <iostream>

class Organism
{
protected:
	int strength = 0;
	int activity = 0;
	int x = 0;
	int y = 0;
	int xX = 0;
	int yY = 0;
	std::string name = "empty";
	unsigned char sign = ' ';
	int color = 15;
	
public:
	virtual void action() = 0;
	virtual void conflict(Organism* org) = 0;
	virtual void display() = 0;
	virtual void move() = 0;
	virtual void checkField(int newX, int newY) = 0;

	void changeXY(int newX, int newY);

	const int getX();
	void setX(int newX);

	const int getY();
	void setY(int newY);
	
	const int getStrength();
	void setStrength(int newStrength);

	const int getActivity();

	const int getColor();
	void setColor(int newColor);


	void setName(std::string newName);
	const std::string getName();

	void setSign(unsigned char newSign);
	const unsigned char getSign();
};