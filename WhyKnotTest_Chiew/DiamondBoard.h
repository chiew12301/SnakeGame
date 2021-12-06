#pragma once
#include "AllHeaderFile.h"

class DiamondBoard : public Board
{
protected:
	void drawBoard(ObjectCreation* objCreator);
public:
	DiamondBoard(int widthSize, int heightSize, ObjectCreation* objCreator);
};

