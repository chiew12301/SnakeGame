#include "AirFood.h"

AirFood::AirFood(int startxPos, int startyPos, int bWidth, int bHeight) : Food(startxPos, startyPos, bWidth, bHeight)
{
	this->m_Symbol = '@';
	this->m_food_Score = 1;
}

void AirFood::Update()
{
	//if there's any feature update could be added
}
