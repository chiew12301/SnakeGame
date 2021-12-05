#include "Board.h"

void Board::drawBoard(float dt, ObjectCreation* objCreator) //perform draw board
{
	if (m_BoardShape == DEFAULT)
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
	else if (m_BoardShape == DIAMOND)
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
					bool isWallSpawned = false;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //red
					if (i + j <= this->m_WIDTH / 2 || i + this->m_WIDTH / 2 - 1 <= j || (i - this->m_HEIGHT / 2 > j && i > this->m_HEIGHT / 2)
						|| (i - this->m_HEIGHT / 2 >= this->m_HEIGHT - j && i > this->m_HEIGHT / 2))
					{
						cout << "*";
						isWallSpawned = true;
					}

					bool isBodyPart = false;
					for (int k = 0; k < objCreator->getSnake()->getBody().size(); k++) //Check Body
					{
						if (i == objCreator->getSnake()->getBody()[k].getYPosition() && j == objCreator->getSnake()->getBody()[k].getXPosition())
						{
							if (isWallSpawned == true)
							{
								objCreator->getSnake()->UpdateMove(dt);
								break;
							}
							else
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //blue
								cout << objCreator->getSnake()->getSnakeSymbol();
								isBodyPart = true;
								break;
							}
						}
					}

					if (isBodyPart == false) //if this is not body part, check food
					{
						bool isFoodSpawned = false;
						for (int l = 0; l < objCreator->getFoodObjectsList().size(); l++) //Check Food
						{
							if (i == objCreator->getFoodObjectsList()[l]->getYpos() && j == objCreator->getFoodObjectsList()[l]->getXpos())
							{
								if (isWallSpawned == true)
								{
									objCreator->getFoodObjectsList()[l]->Reposition(objCreator->getSnake()->getBody(), objCreator->getFoodObjectsList());
									break;
								}
								else
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //bright green
									cout << objCreator->getFoodObjectsList()[l]->getFoodSymbol();
									isFoodSpawned = true;
									break;
								}
							}
						}

						if (isFoodSpawned == false && isWallSpawned == false) //if this is not food part and wall, then is a blank game platform
						{
							cout << " ";
						}
					}
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //red
			cout << "|" << endl;
		}
	}
}


/// <summary>Initialize the board size.
/// <para>Pass widthSize for board width size, heightsize for board height size</para>
/// </summary>
Board::Board(int widthSize, int heightSize, BOARDSHAPE bs)
{
	this->m_WIDTH = widthSize;
	this->m_HEIGHT = heightSize;
	this->m_BoardShape = bs;
}

Board::~Board()
{
	
}

void Board::Update(float dt, ObjectCreation* objCreator) //update all the snake and food and perform draw board with the update
{
	drawBoard(dt, objCreator);
}
