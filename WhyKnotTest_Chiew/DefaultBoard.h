#pragma once
#include "AllHeaderFile.h"

class DefaultBoard : public Board
{
protected:
	void drawBoard(ObjectCreation* objCreator);
public:
	DefaultBoard(int widthSize, int heightSize, ObjectCreation* objCreator);
};

