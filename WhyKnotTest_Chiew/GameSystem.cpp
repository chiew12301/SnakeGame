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
	resetDefault();
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
					cout << "Game Time: " << currentTime/1000 << endl;
					gameBoard->Update(elapsedTime);
					CheckCollider();

					//update game current time;
					elapsedTime = (clock() - lastUpdateTime) * 1000 / CLOCKS_PER_SEC;
					lastUpdateTime = clock();
					cout << "Press Escape/close button to exit the game." << endl;
					cout << "Arrow Up key to move up." << endl;
					cout << "Arrow Down key to move down." << endl;
					cout << "Arrow Left key to move left." << endl;
					cout << "Arrow Right key to move right." << endl;
					Sleep(25);
					system("CLS");
					//SetCursorPos
				} while (!isGameEnd);
			}
		}
	}while(!isExit);
	cout << "\t\tGame Exited " << endl;
	cout << "\t\tThank for playing! " << endl;
	this->~GameSystem();
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
			cout << "Please only key in value that is greater than 20!" << endl;
			goto keyheight;
		}
	}
	else
	{
		system("CLS");
		cout << "Please only key in value that is greater than 20!" << endl;
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
			cout << "Invalid Input" << endl;
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

/// <summary>This is a method to check every collider in the system, it meant to place in loop. It will take all objects data from board data.
/// </summary>
void GameSystem::CheckCollider()
{
	if (gameBoard->getFoodList().size()> 0) //check when it has food
	{
		for (int i = 0; i < gameBoard->getFoodList().size(); i++) //loop the vector
		{
			if (gameBoard->getSnake()->getXpos() == gameBoard->getFoodList()[i]->getXpos() && gameBoard->getSnake()->getYpos() == gameBoard->getFoodList()[i]->getYpos())
			{
				//it means it collided
				if (gameBoard->getSnake()->getSnakeSymbol() == gameBoard->getFoodList()[i]->getFoodSymbol()) //means same symbol
				{
					//eat
					cout << "Eat eat" << endl;
					gameBoard->getFoodList()[i]->Reposition();
				}
				else //means different symbol
				{
					//die
					cout << "Die" << endl;
				}
			}
		}
	}
}

