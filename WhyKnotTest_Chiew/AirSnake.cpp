#include "AirSnake.h"

AirSnake::AirSnake(int startXpos, int startYpos, int bWidth, int bHeight, std::string boardName) : Snake(startXpos, startYpos, bWidth, bHeight, boardName)
{
	this->m_Symbol = '@';
	this->m_speed = 4;
}

void AirSnake::Update(float dt, ObjectCreation* objCreator)
{
	if (this->m_latestTime == 0)
	{
		this->m_latestTime = dt;
	}
	if (dt >= this->m_latestTime + (1/ this->m_speed))
	{
		UpdateMove(dt, objCreator);
		this->m_latestTime = dt;
	}
	else
	{
		return;
	}

}
