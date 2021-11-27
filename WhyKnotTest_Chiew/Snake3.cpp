#include "Snake3.h"

Snake3::Snake3(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	Symbol = '#';
	speed = 6;
}

void Snake3::Update(float dt)
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
