#include "ObjectCreation.h"

ObjectCreation::ObjectCreation(int widthSize, int heightSize)
{
	Food* food1 = new AirFood(2, 2, widthSize, heightSize);
	this->m_FoodObjectList.push_back(food1);
	Food* food2 = new OakFood(3, 3, widthSize, heightSize);
	this->m_FoodObjectList.push_back(food2);
	Food* food3 = new HashFood(5, 5, widthSize, heightSize);
	this->m_FoodObjectList.push_back(food3);
	Snake* snakeAir = new AirSnake(widthSize / 2, heightSize / 2, widthSize, heightSize);
	this->m_SnakeObjectList.push_back(snakeAir);
	Snake* snakeOak = new OakSnake(widthSize / 2, heightSize / 2, widthSize, heightSize);
	this->m_SnakeObjectList.push_back(snakeOak);
	Snake* snakeHash = new HashSnake(widthSize / 2, heightSize / 2, widthSize, heightSize);
	this->m_SnakeObjectList.push_back(snakeHash);
}

ObjectCreation::~ObjectCreation()
{
	for (auto p : this->m_FoodObjectList)
	{
		delete p;
	}
	this->m_FoodObjectList.clear(); //free memories
	for (auto p : this->m_SnakeObjectList)
	{
		delete p;
	}
	this->m_SnakeObjectList.clear(); //free memories
	this->m_snake = NULL;
	delete this->m_snake;
}

void ObjectCreation::Update(float dt)
{
	this->m_snake->Update(dt);
}

/// <summary>This is to set snake data.
/// <para>'1' as snake 1, '2' as snake 2, '3' as snake 3</para>
/// </summary>
void ObjectCreation::setSnakeData(int i)
{
	this->m_snake = this->getSnakesObjectsList()[i - 1];
}

Snake* ObjectCreation::getSnake()
{
	return this->m_snake;
}

std::vector<Food*>& ObjectCreation::getFoodObjectsList()
{
	return this->m_FoodObjectList;
}

std::vector<Snake*>& ObjectCreation::getSnakesObjectsList()
{
	return this->m_SnakeObjectList;
}
