#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
//reason of it was snake was a sub class based. So it can't be used all header file. Meant to designed as "Game Object" typed.

class Snake
{
protected:
	int boardWidth;
	int boardHeight;
	int xPos;
	int yPos;
	char Symbol;
	int speed;
	char direction;

	//For Movement
	int moveTimer;
	int updateDelayTimer;
	int updateDelayDuration;

public:
	Snake(int startXpos, int startYpos, int bWidth, int bHeight);
	virtual void Update(int elapsedTime);
	char getSnakeSymbol();
	int getXpos();
	int getYpos();
	void changeDirection(char dir);
	bool collision(int colliderXpos, int colliderYpos);
	void UpdateMove(int elapsedTime);
};

