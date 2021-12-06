#include "DefaultBoard.h"

void DefaultBoard::drawBoard(ObjectCreation* objCreator)
{
	for (int i = 0; i <= this->m_HEIGHT + 1; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //red
		cout << "\t\t|";
		for (int j = 0; j < this->m_WIDTH; j++)
		{
			if (i == 0 || i == this->m_HEIGHT + 1) //Top and Bottom wall
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //red
				cout << "-";
			}
			else //Render Game Platform
			{
				bool isBodyPart = false;
				for (int k = 0; k < objCreator->getSnake()->getBody().size(); k++) //Check Body
				{
					if (i == objCreator->getSnake()->getBody()[k].getYPosition() && j == objCreator->getSnake()->getBody()[k].getXPosition())
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //blue
						cout << objCreator->getSnake()->getSnakeSymbol();
						isBodyPart = true;
						break;
					}
				}

				if (isBodyPart == false) //if this is not body part, check food
				{
					bool isFoodSpawned = false;
					for (int l = 0; l < objCreator->getFoodObjectsList().size(); l++) //Check Food
					{
						if (i == objCreator->getFoodObjectsList()[l]->getYpos() && j == objCreator->getFoodObjectsList()[l]->getXpos())
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //bright green
							cout << objCreator->getFoodObjectsList()[l]->getFoodSymbol();
							isFoodSpawned = true;
							break;
						}
					}

					if (isFoodSpawned == false) //if this is not food part too, then is a blank game platform
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //white
						cout << " "; //Game Platform
					}
				}
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //red
		cout << "|" << endl;
	}
}

DefaultBoard::DefaultBoard(int widthSize, int heightSize, ObjectCreation* objCreator) : Board(widthSize, heightSize, objCreator)
{
	//No external object.
}