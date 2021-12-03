#include "OakSnake.h"

OakSnake::OakSnake(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	this->m_Symbol = 'O';
	this->m_speed = 5;
}

void OakSnake::Update(float dt)
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