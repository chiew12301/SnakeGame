#include "GameSystem.h"

GameSystem::GameSystem()
{
	isExit = false;
	isMainMenuCompleted = false;
	isSelectedSnake = false;
	GameLoop();
}

GameSystem::~GameSystem()
{
	delete this;
}

void GameSystem::GameLoop()
{
	//First Enter Game
	int startTime = 0;
	int currentTime = 0;
	int elapsedTime = 0;
	int lastUpdateTime = 0;
	startTime = clock();
	do
	{
		MainMenu();
		if (isMainMenuCompleted == true)//means main menu done
		{
			//after main menu done, prompt select character
			SelectSnake();

			if (isSelectedSnake == true)
			{
				bool isGameEnd = false;
				do //player will able play game inside
				{
					if (GetAsyncKeyState(VK_ESCAPE))
					{
						isExit = true;
						isGameEnd = true;
					}
					if (GetAsyncKeyState(VK_UP))
					{
						gameBoard->getSnake()->changeDirection('W');
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						gameBoard->getSnake()->changeDirection('S');
					}
					if (GetAsyncKeyState(VK_LEFT))
					{
						gameBoard->getSnake()->changeDirection('A');
					}
					if (GetAsyncKeyState(VK_RIGHT))
					{
						gameBoard->getSnake()->changeDirection('D');
					}
					currentTime = clock();
					gameBoard->Update(elapsedTime);

					//update game current time;
					elapsedTime = (clock() - lastUpdateTime) * 1000 / CLOCKS_PER_SEC;
					lastUpdateTime = clock();
					Sleep(25);
					system("CLS");
					//SetCursorPos
				} while (!isGameEnd);
			}
		}
	}while(!isExit);
	cout << "\t\tGame Exited " << endl;
	cout << "\t\tThank for playing! " << endl;
}

void GameSystem::MainMenu()
{
	cout << "Please Key in Board Size" << endl;
	cout << "Note: The Board Size must greater than 20" << endl;
	keywidth:
	cout << "Width of Board:"; cin >> boardWidth;
	if (boardWidth >= 20)
	{
		keyheight:
		cout << "Height of Board:"; cin >> boardHeight;
		if (boardHeight >= 20)
		{
			cout << "Generating the map" << endl;
			gameBoard = new Board(boardWidth, boardHeight);
			isMainMenuCompleted = true;
		}
		else
		{
			system("CLS");
			goto keyheight;
		}
	}
	else
	{
		system("CLS");
		goto keywidth;
	}
}

void GameSystem::SelectSnake()
{
	//this is to select snake prompt
	system("CLS");
	cout << "\tPlease select your snake" << endl;
	cout << "\tSnake 1: Symbol '@' and speed is 4 speed each block" << endl;
	cout << "\tSnake 2: Symbol 'O' and speed is 5 speed each block" << endl;
	cout << "\tSnake 3: Symbol '#' and speed is 6 speed each block" << endl;
	selectionPrompt:
	int selection;
	cout << "Please key in your selection:"; cin >> selection;
	switch (selection)
	{
		case(1):
			gameBoard->setSnakeData(1);
			isSelectedSnake = true;
			break;
		case(2):
			gameBoard->setSnakeData(2);
			isSelectedSnake = true;
			break;
		case(3):
			gameBoard->setSnakeData(3);
			isSelectedSnake = true;
			break;
		default:
			system("CLS");
			goto selectionPrompt;
			break;
	}
}

void GameSystem::resetDefault()
{
	isExit = false;
	isMainMenuCompleted = false;
	isSelectedSnake = false;
	gameBoard = NULL;
}

