#include "OakSnake.h"

OakSnake::OakSnake(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	m_Symbol = 'O';
	m_speed = 5;
}

void OakSnake::Update(float dt)
{
	if (m_latestTime == 0)
	{
		m_latestTime = dt;
	}
	if (dt >= m_latestTime + (1 / m_speed))
	{
		UpdateMove(dt);
		m_latestTime = dt;
	}
	else
	{
		return;
	}
}