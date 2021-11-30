#include "Snake.h"

Snake::Snake(int startXpos, int startYpos, int bWidth, int bHeight)
{
	m_Transform.setPosition(startXpos, startYpos);
	m_boardWidth = bWidth;
	m_boardHeight = bHeight;
	m_CurrentBodySize = 1;
	m_MaxBodySize = 10;
	m_direction = 2;
	m_latestTime = 0.0f;

	m_bodyTransform.push_back(m_Transform);
}

void Snake::Update(float dt)
{
	//sub class will handle themself
}

char Snake::getSnakeSymbol()
{
	return m_Symbol;
}

int Snake::getXpos()
{
	return m_Transform.getXPosition();
}

int Snake::getYpos()
{
	return m_Transform.getYPosition();
}

/// <summary>Change Direction is a method that change the snake direction.
/// <para>'W' as up, 'S' as down, 'A' as left, 'D' as right</para>
/// </summary>
void Snake::changeDirection(int dir)
{
	m_direction = dir;
}

void Snake::GrowBody()
{//add body into the vector list
	if (m_CurrentBodySize < m_MaxBodySize)
	{
		m_CurrentBodySize++;
	}
}

std::vector<Transform> Snake::getBody()
{
	return m_bodyTransform;
}

bool Snake::collision(int colliderXpos, int colliderYpos)
{
	for (int i = 0; i < m_bodyTransform.size(); i++)
	{
		if (colliderXpos == m_bodyTransform[i].getXPosition() && colliderYpos == m_bodyTransform[i].getYPosition())
		{
			return true;
		}
	}	
	return false;
}

void Snake::UpdateMove(float dt)
{
	switch (m_direction)
	{
	case(1):
		if (m_Transform.getYPosition() - 1 <= 0)
		{
			m_Transform.setPosition(m_Transform.getXPosition(), m_boardHeight - (1 - m_Transform.getYPosition()));
		}
		else
		{
			m_Transform.setPosition(m_Transform.getXPosition(), m_Transform.getYPosition() - 1);
		}
		break;
	case(2):
		if (m_Transform.getYPosition() + 1 > m_boardHeight)
		{
			m_Transform.setPosition(m_Transform.getXPosition(), (m_Transform.getYPosition()) - m_boardHeight);
		}
		else
		{
			m_Transform.setPosition(m_Transform.getXPosition(), m_Transform.getYPosition() + 1);
		}
		break;
	case(3):
		if (m_Transform.getXPosition() - 1 < 0)
		{
			m_Transform.setPosition(m_boardWidth - (1 - m_Transform.getXPosition()), m_Transform.getYPosition());
		}
		else
		{
			m_Transform.setPosition(m_Transform.getXPosition() - 1, m_Transform.getYPosition());
		}
		break;
	case(4):
		if (m_Transform.getXPosition() + 1 >= m_boardWidth)
		{
			m_Transform.setPosition((m_Transform.getXPosition() + 1) - m_boardWidth, m_Transform.getYPosition());
		}
		else
		{
			m_Transform.setPosition(m_Transform.getXPosition() + 1, m_Transform.getYPosition());
		}
		break;
	}

	m_bodyTransform.push_back(m_Transform);
	if (m_bodyTransform.size() > m_CurrentBodySize)
	{
		m_bodyTransform.erase(m_bodyTransform.begin());
	}
}
