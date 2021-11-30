#include "HashSnake.h"

HashSnake::HashSnake(int startXpos, int startYpos, int bWidth, int bHeight) : Snake(startXpos, startYpos, bWidth, bHeight)
{
	m_Symbol = '#';
	m_speed = 6;
}

void HashSnake::Update(float dt)
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
