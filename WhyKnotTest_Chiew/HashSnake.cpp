#include "HashSnake.h"

HashSnake::HashSnake(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	this->m_Symbol = '#';
	this->m_speed = 6;
}

void HashSnake::Update(float dt)
{
	if (this->m_latestTime == 0)
	{
		this->m_latestTime = dt;
	}
	if (dt >= this->m_latestTime + (1 / this->m_speed))
	{
		UpdateMove(dt);
		this->m_latestTime = dt;
	}
	else
	{
		return;
	}
}
