#include "AirSnake.h"

AirSnake::AirSnake(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	this->m_Symbol = '@';
	this->m_speed = 4;
}

void AirSnake::Update(float dt)
{
	if (this->m_latestTime == 0)
	{
		this->m_latestTime = dt;
	}
	if (dt >= this->m_latestTime + (1/ this->m_speed))
	{
		UpdateMove(dt);
		this->m_latestTime = dt;
	}
	else
	{
		return;
	}

}
