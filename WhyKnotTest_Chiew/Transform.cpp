#include "Transform.h"

int Transform::getXPosition()
{
	return m_xPosition;
}

int Transform::getYPosition()
{
	return m_yPosition;
}

void Transform::setPosition(int newXPos, int newYPos)
{
	m_xPosition = newXPos;
	m_yPosition = newYPos;
}
