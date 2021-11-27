#include "Food.h"

Food::Food(int startxPos, int startyPos, int bWidth, int bHeight)
{
	xPos = startxPos;
	yPos = startyPos;
	boardWidth = bWidth;
	boardHeight = bHeight;
}

void Food::Update()
{
	//let the child do the work
}

char Food::getFoodSymbol()
{
	return Symbol;
}

int Food::getXpos()
{
	return xPos;
}

int Food::getYpos()
{
	return yPos;
}

void Food::Reposition()
{
	randomizePosition:
	int newXPos = rand() % boardWidth;
	int newYPos = rand() % boardHeight;

	if (newXPos == xPos && newYPos == yPos)
	{ //reposition coz is the same
		goto randomizePosition;
	}
	else
	{
		xPos = newXPos;
		yPos = newYPos;
	}
}
