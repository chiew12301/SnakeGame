#include "Snake1.h"

Snake1::Snake1(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	Symbol = '@';
	speed = 4;
	updateDelayTimer = 0;
	updateDelayDuration = 60; // time for next update
}

void Snake1::Update(int elapsedTime)
{
	moveTimer = elapsedTime;
	updateDelayTimer += elapsedTime;
	if (updateDelayTimer < updateDelayDuration)
	{
		return;
	}
	updateDelayTimer %= updateDelayDuration;
	UpdateMove(elapsedTime);
}
