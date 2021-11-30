#pragma once
#include "AllHeaderFile.h"

//Tell Board class there's these classes first before define
class Snake;
class Food;

class Board
{
private:
	int m_WIDTH;
	int m_HEIGHT;
	//Game Objects
	Snake* m_snake;
	std::vector<Snake*> m_SnakeList;
	std::vector<Food*> m_FoodList;
	//===========
	void drawBoard();

public:
	Board(int widthSize, int heightSize);

	~Board();

	void Update(float dt);

	void setSnakeData(int i);

	Snake* getSnake();

	std::vector<Food*>& getFoodList();
};

