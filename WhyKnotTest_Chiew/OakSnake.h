#pragma once
#include "AllHeaderFile.h"

class OakSnake : public Snake
{
public:
	OakSnake(int startXpos, int startYpos, int bWidth, int bHeight);
	void Update(float dt);
};

