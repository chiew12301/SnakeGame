#pragma once
#include "AllHeaderFile.h"

class Snake1 : public Snake
{
public:
	Snake1(int startXpos, int startYpos, int bWidth, int bHeight);
	void Update(int elapsedTime);
};

