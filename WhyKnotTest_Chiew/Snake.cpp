#include "Snake.h"

Snake::Snake(int startXpos, int startYpos, int bWidth, int bHeight, std::string boardName)
{
	this->m_Transform.setPosition(startXpos, startYpos);
	this->m_boardWidth = bWidth;
	this->m_boardHeight = bHeight;
	this->m_CurrentBodySize = 1;
	this->m_direction.setPosition(0,1);
	this->m_latestTime = 0.0f;
	this->m_currentBoardName = boardName;
	this->m_bodyTransform.push_back(m_Transform);
}

void Snake::Update(float dt, ObjectCreation* objCreator)
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
/// <para>Set Transform X position to move left -1, right 1. Set Transform Y position to move up -1, down 1</para>
/// </summary>
void Snake::changeDirection(Transform dir)
{
	if (this->getBody().size() > 1)
	{
		if ((dir.getXPosition() >= 1 && this->m_direction.getXPosition() <= -1) || (dir.getXPosition() <= -1 && this->m_direction.getXPosition() >= 1))
		{
			//means going back to body it will not run. For X
		}
		else if ((dir.getYPosition() >= 1 && this->m_direction.getYPosition() <= -1) || (dir.getYPosition() <= -1 && this->m_direction.getYPosition() >= 1))
		{
			////means going back to body it will not run. For Y
		}
		else
		{
			this->m_direction = dir;
		}
	}
	else
	{
		this->m_direction = dir;
	}

}

Transform Snake::getDirection()
{
	return this->m_direction;
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

void Snake::UpdateMove(float dt, ObjectCreation* objCreator)
{
	this->m_Transform.setPosition(this->m_Transform.getXPosition() + this->m_direction.getXPosition(), this->m_Transform.getYPosition() + this->m_direction.getYPosition());
	//Checking for exiting border
	if (this->m_Transform.getYPosition() - this->m_direction.getYPosition() <= 0) //because the map generation method was start 1 for Y pos means 0 is wall.
	{
		this->m_Transform.setPosition(this->m_Transform.getXPosition(), this->m_boardHeight - (this->m_direction.getYPosition() - this->m_Transform.getYPosition()));
	}
	else if (this->m_Transform.getYPosition()> this->m_boardHeight)
	{
		this->m_Transform.setPosition(this->m_Transform.getXPosition(), (this->m_Transform.getYPosition()) - this->m_boardHeight);
	}
	else if (this->m_Transform.getXPosition() - this->m_direction.getXPosition() < 0) //because the map generation method was start 0 for x pos.
	{
		this->m_Transform.setPosition(this->m_boardWidth - (this->m_direction.getXPosition() - this->m_Transform.getXPosition()), this->m_Transform.getYPosition());
	}
	else if (this->m_Transform.getXPosition() >= this->m_boardWidth)
	{
		this->m_Transform.setPosition((this->m_Transform.getXPosition()) - this->m_boardWidth, this->m_Transform.getYPosition());
	}

	//checking for the inner wall
	if (this->m_currentBoardName != "DefaultBoard") //ignore default
	{
		if (objCreator->getWallObjectsList().size() > 0)//enter if there's one or more
		{
			for (int i = 0; i < objCreator->getWallObjectsList().size(); i++)
			{
				if (this->m_direction.getXPosition() == -1 &&
					this->m_Transform.getXPosition() == objCreator->getWallObjectsList()[i]->getTransform().getXPosition() &&
					this->m_Transform.getYPosition() == objCreator->getWallObjectsList()[i]->getTransform().getYPosition()) //moving left
				{
					this->m_Transform.setPosition(objCreator->getWallObjectsList()[i + 1]->getTransform().getXPosition() - 1, objCreator->getWallObjectsList()[i + 1]->getTransform().getYPosition());
				}
				else if (this->m_direction.getXPosition() == 1 &&
					this->m_Transform.getXPosition() == objCreator->getWallObjectsList()[i]->getTransform().getXPosition() &&
					this->m_Transform.getYPosition() == objCreator->getWallObjectsList()[i]->getTransform().getYPosition()) //moving right
				{
					this->m_Transform.setPosition(objCreator->getWallObjectsList()[i - 1]->getTransform().getXPosition() + 1, objCreator->getWallObjectsList()[i - 1]->getTransform().getYPosition());
				}
				else if (this->m_direction.getYPosition() == -1 &&
					this->m_Transform.getXPosition() == objCreator->getWallObjectsList()[i]->getTransform().getXPosition() &&
					this->m_Transform.getYPosition() == objCreator->getWallObjectsList()[i]->getTransform().getYPosition()) //moving Up
				{
					this->m_Transform.setPosition(objCreator->getWallObjectsList()[i]->getTransform().getXPosition(), (this->m_boardHeight - objCreator->getWallObjectsList()[i]->getTransform().getYPosition()));
				}
				else if (this->m_direction.getYPosition() == 1 &&
					this->m_Transform.getXPosition() == objCreator->getWallObjectsList()[i]->getTransform().getXPosition() &&
					this->m_Transform.getYPosition() == objCreator->getWallObjectsList()[i]->getTransform().getYPosition()) //moving Down
				{
					this->m_Transform.setPosition(objCreator->getWallObjectsList()[i]->getTransform().getXPosition(),
						((objCreator->getWallObjectsList()[i]->getTransform().getYPosition() - (objCreator->getWallObjectsList()[i]->getTransform().getYPosition() - 1)) + (this->m_boardHeight - objCreator->getWallObjectsList()[i]->getTransform().getYPosition())));
				}
			}
		}
	}	

	this->m_bodyTransform.push_back(this->m_Transform);
	if (this->m_bodyTransform.size() > this->m_CurrentBodySize)
	{
		this->m_bodyTransform.erase(this->m_bodyTransform.begin());
	}
}
