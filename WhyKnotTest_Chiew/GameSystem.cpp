#include "GameSystem.h"

GameSystem::GameSystem()
{
	this->m_gameTime = Time::Instance();
	this->m_UIStatus = MapEditUI;
	this->m_CurrentScore = 0;
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
		//Main Menu
		MainMenu();
		do
		{
			//Snake Menu
			SelectSnake();
			//Reset the game time
			this->m_gameTime->Reset();
			do
			{
				//Start the clock
				this->m_gameTime->Tick();
					CheckInput(); //Check Input
					cout << "\t\tGame Time: " << this->m_gameTime->DeltaTime() << endl; //Debug the Time
					if (m_gameTime->DeltaTime() >= 1 / 60.0f){ 
						this->m_ObjCreator->Update(this->m_gameTime->DeltaTime()); //update object first
						this->m_gameBoard->Update(this->m_gameTime->DeltaTime(), this->m_ObjCreator); //then render
					} //Update,Render the Game
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //white
					if (CheckCollider() == true) { 
						this->m_UIStatus = EndGameMenu; system("CLS");
						cout << "\t\tYou dead" << endl; cout << "\t\tYour Final Score: " << this->m_CurrentScore << endl; 
						Sleep(3000);
					} //Condition Checking
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
					//Instruction
					cout << "\t\tPress Escape/close button to exit the game." << endl;
					cout << "\t\tArrow Up key to move up." << endl;
					cout << "\t\tArrow Down key to move down." << endl;
					cout << "\t\tArrow Left key to move left." << endl;
					cout << "\t\tArrow Right key to move right." << endl;
					cout << "\t\tCurrent Score: " << this->m_CurrentScore << endl;
			} while (this->m_UIStatus == InGame);
		} while (this->m_UIStatus == SnakeSelection);
		//Clean before show end game menu
		system("CLS");
		//End Game Menu
		EndGameMenuMethod();
		//reset score
		this->m_CurrentScore = 0; 
	}while(this->m_UIStatus == MapEditUI);
	system("CLS"); cout << "\t\tGame Exited " << endl; cout << "\t\tThank for playing! " << endl; //Exit text
}

