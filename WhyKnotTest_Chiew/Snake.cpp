#include "Snake.h"

Snake::Snake(int startXpos, int startYpos, int bWidth, int bHeight)
{
	xPos = startXpos;
	yPos = startYpos;
	boardWidth = bWidth;
	boardHeight = bHeight;
	direction = 'S';
}

void Snake::Update()
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
