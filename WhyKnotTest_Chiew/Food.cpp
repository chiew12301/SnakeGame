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

void Food::Reposition(std::vector<Transform> ListofsnakeBody)
{
	int newXPos, newYPos;
	bool isSnakeBody = false;
	do
	{
		isSnakeBody = false;
		newXPos = rand() % m_boardWidth;
		newYPos = rand() % m_boardHeight;

		for (int i = 0; i < ListofsnakeBody.size(); i++)
		{
			if (newXPos == ListofsnakeBody[i].getXPosition() && newYPos == ListofsnakeBody[i].getYPosition())
			{
				isSnakeBody = true;
			}
		}

	} while ((newXPos == getXpos() && newYPos == getYpos()) || isSnakeBody == true);

	m_transform.setPosition(newXPos, newYPos);
}
