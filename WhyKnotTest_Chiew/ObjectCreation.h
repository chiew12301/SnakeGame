#pragma once
#include "AllHeaderFile.h"
class Snake;
class Food;

class ObjectCreation
{
private:
	Snake* m_snake;
	std::vector<Snake*> m_SnakeObjectList;
	std::vector<Food*> m_FoodObjectList;
public:
	ObjectCreation(int widthSize, int heightSize);
	~ObjectCreation();;

	void Update(float dt);

	void setSnakeData(int i);
	Snake* getSnake();
	std::vector<Food*>& getFoodObjectsList();
	std::vector<Snake*>& getSnakesObjectsList();
};

