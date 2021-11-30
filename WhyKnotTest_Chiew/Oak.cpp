#include "Oak.h"

Oak::Oak(int startxPos, int startyPos, int bWidth, int bHeight) : Food(startxPos, startyPos, bWidth, bHeight)
{
	m_Symbol = 'O';
	m_food_Score = 3;
}

void Oak::Update()
{
	//if there's any feature update could be added
}
