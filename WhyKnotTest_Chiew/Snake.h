#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include "Transform.h"
//reason of it was snake was a sub class based. So it can't be used all header file. Meant to designed as "Game Object" typed.

class Snake
{
protected:
	int m_boardWidth;
	int m_boardHeight;
	int m_CurrentBodySize;
	int m_MaxBodySize;
	std::vector<Transform> m_bodyTransform;
	Transform m_Transform;
	char m_Symbol;
	float m_speed;
	int m_direction;

	//Time
	float m_latestTime;

public:
	Snake(int startXpos, int startYpos, int bWidth, int bHeight);
	virtual void Update(float dt);
	char getSnakeSymbol();
	int getXpos();
	int getYpos();
	void changeDirection(int dir);
	void GrowBody();
	std::vector<Transform> getBody();
	bool collision(int colliderXpos, int colliderYpos);
	void UpdateMove(float dt);
};

