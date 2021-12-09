#pragma once
#include "AllHeaderFile.h"

class AirSnake : public Snake
{
public:
	AirSnake(int startXpos, int startYpos, int bWidth, int bHeight, std::string boardName);
	void Update(float dt, ObjectCreation* objCreator);
};

