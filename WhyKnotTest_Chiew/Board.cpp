#include "Board.h"

void Board::drawBoard() //perform draw board
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
				for (int k = 0; k < this->m_snake->getBody().size(); k++) //Check Body
				{
					if (i == this->m_snake->getBody()[k].getYPosition() && j == this->m_snake->getBody()[k].getXPosition())
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //blue
						cout << this->m_snake->getSnakeSymbol();
						isBodyPart = true;
						break;
					}
				}

				if (isBodyPart == false) //if this is not body part, check food
				{
					bool isFoodSpawned = false;
					for (int l = 0; l < this->m_objCreator->getFoodObjectsList().size(); l++) //Check Food
					{
						if (i == this->m_objCreator->getFoodObjectsList()[l]->getYpos() && j == this->m_objCreator->getFoodObjectsList()[l]->getXpos())
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //bright green
							cout << this->m_objCreator->getFoodObjectsList()[l]->getFoodSymbol();
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


/// <summary>Initialize the board size.
/// <para>Pass widthSize for board width size, heightsize for board height size</para>
/// </summary>
Board::Board(int widthSize, int heightSize)
{
	this->m_WIDTH = widthSize;
	this->m_HEIGHT = heightSize;
	m_objCreator = new ObjectCreation(widthSize, heightSize);
}

Board::~Board()
{
	m_objCreator->~ObjectCreation();
	this->m_snake = NULL;
	delete this->m_snake;
}

void Board::Update(float dt) //update all the snake and food and perform draw board with the update
{
	this->m_snake->Update(dt);
	drawBoard();
}

/// <summary>This is to set snake data.
/// <para>'1' as snake 1, '2' as snake 2, '3' as snake 3</para>
/// </summary>
void Board::setSnakeData(int i)
{
	this->m_snake = this->m_objCreator->getSnakesObjectsList()[i - 1];
}

Snake* Board::getSnake()
{
	return this->m_snake;
}

std::vector<Food*>& Board::getFoodList()
{
	return this->m_objCreator->getFoodObjectsList();
}
