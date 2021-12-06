#pragma once
#include "AllHeaderFile.h"

class DefaultBoard : public Board
{
protected:
	void drawBoard(float dt, ObjectCreation* objCreator);
public:
	DefaultBoard(int widthSize, int heightSize, ObjectCreation* objCreator);
};

