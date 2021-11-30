#pragma once
#include "AllHeaderFile.h"

class HashSnake : public Snake
{
public:
	HashSnake(int startXpos, int startYpos, int bWidth, int bHeight);
	void Update(float dt);
};

