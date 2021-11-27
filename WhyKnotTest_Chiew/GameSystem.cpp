#include "GameSystem.h"

GameSystem::GameSystem()
{
	isExit = false;
	isMainMenuCompleted = false;
	isSelectedSnake = false;
	gameTime = Time::Instance();
	GameLoop();
}

GameSystem::~GameSystem()
{
	//resetDefault();
	//delete this;
}

void GameSystem::GameLoop()
{
	//First Enter Game
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
				system("CLS");
				gameTime->Reset();
				do //player will able play game inside
				{
					gameTime->Tick();
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
					cout << "\t\tGame Time: " << gameTime->DeltaTime() << endl;
					if(gameTime->DeltaTime() >= 1 / 60.0f)
					{
						gameBoard->Update(gameTime->DeltaTime());
					}

					isExit = isGameEnd = CheckCollider();
					cout << "\t\tPress Escape/close button to exit the game." << endl;
					cout << "\t\tArrow Up key to move up." << endl;
					cout << "\t\tArrow Down key to move down." << endl;
					cout << "\t\tArrow Left key to move left." << endl;
					cout << "\t\tArrow Right key to move right." << endl;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
				} while (!isGameEnd);
				system("CLS");
				cout << "\t\tYou dead" << endl;
				Sleep(3000);
			}
		}
	}while(!isExit);
	cout << "\t\tGame Exited " << endl;
	cout << "\t\tThank for playing! " << endl;
	this->~GameSystem();
}

void GameSystem::MainMenu()
{
	cout << "\t\t\tPlease Key in Board Size" << endl;
	cout << "\t\tNote: The Board Size must greater than 20" << endl;
	keywidth:
	cout << "\t\tWidth of Board:"; cin >> boardWidth;
	if (boardWidth >= 20)
	{
		keyheight:
		cout << "\t\tHeight of Board:"; cin >> boardHeight;
		if (boardHeight >= 20)
		{
			cout << "\t\tGenerating the map" << endl;
			gameBoard = new Board(boardWidth, boardHeight);
			isMainMenuCompleted = true;
		}
		else
		{
			system("CLS");
			cout << "\t\tPlease only key in value that is greater than 20!" << endl;
			goto keyheight;
		}
	}
	else
	{
		system("CLS");
		cout << "\t\tPlease only key in value that is greater than 20!" << endl;
		goto keywidth;
	}
}

void GameSystem::SelectSnake()
{
	//this is to select snake prompt
	system("CLS");
	cout << "\t\tPlease select your snake" << endl;
	cout << "\t\tSnake 1: Symbol '@' and speed is 4 speed each block" << endl;
	cout << "\t\tSnake 2: Symbol 'O' and speed is 5 speed each block" << endl;
	cout << "\t\tSnake 3: Symbol '#' and speed is 6 speed each block" << endl;
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
			cout << "\t\tInvalid Input" << endl;
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
bool GameSystem::CheckCollider()
{
	if (gameBoard->getFoodList().size()> 0) //check when it has food
	{
		bool isTrigger = false;
		for (int i = 0; i < gameBoard->getFoodList().size(); i++) //loop the vector
		{
			if (gameBoard->getSnake()->collision(gameBoard->getFoodList()[i]->getXpos() , gameBoard->getFoodList()[i]->getYpos()))
			{
				//it means it collided
				if (gameBoard->getSnake()->getSnakeSymbol() == gameBoard->getFoodList()[i]->getFoodSymbol()) //means same symbol
				{
					//eat
					isTrigger = true;
					break;
				}
				else //means different symbol
				{
					//die
					//game end
					return true;
				}
			}
		}

		if (isTrigger == true)
		{
			for (int i = 0; i < gameBoard->getFoodList().size(); i++) //loop the vector
			{
				gameBoard->getFoodList()[i]->Reposition();
			}
		}
	}
	return false;
}

