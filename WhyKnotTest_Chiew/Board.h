#pragma once
#include "AllHeaderFile.h"

class Snake;

class Board
{
private:
	int WIDTH;
	int HEIGHT;
	Snake* snake;
	void drawBoard();

public:
	Board(int widthSize, int heightSize);

	void Update(double dt);

	void setSnakeData(int i);

	Snake* getSnake();
};

