#include "Board.h"

void Board::drawBoard() //perform draw board
{
	for (int i = 0; i <= HEIGHT + 1; i++)
	{
		cout << "\t\t|";
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == 0 || i == HEIGHT + 1)
			{
				cout << "-";
			}
			else if (i == snake->getYpos() && j == snake->getXpos())
			{
				cout << snake->getSnakeSymbol();
			}
			else if (FoodList.size() > 0) //when there's food
			{
				for (int k = 0; k < FoodList.size(); k++) //render all food
				{
					if (i == FoodList[k]->getYpos() && j == FoodList[k]->getXpos())
					{
						cout << FoodList[k]->getFoodSymbol();
					}
					else
					{
						cout << " "; //Game Platform 
					}
				}
			}
			else //only will enter when there's no food on the board
			{
				cout << " "; //Game Platform			
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
	WIDTH = widthSize;
	HEIGHT = heightSize;
	Food* food1 = new Food1(2, 2, widthSize, heightSize);
	FoodList.push_back(food1);
}

void Board::Update(double dt) //update all the snake and food and perform draw board with the update
{
	snake->Update();
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
		snake = new Snake1(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT);
		break;
	case(2):
		snake = new Snake2(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT);
		break;
	case(3):
		snake = new Snake3(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT);
		break;
	default:
		break;
	}
}

Snake* Board::getSnake()
{
	return snake;
}

std::vector<Food*>& Board::getFoodList()
{
	return FoodList;
}
