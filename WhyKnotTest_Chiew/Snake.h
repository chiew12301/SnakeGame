#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Transform.h"
//reason of it was snake was a sub class based. So it can't be used all header file. Meant to designed as "Game Object" typed.
class ObjectCreation;
class Snake
{
protected:
	int m_boardWidth;
	int m_boardHeight;
	int m_CurrentBodySize;
	std::vector<Transform> m_bodyTransform;
	Transform m_Transform; //Basically act as head of the transform
	char m_Symbol;
	float m_speed;
	Transform m_direction;

	std::string m_currentBoardName;

	//Time
	float m_latestTime;

public:
	Snake(int startXpos, int startYpos, int bWidth, int bHeight, std::string boardName);
	virtual void Update(float dt, ObjectCreation* objCreator);
	char getSnakeSymbol();
	int getXpos();
	int getYpos();
	void changeDirection(Transform dir);
	Transform getDirection();
	void GrowBody();
	std::vector<Transform> getBody();
	bool collision(int colliderXpos, int colliderYpos, bool isSelf);
	void UpdateMove(float dt, ObjectCreation* objCreator);
};

#include "ObjectCreation.h"