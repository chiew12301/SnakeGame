#include "GameSystem.h"

GameSystem::GameSystem()
{
	m_gameTime = Time::Instance();
	m_UIStatus = MapEditUI;
	m_CurrentScore = 0;
	GameLoop();
}

GameSystem::~GameSystem()
{
	resetDefault();
}

void GameSystem::GameLoop()
{
	//First Enter Game
	do
	{
		MainMenu();
		do
		{
			SelectSnake();
			m_gameTime->Reset();
			do
			{
					m_gameTime->Tick();
					CheckInput();
					cout << "\t\tGame Time: " << m_gameTime->DeltaTime() << endl;
					if (m_gameTime->DeltaTime() >= 1 / 60.0f){ m_gameBoard->Update(m_gameTime->DeltaTime());} //Update,Render the Game

					if (CheckCollider() == true) { m_UIStatus = ExitGame; 	system("CLS");cout << "\t\tYou dead" << endl;Sleep(3000);} //Condition Checking
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
					cout << "\t\tPress Escape/close button to exit the game." << endl;
					cout << "\t\tArrow Up key to move up." << endl;
					cout << "\t\tArrow Down key to move down." << endl;
					cout << "\t\tArrow Left key to move left." << endl;
					cout << "\t\tArrow Right key to move right." << endl;
					cout << "\t\tCurrent Score: " << m_CurrentScore << endl;
			} while (m_UIStatus == InGame);
		} while (m_UIStatus == SnakeSelection);
	}while(m_UIStatus == MapEditUI);
	system("CLS"); cout << "\t\tGame Exited " << endl; cout << "\t\tYour Final Score: " << m_CurrentScore << endl; cout << "\t\tThank for playing! " << endl; //Exit text
}

void GameSystem::MainMenu()
{
	do
	{
		cout << "\t\t\tPlease Key in Board Size" << endl;
		cout << "\t\tNote: The Board Size must greater than 20 (Suggested 20x20)" << endl;
		cout << "\t\tWidth of Board:"; cin >> m_boardWidth;
		if (m_boardWidth >= 20)
		{
			cout << "\t\tHeight of Board:"; cin >> m_boardHeight;
			if (m_boardHeight >= 20)
			{
				cout << "\t\tGenerating the map" << endl;
				m_gameBoard = new Board(m_boardWidth, m_boardHeight);
				m_UIStatus = SnakeSelection;
			}
			else
			{
				system("CLS");
				cout << "\t\tPlease only key in value that is greater than 20!" << endl;
			}
		}
		else
		{		
			system("CLS");
			cout << "\t\tPlease only key in value that is greater than 20!" << endl;
		}
	} while (m_UIStatus == MapEditUI);
	system("CLS");
}

void GameSystem::SelectSnake()
{
	do
	{
		//this is to select snake prompt
		cout << "\t\tPlease select your snake" << endl;
		cout << "\t\tSnake Air: Symbol '@', score 1 point each and speed is 4 speed each block" << endl;
		cout << "\t\tSnake Oak: Symbol 'O', score 3 point and speed is 5 speed each block" << endl;
		cout << "\t\tSnake Hash: Symbol '#', score 5 point and speed is 6 speed each block" << endl;
		int selection;
		cout << "Please key in your selection:"; cin >> selection;
		switch (selection)
		{
		case(1):
			m_gameBoard->setSnakeData(1);
			m_UIStatus = InGame;
			break;
		case(2):
			m_gameBoard->setSnakeData(2);
			m_UIStatus = InGame;
			break;
		case(3):
			m_gameBoard->setSnakeData(3);
			m_UIStatus = InGame;
			break;
		default:
			system("CLS");
			cout << "\t\tInvalid Input" << endl;
			break;
		}
	} while (m_UIStatus == SnakeSelection);
	system("CLS");
}

/// <summary>This is a method only will be called when the game has totally exit. To free the memories
/// </summary>
void GameSystem::resetDefault()
{
	m_UIStatus = MapEditUI;
	m_CurrentScore = 0;
	m_gameBoard->~Board();
	m_gameTime->Release();
}

/// <summary>This is a method to check every collider in the system, it meant to place in loop. It will take all objects data from board data.
/// </summary>
bool GameSystem::CheckCollider()
{
	if (m_gameBoard->getFoodList().size()> 0) //check only when it has foods
	{
		for (int i = 0; i < m_gameBoard->getFoodList().size(); i++) //loop the vector
		{
			if (m_gameBoard->getSnake()->collision(m_gameBoard->getFoodList()[i]->getXpos() , m_gameBoard->getFoodList()[i]->getYpos()))
			{
				//it means it collided
				if (m_gameBoard->getSnake()->getSnakeSymbol() == m_gameBoard->getFoodList()[i]->getFoodSymbol()) //means same symbol
				{
					for (int j = 0; j < m_gameBoard->getFoodList().size(); j++) //loop the vector
					{
						m_gameBoard->getFoodList()[j]->Reposition(m_gameBoard->getSnake()->getBody(), m_gameBoard->getFoodList()); //Reposition all teh foods
					}
					m_gameBoard->getSnake()->GrowBody(); //Grow the body
					m_CurrentScore += m_gameBoard->getFoodList()[i]->getFoodScore(); //increase score
					break;
				}
				else //means different symbol, die and same symbol
				{
					return true;
				}
			}
		}
	}
	return false; //only triggered when is collided with food.
}

void GameSystem::CheckInput()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		m_UIStatus = ExitGame;
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		m_gameBoard->getSnake()->changeDirection(1);
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_gameBoard->getSnake()->changeDirection(2);
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		m_gameBoard->getSnake()->changeDirection(3);
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_gameBoard->getSnake()->changeDirection(4);
	}
}

