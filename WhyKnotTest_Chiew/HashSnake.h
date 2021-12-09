#pragma once
#include "AllHeaderFile.h"

class HashSnake : public Snake
{
public:
	HashSnake(int startXpos, int startYpos, int bWidth, int bHeight, std::string boardName);
	void Update(float dt, ObjectCreation* objCreator);
};

