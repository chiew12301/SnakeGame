#include "OakFood.h"

OakFood::OakFood(int startxPos, int startyPos, int bWidth, int bHeight) : Food(startxPos, startyPos, bWidth, bHeight)
{
	this->m_Symbol = 'O';
	this->m_food_Score = 3;
}

void OakFood::Update()
{
	//if there's any feature update could be added
}
