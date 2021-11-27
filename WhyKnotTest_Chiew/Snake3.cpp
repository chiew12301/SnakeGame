#include "Snake3.h"

Snake3::Snake3(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	Symbol = '#';
	speed = 6;
	updateDelayTimer = 0;
	updateDelayDuration = 60; // time for next update
}

void Snake3::Update(int elapsedTime)
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
