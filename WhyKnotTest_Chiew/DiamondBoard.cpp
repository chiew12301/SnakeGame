#include "DiamondBoard.h"

void DiamondBoard::drawBoard(float dt, ObjectCreation* objCreator)
{
	for (int i = 0; i <= this->m_HEIGHT + 1; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //red
		cout << "\t\t|";
		for (int j = 0; j < this->m_WIDTH; j++)
		{
			if (i == 0 || i == this->m_HEIGHT + 1) //Top and Bottom wall
			{
				cout << "-";
			}
			else //Render Game Platform
			{
				bool isWallSpawned = false; //to force reposition the food if crash

				if (objCreator->getWallObjectsList().size() > 0) //if have wall
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //red
					if (i + j <= this->m_WIDTH / 2 || i + this->m_WIDTH / 2 - 1 <= j || (i - this->m_HEIGHT / 2 > j && i > this->m_HEIGHT / 2)
						|| (i - this->m_HEIGHT / 2 >= this->m_HEIGHT - j && i > this->m_HEIGHT / 2))
					{
						cout << objCreator->getWallObjectsList()[0]->getSymbol();
						isWallSpawned = true;
					}

					if (isWallSpawned == true)
					{
						for (int l = 0; l < objCreator->getFoodObjectsList().size(); l++) //Check Food
						{
							if (i == objCreator->getFoodObjectsList()[l]->getYpos() && j == objCreator->getFoodObjectsList()[l]->getXpos())
							{
								objCreator->getFoodObjectsList()[l]->Reposition(objCreator->getSnake()->getBody(), objCreator->getFoodObjectsList());
								break;
							}
						}
					}
				}

				if (isWallSpawned == false)
				{
					bool isBodyPart = false;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //blue
					for (int k = 0; k < objCreator->getSnake()->getBody().size(); k++) //Check Body
					{
						if (i == objCreator->getSnake()->getBody()[k].getYPosition() && j == objCreator->getSnake()->getBody()[k].getXPosition())
						{
							cout << objCreator->getSnake()->getSnakeSymbol();
							isBodyPart = true;
							break;
						}
					}
					if (isBodyPart == false) //if this is not body part, check food
					{
						bool isFoodSpawned = false;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //bright green
						for (int l = 0; l < objCreator->getFoodObjectsList().size(); l++) //Check Food
						{
							if (i == objCreator->getFoodObjectsList()[l]->getYpos() && j == objCreator->getFoodObjectsList()[l]->getXpos())
							{
								cout << objCreator->getFoodObjectsList()[l]->getFoodSymbol();
								isFoodSpawned = true;
								break;
							}
						}

						if (isFoodSpawned == false && isWallSpawned == false) //if this is not food part and wall, then is a blank game platform
						{
							cout << " ";
						}
					}
				}
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //red
		cout << "|" << endl;
	}
}

DiamondBoard::DiamondBoard(int widthSize, int heightSize, ObjectCreation* objCreator) : Board(widthSize, heightSize, objCreator)
{
	for (int i = 0; i <= this->m_HEIGHT + 1; i++) //this is to assign all wall data into the diamond. For collision checking
	{
		for (int j = 0; j < this->m_WIDTH; j++)
		{
			if (i != 0 || i != this->m_HEIGHT + 1) //Top and Bottom wall
			{
				if (i + j <= this->m_WIDTH / 2 || i + this->m_WIDTH / 2 - 1 <= j || (i - this->m_HEIGHT / 2 > j && i > this->m_HEIGHT / 2)
					|| (i - this->m_HEIGHT / 2 >= this->m_HEIGHT - j && i > this->m_HEIGHT / 2))
				{
					Transform wallDataPos;
					wallDataPos.setPosition(j, i);
					InnerWall* wallData = new InnerWall(wallDataPos, '*');
					objCreator->addWallObject(wallData);
				}
			}
		}
	}
}
