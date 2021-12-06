#include "Board.h"

void Board::drawBoard(float dt, ObjectCreation* objCreator) //perform draw board
{
	//let the child do the work
}

/// <summary>Initialize the board size.
/// <para>Pass widthSize for board width size, heightsize for board height size</para>
/// </summary>
Board::Board(int widthSize, int heightSize, ObjectCreation* objCreato)
{
	this->m_WIDTH = widthSize;
	this->m_HEIGHT = heightSize;
}

Board::~Board()
{
}

void Board::Update(float dt, ObjectCreation* objCreator) //update all the snake and food and perform draw board with the update
{
	drawBoard(dt, objCreator);
}
