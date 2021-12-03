#pragma once
#include "AllHeaderFile.h"

//Tell Board class there's these classes first before define
class Snake;
class Food;
class ObjectCreation;

class Board
{
private:
	int m_WIDTH;
	int m_HEIGHT;
	//Game Objects
	Snake* m_snake;
	ObjectCreation* m_objCreator;
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

