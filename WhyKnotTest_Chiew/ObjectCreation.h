#pragma once
#include "AllHeaderFile.h"
class Snake;
class Food;

class ObjectCreation
{
private:
	std::vector<Snake*> m_SnakeObjectList;
	std::vector<Food*> m_FoodObjectList;
public:
	ObjectCreation(int widthSize, int heightSize);
	~ObjectCreation();
	std::vector<Food*>& getFoodObjectsList();
	std::vector<Snake*>& getSnakesObjectsList();
};

