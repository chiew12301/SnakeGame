#include "Snake1.h"

Snake1::Snake1(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	Symbol = '@';
	speed = 4;
}

void Snake1::Update()
{
	switch (direction)
	{
	case('W'):
		if (yPos - speed < 0)
		{
			yPos = boardHeight - (speed - yPos);
		}
		else
		{
			yPos -= speed;
		}
		break;
	case('S'):
		if (yPos + speed > boardHeight)
		{
			yPos = (yPos + speed) - boardHeight;
		}
		else
		{
			yPos += speed;
		}
		break;
	case('A'):
		if (xPos - speed < 0)
		{
			xPos = boardWidth - (speed - xPos);
		}
		else
		{
			xPos -= speed;
		}
		break;
	case('D'):
		if (xPos + speed > boardWidth)
		{
			xPos = (xPos + speed) - boardWidth;
		}
		else
		{
			xPos += speed;
		}
		break;
	}
}
