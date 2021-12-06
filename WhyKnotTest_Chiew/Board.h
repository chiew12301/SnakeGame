#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
//#pragma message ("Let Board know has object creation class but can don't define first") //extra message
class ObjectCreation;
class Board
{
protected:
	int m_WIDTH;
	int m_HEIGHT;
	virtual void drawBoard(ObjectCreation* objCreator);

public:
	Board(int widthSize, int heightSize, ObjectCreation* objCreator);
	~Board();

	void Update(float dt, ObjectCreation* objCreator);
};
//#pragma message ("Force Board to define first.") //extra message
#include "ObjectCreation.h"