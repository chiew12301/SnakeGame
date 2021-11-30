#pragma once
#include "AllHeaderFile.h"

class AirSnake : public Snake
{
public:
	AirSnake(int startXpos, int startYpos, int bWidth, int bHeight);
	void Update(float dt);
};

