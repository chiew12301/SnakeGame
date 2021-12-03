#include "HashFood.h"

HashFood::HashFood(int startxPos, int startyPos, int bWidth, int bHeight) : Food(startxPos, startyPos, bWidth, bHeight)
{
	this->m_Symbol = '#';
	this->m_food_Score = 5;
}

void HashFood::Update()
{
	//if there's any feature update could be added
}
