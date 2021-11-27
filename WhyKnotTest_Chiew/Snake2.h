#pragma once
#include "AllHeaderFile.h"

class Snake2 : public Snake
{
public:
	Snake2(int startXpos, int startYpos, int bWidth, int bHeight);
	void Update(int elapsedTime);
};

