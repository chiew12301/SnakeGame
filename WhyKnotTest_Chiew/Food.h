#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
//reason of it was snake was a sub class based. So it can't be used all header file. Meant to designed as "Game Object" typed.

class Food
{
protected:
	int boardWidth;
	int boardHeight;
	int xPos;
	int yPos;
	char Symbol;
public:
	Food(int startxPos, int startyPos, int bWidth, int bHeight);
	virtual void Update();
	char getFoodSymbol();
	int getXpos();
	int getYpos();
	void Reposition();
};

