#include "Food.h"

Food::Food(int startxPos, int startyPos, int bWidth, int bHeight)
{
	m_transform.setPosition(startxPos, startyPos);
	m_boardWidth = bWidth;
	m_boardHeight = bHeight;
}

void Food::Update()
{
	//let the child do the work
}

char Food::getFoodSymbol()
{
	return m_Symbol;
}

int Food::getXpos()
{
	return m_transform.getXPosition();
}

int Food::getYpos()
{
	return m_transform.getYPosition();
}

int Food::getFoodScore()
{
	return m_food_Score;
}

void Food::Reposition(std::vector<Transform> ListofsnakeBody, std::vector<Food*> ListofFoodTransform)
{
	int newXPos, newYPos;
	bool isCollapse = false;
	int max_ValueWidth = m_boardWidth - 1;
	int max_ValueHeight = m_boardHeight - 1;
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

	m_transform.setPosition(newXPos, newYPos);
}