void GameSystem::MainMenu()
{
	int shapeInput = 0;
	do
	{
		cout << "\t\t\t\tSnake Game" << endl;
		cout << "\t\t\tPlease Insert Board Shape" << endl;
		cout << "\t\tKey 1 for Default Square/Rectangle Shape, Key 2 for Diamond Shape" << endl;
		cout << "\t\tYour Choice:"; cin >> shapeInput;

		if (shapeInput < 1 || shapeInput > 2) //Error meesage
		{
			system("CLS");
			cout << "\t\tInvalid Input, Please ensure you key in 1 or 2 only." << endl;
		}

	} while (shapeInput < 1 || shapeInput > 2);
	system("CLS");
	do
	{
		cout << "\t\t\tPlease Key in Board Size" << endl;
		cout << "\t\tNote: The Board Size must greater than 20 (Suggested 20x20)" << endl;
		cout << "\t\tWidth of Board:"; cin >> this->m_boardWidth;
		if (this->m_boardWidth >= 20)
		{
			cout << "\t\tHeight of Board:"; cin >> this->m_boardHeight;
			if (this->m_boardHeight >= 20)
			{
				cout << "\t\tGenerating the map" << endl;
				this->m_ObjCreator = new ObjectCreation(this->m_boardWidth, this->m_boardHeight);
				if (shapeInput == 1)
				{
					this->m_gameBoard = new DefaultBoard(this->m_boardWidth, this->m_boardHeight, this->m_ObjCreator);
				}
				else
				{
					this->m_gameBoard = new DiamondBoard(this->m_boardWidth, this->m_boardHeight, this->m_ObjCreator);
				}
				this->m_UIStatus = SnakeSelection;
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
	} while (this->m_UIStatus == MapEditUI);
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
		switch (selection) //Reason of this is to check which snake and gurantee is within the range
		{
		case(1):
			this->m_ObjCreator->setSnakeData(1);
			this->m_UIStatus = InGame;
			break;
		case(2):
			this->m_ObjCreator->setSnakeData(2);
			this->m_UIStatus = InGame;
			break;
		case(3):
			this->m_ObjCreator->setSnakeData(3);
			this->m_UIStatus = InGame;
			break;
		default:
			system("CLS");
			cout << "\t\tInvalid Input" << endl;
			break;
		}
	} while (this->m_UIStatus == SnakeSelection);
	system("CLS");
}

/// <summary>This is a method only will be called when the game has totally exit. To free the memories
/// </summary>
void GameSystem::resetDefault()
{
	this->m_UIStatus = MapEditUI;
	this->m_CurrentScore = 0;
	this->m_gameBoard->~Board();
	this->m_gameTime->Release();
	this->m_ObjCreator->~ObjectCreation();
}

/// <summary>This is a method to check every collider in the system, it meant to place in loop. It will take all objects data from board data.
/// </summary>
bool GameSystem::CheckCollider()
{
	if (this->m_ObjCreator->getSnake()->collision(this->m_ObjCreator->getSnake()->getBody()[0].getXPosition(), this->m_ObjCreator->getSnake()->getBody()[0].getYPosition(), true))
	{
		return true;
	}
	else if (this->m_ObjCreator->getFoodObjectsList().size()> 0 || this->m_ObjCreator->getWallObjectsList().size() > 0) //check only when it has foods/wall, and is not hit body
	{
		for (int i = 0; i < this->m_ObjCreator->getFoodObjectsList().size(); i++) //loop the vector
		{
			if (this->m_ObjCreator->getSnake()->collision(this->m_ObjCreator->getFoodObjectsList()[i]->getXpos() , this->m_ObjCreator->getFoodObjectsList()[i]->getYpos(), false))
			{
				//it means it collided
				if (this->m_ObjCreator->getSnake()->getSnakeSymbol() == this->m_ObjCreator->getFoodObjectsList()[i]->getFoodSymbol()) //means same symbol
				{
					for (int j = 0; j < this->m_ObjCreator->getFoodObjectsList().size(); j++) //loop the vector
					{
						this->m_ObjCreator->getFoodObjectsList()[j]->Reposition(this->m_ObjCreator->getSnake()->getBody(), this->m_ObjCreator->getFoodObjectsList()); //Reposition all teh foods
					}
					this->m_ObjCreator->getSnake()->GrowBody(); //Grow the body
					this->m_CurrentScore += this->m_ObjCreator->getFoodObjectsList()[i]->getFoodScore(); //increase score
					break;
				}
				else //means different symbol, die and same symbol
				{
					return true;
				}
			}
		} //Exit if no collide with foods
		if (this->m_ObjCreator->getWallObjectsList().size() > 0) //if have wall
		{
			for (int wallCount = 0; wallCount < this->m_ObjCreator->getWallObjectsList().size(); wallCount++) //loop the data from object creator
			{
				if (this->m_ObjCreator->getSnake()->collision(this->m_ObjCreator->getWallObjectsList()[wallCount]->getTransform().getXPosition(), this->m_ObjCreator->getWallObjectsList()[wallCount]->getTransform().getYPosition(), false))
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
	Transform next_Move;
	next_Move.setPosition(0, 0);
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		this->m_UIStatus = ExitGame;
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		next_Move.setPosition(0, -1);
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		next_Move.setPosition(0, 1);
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		next_Move.setPosition(-1, 0);
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		next_Move.setPosition(1, 0);
	}

	if (next_Move.getXPosition() == 0 && next_Move.getYPosition() == 0){//do nothing
	}
	else
	{
		this->m_ObjCreator->getSnake()->changeDirection(next_Move);
	}
}

void GameSystem::EndGameMenuMethod()
{
	do
	{
		cout << "\t\t\tRestart the game?" << endl;
		cout << "\t\tReply Y to restart, Reply N to quit." << endl;
		char input = 'N'; //to make sure no any default value on it
		cout << "\t\tYour Reply:"; cin >> input;
		switch (input)
		{
		case('Y'):
		case('y'):
			this->m_UIStatus = MapEditUI;
			break;
		case('N'):
		case('n'):
			this->m_UIStatus = ExitGame;
			break;
		default:
			system("CLS");
			cout <<"Invalid Input, Please only key in Y or N" << endl;
			break;
		}
	} while(this->m_UIStatus == EndGameMenu);
	system("CLS"); //CLS FOR Back to main menu
}

