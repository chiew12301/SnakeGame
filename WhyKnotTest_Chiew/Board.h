#pragma once
#include "AllHeaderFile.h"

class ObjectCreation;

class Board
{
public:
	enum BOARDSHAPE
	{
		DEFAULT = 0,
		DIAMOND
	};
private:
	int m_WIDTH;
	int m_HEIGHT;

	BOARDSHAPE m_BoardShape;

	void drawBoard(float dt, ObjectCreation* objCreator);

public:
	Board(int widthSize, int heightSize, BOARDSHAPE bs);
	~Board();

	void Update(float dt, ObjectCreation* objCreator);
};

