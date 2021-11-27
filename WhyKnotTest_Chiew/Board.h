#pragma once
#include "AllHeaderFile.h"

//Tell Board class there's these classes first before define
class Snake;
class Food;

class Board
{
private:
	int WIDTH;
	int HEIGHT;
	//Game Objects
	Snake* snake;
	std::vector<Food*> FoodList;
	//===========
	void drawBoard();

public:
	Board(int widthSize, int heightSize);

	void Update(double dt);

	void setSnakeData(int i);

	Snake* getSnake();

	std::vector<Food*>& getFoodList();
};

