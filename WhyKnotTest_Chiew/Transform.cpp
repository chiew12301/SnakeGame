#include "Transform.h"

int Transform::getXPosition()
{
	return this->m_xPosition;
}

int Transform::getYPosition()
{
	return this->m_yPosition;
}

void Transform::setPosition(int newXPos, int newYPos)
{
	this->m_xPosition = newXPos;
	this->m_yPosition = newYPos;
}
