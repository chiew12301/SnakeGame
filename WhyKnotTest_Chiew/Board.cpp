#include "Board.h"

void Board::drawBoard() //perform draw board
{
	for (int i = 0; i <= m_HEIGHT + 1; i++)
	{
		cout << "\t\t|";
		for (int j = 0; j < m_WIDTH; j++)
		{
			if (i == 0 || i == m_HEIGHT + 1) //Top and Bottom wall
			{
				cout << "-";
			}
			else //Render Game Platform
			{
				bool isBodyPart = false;
				for (int k = 0; k < m_snake->getBody().size(); k++) //Check Body
				{
					if (i == m_snake->getBody()[k].getYPosition() && j == m_snake->getBody()[k].getXPosition())
					{
						cout << m_snake->getSnakeSymbol();
						isBodyPart = true;
						break;
					}
				}

				if (isBodyPart == false) //if this is not body part, check food
				{
					bool isFoodSpawned = false;
					for (int l = 0; l < m_FoodList.size(); l++) //Check Food
					{
						if (i == m_FoodList[l]->getYpos() && j == m_FoodList[l]->getXpos())
						{
							cout << m_FoodList[l]->getFoodSymbol();
							isFoodSpawned = true;
							break;
						}
					}

					if (isFoodSpawned == false) //if this is not food part too, then is a blank game platform
					{
						cout << " "; //Game Platform
					}
				}
			}
		}
		cout << "|" << endl;
	}
}


/// <summary>Initialize the board size.
/// <para>Pass widthSize for board width size, heightsize for board height size</para>
/// </summary>
Board::Board(int widthSize, int heightSize)
{
	m_WIDTH = widthSize;
	m_HEIGHT = heightSize;
	Food* food1 = new Air(2, 2, widthSize, heightSize);
	m_FoodList.push_back(food1);
	Food* food2 = new Oak(3, 3, widthSize, heightSize);
	m_FoodList.push_back(food2);
	Food* food3 = new Hash(5, 5, widthSize, heightSize);
	m_FoodList.push_back(food3);
	Snake* snakeAir = new AirSnake(m_WIDTH / 2, m_HEIGHT / 2, m_WIDTH, m_HEIGHT);
	m_SnakeList.push_back(snakeAir);
	Snake* snakeOak = new OakSnake(m_WIDTH / 2, m_HEIGHT / 2, m_WIDTH, m_HEIGHT);
	m_SnakeList.push_back(snakeOak);
	Snake* snakeHash = new HashSnake(m_WIDTH / 2, m_HEIGHT / 2, m_WIDTH, m_HEIGHT);
	m_SnakeList.push_back(snakeHash);
}

Board::~Board()
{
	delete m_snake;
	for (auto p : m_FoodList)
	{
		delete p;
	}
	m_FoodList.clear(); //free memories
	for (auto p : m_SnakeList)
	{
		delete p;
	}
	m_SnakeList.clear(); //free memories
}

void Board::Update(float dt) //update all the snake and food and perform draw board with the update
{
	m_snake->Update(dt);
	drawBoard();
}

/// <summary>This is to set snake data.
/// <para>'1' as snake 1, '2' as snake 2, '3' as snake 3</para>
/// </summary>
void Board::setSnakeData(int i)
{
	switch (i)
	{
	case(1):
		m_snake = m_SnakeList[i - 1];
		break;
	case(2):
		m_snake = m_SnakeList[i - 1];
		break;
	case(3):
		m_snake = m_SnakeList[i - 1];
		break;
	default:
		break;
	}
}

Snake* Board::getSnake()
{
	return m_snake;
}

std::vector<Food*>& Board::getFoodList()
{
	return m_FoodList;
}
