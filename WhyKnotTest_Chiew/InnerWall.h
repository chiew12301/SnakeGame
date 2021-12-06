#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include "Transform.h"
//reason of it was snake was a sub class based. So it can't be used all header file. Meant to designed as "Game Object" typed.

class InnerWall
{
private:
	Transform m_Transform;
	char m_symbol;
public:
	InnerWall(Transform trans, char symbol);
	~InnerWall();

	Transform getTransform();
	char getSymbol();
};

