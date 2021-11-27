#pragma once
#include "AllHeaderFile.h"

class Board;
class Snake;

class GameSystem
{
private:
	Board* gameBoard;
	//Time gameTime;

	bool isExit = false;
	bool isMainMenuCompleted = false;
	bool isSelectedSnake = false;
	int boardWidth;
	int boardHeight;

	void GameLoop();

	void MainMenu();

	void SelectSnake();

	void resetDefault();

	bool CheckCollider();

public:
	GameSystem();

	~GameSystem();
};

