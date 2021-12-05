#pragma once
#include "AllHeaderFile.h"

class ObjectCreation;

class Board
{
private:
	int m_WIDTH;
	int m_HEIGHT;

	void drawBoard(ObjectCreation* objCreator);

public:
	Board(int widthSize, int heightSize);

	~Board();

	void Update(float dt, ObjectCreation* objCreator);
};

