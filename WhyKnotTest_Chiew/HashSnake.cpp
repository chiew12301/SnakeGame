#include "HashSnake.h"

HashSnake::HashSnake(int startXpos, int startYpos, int bWidth, int bHeight, std::string boardName) : Snake(startXpos, startYpos, bWidth, bHeight, boardName)
{
	this->m_Symbol = '#';
	this->m_speed = 6;
}

void HashSnake::Update(float dt, ObjectCreation* objCreator)
{
	if (this->m_latestTime == 0)
	{
		this->m_latestTime = dt;
	}
	if (dt >= this->m_latestTime + (1 / this->m_speed))
	{
		UpdateMove(dt, objCreator);
		this->m_latestTime = dt;
	}
	else
	{
		return;
	}
}
