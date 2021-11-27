#include "Snake.h"

Snake::Snake(int startXpos, int startYpos, int bWidth, int bHeight)
{
	xPos = startXpos;
	yPos = startYpos;
	boardWidth = bWidth;
	boardHeight = bHeight;
	direction = 'S';
}

void Snake::Update(int elapsedTime)
{
	//sub class will handle themself
}

char Snake::getSnakeSymbol()
{
	return Symbol;
}

int Snake::getXpos()
{
	return xPos;
}

int Snake::getYpos()
{
	return yPos;
}

/// <summary>Change Direction is a method that change the snake direction.
/// <para>'W' as up, 'S' as down, 'A' as left, 'D' as right</para>
/// </summary>
void Snake::changeDirection(char dir)
{
	direction = dir;
}

bool Snake::collision(int colliderXpos, int colliderYpos)
{
	if (colliderXpos == xPos && colliderYpos == yPos)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

void Snake::UpdateMove(int elapsedTime)
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
