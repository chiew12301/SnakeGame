#pragma once
#pragma message ("enter object")
#include "AllHeaderFile.h"
#pragma message ("Declearing object")
class Snake;
class Food;
class InnerWall;

class ObjectCreation
{
private:
	Snake* m_snake;
	std::vector<Snake*> m_SnakeObjectList;
	std::vector<Food*> m_FoodObjectList;
	std::vector<InnerWall*> m_WallObjectList;
public:
	ObjectCreation(int widthSize, int heightSize, std::string boardName);
	~ObjectCreation();;

	void Update(float dt);

	void setSnakeData(int i);
	Snake* getSnake();
	std::vector<Food*>& getFoodObjectsList();
	std::vector<Snake*>& getSnakesObjectsList();
	std::vector<InnerWall*> getWallObjectsList();
	void addWallObject(InnerWall* newWall);
};

