#include "Snake2.h"

Snake2::Snake2(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	Symbol = 'O';
	speed = 5;
	updateDelayTimer = 0;
	updateDelayDuration = 60; // time for next update
}

void Snake2::Update(int elapsedTime)
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