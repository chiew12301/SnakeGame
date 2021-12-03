#include "Food.h"

Food::Food(int startxPos, int startyPos, int bWidth, int bHeight)
{
	this->m_transform.setPosition(startxPos, startyPos);
	this->m_boardWidth = bWidth;
	this->m_boardHeight = bHeight;
}

void Food::Update()
{
	//let the child do the work
}

char Food::getFoodSymbol()
{
	return this->m_Symbol;
}

int Food::getXpos()
{
	return this->m_transform.getXPosition();
}

int Food::getYpos()
{
	return this->m_transform.getYPosition();
}

int Food::getFoodScore()
{
	return this->m_food_Score;
}

void Food::Reposition(std::vector<Transform> ListofsnakeBody, std::vector<Food*> ListofFoodTransform)
{
	int newXPos, newYPos;
	bool isCollapse = false;
	int max_ValueWidth = this->m_boardWidth - 1;
	int max_ValueHeight = this->m_boardHeight - 1;
	do
	{
		isCollapse = false;
		newXPos = 1 + (rand() % max_ValueWidth);
		newYPos = 1 + (rand() % max_ValueHeight);

		for (int i = 0; i < ListofsnakeBody.size(); i++)
		{
			if (newXPos == ListofsnakeBody[i].getXPosition() && newYPos == ListofsnakeBody[i].getYPosition())
			{
				isCollapse = true;
			}
		}

		for (int j = 0; j < ListofFoodTransform.size(); j++)
		{
			if (newXPos == ListofFoodTransform[j]->getXpos() && newYPos == ListofFoodTransform[j]->getYpos())
			{
				isCollapse = true;
			}
		}

	} while ((newXPos == getXpos() && newYPos == getYpos()) || isCollapse == true);

	this->m_transform.setPosition(newXPos, newYPos);
}
