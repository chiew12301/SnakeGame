#include "InnerWall.h"

InnerWall::InnerWall(Transform trans, char symbol)
{
	this->m_Transform = trans;
	this->m_symbol = symbol;
}

InnerWall::~InnerWall()
{
}

Transform InnerWall::getTransform()
{
	return this->m_Transform;
}

char InnerWall::getSymbol()
{
	return this->m_symbol;
}
