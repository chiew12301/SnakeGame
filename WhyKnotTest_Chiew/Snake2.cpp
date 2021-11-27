#include "Snake2.h"

Snake2::Snake2(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	Symbol = 'O';
	speed = 5;
}

void Snake2::Update(float dt)
{
	if (latestTime == 0)
	{
		latestTime = dt;
	}
	if (dt >= latestTime + (1 / speed))
	{
		UpdateMove(dt);
		latestTime = dt;
	}
	else
	{
		return;
	}
}