#include "Snake1.h"

Snake1::Snake1(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	Symbol = '@';
	speed = 4;
}

void Snake1::Update(float dt)
{
	if (latestTime == 0)
	{
		latestTime = dt;
	}
	if (dt >= latestTime + (1/speed))
	{
		UpdateMove(dt);
		latestTime = dt;
	}
	else
	{
		return;
	}

}
