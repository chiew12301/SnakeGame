#include "Snake.h"

Snake::Snake(int startXpos, int startYpos, int bWidth, int bHeight)
{
	this->m_Transform.setPosition(startXpos, startYpos);
	this->m_boardWidth = bWidth;
	this->m_boardHeight = bHeight;
	this->m_CurrentBodySize = 1;
	this->m_direction = UP;
	this->m_latestTime = 0.0f;

	this->m_bodyTransform.push_back(m_Transform);
}

void Snake::Update(float dt)
{
	//sub class will handle themself
}

char Snake::getSnakeSymbol()
{
	return this->m_Symbol;
}

int Snake::getXpos()
{
	return this->m_Transform.getXPosition();
}

int Snake::getYpos()
{
	return this->m_Transform.getYPosition();
}

/// <summary>Change Direction is a method that change the snake direction.
/// <para>'0' as up, '1' as down, '2' as left, '3' as right</para>
/// </summary>
void Snake::changeDirection(DIRECTION dir)
{
	this->m_direction = dir;
}

void Snake::GrowBody()
{//add body into the vector list
	this->m_CurrentBodySize++;
}

std::vector<Transform> Snake::getBody()
{
	return this->m_bodyTransform;
}

/// <summary>Collider is a method check object on the body, beaware the methods checked whole body.
/// <para>'colliderXpos' is other object of the x position, 'colliderYpos' is other object of the y position, 
/// 'isSelf' set true if is snake object set false if is not</para>
/// </summary>
bool Snake::collision(int colliderXpos, int colliderYpos, bool isSelf)
{
	int i = 0;
	if (isSelf == true)
	{
		i = 1;
	}
	for (i; i < this->m_bodyTransform.size(); i++)
	{
		if (colliderXpos == this->m_bodyTransform[i].getXPosition() && colliderYpos == this->m_bodyTransform[i].getYPosition())
		{
			return true;
		}
	}	
	return false;
}

void Snake::UpdateMove(float dt)
{
	switch (this->m_direction)
	{
	case(0):
		if (this->m_Transform.getYPosition() - 1 <= 0)
		{
			this->m_Transform.setPosition(this->m_Transform.getXPosition(), this->m_boardHeight - (1 - this->m_Transform.getYPosition()));
		}
		else
		{
			this->m_Transform.setPosition(this->m_Transform.getXPosition(), this->m_Transform.getYPosition() - 1);
		}
		break;
	case(1):
		if (this->m_Transform.getYPosition() + 1 > this->m_boardHeight)
		{
			this->m_Transform.setPosition(this->m_Transform.getXPosition(), (this->m_Transform.getYPosition()) - this->m_boardHeight);
		}
		else
		{
			this->m_Transform.setPosition(this->m_Transform.getXPosition(), this->m_Transform.getYPosition() + 1);
		}
		break;
	case(2):
		if (this->m_Transform.getXPosition() - 1 < 0)
		{
			this->m_Transform.setPosition(this->m_boardWidth - (1 - this->m_Transform.getXPosition()), this->m_Transform.getYPosition());
		}
		else
		{
			this->m_Transform.setPosition(this->m_Transform.getXPosition() - 1, this->m_Transform.getYPosition());
		}
		break;
	case(3):
		if (this->m_Transform.getXPosition() + 1 >= this->m_boardWidth)
		{
			this->m_Transform.setPosition((this->m_Transform.getXPosition() + 1) - this->m_boardWidth, this->m_Transform.getYPosition());
		}
		else
		{
			this->m_Transform.setPosition(this->m_Transform.getXPosition() + 1, this->m_Transform.getYPosition());
		}
		break;
	}

	this->m_bodyTransform.push_back(this->m_Transform);
	if (this->m_bodyTransform.size() > this->m_CurrentBodySize)
	{
		this->m_bodyTransform.erase(this->m_bodyTransform.begin());
	}
}
