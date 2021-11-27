#include "Snake.h"

Snake::Snake(int startXpos, int startYpos, int bWidth, int bHeight)
{
	xPos = startXpos;
	yPos = startYpos;
	boardWidth = bWidth;
	boardHeight = bHeight;
	direction = 'S';
	latestTime = 0.0f;
}

void Snake::Update(float dt)
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

void Snake::UpdateMove(float dt)
{
	switch (direction)
	{
	case('W'):
		if (yPos - 1 < 0)
		{
			yPos = boardHeight - (1 - yPos);
		}
		else
		{
			yPos -= 1;
		}
		break;
	case('S'):
		if (yPos + 1 > boardHeight)
		{
			yPos = (yPos + 1) - boardHeight;
		}
		else
		{
			yPos += 1;
		}
		break;
	case('A'):
		if (xPos - 1 < 0)
		{
			xPos = boardWidth - (1 - xPos);
		}
		else
		{
			xPos -= 1;
		}
		break;
	case('D'):
		if (xPos + 1 > boardWidth)
		{
			xPos = (xPos + 1) - boardWidth;
		}
		else
		{
			xPos += 1;
		}
		break;
	}
}
