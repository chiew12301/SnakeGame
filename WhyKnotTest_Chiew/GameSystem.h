#pragma once
#include "AllHeaderFile.h"

class Board;
class Time;
class ObjectCreation;

class GameSystem
{
private:
	Board* m_gameBoard; //Reason have pointer is this storing quite few data. If the game is getting bigger, is better allocate our self.
	Time* m_gameTime; //Reason have pointer is this is because of instance.
	ObjectCreation* m_ObjCreator;

	enum GameUIStatus
	{
		MapEditUI = 0,
		SnakeSelection,
		InGame,
		EndGameMenu,
		ExitGame
	};

	GameUIStatus m_UIStatus; //No Pointer needed coz is only happened here. Better allow visual studio allocate data it self.

	int m_boardWidth;
	int m_boardHeight;

	int m_CurrentScore;

	void GameLoop();

	void MainMenu();

	void SelectSnake();

	void resetDefault();

	bool CheckCollider();

	void CheckInput();

	void EndGameMenuMethod();

public:
	GameSystem();

	~GameSystem();
};

