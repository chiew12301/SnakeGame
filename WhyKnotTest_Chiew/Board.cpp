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
			else
			{
				cout << " "; //Game Platform
			}
		}
		cout << "|" << endl;
	}
}

Board::Board(int widthSize, int heightSize)
{
	WIDTH = widthSize;
	HEIGHT = heightSize;
}

void Board::Update(double dt)
{
	snake->Update();
	drawBoard();
}

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
